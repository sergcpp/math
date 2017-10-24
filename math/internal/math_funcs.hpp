#pragma once

#include <cassert>

#include <vector>

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
    enum e_noinit { noinit };

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
    using NS::mat2_inverse;
#else
    extern void (FASTCALL *mat2_init4)(float4 &vec, float v0, float v1, float v2, float v3);

    extern float4(FASTCALL *mat2_add_mat2)(const float4 &v1, const float4 &v2);
    extern float4(FASTCALL *mat2_sub_mat2)(const float4 &v1, const float4 &v2);
    extern float4(FASTCALL *mat2_mul_mat2)(const float4 &v1, const float4 &v2);
    extern float4(FASTCALL *mat2_div_mat2)(const float4 &v1, const float4 &v2);

    extern float4 (FASTCALL *mat2_comp_mul)(const float4 &m1, const float4 &m2);
    extern float4 (FASTCALL *mat2_inverse)(const float4 &m);
#endif

    using NS::mat2_init1;
    using NS::mat2_init2;

    using NS::mat2_eq_mat2;

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
    using NS::mat3_inverse;
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
    extern float9 (FASTCALL *mat3_inverse)(const float9 &m);
#endif

    using NS::mat3_eq_mat3;

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
    using NS::mat4_inverse;
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
    extern float16 (FASTCALL *mat4_inverse)(const float16 &m);

    extern float4 (FASTCALL *mat4_mul_vec4)(const float16 &v1, const float4 &v2);
#endif

    using NS::mat4_eq_mat4;

    using NS::vec4_mul_mat4;

    // ivec2
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::ivec2_init1;
    using NS::ivec2_init2;
    using NS::ivec2_eq_ivec2;
    using NS::ivec2_add_ivec2;
    using NS::ivec2_sub_ivec2;
    using NS::ivec2_mul_ivec2;
    using NS::ivec2_div_ivec2;
#else
    extern void (FASTCALL *ivec2_init1)(int2 &vec, int val);
    extern void (FASTCALL *ivec2_init2)(int2 &vec, int v0, int v1);
    extern int2 (FASTCALL *ivec2_add_ivec2)(const int2 &v1, const int2 &v2);
    extern int2 (FASTCALL *ivec2_sub_ivec2)(const int2 &v1, const int2 &v2);
    extern int2 (FASTCALL *ivec2_mul_ivec2)(const int2 &v1, const int2 &v2);
    extern int2 (FASTCALL *ivec2_div_ivec2)(const int2 &v1, const int2 &v2);
#endif

    using NS::ivec2_eq_ivec2;

    // ivec3
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::ivec3_init1;
    using NS::ivec3_init3;
    using NS::ivec3_eq_ivec3;
    using NS::ivec3_add_ivec3;
    using NS::ivec3_sub_ivec3;
    using NS::ivec3_mul_ivec3;
    using NS::ivec3_div_ivec3;
#else
    extern void (FASTCALL *ivec3_init1)(int3 &vec, int val);
    extern void (FASTCALL *ivec3_init3)(int3 &vec, int v0, int v1, int v2);
    extern int3 (FASTCALL *ivec3_add_ivec3)(const int3 &v1, const int3 &v2);
    extern int3 (FASTCALL *ivec3_sub_ivec3)(const int3 &v1, const int3 &v2);
    extern int3 (FASTCALL *ivec3_mul_ivec3)(const int3 &v1, const int3 &v2);
    extern int3 (FASTCALL *ivec3_div_ivec3)(const int3 &v1, const int3 &v2);
#endif

    using NS::ivec3_eq_ivec3;

    // ivec4
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::ivec4_init1;
    using NS::ivec4_init4;
    using NS::ivec4_add_ivec4;
    using NS::ivec4_sub_ivec4;
    using NS::ivec4_mul_ivec4;
    using NS::ivec4_div_ivec4;
#else
    extern void (FASTCALL *ivec4_init1)(int4 &vec, int val);
    extern void (FASTCALL *ivec4_init4)(int4 &vec, int v0, int v1, int v2, int v3);
    extern int4 (FASTCALL *ivec4_add_ivec4)(const int4 &v1, const int4 &v2);
    extern int4 (FASTCALL *ivec4_sub_ivec4)(const int4 &v1, const int4 &v2);
    extern int4 (FASTCALL *ivec4_mul_ivec4)(const int4 &v1, const int4 &v2);
    extern int4 (FASTCALL *ivec4_div_ivec4)(const int4 &v1, const int4 &v2);
