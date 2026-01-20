#ifndef UKKONEN_H
#define UKKONEN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../node/node.h"
#include "../macros.h"

typedef struct PX {
    Node* p;
    int x;
    int i; // tells you in which child to look for the next
} PX;

// expected that the string already contains the ending char, this way you can customize it ;)
// totally not because it's annoying to add in code
Node* ukkonen(char* s);

PX* create_px(Node* p, int x);

void move_px(PX* px, int j, char* s);

Node* add_new_node(PX* px, int j, char* s, int n);

#endif