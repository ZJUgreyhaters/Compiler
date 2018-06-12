#include "tree.h"

// 在.y文件中调用，进行规约时，传入个数不定的子树，合成新的树
Tree createTree(string kind, int num, ...) {
    Tree t = malloc(sizeof(struct TreeRecord));
    t->kind = kind;
    t->content = NULL;
    t->firstChild = NULL;
    t->nextSibling = NULL;

    va_list ap;
    va_start(ap, num);

    if(num > 0) {
        Tree tmp = va_arg(ap, Tree);
        t->line = tmp->line;
        t->firstChild = tmp;

        for(int i = 1; i < num; i++) {
            tmp->nextSibling = va_arg(ap, Tree);
            tmp = tmp->nextSibling;
        }
    }
    else {
        printf("There should be at least one subtree!\n");
    }

    return t;
}

// 在.l文件中调用，为每一个终结符创建一个叶子节点
Tree createLeaf(string kind, int line, string content) {
    Tree t = malloc(sizeof(struct TreeRecord));
    t->kind = kind;
    t->line = line;
    t->firstChild = NULL;
    t->nextSibling = NULL;

	if(content != NULL) {
		t->content = malloc(sizeof(strlen(content)));
        strcpy(t->content, content);
	}
	else {
		t->content = NULL;
	}
    
    return t;
}

// 对语法树进行可视化，生成fileName.dot文件
// 命令dot fileName.dot -T png -o imageName.png可生成图片
int nodeId;
void visualize(Tree t, string fileName) {
    FILE *f = fopen(fileName, "w");
    nodeId = 0;
    fprintf(f, "digraph tree {\n");
    write2dot(t, f);
    fprintf(f, "}\n");
    fclose(f);
}

void write2dot(Tree t, FILE* f) {
    if(t == NULL) {
        return;
    }
    else {
        int rootId = nodeId;
        if(strcmp(t->kind, "IDENTIFIER") == 0 
           || strcmp(t->kind, "CONSTANT_INT") == 0 
           || strcmp(t->kind, "CONSTANT_DOUBLE") == 0) {
            fprintf(f, "%d [label=\"%s: %s\"];\n", nodeId++, t->kind, t->content);
        }
        else {
            fprintf(f, "%d [label=\"%s\"];\n", nodeId++, t->kind);
        }
        Tree tmp = t->firstChild;
        while(tmp != NULL) {
            fprintf(f, "%d -> %d;\n", rootId, nodeId);
            write2dot(tmp, f);
            tmp = tmp->nextSibling;
        }
    }
}
