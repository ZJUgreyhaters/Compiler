#include "tree.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
//中间代码生成入口函数
void codeGen(Tree t);
//函数基本快代码生成
void funCode(Tree t);
//参数列表代码生成
void paraListCode(Tree t);
//复合语句代码生成
void compStatCode(Tree t);
//语句列表
void statListCode(Tree t);
//语句代码生成
void statementCode(Tree t);
//表达式代码生成
void expCode(Tree t);
//赋值语句代码生成
void standexpCode(Tree t);
//条件转移语句代码生成
void conditionCode(Tree t);//处理 if 语句
//关系比较语句
void relationexpCode(Tree t);//
//循环语句代码生成
void loopCode(Tree t);//处理 while 和 for 语句
//返回语句代码生成
void returnCode(Tree t);//处理 return 语句