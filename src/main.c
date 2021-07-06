#include <stdint.h>
#include <stdio.h>

#include "c11span.h"

#define UNREF(x) do { (void)(x); } while(0)

int main(int argc, char** argv)
{
    UNREF(argc);
    UNREF(argv);

    printf("Hello, World!\n");
    return 0;
}
