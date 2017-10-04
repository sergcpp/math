#pragma once

#ifndef __arm__
#include <emmintrin.h>
#include <immintrin.h>

#if !defined(__AVX__) && !defined(_MSC_VER) && !defined(__linux__)
typedef float __m256[8];
#endif

#if defined(__EMSCRIPTEN__)
typedef float __m256[8];
#endif

#else
#ifdef __ARM_NEON__
#include <arm_neon.h>

typedef float32x4_t __m256[2];
typedef float32x4_t __m128;
typedef float32x2_t __m64;

typedef int32x4_t __m128i;
#else

typedef float __m256[8];
typedef float __m128[4];
#endif
#endif

// Check windows
#if defined(_MSC_VER)
    #if defined(_WIN64) && _WIN64
        #define ENVIRONMENT64
    #else
        #define ENVIRONMENT32
    #endif

    #define OMIT_FRAME_BEG __pragma(optimize("y", on))
    #define OMIT_FRAME_END __pragma(optimize("y", off))
#endif

// Check GCC
#ifdef __GNUC__
    #if __x86_64__ || __ppc64__
        #define ENVIRONMENT64
    #else
        #define ENVIRONMENT32
    #endif

    #define OMIT_FRAME_BEG __attribute__((optimize("-fomit-frame-pointer")))
    #define OMIT_FRAME_END
#endif

#if defined(ENVIRONMENT32) && !defined(__arm__)
    #ifdef __GNUC__
        #define FASTCALL __attribute__((fastcall))
    #else
        #define FASTCALL __fastcall
    #endif
#else
    // should be fastcall as it is
    #define FASTCALL
#endif

#if defined(MATH_NO_INLINE)
#define DECL_FUNC(x) x FASTCALL
#else
#define DECL_FUNC(x) inline x FASTCALL
#endif

#if !defined(__clang__)
    #define DEF_FUNC(x) OMIT_FRAME_BEG DECL_FUNC(x)
#else
    #define DEF_FUNC(x) DECL_FUNC(x)
#endif

#define DEF_END OMIT_FRAME_END

#if defined(CPU_ARCH_SCALAR)
    #define ALIGN_M32 1
    #define ALIGN_M64 1
    #define ALIGN_M128 1
    #define ALIGN_M256 1
#elif defined(CPU_ARCH_SSE2) || defined(CPU_ARCH_SSE3) || defined(CPU_ARCH_SSE4_1) || defined(CPU_ARCH_NEON)
    #define ALIGN_M32 4
    #define ALIGN_M64 8
    #define ALIGN_M128 16
    #define ALIGN_M256 16
#elif defined(CPU_ARCH_AVX)
    #define ALIGN_M32 4
    #define ALIGN_M64 8
    #define ALIGN_M128 16
    #define ALIGN_M256 32
#else
    #define ALIGN_M32 4
    #define ALIGN_M64 8
    #define ALIGN_M128 16
    #define ALIGN_M256 32
#endif

#ifdef __GNUC__
    #define ALIGN_M32_BEG
    #define ALIGN_M32_END __attribute__((aligned(ALIGN_M32)))
    #define ALIGN_M64_BEG
    #define ALIGN_M64_END __attribute__((aligned(ALIGN_M64)))
    #define ALIGN_M128_BEG
    #define ALIGN_M128_END __attribute__((aligned(ALIGN_M128)))
    #define ALIGN_M256_BEG
    #define ALIGN_M256_END __attribute__((aligned(ALIGN_M256)))
#else
    #define ALIGN_M32_BEG __declspec(align(ALIGN_M32))
    #define ALIGN_M32_END
    #define ALIGN_M64_BEG __declspec(align(ALIGN_M64))
    #define ALIGN_M64_END
    #define ALIGN_M128_BEG __declspec(align(ALIGN_M128))
    #define ALIGN_M128_END
    #define ALIGN_M256_BEG __declspec(align(ALIGN_M256))
    #define ALIGN_M256_END
#endif

#pragma warning(push)
#pragma warning(disable : 4359) // lesser alignment ignored

namespace math {
    const size_t alignment_m32 = ALIGN_M32;
    const size_t alignment_m64 = ALIGN_M64;
    const size_t alignment_m128 = ALIGN_M128;
    const size_t alignment_m256 = ALIGN_M256;

    union float2 {
        float comp[2];
    };

    static_assert(sizeof(float2) == 8, "!");

    ALIGN_M32_BEG union float3 {
        float comp[3];
    } ALIGN_M32_END;

    static_assert(sizeof(float3) == 12, "!");

    ALIGN_M128_BEG union float4 {
        __m128 vec;
        float2 vec2[2];
        float comp[4];
        float comp2[2][2];
    } ALIGN_M128_END;

    static_assert(sizeof(float4) == 16, "!");

    ALIGN_M32_BEG union float9 {
        float3 vec3[3];
        float comp[9];
        float comp3[3][3];
    } ALIGN_M32_END;

    static_assert(sizeof(float9) == 36, "!");

    ALIGN_M128_BEG union float12 {
        __m128 vec[3];
        float4 vec4[3];
        float comp[12];
        float comp4[3][4];
    } ALIGN_M128_END;

    static_assert(sizeof(float12) == 48, "!");

    ALIGN_M256_BEG union float16 {
        __m128 vec[4];
        __m256 vec2[2];
        float4 vec4[4];
        float comp[16];
        float comp4[4][4];
    } ALIGN_M256_END;

    static_assert(sizeof(float16) == 64, "!");

    ALIGN_M128_BEG union double2 {
        __m128d vec;
        double comp[2];
    } ALIGN_M128_END;

    static_assert(sizeof(double2) == 16, "!");

    ALIGN_M32_BEG union double3 {
        double comp[3];
    } ALIGN_M32_END;

    static_assert(sizeof(double3) == 24, "!");

    ALIGN_M256_BEG union double4 {
		__m256d vec;
        double2 vec2[2];
		double comp[4];
		double comp2[2][2];
    } ALIGN_M256_END;

    static_assert(sizeof(double4) == 32, "!");

    ALIGN_M64_BEG union int2 {
        __m64 vec;
        int comp[2];
    } ALIGN_M64_END;

    static_assert(sizeof(int2) == 8, "!");

    ALIGN_M32_BEG union int3 {
        int comp[3];
    } ALIGN_M32_END;

    static_assert(sizeof(int3) == 12, "!");

    ALIGN_M128_BEG union int4 {
        __m128i vec;
        int comp[4];
    } ALIGN_M128_END;

    static_assert(sizeof(int4) == 16, "!");
}

#undef ALIGN_M32
#undef ALIGN_M64
#undef ALIGN_M128
#undef ALIGN_M256

#pragma warning(pop)
