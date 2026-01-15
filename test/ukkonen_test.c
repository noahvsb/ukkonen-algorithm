#define TEST_NO_MAIN

#include "test.h"
#include "../src/ukkonen/ukkonen.h"

void move_px_test(void) {
    // part of a suffix tree
    char* s = "ababcc";
    Node* root = create_node(0, 0);
    Node* child = create_node(0, 2); // "ab"
    Node* grandchild0 = create_node(2, 6); // "ababcc"
    Node* grandchild1 = create_node(4, 6); // "abcc"
    add_child(root, child); add_child(child, grandchild0); add_child(child, grandchild1);

    PX px = { root, 3, -1 };

    px = move_px(px, 2, s);

    // p should be child
    TEST_CHECK(px.p->start == 0 && px.p->end == 2);

    // x should be 1
    TEST_CHECK(px.x == 1);

    // child to look in should be grandchild1 (at index 1)
    TEST_CHECK(px.i == 1);

    free_node(root);
}

void ukkonen_test(void) {
    Node* root = ukkonen("test");
    free_node(root);
    int a = 2;
    TEST_CHECK(a == 2);
}