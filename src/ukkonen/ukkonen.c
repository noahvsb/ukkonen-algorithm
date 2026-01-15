#include "ukkonen.h"

Node* ukkonen(char* s) {
    int n = strlen(s);

    Node* root = create_node(0, 0);
    root->link = root;

    PX* px = create_px(root, 0);

    int j = 0;
    Node* needs_suffix_link = NULL;
    for (int i = 1; i <= n; i++) {
        for (; j < i; j++) {
            // move px until it points to the deepest node possible
            int diff = px->x;
            move_px(px, j, s);
            diff -= px->x; // s[j + diff] is where we need to start looking at to check if it exists

            // check if it exists
            bool exists = px->x != 0;
            if (exists) {
                int start = px->p->children[px->i]->start;
                for (int k = 1; k < px->x; k++) {
                    if (s[j + diff + k] != s[start + k]) {
                        exists = false;
                        break;
                    }
                }
            }

            // add if doesn't exist
            if (!exists) {
                Node* new_node = add_new_node(px, j + diff, s, n);

                // add suffix link if necessary
                if (needs_suffix_link != NULL) {
                    needs_suffix_link->link = new_node;
                }

                // new node needs a suffix link if not a leaf
                if (new_node->end != n) needs_suffix_link = new_node;
            } else {
                // add suffix link if necessary
                if (needs_suffix_link != NULL) {
                    needs_suffix_link->link = px->p;
                }

                needs_suffix_link = NULL;
            }

            // update px
            if (!exists) {
                // p is root
                if (px->p->end == 0)
                    px->x--;
                // p is not root
                else
                    px->p = px->p->link;
            } else {
                // iteration fully finished
                if (j == i - 1) {
                    px->p = root;
                    px->x = 0;
                }
                // not fully finished
                else
                    px->x++;

                // break if it exists
                break;
            }
        }
    }

    free(px);

    return root;
}

PX* create_px(Node* p, int x) {
    PX* px = malloc(sizeof(PX));
    if (!px) ALLOCATION_ERROR();
    px->p = p; px->x = x; px->i = -1;
    return px;
}

void move_px(PX* px, int j, char* s) {
    bool done = false;
    while (!done) {
        for (int k = 0; k < px->p->size; k++) {
            Node* n = px->p->children[k];
            char c = s[n->start];
            int len = n->end - n->start;

            if (c == s[j]) {
                if (px->x >= len) {
                    // move to next node
                    px->x -= len;
                    px->p = n; // results in an endless loop when n has no children (but this shouldn't occur)
                    j += len;
                } else {
                    // current node is the last
                    px->i = k;
                    done = true;
                }
                // done checking the children, since there can only be 1 match maximum
                break;
            }

            // found nothing
            if (k == px->p->size - 1) {
                // current node is the last
                done = true;
            }
        }
    }
}

Node* add_new_node(PX* px, int j, char* s, int n) {
    Node* new_node;

    // add immediately as leaf
    if (px->x == 0) {
        new_node = create_node(j, n);

        add_child(px->p, new_node);
    }
    // add in the middle of an edge and attach leaf
    else {
        new_node = create_node(px->p->end, px->p->end + px->x);

        Node* child = px->p->children[px->i];
        
        // put new node inbetween
        px->p->children[px->i] = new_node;
        add_child(new_node, child);

        // update child start
        child->start += px->x;

        // add leaf
        add_child(new_node, create_node(j, n));
    }

    return new_node;
}
