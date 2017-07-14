#include "math.hpp"

#include <cassert>

#ifdef _WIN32

//  Windows
#include <intrin.h>
#ifdef __GNUC__
#include <cpuid.h>
void cpuid(int info[4], int InfoType) {
    __cpuid_count(InfoType, 0, info[0], info[1], info[2], info[3]);
}
#else
#define cpuid(info, x)    __cpuidex(info, x, 0)
#endif

#else

#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
//  GCC Intrinsics
#include <cpuid.h>
void cpuid(int info[4], int InfoType) {
    __cpuid_count(InfoType, 0, info[0], info[1], info[2], info[3]);
}
#endif

#endif

#if defined(__arm__)
    #ifdef __ARM_NEON__
        #include "math_neon.hpp"
    #endif
#elif defined(__EMSCRIPTEN__)
    #include "math_sse2.hpp"
    #include "math_sse3.hpp"
#else
    #include "math_sse2.hpp"
    #include "math_sse3.hpp"
    #include "math_sse4_1.hpp"
    #include "math_avx.hpp"
#endif

#define FUNC_LIST(NS)                                   \
    NS::vec3_init1, NS::vec3_init3,                     \
    NS::vec3_add_vec3, NS::vec3_sub_vec3,               \
    NS::vec3_mul_vec3, NS::vec3_div_vec3,               \
                                                        \
    NS::vec3_length,                                    \
    NS::vec3_dot,                                       \
    NS::vec3_cross,                                     \
    NS::vec3_normalize,                                 \
    NS::vec3_normalize_fast,                            \
                                                        \
    NS::vec4_init1, NS::vec4_init4,                     \
    NS::vec4_eq_vec4,                                   \
    NS::vec4_add_vec4, NS::vec4_sub_vec4,               \
    NS::vec4_mul_vec4, NS::vec4_div_vec4,               \
                                                        \
    NS::vec4_length,                                    \
    NS::vec4_dot,                                       \
    NS::vec4_normalize,                                 \
    NS::vec4_normalize_fast,                            \
                                                        \
    NS::mat2_init4,                                     \
    NS::mat2_add_mat2, NS::mat2_sub_mat2,               \
    NS::mat2_mul_mat2, NS::mat2_div_mat2,               \
                                                        \
    NS::mat2_comp_mul,                                  \
                                                        \
    NS::mat3_init1, NS::mat3_init3, NS::mat3_init9,     \
    NS::mat3_add_mat3, NS::mat3_sub_mat3,               \
    NS::mat3_mul_mat3, NS::mat3_div_mat3,               \
                                                        \
    NS::mat3_mul_float, NS::mat3_div_float,             \
                                                        \
    NS::mat3_comp_mul,                                  \
                                                        \
    NS::mat4_init1, NS::mat4_init4, NS::mat4_init16,    \
    NS::mat4_add_mat4, NS::mat4_sub_mat4,               \
    NS::mat4_mul_mat4, NS::mat4_div_mat4,               \
                                                        \
    NS::mat4_mul_float, NS::mat4_div_float,             \
                                                        \
    NS::mat4_comp_mul,                                  \
                                                        \
    NS::mat4_mul_vec4,                                  

namespace math {
    CPUFeatures cpu = {};

