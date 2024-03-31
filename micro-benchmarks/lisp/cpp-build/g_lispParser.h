
// Generated from ./micro-benchmarks/lisp/cpp-build/g_lisp.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  g_lispParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, LETTER = 4, NUMBER = 5, EMPTY = 6
  };

  enum {
    RuleStart = 0, RuleSexpression = 1, RuleList = 2, RuleAtomicsymbol = 3, 
    RuleAtompart = 4
  };

  explicit g_lispParser(antlr4::TokenStream *input);

  g_lispParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~g_lispParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class SexpressionContext;
  class ListContext;
  class AtomicsymbolContext;
  class AtompartContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SexpressionContext *sexpression();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  SexpressionContext : public antlr4::ParserRuleContext {
  public:
    SexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomicsymbolContext *atomicsymbol();
    std::vector<SexpressionContext *> sexpression();
    SexpressionContext* sexpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EMPTY();
    antlr4::tree::TerminalNode* EMPTY(size_t i);
    ListContext *list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SexpressionContext* sexpression();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SexpressionContext *> sexpression();
    SexpressionContext* sexpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EMPTY();
    antlr4::tree::TerminalNode* EMPTY(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ListContext* list();

  class  AtomicsymbolContext : public antlr4::ParserRuleContext {
  public:
    AtomicsymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LETTER();
    AtompartContext *atompart();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomicsymbolContext* atomicsymbol();

  class  AtompartContext : public antlr4::ParserRuleContext {
  public:
    AtompartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LETTER();
    antlr4::tree::TerminalNode *NUMBER();
    AtompartContext *atompart();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtompartContext* atompart();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

