#pragma once

// Game settings
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define TILE_SZIE 64
#define ANIMATION_SPEED 6
#define TOTAL_LEVELS 6

// fixed width numeric types
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef float f32;
typedef double f64;

typedef uint32_t b32;
typedef uint8_t b8;

// Properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif
