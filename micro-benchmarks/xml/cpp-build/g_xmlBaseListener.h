
// Generated from ./micro-benchmarks/xml/cpp-build/g_xml.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_xmlListener.h"


/**
 * This class provides an empty implementation of g_xmlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  g_xmlBaseListener : public g_xmlListener {
public:

  virtual void enterStart(g_xmlParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(g_xmlParser::StartContext * /*ctx*/) override { }

  virtual void enterXml(g_xmlParser::XmlContext * /*ctx*/) override { }
  virtual void exitXml(g_xmlParser::XmlContext * /*ctx*/) override { }

  virtual void enterBody(g_xmlParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(g_xmlParser::BodyContext * /*ctx*/) override { }

  virtual void enterAttrlist(g_xmlParser::AttrlistContext * /*ctx*/) override { }
  virtual void exitAttrlist(g_xmlParser::AttrlistContext * /*ctx*/) override { }

  virtual void enterAttr(g_xmlParser::AttrContext * /*ctx*/) override { }
  virtual void exitAttr(g_xmlParser::AttrContext * /*ctx*/) override { }

  virtual void enterText(g_xmlParser::TextContext * /*ctx*/) override { }
  virtual void exitText(g_xmlParser::TextContext * /*ctx*/) override { }

  virtual void enterSpace(g_xmlParser::SpaceContext * /*ctx*/) override { }
  virtual void exitSpace(g_xmlParser::SpaceContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

