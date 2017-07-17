#pragma once

#include <cassert>

#include <vector>

#include "allocator.hpp"
#include "math_ref.hpp"

#if defined(CPU_ARCH_SCALAR)
    #define NS ref
#elif defined(CPU_ARCH_SSE2)
    #include "math_sse2.hpp"
    #define NS sse2
#elif defined(CPU_ARCH_SSE3)
    #include "math_sse3.hpp"
    #define NS sse3
#elif defined(CPU_ARCH_SSE4_1)
    #include "math_sse4_1.hpp"
    #define NS sse4_1
#elif defined(CPU_ARCH_AVX)
    #include "math_avx.hpp"
    #define NS avx
#elif defined(CPU_ARCH_NEON)
    #include "math_neon.hpp"
    #define NS neon
#else
    #define CPU_ARCH_UNKNOWN
    #define NS ref
#endif

namespace math {
    enum e_uninitialize { uninitialize };

    template <typename T>
    using aligned_vector = std::vector<T, aligned_allocator<T, T::alignment>>;

    inline bool is_aligned(const void *p, size_t byte_count) {
        return ((uintptr_t)p) % byte_count == 0;
    }

    // vec2
    using NS::vec2_init1;
    using NS::vec2_init2;
    using NS::vec2_eq_vec2;
    using NS::vec2_add_vec2;
    using NS::vec2_sub_vec2;
    using NS::vec2_mul_vec2;
    using NS::vec2_div_vec2;

    using NS::vec2_get;
    using NS::vec2_set;

    using NS::vec2_length;
    using NS::vec2_dot;
    using NS::vec2_normalize;
    using NS::vec2_normalize_fast;

    using NS::vec2_sin;
    using NS::vec2_cos;
    using NS::vec2_tan;
    using NS::vec2_asin;
    using NS::vec2_acos;
    using NS::vec2_atan;

    // vec3
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::vec3_init1;
    using NS::vec3_init3;
    using NS::vec3_add_vec3;
    using NS::vec3_sub_vec3;
    using NS::vec3_mul_vec3;
    using NS::vec3_div_vec3;

    using NS::vec3_length;
    using NS::vec3_dot;
    using NS::vec3_cross;
    using NS::vec3_normalize;
    using NS::vec3_normalize_fast;
#else
    extern void (FASTCALL *vec3_init1)(float3 &vec, float val);
    extern void (FASTCALL *vec3_init3)(float3 &vec, float v0, float v1, float v2);
    extern float3 (FASTCALL *vec3_add_vec3)(const float3 &v1, const float3 &v2);
    extern float3 (FASTCALL *vec3_sub_vec3)(const float3 &v1, const float3 &v2);
    extern float3 (FASTCALL *vec3_mul_vec3)(const float3 &v1, const float3 &v2);
    extern float3 (FASTCALL *vec3_div_vec3)(const float3 &v1, const float3 &v2);

    extern float (FASTCALL *vec3_length)(const float3 &vec);
    extern float (FASTCALL *vec3_dot)(const float3 &v1, const float3 &v2);
    extern float3 (FASTCALL *vec3_cross)(const float3 &v1, const float3 &v2);
    extern float3 (FASTCALL *vec3_normalize)(const float3 &vec);
    extern float3 (FASTCALL *vec3_normalize_fast)(const float3 &vec);
#endif
    using NS::vec3_eq_vec3;

    using NS::vec3_get;
    using NS::vec3_set;

    using NS::vec3_sin;
    using NS::vec3_cos;
    using NS::vec3_tan;
    using NS::vec3_asin;
    using NS::vec3_acos;
    using NS::vec3_atan;

    // vec4
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::vec4_init1;
    using NS::vec4_init4;
    using NS::vec4_eq_vec4;
    using NS::vec4_add_vec4;
    using NS::vec4_sub_vec4;
    using NS::vec4_mul_vec4;
    using NS::vec4_div_vec4;

    using NS::vec4_length;
    using NS::vec4_dot;
    using NS::vec4_normalize;
    using NS::vec4_normalize_fast;
#else
    extern void (FASTCALL *vec4_init1)(float4 &vec, float val);
    extern void (FASTCALL *vec4_init4)(float4 &vec, float v0, float v1, float v2, float v3);
    extern bool (FASTCALL *vec4_eq_vec4)(const float4 &v1, const float4 &v2);
    extern float4 (FASTCALL *vec4_add_vec4)(const float4 &v1, const float4 &v2);
    extern float4 (FASTCALL *vec4_sub_vec4)(const float4 &v1, const float4 &v2);
    extern float4 (FASTCALL *vec4_mul_vec4)(const float4 &v1, const float4 &v2);
    extern float4 (FASTCALL *vec4_div_vec4)(const float4 &v1, const float4 &v2);

    extern float (FASTCALL *vec4_length)(const float4 &vec);
    extern float (FASTCALL *vec4_dot)(const float4 &v1, const float4 &v2);
    extern float4 (FASTCALL *vec4_normalize)(const float4 &vec);
    extern float4 (FASTCALL *vec4_normalize_fast)(const float4 &vec);
#endif
    using NS::vec4_get;
    using NS::vec4_set;

