#define TEST_NO_MAIN

#include "test.h"
#include "../src/ukkonen/ukkonen.h"

void ukkonen_test(void) {
    ukkonen("test");
    int a = 2;
    TEST_CHECK(a == 2);
}