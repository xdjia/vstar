
// Generated from ./micro-benchmarks/lisp/cpp-build/g_lisp.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_lispParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by g_lispParser.
 */
class  g_lispListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(g_lispParser::StartContext *ctx) = 0;
  virtual void exitStart(g_lispParser::StartContext *ctx) = 0;

  virtual void enterSexpression(g_lispParser::SexpressionContext *ctx) = 0;
  virtual void exitSexpression(g_lispParser::SexpressionContext *ctx) = 0;

  virtual void enterList(g_lispParser::ListContext *ctx) = 0;
  virtual void exitList(g_lispParser::ListContext *ctx) = 0;

  virtual void enterAtomicsymbol(g_lispParser::AtomicsymbolContext *ctx) = 0;
  virtual void exitAtomicsymbol(g_lispParser::AtomicsymbolContext *ctx) = 0;

  virtual void enterAtompart(g_lispParser::AtompartContext *ctx) = 0;
  virtual void exitAtompart(g_lispParser::AtompartContext *ctx) = 0;


};

