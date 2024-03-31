
// Generated from ./micro-benchmarks/xml/cpp-build/g_xml.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  g_xmlLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, ASTART = 5, AEND = 6, BSTART = 7, 
    BEND = 8, CSTART = 9, CEND = 10, DSTART = 11, DEND = 12, ESTART = 13, 
    EEND = 14, CHAR = 15, QUOTE = 16
  };

  explicit g_xmlLexer(antlr4::CharStream *input);

  ~g_xmlLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