    static void init_cpu(CPUFeatures &cpu);

#if defined(CPU_ARCH_UNKNOWN)
    void (FASTCALL *vec3_init1)(float4 &vec, float val);
    void (FASTCALL *vec3_init3)(float4 &vec, float v0, float v1, float v2);
    float4 (FASTCALL *vec3_add_vec3)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec3_sub_vec3)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec3_mul_vec3)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec3_div_vec3)(const float4 &v1, const float4 &v2);

    float (FASTCALL *vec3_length)(const float4 &vec);
    float (FASTCALL *vec3_dot)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec3_cross)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec3_normalize)(const float4 &vec);
    float4 (FASTCALL *vec3_normalize_fast)(const float4 &vec);

    void (FASTCALL *vec4_init1)(float4 &vec, float val);
    void (FASTCALL *vec4_init4)(float4 &vec, float v0, float v1, float v2, float v3);
    bool (FASTCALL *vec4_eq_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_add_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_sub_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_mul_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_div_vec4)(const float4 &v1, const float4 &v2);

    float (FASTCALL *vec4_length)(const float4 &vec);
    float (FASTCALL *vec4_dot)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_normalize)(const float4 &vec);
    float4 (FASTCALL *vec4_normalize_fast)(const float4 &vec);

    void (FASTCALL *mat2_init4)(float4 &vec, float v0, float v1, float v2, float v3);

    float4 (FASTCALL *mat2_add_mat2)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *mat2_sub_mat2)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *mat2_mul_mat2)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *mat2_div_mat2)(const float4 &v1, const float4 &v2);

    float4 (FASTCALL *mat2_comp_mul)(const float4 &m1, const float4 &m2);

    void (FASTCALL *mat3_init1)(float12 &vec, float val);
    void (FASTCALL *mat3_init3)(float12 &vec, const float4 &v0, const float4 &v1, const float4 &v2);
    void (FASTCALL *mat3_init9)(float12 &vec, float v00, float v01, float v02,
                                              float v10, float v11, float v12,
                                              float v20, float v21, float v22);

    float12 (FASTCALL *mat3_add_mat3)(const float12 &v1, const float12 &v2);
    float12 (FASTCALL *mat3_sub_mat3)(const float12 &v1, const float12 &v2);
    float12 (FASTCALL *mat3_mul_mat3)(const float12 &v1, const float12 &v2);
    float12 (FASTCALL *mat3_div_mat3)(const float12 &v1, const float12 &v2);

    float12 (FASTCALL *mat3_mul_float)(const float12 &v1, float v2);
    float12 (FASTCALL *mat3_div_float)(const float12 &v1, float v2);

    float12 (FASTCALL *mat3_comp_mul)(const float12 &m1, const float12 &m2);

    void (FASTCALL *mat4_init1)(float16 &vec, float val);
    void (FASTCALL *mat4_init4)(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3);
    void (FASTCALL *mat4_init16)(float16 &vec, float v00, float v01, float v02, float v03,
                                               float v10, float v11, float v12, float v13,
                                               float v20, float v21, float v22, float v23,
                                               float v30, float v31, float v32, float v33);

    float16 (FASTCALL *mat4_add_mat4)(const float16 &v1, const float16 &v2);
    float16 (FASTCALL *mat4_sub_mat4)(const float16 &v1, const float16 &v2);
    float16 (FASTCALL *mat4_mul_mat4)(const float16 &v1, const float16 &v2);
    float16 (FASTCALL *mat4_div_mat4)(const float16 &v1, const float16 &v2);

    float16 (FASTCALL *mat4_mul_float)(const float16 &v1, float v2);
    float16 (FASTCALL *mat4_div_float)(const float16 &v1, float v2);

    float16 (FASTCALL *mat4_comp_mul)(const float16 &m1, const float16 &m2);

    float4 (FASTCALL *mat4_mul_vec4)(const float16 &v1, const float4 &v2);
