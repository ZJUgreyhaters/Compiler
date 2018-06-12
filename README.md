# Compiler
#  implemention of a mini C Compiler in lex&yacc

#apt install bison & flex
bison -vdty c.y 

gcc -w  lex.yy.c y.tab.c tree.c codeGen.c -o compiler

bash ./compiler

dot tree.dot -T png -o tree.png
