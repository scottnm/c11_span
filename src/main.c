#include <stdint.h>
#include <stdio.h>

#include "c11span.h"

#define UNREF(x) do { (void)(x); } while(0)
#define ARRAYSIZE(x) (sizeof((x)) / sizeof((x)[0]))

int main(int argc, char** argv)
{
    UNREF(argc);
    UNREF(argv);

    const int8_t numbers[] = { -120, 10, 2 };
    ci8_span nspan = make_span(numbers, ARRAYSIZE(numbers));

    for (size_t i = 0; i < nspan.size; ++i)
    {
        ci8_span first_n = span_first(nspan, i);
        for (size_t j = 0; j < first_n.size; ++j)
        {
            printf("%i ", first_n.data[i]);
        }

        printf("| ");
        ci8_span rest_n = span_rest(nspan, i);
        for (size_t j = 0; j < rest_n.size; ++j)
        {
            printf("%i ", rest_n.data[i]);
        }
        printf("\n");
    }

    // FIXME: improvment
    // foreach_span(int8_t, e, nspan)
    // {
    //    printf("%i\n", *e);
    // }

    printf("Hello, World!\n");
    return 0;
}
