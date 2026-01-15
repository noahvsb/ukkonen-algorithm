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
            px = move_px(px, j, s);

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

    return root;
}

PX move_px(PX px, int j, char* s) {
    bool done = false;
    while (!done) {
        for (int k = 0; k < px.p->size; k++) {
            Node* n = px.p->children[k];
            char c = s[n->start];
            int len = n->end - n->start;

            if (c == s[j]) {
                if (px.x >= len) {
                    // move to next node
                    px.x -= len;
                    px.p = n; // results in an endless loop when n has no children (but this shouldn't occur)
                    j += len;
                } else {
                    // current node is the last
                    px.i = k;
                    done = true;
                }
                // done checking the children, since there can only be 1 match maximum
                break;
            }

            // found nothing
            if (k == px.p->size - 1) {
                // current node is the last
                done = true;
            }
        }
    }
    return px;
}

