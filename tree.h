#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

typedef struct TreeRecord *Tree;
struct TreeRecord {
    string kind;    // 该节点的种类，如IDENTIFIER，statement等
    int line;
    string content; // 若节点为IDENTIFIER, CONSTANT_INT, CONSTANT_DOUBLE，存储其内容，否则为空
    Tree firstChild;
    Tree nextSibling;
};

Tree createTree(string kind, int num, ...);
Tree createLeaf(string kind, int line, string content);
void visualize(Tree t, string fileName);
void write2dot(Tree t, FILE *f);
