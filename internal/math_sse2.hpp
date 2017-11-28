#include "math_ref.hpp"

#if defined(MATH_NO_INLINE) && !defined(MATH_IMPL)

namespace math {
namespace sse2 {
    using namespace ref;

    // vec3
    DECL_FUNC(float3) vec3_add_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_sub_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_mul_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_div_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float) vec3_length(const float3 &v);
    DECL_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_cross(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_normalize(const float3 &v);

    // vec4
    DECL_FUNC(void) vec4_init1(float4 &vec, float val);
    DECL_FUNC(void) vec4_init4(float4 &vec, float v0, float v1, float v2, float v3);
    DECL_FUNC(bool) vec4_eq_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_add_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_sub_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_mul_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_div_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float) vec4_length(const float4 &v);
    DECL_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_normalize(const float4 &v);

    // mat2
    DECL_FUNC(void) mat2_init4(float4 &vec, float v0, float v1, float v2, float v3);
    DECL_FUNC(float4) mat2_add_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) mat2_sub_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) mat2_mul_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) mat2_div_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) mat2_comp_mul(const float4 &m1, const float4 &m2);

    // mat3
    DECL_FUNC(float9) mat3_add_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_sub_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_mul_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_div_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_comp_mul(const float9 &v1, const float9 &v2);

    // mat4
    DECL_FUNC(void) mat4_init1(float16 &vec, float val);
    DECL_FUNC(void) mat4_init16(float16 &vec, float v00, float v01, float v02, float v03,
                                float v10, float v11, float v12, float v13,
                                float v20, float v21, float v22, float v23,
                                float v30, float v31, float v32, float v33);
    DECL_FUNC(void) mat4_init4(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3);
    DECL_FUNC(float16) mat4_add_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_sub_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_mul_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_div_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_mul_float(const float16 &v1, float v2);
    DECL_FUNC(float16) mat4_div_float(const float16 &v1, float v2);
    DECL_FUNC(float16) mat4_comp_mul(const float16 &v1, const float16 &v2);

    // ivec2
    DECL_FUNC(void) ivec2_init1(int2 &vec, int val);
    DECL_FUNC(void) ivec2_init2(int2 &vec, int v0, int v1);
    DECL_FUNC(void) ivec2_add_ivec2(int2 &vec, const int2 &rhs);
    DECL_FUNC(void) ivec2_sub_ivec2(int2 &vec, const int2 &rhs);

    // ivec4
    DECL_FUNC(void) ivec4_init1(int4 &vec, int val);
    DECL_FUNC(void) ivec4_init4(int4 &vec, int v0, int v1, int v2, int v3);
    DECL_FUNC(void) ivec4_add_ivec4(int4 &vec, const int4 &rhs);
    DECL_FUNC(void) ivec4_sub_ivec4(int4 &vec, const int4 &rhs);

    // dvec2
    DECL_FUNC(void) dvec2_init1(double2 &vec, double val);
    DECL_FUNC(void) dvec2_init2(double2 &vec, double v0, double v1);
    DECL_FUNC(double2) dvec2_add_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double2) dvec2_sub_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double2) dvec2_mul_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double2) dvec2_div_dvec2(const double2 &v1, const double2 &v2);

    // dvec3
    DECL_FUNC(double3) dvec3_add_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double3) dvec3_sub_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double3) dvec3_mul_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double3) dvec3_div_dvec3(const double3 &v1, const double3 &v2);

    // dvec4
    DECL_FUNC(void) dvec4_init1(double4 &vec, double val);
    DECL_FUNC(void) dvec4_init4(double4 &vec, double v0, double v1, double v2, double v3);
    DECL_FUNC(double4) dvec4_add_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_sub_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_mul_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_div_dvec4(const double4 &v1, const double4 &v2);

    // comb
    DECL_FUNC(float4) mat4_mul_vec4(const float16 &m, const float4 &v);

    // quat
    DECL_FUNC(void) quat_init4(float4 &vec, float r, float i, float j, float k);
    DECL_FUNC(float4) quat_add_quat(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) quat_mul_float(const float4 &v1, const float f);
    DECL_FUNC(float4) quat_div_float(const float4 &v1, const float f);
}
}

#else

#pragma once

#ifdef __GNUC__
#pragma GCC push_options
#pragma GCC target ("sse2")
#endif

namespace math {
namespace sse2 {
    using namespace ref;

#include "math_sse2.ipp"
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#endif