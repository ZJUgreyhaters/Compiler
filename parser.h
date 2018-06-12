#include <stdio.h>
#include "table.h"
#include "tree.h"
#include "string.h"

typedef char *string;

void parse(Tree t);
void parseFuncitonDefinition(Tree t);
void parseCompoundStatement(Tree t);
void parseJumpStatement(Tree t);
void parseStatement(Tree t);

string parseExpression(Tree t);
string parseRelationalExpression(Tree t);
string parseAdditiveExpression(Tree t);
string parseMultiplicativeExpression(Tree t);
string parseUnaryExpression(Tree t);
string parsePostfixExpression(Tree t);
string parsePrimaryExpression(Tree t);

void error(int line, string message);