#endif

    using NS::ivec4_eq_ivec4;

    // quat
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::quat_init4;
    using NS::quat_add_quat;
    using NS::quat_mul_quat;
    using NS::quat_mul_float;
    using NS::quat_div_float;
#else
    extern void (FASTCALL *quat_init4)(float4 &vec, float r, float i, float j, float k);
    extern float4 (FASTCALL *quat_add_quat)(const float4 &v1, const float4 &v2);
    extern float4 (FASTCALL *quat_mul_quat)(const float4 &v1, const float4 &v2);
    extern float4 (FASTCALL *quat_mul_float)(const float4 &v, float f);
    extern float4 (FASTCALL *quat_div_float)(const float4 &v, float f);
#endif

    using NS::quat_eq_quat;

    using NS::quat_to_mat3;
    using NS::mat3_to_quat;
    using NS::mat4_to_quat;

    // dvec2
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::dvec2_init1;
    using NS::dvec2_init2;
    using NS::dvec2_eq_dvec2;
    using NS::dvec2_add_dvec2;
    using NS::dvec2_sub_dvec2;
    using NS::dvec2_mul_dvec2;
    using NS::dvec2_div_dvec2;
#else
    extern void (FASTCALL *dvec2_init1)(double2 &vec, double val);
    extern void (FASTCALL *dvec2_init2)(double2 &vec, double v0, double v1);
    extern double2 (FASTCALL *dvec2_add_dvec2)(const double2 &v1, const double2 &v2);
    extern double2 (FASTCALL *dvec2_sub_dvec2)(const double2 &v1, const double2 &v2);
    extern double2 (FASTCALL *dvec2_mul_dvec2)(const double2 &v1, const double2 &v2);
    extern double2 (FASTCALL *dvec2_div_dvec2)(const double2 &v1, const double2 &v2);
#endif

    using NS::dvec2_eq_dvec2;

    using NS::dvec2_length;

    // dvec3
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::dvec3_init1;
    using NS::dvec3_init3;
    using NS::dvec3_eq_dvec3;
    using NS::dvec3_add_dvec3;
    using NS::dvec3_sub_dvec3;
    using NS::dvec3_mul_dvec3;
    using NS::dvec3_div_dvec3;
#else
    extern void (FASTCALL *dvec3_init1)(double3 &vec, double val);
    extern void (FASTCALL *dvec3_init3)(double3 &vec, double v0, double v1, double v2);
    extern double3 (FASTCALL *dvec3_add_dvec3)(const double3 &v1, const double3 &v2);
    extern double3 (FASTCALL *dvec3_sub_dvec3)(const double3 &v1, const double3 &v2);
    extern double3 (FASTCALL *dvec3_mul_dvec3)(const double3 &v1, const double3 &v2);
    extern double3 (FASTCALL *dvec3_div_dvec3)(const double3 &v1, const double3 &v2);
#endif

    using NS::dvec3_eq_dvec3;

    using NS::dvec3_length;

    // dvec4
#if !defined(CPU_ARCH_UNKNOWN)
    using NS::dvec4_init1;
    using NS::dvec4_init4;
    using NS::dvec4_eq_dvec4;
    using NS::dvec4_add_dvec4;
    using NS::dvec4_sub_dvec4;
    using NS::dvec4_mul_dvec4;
    using NS::dvec4_div_dvec4;
#else
    extern void (FASTCALL *dvec4_init1)(double4 &vec, double val);
    extern void (FASTCALL *dvec4_init4)(double4 &vec, double v0, double v1, double v2, double v3);
    extern double4 (FASTCALL *dvec4_add_dvec4)(const double4 &v1, const double4 &v2);
    extern double4 (FASTCALL *dvec4_sub_dvec4)(const double4 &v1, const double4 &v2);
    extern double4 (FASTCALL *dvec4_mul_dvec4)(const double4 &v1, const double4 &v2);
    extern double4 (FASTCALL *dvec4_div_dvec4)(const double4 &v1, const double4 &v2);
#endif

    using NS::dvec4_eq_dvec4;

    using NS::dvec4_length;
}

#undef NS