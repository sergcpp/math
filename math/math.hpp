#pragma once

#include "allocator.hpp"

#include "common.hpp"
#include "exponential.hpp"
#include "geometric.hpp"
#include "transform.hpp"
#include "trigonometric.hpp"

#include "mat2.hpp"
#include "mat3.hpp"
#include "mat4.hpp"

#include "ivec2.hpp"
#include "ivec3.hpp"
#include "ivec4.hpp"

namespace math {
    struct CPUFeatures {
        bool initialized = false;
        //  Misc.
        bool HW_MMX;
        bool HW_x64;
        bool HW_ABM;      // Advanced Bit Manipulation
        bool HW_RDRAND;
        bool HW_BMI1;
        bool HW_BMI2;
        bool HW_ADX;
        bool HW_PREFETCHWT1;

        //  SIMD: 128-bit
        bool HW_SSE;
        bool HW_SSE2;
        bool HW_SSE3;
        bool HW_SSSE3;
        bool HW_SSE41;
        bool HW_SSE42;
        bool HW_SSE4a;
        bool HW_AES;
        bool HW_SHA;

        //  SIMD: 256-bit
        bool HW_AVX;
        bool HW_XOP;
        bool HW_FMA3;
        bool HW_FMA4;
        bool HW_AVX2;

        //  SIMD: 512-bit
        bool HW_AVX512F;    //  AVX512 Foundation
        bool HW_AVX512CD;   //  AVX512 Conflict Detection
        bool HW_AVX512PF;   //  AVX512 Prefetch
        bool HW_AVX512ER;   //  AVX512 Exponential + Reciprocal
        bool HW_AVX512VL;   //  AVX512 Vector Length Extensions
        bool HW_AVX512BW;   //  AVX512 Byte + Word
        bool HW_AVX512DQ;   //  AVX512 Doubleword + Quadword
        bool HW_AVX512IFMA; //  AVX512 Integer 52-bit Fused Multiply-Add
        bool HW_AVX512VBMI; //  AVX512 Vector Byte Manipulation Instructions
    };

    extern CPUFeatures cpu;

    enum e_arch { Scalar, SSE2, SSE3, SSE4_1, AVX, NEON };
    void init(e_arch arch = AVX);
    bool supported(e_arch arch);
}

