import re
from typing import Literal

from .Automata import UDFA
from .RE import StarRE, re2pyre, pp_re
from .Utils import pp, art_call, art_retn

# NOTE - tagged token
TokenType = Literal['plain', 'call', 'return']

# NOTE - a counterexample (s, h) is string s and its tokenization h
CE = tuple[str, list[str | tuple["Token", str]]]


class Token:
    def __init__(self, rex: StarRE, strs, udfa: UDFA,
                 token_type: TokenType = "plain") -> None:
        """ A token is a collection of regular expressions. """

        self.rex = rex
        self.re = re.compile(re2pyre(rex))
        self.strs: list[str] = strs
        self.udfa = udfa
        self.token_type: TokenType = token_type
        self.module = 0
        self.repr = strs[0]

    def copy(self):
        return Token(self.rex, self.strs, self.udfa, self.token_type)

    def replace_with(self, token: "Token"):
        """ set self to another token """
        assert self.token_type == token.token_type

        self.rex = token.rex
        self.re = token.re
        self.strs = token.strs
        self.udfa = token.udfa

    def __str__(self) -> str:
        return pp_re(self.rex, all_chars=[])

    def match(self, s: str, pos=0):
        """ match a string using `re` """
        return self.re.match(s, pos=pos)

    def search(self, s: str, pos=0):
        """ search a string using `re` """

        m = self.re.search(s, pos=pos)
        if m:
            return (self, m)
        else:
            return None


def pp_tokens(s: str, tokens: list[tuple[Token, re.Match]]) -> str:
    """ pretty print token list """
    return f"{pp(s)} => [{', '.join(f'{pp(s[m.start():m.end()])}'
                                    for token, m in tokens)}]"


def pp_ce(s: CE):
    """ pretty print counterexample """

    pp_s = ""
    for c in s[1]:
        match c:
            case str(c):
                pp_s += pp(c)
            case (token, w):
                if token.token_type == 'call':
                    pp_s += f"{art_call}{pp(w)}"
                else:
                    pp_s += f"{pp(w)}{art_retn}"
        pp_s += " "

    return pp_s
