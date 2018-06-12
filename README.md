# Compiler
# implemention of a mini C Compiler in lex&yacc
# syntax is a sub-set of ANSI-C
#apt install bison & flex
bison -vdty c.y 

gcc -w  lex.yy.c y.tab.c tree.c codeGen.c -o compiler

bash ./compiler

dot tree.dot -T png -o tree.png


any question? Contact me -> 3150103635@zju.edu.cn
