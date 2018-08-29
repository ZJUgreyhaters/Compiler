%{
#include "y.tab.h"
#include "tree.h"

void count();
void comment();

int column = 0;
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%option yylineno

%%
"/*"			{ comment(); }

"auto"			{ 
					count(); 
					yylval = createLeaf("AUTO", yylineno, NULL); 
					return(AUTO); 
				}

"break"			{ 
					count(); 
					yylval = createLeaf("BREAK", yylineno, NULL); 
					return(BREAK); 
				}

"case"			{ 
					count(); 
					yylval = createLeaf("CASE", yylineno, NULL); 
					return(CASE); 
				}

"char"			{ 
					count(); 
					yylval = createLeaf("CHAR", yylineno, NULL); 
					return(CHAR); 
				}

"const"			{ 
					count(); 
					yylval = createLeaf("CONST", yylineno, NULL); 
					return(CONST); 
				}

"continue"		{ 
					count(); 
					yylval = createLeaf("CONTINUE", yylineno, NULL); 
					return(CONTINUE); 
				}

"default"		{ 
					count(); 
					yylval = createLeaf("DEFAULT", yylineno, NULL); 
					return(DEFAULT); 
				}

"do"			{ 
					count(); 
					yylval = createLeaf("DO", yylineno, NULL); 
					return(DO); 
				}

"double"		{ 
					count(); 
					yylval = createLeaf("DOUBLE", yylineno, NULL); 
					return(DOUBLE); 
				}

"else"			{ 
					count(); 
					yylval = createLeaf("ELSE", yylineno, NULL); 
					return(ELSE); 
				}

"enum"			{ 
					count(); 
					yylval = createLeaf("ENUM", yylineno, NULL); 
					return(ENUM); 
				}

"extern"		{ 
					count(); 
					yylval = createLeaf("EXTERN", yylineno, NULL); 
					return(EXTERN); 
				}

"float"			{ 
					count(); 
					yylval = createLeaf("FLOAT", yylineno, NULL); 
					return(FLOAT); 
				}

"for"			{ 
					count(); 
					yylval = createLeaf("FOR", yylineno, NULL); 
					return(FOR); 
				}

"goto"			{ 
					count(); 
					yylval = createLeaf("GOTO", yylineno, NULL); 
					return(GOTO); 
				}

"if"			{ 
					count(); 
					yylval = createLeaf("IF", yylineno, NULL); 
					return(IF); 
				}

"int"			{ 
					count(); 
					yylval = createLeaf("INT", yylineno, NULL); 
					return(INT); 
				}

"long"			{ 
					count(); 
					yylval = createLeaf("LONG", yylineno, NULL); 
					return(LONG); 
				}

"register"		{ 
					count(); 
					yylval = createLeaf("REGISTER", yylineno, NULL); 
					return(REGISTER); 
				}

"return"		{ 
					count(); 
					yylval = createLeaf("RETURN", yylineno, NULL); 
					return(RETURN); 
				}

"short"			{ 
					count(); 
					yylval = createLeaf("SHORT", yylineno, NULL); 
					return(SHORT); 
				}

"signed"		{ 
					count(); 
					yylval = createLeaf("SIGNED", yylineno, NULL); 
					return(SIGNED); 
				}

"sizeof"		{ 
					count(); 
					yylval = createLeaf("SIZEOF", yylineno, NULL); 
					return(SIZEOF); 
				}

"static"		{ 
					count(); 
					yylval = createLeaf("STATIC", yylineno, NULL); 
					return(STATIC); 
				}

"struct"		{ 
					count(); 
					yylval = createLeaf("STRUCT", yylineno, NULL); 
					return(STRUCT); 
				}

"switch"		{ 
					count(); 
					yylval = createLeaf("SWITCH", yylineno, NULL); 
					return(SWITCH); 
				}

"typedef"		{ 
					count(); 
					yylval = createLeaf("TYPEDEF", yylineno, NULL); 
					return(TYPEDEF); 
				}

"union"			{ 
					count(); 
					yylval = createLeaf("UNION", yylineno, NULL); 
					return(UNION); 
				}

"unsigned"		{ 
					count(); 
					yylval = createLeaf("UNSIGNED", yylineno, NULL); 
					return(UNSIGNED); 
				}

"void"			{ 
					count(); 
					yylval = createLeaf("VOID", yylineno, NULL); 
					return(VOID); 
				}

"volatile"		{ 
					count(); 
					yylval = createLeaf("VOLATILE", yylineno, NULL); 
					return(VOLATILE); 
				}

"while"			{ 
					count(); 
					yylval = createLeaf("WHILE", yylineno, NULL); 
					return(WHILE); 
				}


{L}({L}|{D})*			{
							count(); 
							yylval = createLeaf("IDENTIFIER", yylineno, yytext); 
							return(IDENTIFIER); 
						}

0[xX]{H}+{IS}?			{
							count(); 
							yylval = createLeaf("CONSTANT_INT", yylineno, yytext); 
							return(CONSTANT_INT); 
						}

0{D}+{IS}?				{
							count();
							yylval = createLeaf("CONSTANT_INT", yylineno, yytext); 
							return(CONSTANT_INT); 
						}

{D}+{IS}?				{	count();
							yylval = createLeaf("CONSTANT_INT", yylineno, yytext); 
							return(CONSTANT_INT); 
						}

L?'(\\.|[^\\'])+'		{ 	count(); 
							return(CONSTANT); }

