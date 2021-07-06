# C11 Span

C11 (and by extension C17) are pretty neat.

One of the features from C++ that I miss somewhat though is support for spans (e.g. `gsl::span<foo>`).

This is a prototype implementation of providing an interface/utility much like that for C using C11's [`_Generic` support](https://en.cppreference.com/w/c/language/generic).

## Features

gsl::span | c11 span equivalent
----------|--------------------
`gsl::span<int> int_span = some_int_array` | `i32_span int_span = span_make(some_int_array, ARRAYSIZE(some_int_array)); `
`auto first_bit = int_span.first(3); ` | `i32_span first_bit = span_first(int_span, 3); `
`auto rest_of_span = int_span.subspan(3); ` | `i32_span rest_of_span = span_skip(int_span, 3); `
