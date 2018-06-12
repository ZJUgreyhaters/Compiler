#include "block.h"

Bucket initializeBucket(string key, string binding) {
    Bucket bucket = malloc(sizeof(struct BucketRecord));
    bucket->key = key;
    bucket->binding = binding;
    bucket->next = NULL;
    return bucket;
}

Block initializeBlock() {
    Block block = malloc(sizeof(struct BlockRecord));
    for(int i = 0; i < BLOCK_SIZE; i++) {
        block->array[i] = NULL;
    }
    return block;
}

void destroyBlock(Block block) {
    
}

unsigned int hash(char *s0) {
    unsigned int h = 0;
    for(char *s = s0; *s; s++) {
        h = h * 65599 + *s;
    }
    return h;
}

void blockInsert(string key, string binding, Block block) {
    int index = hash(key) % BLOCK_SIZE;
    Bucket tmp = initializeBucket(key, binding);
    tmp->next = block->array[index];
    block->array[index] = tmp;
}

string blockLookup(string key, Block block) {
    int index = hash(key) % BLOCK_SIZE;
    for(Bucket i = block->array[index]; i; i = i->next) {
        if(strcmp(i->key, key) == 0) {
            return i->binding;
        }
    }
    return NULL;
}

void blockDelete(string key, Block block) {

}

