
// Generated from ./micro-benchmarks/json/cpp-build/g_json.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_jsonListener.h"


/**
 * This class provides an empty implementation of g_jsonListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  g_jsonBaseListener : public g_jsonListener {
public:

  virtual void enterStart(g_jsonParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(g_jsonParser::StartContext * /*ctx*/) override { }

  virtual void enterValue(g_jsonParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(g_jsonParser::ValueContext * /*ctx*/) override { }

  virtual void enterArray(g_jsonParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(g_jsonParser::ArrayContext * /*ctx*/) override { }

  virtual void enterList(g_jsonParser::ListContext * /*ctx*/) override { }
  virtual void exitList(g_jsonParser::ListContext * /*ctx*/) override { }

  virtual void enterObject(g_jsonParser::ObjectContext * /*ctx*/) override { }
  virtual void exitObject(g_jsonParser::ObjectContext * /*ctx*/) override { }

  virtual void enterObjtuple(g_jsonParser::ObjtupleContext * /*ctx*/) override { }
  virtual void exitObjtuple(g_jsonParser::ObjtupleContext * /*ctx*/) override { }

  virtual void enterObjlist(g_jsonParser::ObjlistContext * /*ctx*/) override { }
  virtual void exitObjlist(g_jsonParser::ObjlistContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