#endif
    const struct func_table {
        void (FASTCALL *vec3_init1)(float4 &vec, float val);
        void (FASTCALL *vec3_init3)(float4 &vec, float v0, float v1, float v2);
        float4 (FASTCALL *vec3_add_vec3)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec3_sub_vec3)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec3_mul_vec3)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec3_div_vec3)(const float4 &v1, const float4 &v2);

        float (FASTCALL *vec3_length)(const float4 &vec);
        float (FASTCALL *vec3_dot)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec3_cross)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec3_normalize)(const float4 &vec);
        float4 (FASTCALL *vec3_normalize_fast)(const float4 &vec);

        void (FASTCALL *vec4_init1)(float4 &vec, float val);
        void (FASTCALL *vec4_init4)(float4 &vec, float v0, float v1, float v2, float v3);
        bool (FASTCALL *vec4_eq_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_add_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_sub_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_mul_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_div_vec4)(const float4 &v1, const float4 &v2);

        float (FASTCALL *vec4_length)(const float4 &vec);
        float (FASTCALL *vec4_dot)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_normalize)(const float4 &vec);
        float4 (FASTCALL *vec4_normalize_fast)(const float4 &vec);

        void (FASTCALL *mat2_init4)(float4 &vec, float v0, float v1, float v2, float v3);

        float4 (FASTCALL *mat2_add_mat2)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *mat2_sub_mat2)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *mat2_mul_mat2)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *mat2_div_mat2)(const float4 &v1, const float4 &v2);

        float4 (FASTCALL *mat2_comp_mul)(const float4 &m1, const float4 &m2);

        void (FASTCALL *mat3_init1)(float12 &vec, float val);
        void (FASTCALL *mat3_init3)(float12 &vec, const float4 &v0, const float4 &v1, const float4 &v2);
        void (FASTCALL *mat3_init9)(float12 &vec, float v00, float v01, float v02,
                                                  float v10, float v11, float v12,
                                                  float v20, float v21, float v22);

        float12 (FASTCALL *mat3_add_mat3)(const float12 &v1, const float12 &v2);
        float12 (FASTCALL *mat3_sub_mat3)(const float12 &v1, const float12 &v2);
        float12 (FASTCALL *mat3_mul_mat3)(const float12 &v1, const float12 &v2);
        float12 (FASTCALL *mat3_div_mat3)(const float12 &v1, const float12 &v2);

        float12 (FASTCALL *mat3_mul_float)(const float12 &v1, float v2);
        float12 (FASTCALL *mat3_div_float)(const float12 &v1, float v2);

        float12 (FASTCALL *mat3_comp_mul)(const float12 &m1, const float12 &m2);

        void (FASTCALL *mat4_init1)(float16 &vec, float val);
        void (FASTCALL *mat4_init4)(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3);
        void (FASTCALL *mat4_init16)(float16 &vec, float v00, float v01, float v02, float v03,
                                                   float v10, float v11, float v12, float v13,
                                                   float v20, float v21, float v22, float v23,
                                                   float v30, float v31, float v32, float v33);

        float16 (FASTCALL *mat4_add_mat4)(const float16 &v1, const float16 &v2);
        float16 (FASTCALL *mat4_sub_mat4)(const float16 &v1, const float16 &v2);
        float16 (FASTCALL *mat4_mul_mat4)(const float16 &v1, const float16 &v2);
        float16 (FASTCALL *mat4_div_mat4)(const float16 &v1, const float16 &v2);

        float16 (FASTCALL *mat4_mul_float)(const float16 &v1, float v2);
        float16 (FASTCALL *mat4_div_float)(const float16 &v1, float v2);

        float16 (FASTCALL *mat4_comp_mul)(const float16 &m1, const float16 &m2);

        float4 (FASTCALL *mat4_mul_vec4)(const float16 &v1, const float4 &v2);
    } funcs[] = {   {   // Reference
                        FUNC_LIST(ref)
                    },
                    {   // SSE2
#if !defined(__arm__)
                        FUNC_LIST(sse2)
#endif
                    },
                    {   // SSE3
#if !defined(__arm__)
                        FUNC_LIST(sse3)
#endif
                    },
                    {   // SSE4.1
#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
                        FUNC_LIST(sse4_1)
#endif
                    },
                    {   // AVX
#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
                        FUNC_LIST(avx)
#endif
                    },
                    {   // NEON
#if defined(__ARM_NEON__)
                        FUNC_LIST(neon)
#endif
                    }
    };
}

#undef FUNC_LIST

