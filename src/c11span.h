#pragma once

#include <stdint.h>

// A DEFAULT SET OF SPANTYPE DEFINITIONS
// TOP PROVIDE A CUSTOM SET OF SPAN TYPES UNCOMMENT THE NEXT LINE AND DEFINE YOUR OWN

#ifndef C11_SPAN_CUSTOM_SPAN_TYPES

#define C11_SPAN_TYPES(macro) \
    macro(uint8_t, u8) \
    macro(const uint8_t, cu8) \
    macro(uint16_t, u16) \
    macro(const uint16_t, cu16) \
    macro(uint32_t, u32) \
    macro(const uint32_t, cu32) \
    macro(uint64_t, u64) \
    macro(const uint64_t, cu64) \
    macro(int8_t, i8) \
    macro(const int8_t, ci8) \
    macro(int16_t, i16) \
    macro(const int16_t, ci16) \
    macro(int32_t, i32) \
    macro(const int32_t, ci32) \
    macro(int64_t, i64) \
    macro(const int64_t, ci64) \

#endif // !C11_SPAN_CUSTOM_SPAN_TYPES

#define DECLARE_STRUCTS(value_type, short_name) \
    typedef struct { \
        value_type * data; \
        size_t count; \
    } short_name ## _span; \

C11_SPAN_TYPES(DECLARE_STRUCTS)

// PROVIDED SPAN OPERATIONS
// make
// first
// subspan
// data
// size

// FIXME: tmp till generics
inline ci8_span make_span(const int8_t* data, size_t count)
{
    return (ci8_span) { .data = data, .count = count };
}

inline ci8_span span_first(ci8_span span, size_t first_n)
{
    return (ci8_span) { .data = span.data, .count = first_n };
}

inline ci8_span span_skip(ci8_span span, size_t skip_n)
{
    return (ci8_span) { .data = span.data + skip_n, .count = span.count - skip_n };
}

/*
void span_first_common(
    void* data,
    size_t data_size,
    size_t first,
    void* out_data,
    void* out_data_size)
{
}
*/

/*
void span_first_common(
    void* data,
    size_t data_size,
    size_t first,
    void* out_data,
    void* out_data_size)
{
}
*/
