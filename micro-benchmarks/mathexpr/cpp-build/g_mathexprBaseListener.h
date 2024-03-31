
// Generated from ./micro-benchmarks/mathexpr/cpp-build/g_mathexpr.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_mathexprListener.h"


/**
 * This class provides an empty implementation of g_mathexprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  g_mathexprBaseListener : public g_mathexprListener {
public:

  virtual void enterStart(g_mathexprParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(g_mathexprParser::StartContext * /*ctx*/) override { }

  virtual void enterExpr(g_mathexprParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(g_mathexprParser::ExprContext * /*ctx*/) override { }

  virtual void enterExprp(g_mathexprParser::ExprpContext * /*ctx*/) override { }
  virtual void exitExprp(g_mathexprParser::ExprpContext * /*ctx*/) override { }

  virtual void enterFunccall(g_mathexprParser::FunccallContext * /*ctx*/) override { }
  virtual void exitFunccall(g_mathexprParser::FunccallContext * /*ctx*/) override { }

  virtual void enterArglist(g_mathexprParser::ArglistContext * /*ctx*/) override { }
  virtual void exitArglist(g_mathexprParser::ArglistContext * /*ctx*/) override { }

  virtual void enterOp(g_mathexprParser::OpContext * /*ctx*/) override { }
  virtual void exitOp(g_mathexprParser::OpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

