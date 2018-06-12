%{
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tree.h"
#include "table.h"

extern char yytext[];
extern int column;
extern FILE *yyin;

void yyerror(char const *s);

Tree root;
%}

%token IDENTIFIER CONSTANT CONSTANT_INT CONSTANT_DOUBLE STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%%

programme
    : translation_unit {
        root = createTree("programme", 1, $1);
    }

translation_unit
	: function_definition {
        $$ = createTree("translation_unit", 1, $1);
    }
	| translation_unit function_definition {
        $$ = createTree("translation_unit", 2, $1, $2);
    }
	;

function_definition
	: type_specifier IDENTIFIER '(' ')' compound_statement {
        $$ = createTree("function_definition", 3, $1, $2, $5);
    }
    | type_specifier IDENTIFIER '(' parameter_list ')' compound_statement {
        $$ = createTree("function_definition", 4, $1, $2, $4, $6);
    }
	;

type_specifier
	: VOID {
        $$ = createTree("type_specifier", 1, $1);
    }
	| INT {
        $$ = createTree("type_specifier", 1, $1);
    }
	| DOUBLE {
        $$ = createTree("type_specifier", 1, $1);
    }
	;

parameter_list
	: parameter_declaration {
        $$ = createTree("parameter_list", 1, $1);
    }
	| parameter_list ',' parameter_declaration {
        $$ = createTree("parameter_list", 2, $1, $3);
    }
	;

parameter_declaration
	: type_specifier IDENTIFIER {
        $$ = createTree("parameter_declaration", 2, $1, $2);
    }
	;

compound_statement
	: '{' statement_list '}' {
        $$ = createTree("compound_statement", 1, $2);
    }
	;

statement_list
	: statement {
        $$ = createTree("statement_list", 1, $1);
    }
	| statement_list statement {
        $$ = createTree("statement_list", 2, $1, $2);
    }
	;

statement
	: compound_statement {
        $$ = createTree("statement", 1, $1);
    }
	| expression ';'{
        $$ = createTree("statement", 1, $1);
    }
	| selection_statement {
        $$ = createTree("statement", 1, $1);
    }
	| iteration_statement {
        $$ = createTree("statement", 1, $1);
    }
	| jump_statement {
        $$ = createTree("statement", 1, $1);
    }
    | declaration {
        $$ = createTree("statement", 1, $1);
    }
    | ';' {
        
    }
	;

expression_statement
	: ';' {
    }
	| expression ';' {
        $$ = createTree("expression_statement", 1, $1);
    }
	;

selection_statement
	: IF '(' expression ')' statement {
        $$ = createTree("selection_statement", 3, $1, $3, $5);
    }
	| IF '(' expression ')' statement ELSE statement {
        $$ = createTree("selection_statement", 5, $1, $3, $5, $6, $7);
    }
	;

iteration_statement
	: WHILE '(' expression ')' statement {
        $$ = createTree("iteration_statement", 5, $1, $2, $3, $4, $5);
    }
	| FOR '(' expression_statement expression_statement ')' statement {
        $$ = createTree("iteration_statement", 6, $1, $2, $3, $4, $5, $6);
    }
	| FOR '(' expression_statement expression_statement expression ')' statement {
        $$ = createTree("iteration_statement", 7, $1, $2, $3, $4, $5, $6, $7);
    }
	;

jump_statement
	: RETURN ';' {
        $$ = createTree("jump_statement", 2, $1, $2);
    }
	| RETURN expression ';' {
        $$ = createTree("jump_statement", 3, $1, $2, $3);
    }
	;

declaration
	: type_specifier identifier_list ';' {
        $$ = createTree("declaration", 2, $1, $2);
    }
	;

identifier_list
	: IDENTIFIER {
        $$ = createTree("identifier_list", 1, $1);
    }
	| identifier_list ',' IDENTIFIER {
        $$ = createTree("identifier_list", 2, $1, $3);
    }
	;

expression
	: IDENTIFIER '=' expression{
        $$ = createTree("expression", 3, $1, $2, $3);
    }
	| relational_expression {
        $$ = createTree("expression", 1, $1);
    }
	;

unary_expression
	: postfix_expression {
        $$ = createTree("unary_expression", 1, $1);
    }
	| '+' unary_expression {
        $$ = createTree("unary_expression", 2, $1, $2);
    }
    | '-' unary_expression {
        $$ = createTree("unary_expression", 2, $1, $2);
    }
	;

multiplicative_expression
	: unary_expression {
        $$ = createTree("multiplicative_expression", 1, $1);
    }
	| multiplicative_expression '*' unary_expression {
        $$ = createTree("multiplicative_expression", 3, $1, $2, $3);
    }
	| multiplicative_expression '/' unary_expression {
        $$ = createTree("multiplicative_expression", 3, $1, $2, $3);
    }
	;

additive_expression
	: multiplicative_expression {
        $$ = createTree("additive_expression", 1, $1);
    }
	| additive_expression '+' multiplicative_expression {
        $$ = createTree("additive_expression", 3, $1, $2, $3);
    }
	| additive_expression '-' multiplicative_expression {
        $$ = createTree("additive_expression", 3, $1, $2, $3);
    }
	;

relational_expression
	: additive_expression {
        $$ = createTree("relational_expression", 1, $1);
    }
	| relational_expression '<' additive_expression {
        $$ = createTree("relational_expression", 3, $1, $2, $3);
    }
	| relational_expression '>' additive_expression {
        $$ = createTree("relational_expression", 3, $1, $2, $3);
    }
	| relational_expression LE_OP additive_expression {
        $$ = createTree("relational_expression", 3, $1, $2, $3);
    }
	| relational_expression GE_OP additive_expression {
        $$ = createTree("relational_expression", 3, $1, $2, $3);
    }
	;

postfix_expression
	: primary_expression {
        $$ = createTree("postfix_expression", 1, $1);
    }
	| postfix_expression '[' expression ']' {
        $$ = createTree("postfix_expression", 4, $1, $2, $3, $4);
    }
	| postfix_expression '(' ')' {
        $$ = createTree("postfix_expression", 3, $1, $2, $3);
    }
	| postfix_expression '(' argument_expression_list ')' {
        $$ = createTree("postfix_expression", 4, $1, $2, $3, $4);
    }
	;

primary_expression
	: IDENTIFIER {
        $$ = createTree("primary_expression", 1, $1);
    }
	| CONSTANT_INT {
        $$ = createTree("primary_expression", 1, $1);
    }
    | CONSTANT_DOUBLE {
        $$ = createTree("primary_expression", 1, $1);
    }
	| '(' expression ')' {
        $$ = createTree("primary_expression", 1, $2);
    }
	;

argument_expression_list
	: assignment_expression {
        $$ = createTree("argument_expression_list", 1, $1);
    }
	| argument_expression_list ',' assignment_expression {
        $$ = createTree("argument_expression_list", 3, $1, $2, $3);
    }
	;

assignment_expression
	: relational_expression {
        $$ = createTree("assignment_expression", 1, $1);
    }
	| unary_expression '=' assignment_expression {
        $$ = createTree("assignment_expression", 3, $1, $2, $3);
    }
	;

%%

// 主函数
int main() {
    yyin = fopen("test.c", "r");  // 测试代码
    if(yyin == NULL)
    	printf("open failed");
    //initialize();
    yyparse();  // 进行语法分析，生成的树存储在全局变量root中
    visualize(root, "tree.dot");  // 可视化
    printf("\n");
    codeGen(root);
    //parse(root);
	fclose(yyin);
    return 0;
}

void yyerror(char const *s) {
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