{D}+{E}{FS}?			{ 
							count(); 
							yylval = createLeaf("CONSTANT_DOUBLE", yylineno, yytext); 
							return(CONSTANT_DOUBLE); 
						}

{D}*"."{D}+({E})?{FS}?	{ 
							count(); 
							yylval = createLeaf("CONSTANT_DOUBLE", yylineno, yytext); 
							return(CONSTANT_DOUBLE); 
						}

{D}+"."{D}*({E})?{FS}?	{ 
							count(); 
							yylval = createLeaf("CONSTANT_DOUBLE", yylineno, yytext); 
							return(CONSTANT_DOUBLE); 
						}

L?\"(\\.|[^\\"])*\"		{ 
							count(); 
							yylval = createLeaf("STRING_LITERAL", yylineno, NULL); 
							return(STRING_LITERAL); 
						}

"..."			{ 
					count(); 
					yylval = createLeaf("ELLIPSIS", yylineno, NULL); 
					return(ELLIPSIS); 
				}

">>="			{ 
					count(); 
					yylval = createLeaf("RIGHT_ASSIGN", yylineno, NULL); 
					return(RIGHT_ASSIGN); 
				}

"<<="			{ 
					count(); 
					yylval = createLeaf("LEFT_ASSIGN", yylineno, NULL); 
					return(LEFT_ASSIGN); 
				}

"+="			{ 
					count(); 
					yylval = createLeaf("ADD_ASSIGN", yylineno, NULL); 
					return(ADD_ASSIGN); 
				}

"-="			{ 
					count(); 
					yylval = createLeaf("SUB_ASSIGN", yylineno, NULL); 
					return(SUB_ASSIGN); 
				}

"*="			{ 
					count(); 
					yylval = createLeaf("MUL_ASSIGN", yylineno, NULL); 
					return(MUL_ASSIGN); 
				}

"/="			{ 
					count(); 
					yylval = createLeaf("DIV_ASSIGN", yylineno, NULL); 
					return(DIV_ASSIGN); 
				}

"%="			{ 
					count(); 
					yylval = createLeaf("MOD_ASSIGN", yylineno, NULL); 
					return(MOD_ASSIGN); 
				}

"&="			{ 
					count(); 
					yylval = createLeaf("AND_ASSIGN", yylineno, NULL); 
					return(AND_ASSIGN); 
				}

"^="			{ 
					count(); 
					yylval = createLeaf("XOR_ASSIGN", yylineno, NULL); 
					return(XOR_ASSIGN); 
				}

"|="			{ 
					count(); 
					yylval = createLeaf("OR_ASSIGN", yylineno, NULL); 
					return(OR_ASSIGN); 
				}

">>"			{ 
					count(); 
					yylval = createLeaf("RIGHT_OP", yylineno, NULL); 
					return(RIGHT_OP); 
				}

"<<"			{ 
					count(); 
					yylval = createLeaf("LEFT_OP", yylineno, NULL); 
					return(LEFT_OP); 
				}

"++"			{ 
					count(); 
					yylval = createLeaf("INC_OP", yylineno, NULL); 
					return(INC_OP); 
				}

