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
    } short_name ## _span;
C11_SPAN_TYPES(DECLARE_STRUCTS)

// PROVIDED SPAN OPERATIONS

//
// span_make
//
#define DEFINE_MAKE_SPAN(value_type, short_name) \
    inline \
    short_name ## _span \
    make_span_ ## short_name( \
        value_type * data, \
        size_t count) \
    { \
        return (short_name ## _span) { .data = data, .count = count }; \
    }
C11_SPAN_TYPES(DEFINE_MAKE_SPAN)

#define SET_GENERIC_MAKE_SPAN_DEFINITION(value_type, short_name) \
    value_type* : make_span_ ## short_name, \

inline void make_span_default(void* data, size_t count) { (void)data;(void)count; }
#define make_span(data, count) _Generic((data), \
    C11_SPAN_TYPES(SET_GENERIC_MAKE_SPAN_DEFINITION) \
    default: make_span_default \
)(data, count)

//
// span_first
//
#define DEFINE_SPAN_FIRST(value_type, short_name) \
    inline \
    short_name ## _span \
    span_first_ ## short_name( \
        short_name ## _span span, \
        size_t first_n) \
    { \
        return (short_name ## _span) { .data = span.data, .count = first_n }; \
    }
C11_SPAN_TYPES(DEFINE_SPAN_FIRST)

#define SET_GENERIC_SPAN_FIRST_DEFINITION(value_type, short_name) \
    short_name ## _span : span_first_ ## short_name, \

inline void span_first_default(void* span, size_t first_n) { (void)span;(void)first_n; }
#define span_first(data, count) _Generic((data), \
    C11_SPAN_TYPES(SET_GENERIC_SPAN_FIRST_DEFINITION) \
    default: span_first_default \
)(data, count)

//
// span_skip
//
#define DEFINE_SPAN_SKIP(value_type, short_name) \
    inline \
    short_name ## _span \
    span_skip_ ## short_name( \
        short_name ## _span span, \
        size_t skip_n) \
    { \
        return (short_name ## _span) { .data = span.data + skip_n, .count = span.count - skip_n }; \
    }
C11_SPAN_TYPES(DEFINE_SPAN_SKIP)

#define SET_GENERIC_SPAN_SKIP_DEFINITION(value_type, short_name) \
    short_name ## _span : span_skip_ ## short_name, \

inline void span_skip_default(void* span, size_t skip_n) { (void)span;(void)skip_n; }
#define span_skip(data, count) _Generic((data), \
    C11_SPAN_TYPES(SET_GENERIC_SPAN_SKIP_DEFINITION) \
    default: span_skip_default \
)(data, count)
