
// Generated from ./micro-benchmarks/mathexpr/cpp-build/g_mathexpr.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_mathexprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by g_mathexprParser.
 */
class  g_mathexprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(g_mathexprParser::StartContext *ctx) = 0;
  virtual void exitStart(g_mathexprParser::StartContext *ctx) = 0;

  virtual void enterExpr(g_mathexprParser::ExprContext *ctx) = 0;
  virtual void exitExpr(g_mathexprParser::ExprContext *ctx) = 0;

  virtual void enterExprp(g_mathexprParser::ExprpContext *ctx) = 0;
  virtual void exitExprp(g_mathexprParser::ExprpContext *ctx) = 0;

  virtual void enterFunccall(g_mathexprParser::FunccallContext *ctx) = 0;
  virtual void exitFunccall(g_mathexprParser::FunccallContext *ctx) = 0;

  virtual void enterArglist(g_mathexprParser::ArglistContext *ctx) = 0;
  virtual void exitArglist(g_mathexprParser::ArglistContext *ctx) = 0;

  virtual void enterOp(g_mathexprParser::OpContext *ctx) = 0;
  virtual void exitOp(g_mathexprParser::OpContext *ctx) = 0;


};

