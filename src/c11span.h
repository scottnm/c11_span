#pragma once

#include <stdint.h>

// A DEFAULT SET OF SPANTYPE DEFINITIONS
// TOP PROVIDE A CUSTOM SET OF SPAN TYPES UNDEF THE DEFAULT SET AND DEFINE YOUR OWN

#define SPAN_TYPES(macro) \
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

// PROVIDED SPAN OPERATIONS
// first
// subspan
// data
// size

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
