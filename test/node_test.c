#define TEST_NO_MAIN

#include "test.h"
#include "../src/node/node.h"

void node_test(void) {
    Node* n = create_node(0, 1);
    add_child(n, create_node(1, 2));

    TEST_CHECK(n->size == 1);
    TEST_CHECK(n->size_left == 0);

    add_child(n, create_node(2, 3));

    TEST_CHECK(n->size == 2);
    TEST_CHECK(n->size_left == 0);

    TEST_CHECK(n->children[0]->end == 2);
    TEST_CHECK(n->children[1]->end == 3);

    free_node(n);
}

