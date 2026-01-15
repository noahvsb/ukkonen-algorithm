#include "ukkonen.h"

Node* ukkonen(char* s) {
    int n = strlen(s);

    Node* root = create_node(0, 0);
    root->link = root;
    add_child(root, create_node(0, n)); // adding first letter

    PX px = { root, 0, -1 };

    int j = 1;
    Node* needs_suffix_link = NULL;
    for (int i = 2; i <= strlen(s); i++) {
        while (true) {
            // move px until it points to the deepest node possible
            px = move_px(px, j, i, s);

            // check if exists
            // TODO

            // add if doesn't exist
            // TODO

            // add suffix link if necessary
            if (needs_suffix_link != NULL) {
                // TODO
            }

            // update px
            // TODO

            // break if it exists
            break; // TODO
            j++;
        }
    }

    free_node(root);

    return NULL;
}

PX move_px(PX px, int j, int i, char* s) {
    while (true) {
        for (int k = 0; k < px.p->size; k++) {
            //int start = px.p->children[k]->start;
            // TODO
        }
        break;
    }
    return px;
}

