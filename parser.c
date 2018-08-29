#include "parser.h"

// 对语法树进行语义分析
void parse(Tree t) {
    if(t == NULL) {
        return;
    }
    else if(strcmp(t->kind, "function_definition") == 0) {
        parseFuncitonDefinition(t);
    }
    else {
        parse(t->firstChild);
        parse(t->nextSibling);
    }
}

// 将函数的名称、类型、形参类型列表存入函数池中
void parseFuncitonDefinition(Tree t) {
    beginScope();
    FuncNode func = malloc(sizeof(struct FuncNodeRecord));
    func->name = t->firstChild->nextSibling->content;
    func->type = t->firstChild->firstChild->kind;
    for(int i = 0; i < PARA_LIST_SIZE; i++) {
        func->paralist[i] = NULL;
    }

    t = t->firstChild->nextSibling->nextSibling;
    if(strcmp(t->kind, "parameter_list") == 0) {
        Tree tmp = t;
        Tree para;
        int i = 0;
        while(strcmp(tmp->firstChild->kind, "parameter_list") == 0) {
            tmp = tmp->firstChild;
            para = tmp->nextSibling;
            func->paralist[i++] = para->firstChild->firstChild->kind;

            // 将形参存入符号表
            insertVar(para->firstChild->nextSibling->content, para->firstChild->firstChild->kind);
        }
        
        para = tmp->firstChild;
        func->paralist[i] = para->firstChild->firstChild->kind;
        insertFunc(func);
        insertVar(para->firstChild->nextSibling->content, para->firstChild->firstChild->kind);

        t = t->nextSibling;
    }

    parseCompoundStatement(t);
    endScope();
    parse(t->nextSibling);
}

void parseCompoundStatement(Tree t) {
    if(t == NULL) {
        return;
    }
    else if(strcmp(t->kind, "statement") == 0) {
        parseStatement(t);
    }
    else {
        parseCompoundStatement(t->firstChild);
        parseCompoundStatement(t->nextSibling);
    }
}

void parseStatement(Tree t) {
    if(strcmp(t->firstChild->kind, "compound_statement") == 0) {
        parseCompoundStatement(t->firstChild);
    }
    else if(strcmp(t->firstChild->kind, "expression") == 0) {
        parseExpression(t->firstChild);
    }
    else if(strcmp(t->firstChild->kind, "selection_statement") == 0) {
        
    }
    else if(strcmp(t->firstChild->kind, "iteration_statement") == 0) {

    }
    else if(strcmp(t->firstChild->kind, "jump_statement") == 0) {
        parseJumpStatement(t->firstChild);
    }
    else if(strcmp(t->firstChild->kind, "declaration") == 0) {
        Tree tmp = t->firstChild->firstChild->nextSibling;
		tmp = tmp->firstChild;
        string type = t->firstChild->firstChild->firstChild->kind;
        while(tmp->firstChild != NULL) {
            insertVar(tmp->nextSibling->content, type);
            tmp = tmp->firstChild;
        }
        insertVar(tmp->content, type);
    }
}

string parseExpression(Tree t) {
    if(strcmp(t->firstChild->kind, "IDENTIFIER") == 0) {
        Tree e1 = t->firstChild;
        Tree e2 = t->firstChild->nextSibling->nextSibling;

        string type1 = lookupVar(e1->content);
        if(type1 == NULL) {
            error(e1->line, "the identifier is not defined yet.");
        }

        string type2 = parseExpression(e2);

        if(type2!= NULL && strcmp(type1, type2) != 0) {  // 赋值表达式类型不匹配 & 错误恢复
            error(t->line, "the assignment expression should have the same type with the identifier.");
        }
        return NULL;
    }
    else {
        return parseRelationalExpression(t->firstChild);
    }
}

string parseRelationalExpression(Tree t) {
    if(strcmp(t->firstChild->kind, "additive_expression") == 0) {
        return parseAdditiveExpression(t->firstChild);
    }
    else {
        return "INT";   // 关系表达式真为1，假为0，用INT表示
    }
}

// 分析additive_expresssion，返回表达式的类型
string parseAdditiveExpression(Tree t) {
    if(strcmp(t->firstChild->kind, "multiplicative_expression") == 0) {
        return parseMultiplicativeExpression(t->firstChild);
    }
    else {
        Tree e1 = t->firstChild;
        Tree e2 = t->firstChild->nextSibling->nextSibling;
        string type1 = parseAdditiveExpression(e1);
        string type2 = parseMultiplicativeExpression(e2);
        if(strcmp(type1, type2) != 0) {  // 表达式类型不匹配
			error(t->line, "the expression should have the same type.");
            return type1;   // 错误恢复：将表达式的类型设置type1
        }
        else {
            return type1;
        }
    }
}

