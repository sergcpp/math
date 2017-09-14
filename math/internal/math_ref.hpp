#include "types.hpp"

#if defined(MATH_NO_INLINE) && !defined(MATH_IMPL)

namespace math {
namespace ref {
    // vec2
    DECL_FUNC(void) vec2_init1(float2 &vec, float val);
    DECL_FUNC(void) vec2_init2(float2 &vec, float v0, float v1);
    DECL_FUNC(bool) vec2_eq_vec2(const float2 &v1, const float2 &v2);
    DECL_FUNC(float2) vec2_add_vec2(const float2 &v1, const float2 &v2);
    DECL_FUNC(float2) vec2_sub_vec2(const float2 &v1, const float2 &v2);
    DECL_FUNC(float2) vec2_mul_vec2(const float2 &v1, const float2 &v2);
    DECL_FUNC(float2) vec2_div_vec2(const float2 &v1, const float2 &v2);
    DECL_FUNC(float) vec2_get(const float2 &vec, int i);
    DECL_FUNC(void) vec2_set(float2 &vec, int i, float v);
    DECL_FUNC(float) vec2_length(const float2 &vec);
    DECL_FUNC(float) vec2_dot(const float2 &v1, const float2 &v2);
    DECL_FUNC(float2) vec2_normalize(const float2 &vec);
    DECL_FUNC(float2) vec2_normalize_fast(const float2 &vec);
    DECL_FUNC(float2) vec2_sin(const float2 &v);
    DECL_FUNC(float2) vec2_cos(const float2 &v);
    DECL_FUNC(float2) vec2_tan(const float2 &v);
    DECL_FUNC(float2) vec2_asin(const float2 &v);
    DECL_FUNC(float2) vec2_acos(const float2 &v);
    DECL_FUNC(float2) vec2_atan(const float2 &v);

    // vec3
    DECL_FUNC(void) vec3_init1(float3 &vec, float val);
    DECL_FUNC(void) vec3_init3(float3 &vec, float v0, float v1, float v2);
    DECL_FUNC(bool) vec3_eq_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_add_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_sub_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_mul_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_div_vec3(const float3 &v1, const float3 &v2);
    DECL_FUNC(float) vec3_get(const float3 &vec, int i);
    DECL_FUNC(void) vec3_set(float3 &vec, int i, float v);
    DECL_FUNC(float) vec3_length(const float3 &vec);
    DECL_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_cross(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_normalize(const float3 &vec);
    DECL_FUNC(float3) vec3_normalize_fast(const float3 &vec);
    DECL_FUNC(float3) vec3_sin(const float3 &v);
    DECL_FUNC(float3) vec3_cos(const float3 &v);
    DECL_FUNC(float3) vec3_tan(const float3 &v);
    DECL_FUNC(float3) vec3_asin(const float3 &v);
    DECL_FUNC(float3) vec3_acos(const float3 &v);
    DECL_FUNC(float3) vec3_atan(const float3 &v);

    // vec4
    DECL_FUNC(void) vec4_init1(float4 &vec, float val);
    DECL_FUNC(void) vec4_init4(float4 &vec, float v0, float v1, float v2, float v3);
    DECL_FUNC(bool) vec4_eq_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_add_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_sub_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_mul_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_div_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float) vec4_get(const float4 &vec, int i);
    DECL_FUNC(void) vec4_set(float4 &vec, int i, float v);
    DECL_FUNC(float) vec4_length(const float4 &vec);
    DECL_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_normalize(const float4 &vec);
    DECL_FUNC(float4) vec4_normalize_fast(const float4 &vec);
    DECL_FUNC(float4) vec4_sin(const float4 &v);
    DECL_FUNC(float4) vec4_cos(const float4 &v);
    DECL_FUNC(float4) vec4_tan(const float4 &v);
    DECL_FUNC(float4) vec4_asin(const float4 &v);
    DECL_FUNC(float4) vec4_acos(const float4 &v);
    DECL_FUNC(float4) vec4_atan(const float4 &v);