void math::init(math::e_arch arch) {
    if (!cpu.initialized) {
        init_cpu(cpu);
    }

#if !defined(__EMSCRIPTEN__)

#if defined(CPU_ARCH_SCALAR)
#elif defined(CPU_ARCH_SSE2)
    assert(cpu.HW_SSE2);
#elif defined(CPU_ARCH_SSE3)
    assert(cpu.HW_SSE3);
#elif defined(CPU_ARCH_SSE4_1)
    assert(cpu.HW_SSE41);
#elif defined(CPU_ARCH_AVX)
    assert(cpu.HW_AVX);
#else

    if (arch == AVX && !cpu.HW_AVX) arch = SSE4_1;
    if (arch == SSE4_1 && !cpu.HW_SSE41) arch = SSE3;
    if (arch == SSE3 && !cpu.HW_SSE3) arch = SSE2;
    if (arch == SSE2 && !cpu.HW_SSE2) arch = Scalar;
#endif

#if defined(CPU_ARCH_UNKNOWN)
    const func_table &t = funcs[arch];

    vec3_init1 = t.vec3_init1;
    vec3_init3 = t.vec3_init3;
    vec3_add_vec3 = t.vec3_add_vec3;
    vec3_sub_vec3 = t.vec3_sub_vec3;
    vec3_mul_vec3 = t.vec3_mul_vec3;
    vec3_div_vec3 = t.vec3_div_vec3;

    vec3_length = t.vec3_length;
    vec3_dot = t.vec3_dot;
    vec3_cross = t.vec3_cross;
    vec3_normalize = t.vec3_normalize;
    vec3_normalize_fast = t.vec3_normalize_fast;

    vec4_init1 = t.vec4_init1;
    vec4_init4 = t.vec4_init4;
    vec4_eq_vec4 = t.vec4_eq_vec4;
    vec4_add_vec4 = t.vec4_add_vec4;
    vec4_sub_vec4 = t.vec4_sub_vec4;
    vec4_mul_vec4 = t.vec4_mul_vec4;
    vec4_div_vec4 = t.vec4_div_vec4;

    vec4_length = t.vec4_length;
    vec4_dot = t.vec4_dot;
    vec4_normalize = t.vec4_normalize;
    vec4_normalize_fast = t.vec4_normalize_fast;

    mat2_init4 = t.mat2_init4;

    mat2_add_mat2 = t.mat2_add_mat2;
    mat2_sub_mat2 = t.mat2_sub_mat2;
    mat2_mul_mat2 = t.mat2_mul_mat2;
    mat2_div_mat2 = t.mat2_div_mat2;

    mat2_comp_mul = t.mat2_comp_mul;

    mat3_init1 = t.mat3_init1;
    mat3_init3 = t.mat3_init3;
    mat3_init9 = t.mat3_init9;

    mat3_add_mat3 = t.mat3_add_mat3;
    mat3_sub_mat3 = t.mat3_sub_mat3;
    mat3_mul_mat3 = t.mat3_mul_mat3;
    mat3_div_mat3 = t.mat3_div_mat3;

    mat3_mul_float = t.mat3_mul_float;
    mat3_div_float = t.mat3_div_float;

    mat3_comp_mul = t.mat3_comp_mul;

    mat4_init1 = t.mat4_init1;
    mat4_init4 = t.mat4_init4;
    mat4_init16 = t.mat4_init16;

    mat4_add_mat4 = t.mat4_add_mat4;
    mat4_sub_mat4 = t.mat4_sub_mat4;
    mat4_mul_mat4 = t.mat4_mul_mat4;
    mat4_div_mat4 = t.mat4_div_mat4;

    mat4_mul_float = t.mat4_mul_float;
    mat4_div_float = t.mat4_div_float;

    mat4_comp_mul = t.mat4_comp_mul;

    mat4_mul_vec4 = t.mat4_mul_vec4;
#endif
#endif
}

bool math::supported(e_arch arch) {
    if (!cpu.initialized) {
        init_cpu(cpu);
    }

#if defined(__arm__)
    return arch == Scalar || arch == NEON;
#elif defined(__EMSCRIPTEN__)
    return arch == Scalar || arch == SSE2 || arch == SSE3 || arch == SSE4_1;
#else
    return arch == Scalar ||
           (arch == SSE2 && cpu.HW_SSE2) ||
           (arch == SSE3 && cpu.HW_SSE3) ||
           (arch == SSE4_1 && cpu.HW_SSE41) ||
           (arch == AVX && cpu.HW_AVX);
#endif
}

