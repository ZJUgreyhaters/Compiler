#include "table.h"

BlockStack initializeBlockStack() {
    BlockStack blockStack = malloc(sizeof(struct BlockStackRecord));
    blockStack->top = -1;
    for(int i = 0; i < STACK_SIZE; i++) {
        blockStack->array[i] = NULL;
    }
    return blockStack;
}

void initialize() {
    table = malloc(sizeof(struct SymbolTableRecord));
    table->funcNum = 0;
    for(int i = 0; i < POOL_SIZE; i++) {
        table->funcPool[i] = NULL;
    }
    table->blockStack = initializeBlockStack();
}

void beginScope() {
    table->blockStack->array[++table->blockStack->top] = initializeBlock();
}

void endScope() {
    destroyBlock(table->blockStack->array[table->blockStack->top]);
    table->blockStack->array[table->blockStack->top--] = NULL;
}

void insertVar(string key, string binding) {
    blockInsert(key, binding, table->blockStack->array[table->blockStack->top]);
}

void deleteVar(string key) {

}

string lookupVar(string key) {
    return blockLookup(key, table->blockStack->array[table->blockStack->top]);
}

void insertFunc(FuncNode func) {
    table->funcPool[table->funcNum++] = func;
}

FuncNode lookupFunc(string name) {
    for(int i = 0; i < table->funcNum; i++) {
        if(strcmp(table->funcPool[i]->name, name) == 0) {
            return table->funcPool[i];
        }
    }
    return NULL;
}

// int main() {
//     initialize();
//     FuncNode func = malloc(sizeof(struct FuncNodeRecord));
//     func->name = "main";
//     func->type = "void";
//     func->paralist[0] = "int";
//     insertFunc(func);
//     FuncNode func1 = malloc(sizeof(struct FuncNodeRecord));
//     func1->name = "test";
//     func1->type = "void";
//     func1->paralist[0] = "int";
//     insertFunc(func1);
//     FuncNode test = lookupFunc("test");
// 	return 0;
// }
