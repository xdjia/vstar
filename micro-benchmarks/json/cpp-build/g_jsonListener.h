
// Generated from ./micro-benchmarks/json/cpp-build/g_json.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "g_jsonParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by g_jsonParser.
 */
class  g_jsonListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(g_jsonParser::StartContext *ctx) = 0;
  virtual void exitStart(g_jsonParser::StartContext *ctx) = 0;

  virtual void enterValue(g_jsonParser::ValueContext *ctx) = 0;
  virtual void exitValue(g_jsonParser::ValueContext *ctx) = 0;

  virtual void enterArray(g_jsonParser::ArrayContext *ctx) = 0;
  virtual void exitArray(g_jsonParser::ArrayContext *ctx) = 0;

  virtual void enterList(g_jsonParser::ListContext *ctx) = 0;
  virtual void exitList(g_jsonParser::ListContext *ctx) = 0;

  virtual void enterObject(g_jsonParser::ObjectContext *ctx) = 0;
  virtual void exitObject(g_jsonParser::ObjectContext *ctx) = 0;

  virtual void enterObjtuple(g_jsonParser::ObjtupleContext *ctx) = 0;
  virtual void exitObjtuple(g_jsonParser::ObjtupleContext *ctx) = 0;

  virtual void enterObjlist(g_jsonParser::ObjlistContext *ctx) = 0;
  virtual void exitObjlist(g_jsonParser::ObjlistContext *ctx) = 0;


};

