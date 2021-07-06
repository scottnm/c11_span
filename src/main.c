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

    /*
    for (size_t i = 0; i < nspan.count; ++i)
    {
        ci8_span first_n = span_first(nspan, i);
        ci8_span skip_n = span_skip(nspan, i);
        for (size_t j = 0; j < skip_n.count; ++j)
        {
            printf("     ");
        }
        for (size_t j = 0; j < first_n.count; ++j)
        {
            printf("%4i ", first_n.data[j]);
        }

        printf("| ");
        for (size_t j = 0; j < skip_n.count; ++j)
        {
            printf("%4i ", skip_n.data[j]);
        }
        printf("\n");
    }
    */

    // FIXME: improvment
    // foreach_span(int8_t, e, nspan)
    // {
    //    printf("%i\n", *e);
    // }

    return 0;
}