// 分析multiplicative_expression，返回表达式的类型
string parseMultiplicativeExpression(Tree t) {
    if(strcmp(t->firstChild->kind, "unary_expression") == 0) {
        return parseUnaryExpression(t->firstChild);
    }
    else {
        Tree e1 = t->firstChild;
        Tree e2 = t->firstChild->nextSibling->nextSibling;
        string type1 = parseMultiplicativeExpression(e1);
        string type2 = parseUnaryExpression(e2);
        if(strcmp(type1, type2) != 0) {  // 表达式类型不匹配
			error(t->line, "the expression should have the same type.");
            return type1;   // 错误恢复：将表达式的类型设置type1
        }
        else {
            return type1;
        }
    }
}

string parseUnaryExpression(Tree t) {
    if(strcmp(t->firstChild->kind, "postfix_expression") == 0) {
        return parsePostfixExpression(t->firstChild);
    }
    else {
        return parseUnaryExpression(t->firstChild->nextSibling);
    }
}

string parsePostfixExpression(Tree t) {
    if(strcmp(t->firstChild->kind, "primary_expression") == 0) {
        return parsePrimaryExpression(t->firstChild);
    }
    else if(strcmp(t->firstChild->nextSibling->kind, "argument_expression_list") == 0) {
        FuncNode func = lookupFunc(t->firstChild->firstChild->firstChild->content);
        if(func == NULL) {
            error(t->line, "the function is not defined yet.");
            return NULL;
        }
        else {
            // 调用函数时检查函数参数个数是否正确
            int count1 = 0;
            for(int i = 0; i < PARA_LIST_SIZE; i++) {
                if(func->paralist[i] != NULL) {
                    count1++;
                }
            }

            int count2 = 1;
            Tree tmp = t->firstChild->nextSibling;
            while(strcmp(tmp->firstChild->kind, "argument_expression_list") == 0) {
                tmp = tmp->firstChild;
                count2++;
            }

            if(count2 < count1) {
                error(t->line, "their are too few arguments.");
                return NULL;
            }
            else if(count2 > count1) {
                error(t->line, "their are too many arguments.");
                return NULL;
            }

            // 调用函数时检查函数形参的类型是否匹配
            tmp = t->firstChild->nextSibling;
            Tree arg;
            int i = 0;

            while(strcmp(tmp->firstChild->kind, "argument_expression_list") == 0) {
                tmp = tmp->firstChild;
                arg = tmp->nextSibling;
                while(strcmp(arg->kind, "IDENTIFIER") != 0) {
                    arg = arg->firstChild;
                }
                string type = lookupVar(arg->content);
                if(type == NULL) {
                    error(t->line, "the identifier is not defined yet.");
                }
                else if(strcmp(type, func->paralist[i++]) != 0) {
                    printf("Error(at line %d): the type of the argument %s is not matched with the definiton of function %s.\n", t->line, arg->content, func->name);
                }
            }

            arg = tmp;
            while(strcmp(arg->kind, "IDENTIFIER") != 0) {
                arg = arg->firstChild;
            }
            string type = lookupVar(arg->content);
            if(type == NULL) {
                error(t->line, "the identifier is not defined yet.");
            }
            else if(strcmp(type, func->paralist[i]) != 0) {
                printf("Error(at line %d): the type of the argument %s is not matched with the definiton of function %s.\n", t->line, arg->content, func->name);
            }

            return func->type;
        }
    }
}

string parsePrimaryExpression(Tree t) {
    if(strcmp(t->firstChild->kind, "IDENTIFIER") == 0) {
        string type = lookupVar(t->firstChild->content);
        if(type == NULL) {
            error(t->line, "the identifier is not defined yet.");
        }
        return type;
    }
    else if(strcmp(t->firstChild->kind, "CONSTANT_INT") == 0) {
        return "INT";
    }
    else if(strcmp(t->firstChild->kind, "CONSTANT_DOUBLE") == 0) {
        return "DOUBLE";
    }
    else {
        return parseExpression(t->firstChild);
    }
}

void parseJumpStatement(Tree t) {
    if(strcmp(t->firstChild->nextSibling->kind, "expression") == 0) {
        string returnType = parseExpression(t->firstChild->nextSibling);
        string funcType = getFuncType();
        if(strcmp(returnType, funcType) != 0) {
            error(t->line, "the return type is not matched with its function type.");
        }
    }
}

void error(int line, string message) {
    printf("Error(at line %d): %s\n", line, message);
}
