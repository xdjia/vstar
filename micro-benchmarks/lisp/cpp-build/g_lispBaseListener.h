
// Generated from ./micro-benchmarks/lisp/cpp-build/g_lisp.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_lispListener.h"


/**
 * This class provides an empty implementation of g_lispListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  g_lispBaseListener : public g_lispListener {
public:

  virtual void enterStart(g_lispParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(g_lispParser::StartContext * /*ctx*/) override { }

  virtual void enterSexpression(g_lispParser::SexpressionContext * /*ctx*/) override { }
  virtual void exitSexpression(g_lispParser::SexpressionContext * /*ctx*/) override { }

  virtual void enterList(g_lispParser::ListContext * /*ctx*/) override { }
  virtual void exitList(g_lispParser::ListContext * /*ctx*/) override { }

  virtual void enterAtomicsymbol(g_lispParser::AtomicsymbolContext * /*ctx*/) override { }
  virtual void exitAtomicsymbol(g_lispParser::AtomicsymbolContext * /*ctx*/) override { }

  virtual void enterAtompart(g_lispParser::AtompartContext * /*ctx*/) override { }
  virtual void exitAtompart(g_lispParser::AtompartContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

