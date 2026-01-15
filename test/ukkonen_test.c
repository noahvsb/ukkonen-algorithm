#define TEST_NO_MAIN

#include "test.h"
#include "../src/ukkonen/ukkonen.h"

void px_test(void) {
    // part of a suffix tree
    char* s = "ababcc";
    int n = 6;
    Node* root = create_node(0, 0);
    Node* child = create_node(0, 2); // "ab"
    Node* grandchild0 = create_node(2, n); // "ababcc"
    Node* grandchild1 = create_node(4, n); // "abcc"
    add_child(root, child); add_child(child, grandchild0); add_child(child, grandchild1);

    PX* px = create_px(root, 3);

    move_px(px, 2, s);

    // p should be child
    TEST_CHECK(px->p->start == 0 && px->p->end == 2);

    // x should be 1
    TEST_CHECK(px->x == 1);

    // child to look in should be grandchild1 (at index 1)
    TEST_CHECK(px->i == 1);

    free(px);
    free_node(root);
}

void add_new_node_test(void) {
    char* s = "ababcc";
    int n = 6;
    Node* root = create_node(0, 0);

    // add leaf immediately
    PX* px = create_px(root, 0);
    Node* grandchild0 = add_new_node(px, 0, s, n);

    TEST_CHECK(root->size == 1 && root->leftover == 0);
    TEST_CHECK(grandchild0->start == 0 && grandchild0->end == n);

    // add inbetween
    px->x = 2; px->i = 0;
    Node* child = add_new_node(px, 4, s, n);
    Node* grandchild1 = child->children[1];

    TEST_CHECK(child->start == 0 && child->end == 2);
    TEST_CHECK(grandchild0->start == 2 && grandchild0->end == n);
    TEST_CHECK(grandchild1->start == 4 && grandchild1->end == n);

    free(px);
    free_node(root);
}

void ukkonen_test(void) {
    Node* root = ukkonen("ababcc");

    // TODO

    free_node(root);
}