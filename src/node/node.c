#include "node.h"

Node* create_node(int start, int end) {
    Node* node = malloc(sizeof(Node));
    if (!node) ALLOCATION_ERROR();

    node->link = NULL;
    node->start = start;
    node->end = end;

    node->size = 0;
    node->size_left = 1;
    node->children = calloc(node->size_left, sizeof(Node*));
    if (!node->children) ALLOCATION_ERROR();
    node->children[0] = NULL;

    return node;
}

void add_child(Node* node, Node* child) {
    expand_children(node);

    node->children[node->size] = child;
    node->size++;
    node->size_left--;
}

void expand_children(Node* node) {
    if (node->size_left == 0) {
        node->children = realloc(node->children, 2 * node->size * sizeof(Node*)); // double the size
        if (!node->children) ALLOCATION_ERROR();
        node->size_left = node->size;
    }
}

void free_node(Node* node) {
    if (node) {
        if (node->children) {
            for (int i = 0; i < node->size; i++) free_node(node->children[i]); // recursive removal of child nodes
            free(node->children);
        }
        free(node);
    }
}