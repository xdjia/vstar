
// Generated from ./micro-benchmarks/xml/cpp-build/g_xml.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_xmlParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by g_xmlParser.
 */
class  g_xmlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(g_xmlParser::StartContext *ctx) = 0;
  virtual void exitStart(g_xmlParser::StartContext *ctx) = 0;

  virtual void enterXml(g_xmlParser::XmlContext *ctx) = 0;
  virtual void exitXml(g_xmlParser::XmlContext *ctx) = 0;

  virtual void enterBody(g_xmlParser::BodyContext *ctx) = 0;
  virtual void exitBody(g_xmlParser::BodyContext *ctx) = 0;

  virtual void enterAttrlist(g_xmlParser::AttrlistContext *ctx) = 0;
  virtual void exitAttrlist(g_xmlParser::AttrlistContext *ctx) = 0;

  virtual void enterAttr(g_xmlParser::AttrContext *ctx) = 0;
  virtual void exitAttr(g_xmlParser::AttrContext *ctx) = 0;

  virtual void enterText(g_xmlParser::TextContext *ctx) = 0;
  virtual void exitText(g_xmlParser::TextContext *ctx) = 0;

  virtual void enterSpace(g_xmlParser::SpaceContext *ctx) = 0;
  virtual void exitSpace(g_xmlParser::SpaceContext *ctx) = 0;


};

