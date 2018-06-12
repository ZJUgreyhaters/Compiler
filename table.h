#include <string.h>
#include <stdlib.h>
#include "block.h"

#define PARA_LIST_SIZE 10
#define STACK_SIZE 10
#define POOL_SIZE 10

typedef struct FuncNodeRecord *FuncNode;
struct FuncNodeRecord {
    string name;    // 函数名称
    string type;    // 函数返回值类型
    string paralist[PARA_LIST_SIZE];    // 形参类型列表
};

typedef struct BlockStackRecord *BlockStack;
struct BlockStackRecord {
    int top;
    Block array[STACK_SIZE];
};

BlockStack initializeBlockStack();

// 符号表由函数池和一个栈组成，函数池中存放函数定义，栈顶的block存放当前环境的符号
typedef struct SymbolTableRecord *SymbolTable;
struct SymbolTableRecord {
    int funcNum;
    FuncNode funcPool[POOL_SIZE];
    BlockStack blockStack;
};

SymbolTable table;  // 符号表全局变量

void initialize();

void beginScope();
void endScope();

void insertVar(string key, string binding);
void deleteVar(string key);
string lookupVar(string key);

void insertFunc(FuncNode func);
FuncNode lookupFunc(string name);
