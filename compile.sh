#!/bin/bash
echo "1"
bison -vdty c.y
echo "2"
gcc -w  lex.yy.c y.tab.c tree.c -o compiler
echo "3"
bash ./compiler
echo "4"
dot tree.dot -T png -o tree.png