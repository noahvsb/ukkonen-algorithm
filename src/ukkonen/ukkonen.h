#ifndef UKKONEN_H
#define UKKONEN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../node/node.h"

typedef struct PX {
    Node* p;
    int x;
    int i; // tells you in which child to look for the next
} PX;

Node* ukkonen(char* s);

PX move_px(PX px, int j, int i, char* s);

#endif