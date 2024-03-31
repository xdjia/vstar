
// Generated from ./micro-benchmarks/xml/cpp-build/g_xml.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  g_xmlParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, ASTART = 5, AEND = 6, BSTART = 7, 
    BEND = 8, CSTART = 9, CEND = 10, DSTART = 11, DEND = 12, ESTART = 13, 
    EEND = 14, CHAR = 15, QUOTE = 16
  };

  enum {
    RuleStart = 0, RuleXml = 1, RuleBody = 2, RuleAttrlist = 3, RuleAttr = 4, 
    RuleText = 5, RuleSpace = 6
  };

  explicit g_xmlParser(antlr4::TokenStream *input);

  g_xmlParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~g_xmlParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class XmlContext;
  class BodyContext;
  class AttrlistContext;
  class AttrContext;
  class TextContext;
  class SpaceContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    XmlContext *xml();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  XmlContext : public antlr4::ParserRuleContext {
  public:
    XmlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASTART();
    BodyContext *body();
    antlr4::tree::TerminalNode *AEND();
    AttrlistContext *attrlist();
    antlr4::tree::TerminalNode *BSTART();
    antlr4::tree::TerminalNode *BEND();
    antlr4::tree::TerminalNode *CSTART();
    antlr4::tree::TerminalNode *CEND();
    antlr4::tree::TerminalNode *DSTART();
    antlr4::tree::TerminalNode *DEND();
    antlr4::tree::TerminalNode *ESTART();
    antlr4::tree::TerminalNode *EEND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  XmlContext* xml();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    XmlContext *xml();
    TextContext *text();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BodyContext* body();

  class  AttrlistContext : public antlr4::ParserRuleContext {
  public:
    AttrlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SpaceContext *space();
    AttrContext *attr();
    AttrlistContext *attrlist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttrlistContext* attrlist();

  class  AttrContext : public antlr4::ParserRuleContext {
  public:
    AttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TextContext *> text();
    TextContext* text(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QUOTE();
    antlr4::tree::TerminalNode* QUOTE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttrContext* attr();

  class  TextContext : public antlr4::ParserRuleContext {
  public:
    TextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHAR();
    TextContext *text();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TextContext* text();
  TextContext* text(int precedence);
  class  SpaceContext : public antlr4::ParserRuleContext {
  public:
    SpaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SpaceContext* space();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool textSempred(TextContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

