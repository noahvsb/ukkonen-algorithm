#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

#define ALLOCATION_ERROR() \
    do { \
        fprintf(stderr, "Allocation error at %s:%d: ", __FILE__, __LINE__); \
        perror(NULL); \
        exit(EXIT_FAILURE); \
    } while (0)

typedef struct Node Node;

struct Node {
    Node** children;
    int size; // current amount of children
    int leftover; // amount of children you can still add before needing to realloc

    Node* link;
    int start;
    // not included
    // for leafs this will be |s|, but you need to know that it's actually min(it, |s|)
    int end;
};

Node* create_node(int start, int end);
// free's node and all children recursively
void free_node(Node* node);

// will expand if necessary
void add_child(Node* node, Node* child);
// does nothing if there's still space, else doubles memory for the children
void expand_children(Node* node);

#endif