"--"			{ 
					count(); 
					yylval = createLeaf("DEC_OP", yylineno, NULL); 
					return(DEC_OP); 
				}

"->"			{ 
					count(); 
					yylval = createLeaf("PTR_OP", yylineno, NULL); 
					return(PTR_OP); 
				}

"&&"			{ 
					count(); 
					yylval = createLeaf("AND_OP", yylineno, NULL); 
					return(AND_OP); 
				}

"||"			{ 
					count(); 
					yylval = createLeaf("OR_OP", yylineno, NULL); 
					return(OR_OP); 
				}

"<="			{ 
					count(); 
					yylval = createLeaf("LE_OP", yylineno, NULL); 
					return(LE_OP); 
				}

">="			{ 
					count(); 
					yylval = createLeaf("GE_OP", yylineno, NULL); 
					return(GE_OP); 
				}

"=="			{ 
					count(); 
					yylval = createLeaf("EQ_OP", yylineno, NULL); 
					return(EQ_OP); 
				}

"!="			{ 
					count(); 
					yylval = createLeaf("NE_OP", yylineno, NULL); 
					return(NE_OP); 
				}

";"				{ 
					count(); 
					yylval = createLeaf(";", yylineno, NULL); 
					return(';'); 
				}

("{"|"<%")		{ 
					count(); 
					yylval = createLeaf("{", yylineno, NULL); 
					return('{'); 
				}

("}"|"%>")		{ 
					count(); 
					yylval = createLeaf("}", yylineno, NULL); 
					return('}'); 
				}

","				{ 
					count(); 
					yylval = createLeaf(",", yylineno, NULL); 
					return(','); 
				}

":"				{ 
					count(); 
					yylval = createLeaf(":", yylineno, NULL); 
					return(':'); 
				}

"="				{ 
					count(); 
					yylval = createLeaf("=", yylineno, NULL); 
					return('='); 
				}

"("				{ 
					count(); 
					yylval = createLeaf("(", yylineno, NULL); 
					return('('); 
				}

")"				{ 
					count(); 
					yylval = createLeaf(")", yylineno, NULL); 
					return(')'); 
				}

("["|"<:")		{ 
					count(); 
					yylval = createLeaf("[", yylineno, NULL); 
					return('['); 
				}

("]"|":>")		{ 
					count(); 
					yylval = createLeaf("]", yylineno, NULL); 
					return(']'); 
				}

"."				{ 
					count(); 
					yylval = createLeaf(".", yylineno, NULL); 
					return('.'); 
				}

"&"				{ 
					count(); 
					yylval = createLeaf("&", yylineno, NULL); 
					return('&'); 
				}

"!"				{ 
					count(); 
					yylval = createLeaf("!", yylineno, NULL); 
					return('!'); 
				}

"~"				{ 
					count(); 
					yylval = createLeaf("~", yylineno, NULL); 
					return('~'); 
				}

"-"				{ 
					count(); 
					yylval = createLeaf("-", yylineno, NULL); 
					return('-'); 
				}

"+"				{ 
					count(); 
					yylval = createLeaf("+", yylineno, NULL); 
					return('+'); 
				}

"*"				{ 
					count(); 
					yylval = createLeaf("*", yylineno, NULL); 
					return('*'); 
				}

"/"				{ 
					count(); 
					yylval = createLeaf("/", yylineno, NULL); 
					return('/'); 
				}

"%"				{ 
					count(); 
					yylval = createLeaf("%", yylineno, NULL); 
					return('%'); 
				}

"<"				{ 
					count(); 
					yylval = createLeaf("<", yylineno, NULL); 
					return('<'); 
				}

">"				{ 
					count(); 
					yylval = createLeaf(">", yylineno, NULL); 
					return('>'); 
				}

"^"				{ 
					count(); 
					yylval = createLeaf("^", yylineno, NULL); 
					return('^'); 
				}

"|"				{ 
					count(); 
					yylval = createLeaf("|", yylineno, NULL); 
					return('|'); 
				}

"?"				{ 
					count(); 
					yylval = createLeaf("?", yylineno, NULL); 
					return('?'); 
				}


[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%
int yywrap() {
	return 1;
}

void comment() {
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}

void count() {
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}
