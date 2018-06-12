#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 109

typedef char *string;

typedef struct BucketRecord *Bucket;
struct BucketRecord {
    string key;
    string binding;
    Bucket next;
};

Bucket initializeBucket(string key, string binding);

typedef struct BlockRecord *Block;
struct BlockRecord {
    Bucket array[BLOCK_SIZE];
};

Block initializeBlock();
void destroyBlock(Block block);
unsigned int hash(char *s0, Block block);
void blockInsert(string key, string binding, Block block);
string blockLookup(string key, Block block);
void blockDelete(string key, Block block);