    // mat2
    DECL_FUNC(void) mat2_init1(float4 &vec, float val);
    DECL_FUNC(void) mat2_init2(float4 &vec, const float2 &v01, const float2 &v23);
    DECL_FUNC(void) mat2_init4(float4 &vec, float v0, float v1, float v2, float v3);
    DECL_FUNC(bool) mat2_eq_mat2(const float4 &m1, const float4 &m2);
    DECL_FUNC(float4) mat2_add_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) mat2_sub_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) mat2_mul_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) mat2_div_mat2(const float4 &v1, const float4 &v2);
    DECL_FUNC(float2) mat2_get(const float4 &vec, int i);
    DECL_FUNC(void) mat2_set(float4 &vec, int i, const float2 &v);
    DECL_FUNC(float4) mat2_comp_mul(const float4 &m1, const float4 &m2);
    DECL_FUNC(float4) mat2_inverse(const float4 &m);

    // mat3
    DECL_FUNC(void) mat3_init1(float9 &vec, float val);
    DECL_FUNC(void) mat3_init9(float9 &vec, float v00, float v01, float v02,
                                            float v10, float v11, float v12,
                                            float v20, float v21, float v22);
    DECL_FUNC(void) mat3_init3(float9 &vec, const float3 &v0, const float3 &v1, const float3 &v2);
    DECL_FUNC(bool) mat3_eq_mat3(const float9 &m1, const float9 &m2);
    DECL_FUNC(float9) mat3_add_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_sub_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_mul_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_div_mat3(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_mul_float(const float9 &v1, float v2);
    DECL_FUNC(float9) mat3_div_float(const float9 &v1, float v2);
    DECL_FUNC(float3) mat3_get(const float9 &vec, int i);
    DECL_FUNC(void) mat3_set(float9 &vec, int i, const float3 &v);
    DECL_FUNC(float9) mat3_comp_mul(const float9 &v1, const float9 &v2);
    DECL_FUNC(float9) mat3_inverse(const float9 &m);

    // mat4
    DECL_FUNC(void) mat4_init1(float16 &vec, float val);
    DECL_FUNC(void) mat4_init16(float16 &vec, float v00, float v01, float v02, float v03,
                                              float v10, float v11, float v12, float v13,
                                              float v20, float v21, float v22, float v23,
                                              float v30, float v31, float v32, float v33);
    DECL_FUNC(void) mat4_init4(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3);
    DECL_FUNC(bool) mat4_eq_mat4(const float16 &m1, const float16 &m2);
    DECL_FUNC(float16) mat4_add_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_sub_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_mul_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_div_mat4(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_mul_float(const float16 &v1, float v2);
    DECL_FUNC(float16) mat4_div_float(const float16 &v1, float v2);
    DECL_FUNC(float4) mat4_get(const float16 &vec, int i);
    DECL_FUNC(void) mat4_set(float16 &vec, int i, const float4 &v);
    DECL_FUNC(float16) mat4_comp_mul(const float16 &v1, const float16 &v2);
    DECL_FUNC(float16) mat4_inverse(const float16 &m);

    // ivec2
    DECL_FUNC(void) ivec2_init1(int2 &vec, int val);
    DECL_FUNC(void) ivec2_init2(int2 &vec, int v0, int v1);
    DECL_FUNC(bool) ivec2_eq_ivec2(const int2 &v1, const int2 &v2);
    DECL_FUNC(int2) ivec2_add_ivec2(const int2 &v1, const int2 &v2);
    DECL_FUNC(int2) ivec2_sub_ivec2(const int2 &v1, const int2 &v2);
    DECL_FUNC(int2) ivec2_mul_ivec2(const int2 &v1, const int2 &v2);
    DECL_FUNC(int2) ivec2_div_ivec2(const int2 &v1, const int2 &v2);
    DECL_FUNC(int) ivec2_get(const int2 &vec, int i);
    DECL_FUNC(void) ivec2_set(int2 &vec, int i, int v);

    // ivec3
    DECL_FUNC(void) ivec3_init1(int3 &vec, int val);
    DECL_FUNC(void) ivec3_init3(int3 &vec, int v0, int v1, int v2);
    DECL_FUNC(bool) ivec3_eq_ivec3(const int3 &v1, const int3 &v2);
    DECL_FUNC(int3) ivec3_add_ivec3(const int3 &v1, const int3 &v2);
    DECL_FUNC(int3) ivec3_sub_ivec3(const int3 &v1, const int3 &v2);
    DECL_FUNC(int3) ivec3_mul_ivec3(const int3 &v1, const int3 &v2);
    DECL_FUNC(int3) ivec3_div_ivec3(const int3 &v1, const int3 &v2);
    DECL_FUNC(int) ivec3_get(const int3 &vec, int i);
    DECL_FUNC(void) ivec3_set(int3 &vec, int i, int v);

    // ivec4
    DECL_FUNC(void) ivec4_init1(int4 &vec, int val);
    DECL_FUNC(void) ivec4_init4(int4 &vec, int v0, int v1, int v2, int v3);
    DECL_FUNC(bool) ivec4_eq_ivec4(const int4 &v1, const int4 &v2);
    DECL_FUNC(int4) ivec4_add_ivec4(const int4 &v1, const int4 &v2);
    DECL_FUNC(int4) ivec4_sub_ivec4(const int4 &v1, const int4 &v2);
    DECL_FUNC(int4) ivec4_mul_ivec4(const int4 &v1, const int4 &v2);
    DECL_FUNC(int4) ivec4_div_ivec4(const int4 &v1, const int4 &v2);
    DECL_FUNC(int) ivec4_get(const int4 &vec, int i);
    DECL_FUNC(void) ivec4_set(int4 &vec, int i, int v);

    // quat
    DECL_FUNC(void) quat_init4(float4 &vec, float r, float i, float j, float k);
    DECL_FUNC(bool) quat_eq_quat(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) quat_add_quat(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) quat_mul_quat(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) quat_mul_float(const float4 &v1, const float f);
    DECL_FUNC(float4) quat_div_float(const float4 &v1, const float f);
    DECL_FUNC(float) quat_get(const float4 &vec, int i);
    DECL_FUNC(void) quat_set(float4 &vec, int i, float v);
    DECL_FUNC(float9) quat_to_mat3(const float4 &vec);
    DECL_FUNC(float4) mat3_to_quat(const float9 &vec);
    DECL_FUNC(float4) mat4_to_quat(const float16 &vec);

    // dvec2
    DECL_FUNC(void) dvec2_init1(double2 &vec, double val);
    DECL_FUNC(void) dvec2_init2(double2 &vec, double v0, double v1);
    DECL_FUNC(bool) dvec2_eq_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double2) dvec2_add_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double2) dvec2_sub_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double2) dvec2_mul_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double2) dvec2_div_dvec2(const double2 &v1, const double2 &v2);
    DECL_FUNC(double) dvec2_get(const double2 &vec, int i);
    DECL_FUNC(void) dvec2_set(double2 &vec, int i, double v);
    DECL_FUNC(double) dvec2_length(const double2 &vec);

    // dvec3
    DECL_FUNC(void) dvec3_init1(double3 &vec, double val);
    DECL_FUNC(void) dvec3_init3(double3 &vec, double v0, double v1, double v2);
    DECL_FUNC(bool) dvec3_eq_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double3) dvec3_add_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double3) dvec3_sub_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double3) dvec3_mul_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double3) dvec3_div_dvec3(const double3 &v1, const double3 &v2);
    DECL_FUNC(double) dvec3_get(const double3 &vec, int i);
    DECL_FUNC(void) dvec3_set(double3 &vec, int i, double v);
    DECL_FUNC(double) dvec3_length(const double3 &vec);

    // dvec4
    DECL_FUNC(void) dvec4_init1(double4 &vec, double val);
    DECL_FUNC(void) dvec4_init4(double4 &vec, double v0, double v1, double v2, double v3);
    DECL_FUNC(bool) dvec4_eq_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_add_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_sub_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_mul_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_div_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double) dvec4_get(const double4 &vec, int i);
    DECL_FUNC(void) dvec4_set(double4 &vec, int i, double v);
    DECL_FUNC(double) dvec4_length(const double4 &vec);

    // comb
    DECL_FUNC(float2) mat2_mul_vec2(const float4 &m, const float2 &v);
    DECL_FUNC(float3) mat3_mul_vec3(const float9 &m, const float3 &v);
    DECL_FUNC(float4) mat4_mul_vec4(const float16 &m, const float4 &v);

    DECL_FUNC(float2) vec2_mul_mat2(const float2 &v, const float4 &m);
    DECL_FUNC(float3) vec3_mul_mat3(const float3 &v, const float9 &m);
    DECL_FUNC(float4) vec4_mul_mat4(const float4 &v, const float16 &m);
}
}

#else

#pragma once

#include <cmath>

namespace math {
namespace ref {
	#include "math_ref.ipp"
}
}

#endif