void math::init_cpu(CPUFeatures &cpu) {
    cpu.initialized = true;

#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
    int info[4];
    cpuid(info, 0);
    int nIds = info[0];

    cpuid(info, 0x80000000);
    unsigned nExIds = info[0];

    //  Detect Features
    if (nIds >= 0x00000001) {
        cpuid(info, 0x00000001);
        cpu.HW_MMX = (info[3] & ((int)1 << 23)) != 0;
        cpu.HW_SSE = (info[3] & ((int)1 << 25)) != 0;
        cpu.HW_SSE2 = (info[3] & ((int)1 << 26)) != 0;
        cpu.HW_SSE3 = (info[2] & ((int)1 << 0)) != 0;

        cpu.HW_SSSE3 = (info[2] & ((int)1 << 9)) != 0;
        cpu.HW_SSE41 = (info[2] & ((int)1 << 19)) != 0;
        cpu.HW_SSE42 = (info[2] & ((int)1 << 20)) != 0;
        cpu.HW_AES = (info[2] & ((int)1 << 25)) != 0;

        cpu.HW_AVX = (info[2] & ((int)1 << 28)) != 0;
        cpu.HW_FMA3 = (info[2] & ((int)1 << 12)) != 0;

        cpu.HW_RDRAND = (info[2] & ((int)1 << 30)) != 0;
    }
    if (nIds >= 0x00000007) {
        cpuid(info, 0x00000007);
        cpu.HW_AVX2 = (info[1] & ((int)1 << 5)) != 0;

        cpu.HW_BMI1 = (info[1] & ((int)1 << 3)) != 0;
        cpu.HW_BMI2 = (info[1] & ((int)1 << 8)) != 0;
        cpu.HW_ADX = (info[1] & ((int)1 << 19)) != 0;
        cpu.HW_SHA = (info[1] & ((int)1 << 29)) != 0;
        cpu.HW_PREFETCHWT1 = (info[2] & ((int)1 << 0)) != 0;

        cpu.HW_AVX512F = (info[1] & ((int)1 << 16)) != 0;
        cpu.HW_AVX512CD = (info[1] & ((int)1 << 28)) != 0;
        cpu.HW_AVX512PF = (info[1] & ((int)1 << 26)) != 0;
        cpu.HW_AVX512ER = (info[1] & ((int)1 << 27)) != 0;
        cpu.HW_AVX512VL = (info[1] & ((int)1 << 31)) != 0;
        cpu.HW_AVX512BW = (info[1] & ((int)1 << 30)) != 0;
        cpu.HW_AVX512DQ = (info[1] & ((int)1 << 17)) != 0;
        cpu.HW_AVX512IFMA = (info[1] & ((int)1 << 21)) != 0;
        cpu.HW_AVX512VBMI = (info[2] & ((int)1 << 1)) != 0;
    }
    if (nExIds >= 0x80000001) {
        cpuid(info, 0x80000001);
        cpu.HW_x64 = (info[3] & ((int)1 << 29)) != 0;
        cpu.HW_ABM = (info[2] & ((int)1 << 5)) != 0;
        cpu.HW_SSE4a = (info[2] & ((int)1 << 6)) != 0;
        cpu.HW_FMA4 = (info[2] & ((int)1 << 16)) != 0;
        cpu.HW_XOP = (info[2] & ((int)1 << 11)) != 0;
    }
#endif
}

#if defined(MATH_NO_INLINE)
#define MATH_IMPL

#include "math_ref.hpp"
#ifndef __arm__
    #include "math_sse2.hpp"
    #include "math_sse3.hpp"
    #include "math_sse4_1.hpp"
    #include "math_avx.hpp"
#else
    #include "math_neon.hpp"
#endif

#undef MATH_IMPL
#endif