    using NS::vec4_sin;
    using NS::vec4_cos;
    using NS::vec4_tan;
    using NS::vec4_asin;
    using NS::vec4_acos;
    using NS::vec4_atan;

    // mat2
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::mat2_init4;

    using NS::mat2_add_mat2;
    using NS::mat2_sub_mat2;
    using NS::mat2_mul_mat2;
    using NS::mat2_div_mat2;

    using NS::mat2_comp_mul;
#else
    extern void (FASTCALL *mat2_init4)(float4 &vec, float v0, float v1, float v2, float v3);

    extern float4(FASTCALL *mat2_add_mat2)(const float4 &v1, const float4 &v2);
    extern float4(FASTCALL *mat2_sub_mat2)(const float4 &v1, const float4 &v2);
    extern float4(FASTCALL *mat2_mul_mat2)(const float4 &v1, const float4 &v2);
    extern float4(FASTCALL *mat2_div_mat2)(const float4 &v1, const float4 &v2);

    extern float4 (FASTCALL *mat2_comp_mul)(const float4 &m1, const float4 &m2);
#endif

    using NS::mat2_init1;
    using NS::mat2_init2;

    using NS::mat2_eq_mat2;

    using NS::mat2_get;
    using NS::mat2_set;

    using NS::mat2_mul_vec2;
    using NS::vec2_mul_mat2;

    // mat3
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::mat3_init1;
    using NS::mat3_init3;
    using NS::mat3_init9;

    using NS::mat3_add_mat3;
    using NS::mat3_sub_mat3;
    using NS::mat3_mul_mat3;
    using NS::mat3_div_mat3;

    using NS::mat3_mul_float;
    using NS::mat3_div_float;

    using NS::mat3_comp_mul;
#else
    extern void (FASTCALL *mat3_init1)(float9 &vec, float val);
    extern void (FASTCALL *mat3_init3)(float9 &vec, const float3 &v0, const float3 &v1, const float3 &v2);
    extern void (FASTCALL *mat3_init9)(float9 &vec, float v00, float v01, float v02,
                                                    float v10, float v11, float v12,
                                                    float v20, float v21, float v22);

    extern float9 (FASTCALL *mat3_add_mat3)(const float9 &v1, const float9 &v2);
    extern float9 (FASTCALL *mat3_sub_mat3)(const float9 &v1, const float9 &v2);
    extern float9 (FASTCALL *mat3_mul_mat3)(const float9 &v1, const float9 &v2);
    extern float9 (FASTCALL *mat3_div_mat3)(const float9 &v1, const float9 &v2);

    extern float9 (FASTCALL *mat3_mul_float)(const float9 &v1, float v2);
    extern float9 (FASTCALL *mat3_div_float)(const float9 &v1, float v2);

    extern float9 (FASTCALL *mat3_comp_mul)(const float9 &m1, const float9 &m2);
#endif

    using NS::mat3_eq_mat3;

    using NS::mat3_get;
    using NS::mat3_set;

    using NS::mat3_mul_vec3;
    using NS::vec3_mul_mat3;

    // mat4
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::mat4_init1;
    using NS::mat4_init4;
    using NS::mat4_init16;

    using NS::mat4_add_mat4;
    using NS::mat4_sub_mat4;
    using NS::mat4_mul_mat4;
    using NS::mat4_div_mat4;

    using NS::mat4_mul_float;
    using NS::mat4_div_float;

    using NS::mat4_comp_mul;

    using NS::mat4_mul_vec4;
#else
    extern void (FASTCALL *mat4_init1)(float16 &vec, float val);
    extern void (FASTCALL *mat4_init4)(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3);
    extern void (FASTCALL *mat4_init16)(float16 &vec, float v00, float v01, float v02, float v03,
                                                      float v10, float v11, float v12, float v13,
                                                      float v20, float v21, float v22, float v23,
                                                      float v30, float v31, float v32, float v33);

    extern float16 (FASTCALL *mat4_add_mat4)(const float16 &v1, const float16 &v2);
    extern float16 (FASTCALL *mat4_sub_mat4)(const float16 &v1, const float16 &v2);
    extern float16 (FASTCALL *mat4_mul_mat4)(const float16 &v1, const float16 &v2);
    extern float16 (FASTCALL *mat4_div_mat4)(const float16 &v1, const float16 &v2);

    extern float16 (FASTCALL *mat4_mul_float)(const float16 &v1, float v2);
    extern float16 (FASTCALL *mat4_div_float)(const float16 &v1, float v2);

    extern float16 (FASTCALL *mat4_comp_mul)(const float16 &m1, const float16 &m2);

    extern float4 (FASTCALL *mat4_mul_vec4)(const float16 &v1, const float4 &v2);
#endif

    using NS::mat4_eq_mat4;

    using NS::mat4_get;
    using NS::mat4_set;

    using NS::vec4_mul_mat4;
}

#undef NS