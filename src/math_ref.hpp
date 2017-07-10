#include "types.hpp"

#if !defined(MATH_NO_INLINE) || defined(MATH_IMPL)
#pragma once

#include <cmath>

namespace math {
namespace ref {
    // vec2
    DECL_FUNC(void) vec2_init1(float2 &vec, float val) {
        vec.comp[0] = vec.comp[1] = val;
    } DEF_END
    
    DECL_FUNC(void) vec2_init2(float2 &vec, float v0, float v1) {
        vec.comp[0] = v0; vec.comp[1] = v1;
    } DEF_END

    DECL_FUNC(bool) vec2_eq_vec2(const float2 &v1, const float2 &v2) {
        return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1];
    } DEF_END

    DECL_FUNC(float2) vec2_add_vec2(const float2 &v1, const float2 &v2) {
        float2 ret;
        ret.comp[0] = v1.comp[0] + v2.comp[0];
        ret.comp[1] = v1.comp[1] + v2.comp[1];
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_sub_vec2(const float2 &v1, const float2 &v2) {
        float2 ret;
        ret.comp[0] = v1.comp[0] - v2.comp[0];
        ret.comp[1] = v1.comp[1] - v2.comp[1];
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_mul_vec2(const float2 &v1, const float2 &v2) {
        float2 ret;
        ret.comp[0] = v1.comp[0] * v2.comp[0];
        ret.comp[1] = v1.comp[1] * v2.comp[1];
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_div_vec2(const float2 &v1, const float2 &v2) {
        float2 ret;
        ret.comp[0] = v1.comp[0] / v2.comp[0];
        ret.comp[1] = v1.comp[1] / v2.comp[1];
        return ret;
    } DEF_END

    DECL_FUNC(float) vec2_get(const float2 &vec, int i) {
        return vec.comp[i];
    } DEF_END

    DECL_FUNC(void) vec2_set(float2 &vec, int i, float v) {
        vec.comp[i] = v;
    } DEF_END

    DECL_FUNC(float) vec2_length(const float2 &vec) {
        return sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1]);
    } DEF_END

    DECL_FUNC(float) vec2_dot(const float2 &v1, const float2 &v2) {
        return v1.comp[0] * v2.comp[0] + v1.comp[1] * v2.comp[1];
    } DEF_END

    DECL_FUNC(float2) vec2_normalize(const float2 &vec) {
        float norm = sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1]);
        float2 ret;
        ret.comp[0] = vec.comp[0] / norm;
        ret.comp[1] = vec.comp[1] / norm;
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_normalize_fast(const float2 &vec) {
        float inv_norm = 1.0f / sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1]);
        float2 ret;
        ret.comp[0] = vec.comp[0] * inv_norm;
        ret.comp[1] = vec.comp[1] * inv_norm;
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_sin(const float2 &v) {
        float2 ret;
        ret.comp[0] = sinf(v.comp[0]);
        ret.comp[1] = sinf(v.comp[1]);
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_cos(const float2 &v) {
        float2 ret;
        ret.comp[0] = cosf(v.comp[0]);
        ret.comp[1] = cosf(v.comp[1]);
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_tan(const float2 &v) {
        float2 ret;
        ret.comp[0] = tanf(v.comp[0]);
        ret.comp[1] = tanf(v.comp[1]);
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_asin(const float2 &v) {
        float2 ret;
        ret.comp[0] = asinf(v.comp[0]);
        ret.comp[1] = asinf(v.comp[1]);
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_acos(const float2 &v) {
        float2 ret;
        ret.comp[0] = acosf(v.comp[0]);
        ret.comp[1] = acosf(v.comp[1]);
        return ret;
    } DEF_END

    DECL_FUNC(float2) vec2_atan(const float2 &v) {
        float2 ret;
        ret.comp[0] = atanf(v.comp[0]);
        ret.comp[1] = atanf(v.comp[1]);
        return ret;
    } DEF_END

    // vec3
    DECL_FUNC(void) vec3_init1(float4 &vec, float val) {
        vec.comp[0] = vec.comp[1] = vec.comp[2] = val;
    } DEF_END

    DECL_FUNC(void) vec3_init3(float4 &vec, float v0, float v1, float v2) {
        vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2;
    } DEF_END

    DECL_FUNC(bool) vec3_eq_vec3(const float4 &v1, const float4 &v2) {
        return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2];
    } DEF_END

    DECL_FUNC(float4) vec3_add_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] + v2.comp[0];
        ret.comp[1] = v1.comp[1] + v2.comp[1];
        ret.comp[2] = v1.comp[2] + v2.comp[2];
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_sub_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] - v2.comp[0];
        ret.comp[1] = v1.comp[1] - v2.comp[1];
        ret.comp[2] = v1.comp[2] - v2.comp[2];
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_mul_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] * v2.comp[0];
        ret.comp[1] = v1.comp[1] * v2.comp[1];
        ret.comp[2] = v1.comp[2] * v2.comp[2];
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_div_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] / v2.comp[0];
        ret.comp[1] = v1.comp[1] / v2.comp[1];
        ret.comp[2] = v1.comp[2] / v2.comp[2];
        return ret;
    } DEF_END

    DECL_FUNC(float) vec3_get(const float4 &vec, int i) {
        return vec.comp[i];
    } DEF_END

    DECL_FUNC(void) vec3_set(float4 &vec, int i, float v) {
        vec.comp[i] = v;
    } DEF_END

    DECL_FUNC(float) vec3_length(const float4 &vec) {
        return sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] + vec.comp[2] * vec.comp[2]);
    } DEF_END

    DECL_FUNC(float) vec3_dot(const float4 &v1, const float4 &v2) {
        return v1.comp[0] * v2.comp[0] + v1.comp[1] * v2.comp[1] + v1.comp[2] * v2.comp[2];
    } DEF_END

    DECL_FUNC(float4) vec3_cross(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[1] * v2.comp[2] - v1.comp[2] * v2.comp[1];
        ret.comp[1] = v1.comp[2] * v2.comp[0] - v1.comp[0] * v2.comp[2];
        ret.comp[2] = v1.comp[0] * v2.comp[1] - v1.comp[1] * v2.comp[0];
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_normalize(const float4 &vec) {
        float norm = sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] + vec.comp[2] * vec.comp[2]);
        float4 ret;
        ret.comp[0] = vec.comp[0] / norm;
        ret.comp[1] = vec.comp[1] / norm;
        ret.comp[2] = vec.comp[2] / norm;
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_normalize_fast(const float4 &vec) {
        float inv_norm = 1.0f / sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] + vec.comp[2] * vec.comp[2]);
        float4 ret;
        ret.comp[0] = vec.comp[0] * inv_norm;
        ret.comp[1] = vec.comp[1] * inv_norm;
        ret.comp[2] = vec.comp[2] * inv_norm;
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_sin(const float4 &v) {
        float4 ret;
        ret.comp[0] = sinf(v.comp[0]);
        ret.comp[1] = sinf(v.comp[1]);
        ret.comp[2] = sinf(v.comp[2]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_cos(const float4 &v) {
        float4 ret;
        ret.comp[0] = cosf(v.comp[0]);
        ret.comp[1] = cosf(v.comp[1]);
        ret.comp[2] = cosf(v.comp[2]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_tan(const float4 &v) {
        float4 ret;
        ret.comp[0] = tanf(v.comp[0]);
        ret.comp[1] = tanf(v.comp[1]);
        ret.comp[2] = tanf(v.comp[2]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_asin(const float4 &v) {
        float4 ret;
        ret.comp[0] = asinf(v.comp[0]);
        ret.comp[1] = asinf(v.comp[1]);
        ret.comp[2] = asinf(v.comp[2]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_acos(const float4 &v) {
        float4 ret;
        ret.comp[0] = acosf(v.comp[0]);
        ret.comp[1] = acosf(v.comp[1]);
        ret.comp[2] = acosf(v.comp[2]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec3_atan(const float4 &v) {
        float4 ret;
        ret.comp[0] = atanf(v.comp[0]);
        ret.comp[1] = atanf(v.comp[1]);
        ret.comp[2] = atanf(v.comp[2]);
        return ret;
    } DEF_END

    // vec4
    DECL_FUNC(void) vec4_init1(float4 &vec, float val) {
        vec.comp[0] = vec.comp[1] = vec.comp[2] = vec.comp[3] = val;
    } DEF_END

    DECL_FUNC(void) vec4_init4(float4 &vec, float v0, float v1, float v2, float v3) {
        vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2; vec.comp[3] = v3;
    } DEF_END

    DECL_FUNC(bool) vec4_eq_vec4(const float4 &v1, const float4 &v2) {
        return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2] && v1.comp[3] == v2.comp[3];
    } DEF_END

    DECL_FUNC(float4) vec4_add_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] + v2.comp[0];
        ret.comp[1] = v1.comp[1] + v2.comp[1];
        ret.comp[2] = v1.comp[2] + v2.comp[2];
        ret.comp[3] = v1.comp[3] + v2.comp[3];
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_sub_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] - v2.comp[0];
        ret.comp[1] = v1.comp[1] - v2.comp[1];
        ret.comp[2] = v1.comp[2] - v2.comp[2];
        ret.comp[3] = v1.comp[3] - v2.comp[3];
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_mul_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] * v2.comp[0];
        ret.comp[1] = v1.comp[1] * v2.comp[1];
        ret.comp[2] = v1.comp[2] * v2.comp[2];
        ret.comp[3] = v1.comp[3] * v2.comp[3];
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_div_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] / v2.comp[0];
        ret.comp[1] = v1.comp[1] / v2.comp[1];
        ret.comp[2] = v1.comp[2] / v2.comp[2];
        ret.comp[3] = v1.comp[3] / v2.comp[3];
        return ret;
    } DEF_END

    DECL_FUNC(float) vec4_get(const float4 &vec, int i) {
        return vec.comp[i];
    } DEF_END

    DECL_FUNC(void) vec4_set(float4 &vec, int i, float v) {
        vec.comp[i] = v;
    } DEF_END

    DECL_FUNC(float) vec4_length(const float4 &vec) {
        return sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] +
            vec.comp[2] * vec.comp[2] + vec.comp[3] * vec.comp[3]);
    } DEF_END

    DECL_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2) {
        return v1.comp[0] * v2.comp[0] + v1.comp[1] * v2.comp[1] +
            v1.comp[2] * v2.comp[2] + v1.comp[3] * v2.comp[3];
    } DEF_END

    DECL_FUNC(float4) vec4_normalize(const float4 &vec) {
        float norm = sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] +
            vec.comp[2] * vec.comp[2] + vec.comp[3] * vec.comp[3]);
        float4 ret;
        ret.comp[0] = vec.comp[0] / norm;
        ret.comp[1] = vec.comp[1] / norm;
        ret.comp[2] = vec.comp[2] / norm;
        ret.comp[3] = vec.comp[3] / norm;
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_normalize_fast(const float4 &vec) {
        float inv_norm = 1.0f / sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] +
            vec.comp[2] * vec.comp[2] + vec.comp[3] * vec.comp[3]);
        float4 ret;
        ret.comp[0] = vec.comp[0] * inv_norm;
        ret.comp[1] = vec.comp[1] * inv_norm;
        ret.comp[2] = vec.comp[2] * inv_norm;
        ret.comp[3] = vec.comp[3] * inv_norm;
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_sin(const float4 &v) {
        float4 ret;
        ret.comp[0] = sinf(v.comp[0]);
        ret.comp[1] = sinf(v.comp[1]);
        ret.comp[2] = sinf(v.comp[2]);
        ret.comp[3] = sinf(v.comp[3]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_cos(const float4 &v) {
        float4 ret;
        ret.comp[0] = cosf(v.comp[0]);
        ret.comp[1] = cosf(v.comp[1]);
        ret.comp[2] = cosf(v.comp[2]);
        ret.comp[3] = cosf(v.comp[3]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_tan(const float4 &v) {
        float4 ret;
        ret.comp[0] = tanf(v.comp[0]);
        ret.comp[1] = tanf(v.comp[1]);
        ret.comp[2] = tanf(v.comp[2]);
        ret.comp[3] = tanf(v.comp[3]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_asin(const float4 &v) {
        float4 ret;
        ret.comp[0] = asinf(v.comp[0]);
        ret.comp[1] = asinf(v.comp[1]);
        ret.comp[2] = asinf(v.comp[2]);
        ret.comp[3] = asinf(v.comp[3]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_acos(const float4 &v) {
        float4 ret;
        ret.comp[0] = acosf(v.comp[0]);
        ret.comp[1] = acosf(v.comp[1]);
        ret.comp[2] = acosf(v.comp[2]);
        ret.comp[3] = acosf(v.comp[3]);
        return ret;
    } DEF_END

    DECL_FUNC(float4) vec4_atan(const float4 &v) {
        float4 ret;
        ret.comp[0] = atanf(v.comp[0]);
        ret.comp[1] = atanf(v.comp[1]);
        ret.comp[2] = atanf(v.comp[2]);
        ret.comp[3] = atanf(v.comp[3]);
        return ret;
    } DEF_END

    // mat2
    DECL_FUNC(void) mat2_init1(float4 &vec, float val) {
        vec.comp[0] = vec.comp[3] = val;
        vec.comp[1] = vec.comp[2] = 0;
    } DEF_END

    DECL_FUNC(void) mat2_init2(float4 &vec, const float2 &v01, const float2 &v23) {
        vec.vec2[0] = v01;
        vec.vec2[1] = v23;
    } DEF_END

    DECL_FUNC(void) mat2_init4(float4 &vec, float v0, float v1, float v2, float v3) {
        vec.comp[0] = v0; vec.comp[1] = v1;
        vec.comp[2] = v2; vec.comp[3] = v3;
    } DEF_END

    DECL_FUNC(bool) mat2_eq_mat2(const float4 &m1, const float4 &m2) {
        return m1.comp[0] == m2.comp[0] && m1.comp[1] == m2.comp[1] &&
            m1.comp[2] == m2.comp[2] && m1.comp[3] == m2.comp[3];
    }

    DECL_FUNC(float4) mat2_add_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] + v2.comp[0];
        ret.comp[1] = v1.comp[1] + v2.comp[1];
        ret.comp[2] = v1.comp[2] + v2.comp[2];
        ret.comp[3] = v1.comp[3] + v2.comp[3];
        return ret;
    } DEF_END

    DECL_FUNC(float4) mat2_sub_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] - v2.comp[0];
        ret.comp[1] = v1.comp[1] - v2.comp[1];
        ret.comp[2] = v1.comp[2] - v2.comp[2];
        ret.comp[3] = v1.comp[3] - v2.comp[3];
        return ret;
    } DEF_END

    DECL_FUNC(float4) mat2_mul_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp2[0][0] = v1.comp2[0][0] * v2.comp2[0][0] + v1.comp2[0][1] * v2.comp2[1][0];
        ret.comp2[0][1] = v1.comp2[0][0] * v2.comp2[0][1] + v1.comp2[0][1] * v2.comp2[1][1];
        ret.comp2[1][0] = v1.comp2[1][0] * v2.comp2[0][0] + v1.comp2[1][1] * v2.comp2[1][0];
        ret.comp2[1][1] = v1.comp2[1][0] * v2.comp2[0][1] + v1.comp2[1][1] * v2.comp2[1][1];
        return ret;
    } DEF_END

    DECL_FUNC(float4) mat2_div_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.comp[0] = v1.comp[0] / v2.comp[0];
        ret.comp[1] = v1.comp[1] / v2.comp[1];
        ret.comp[2] = v1.comp[2] / v2.comp[2];
        ret.comp[3] = v1.comp[3] / v2.comp[3];
        return ret;
    } DEF_END

    DECL_FUNC(float2) mat2_get(const float4 &vec, int i) {
        return vec.vec2[i];
    } DEF_END

    DECL_FUNC(void) mat2_set(float4 &vec, int i, const float2 &v) {
        vec.vec2[i] = v;
    } DEF_END

    DECL_FUNC(float4) mat2_comp_mul(const float4 &m1, const float4 &m2) {
        float4 ret;
        ret.comp[0] = m1.comp[0] * m2.comp[0];
        ret.comp[1] = m1.comp[1] * m2.comp[1];
        ret.comp[2] = m1.comp[2] * m2.comp[2];
        ret.comp[3] = m1.comp[3] * m2.comp[3];
        return ret;
    } DEF_END

    // mat3
    DECL_FUNC(void) mat3_init1(float12 &vec, float val) {
        vec.comp4[0][0] = vec.comp4[1][1] = vec.comp4[2][2] = val;
        vec.comp4[0][1] = vec.comp4[0][2] =
            vec.comp4[1][0] = vec.comp4[1][2] =
            vec.comp4[2][0] = vec.comp4[2][1] = 0;
    } DEF_END

    DECL_FUNC(void) mat3_init9(float12 &vec, float v00, float v01, float v02,
                                             float v10, float v11, float v12,
                                             float v20, float v21, float v22) {
        vec.comp4[0][0] = v00; vec.comp4[0][1] = v01; vec.comp4[0][2] = v02;
        vec.comp4[1][0] = v10; vec.comp4[1][1] = v11; vec.comp4[1][2] = v12;
        vec.comp4[2][0] = v20; vec.comp4[2][1] = v21; vec.comp4[2][2] = v22;
    } DEF_END

    DECL_FUNC(void) mat3_init3(float12 &vec, const float4 &v0, const float4 &v1, const float4 &v2) {
        vec.vec4[0] = v0;
        vec.vec4[1] = v1;
        vec.vec4[2] = v2;
    } DEF_END

    DECL_FUNC(bool) mat3_eq_mat3(const float12 &m1, const float12 &m2) {
        return m1.comp[0] == m2.comp[0] && m1.comp[1] == m2.comp[1] && m1.comp[2] == m2.comp[2] &&
            m1.comp[3] == m2.comp[3] && m1.comp[4] == m2.comp[4] && m1.comp[5] == m2.comp[5] &&
            m1.comp[6] == m2.comp[6] && m1.comp[7] == m2.comp[7] && m1.comp[8] == m2.comp[8];
    }

    DECL_FUNC(float12) mat3_add_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ret.comp4[i][j] = v1.comp4[i][j] + v2.comp4[i][j];
            }
        }
        return ret;
    } DEF_END

    DECL_FUNC(float12) mat3_sub_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ret.comp4[i][j] = v1.comp4[i][j] - v2.comp4[i][j];
            }
        }
        return ret;
    } DEF_END

    DECL_FUNC(float12) mat3_mul_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ret.comp4[i][j] = (v1.comp4[i][0] * v2.comp4[0][j])
                    + (v1.comp4[i][1] * v2.comp4[1][j])
                    + (v1.comp4[i][2] * v2.comp4[2][j]);
            }
        }
        return ret;
    } DEF_END

    DECL_FUNC(float12) mat3_div_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ret.comp4[i][j] = v1.comp4[i][j] / v2.comp4[i][j];
            }
        }
        return ret;
    } DEF_END

    DECL_FUNC(float12) mat3_mul_float(const float12 &v1, float v2) {
        float12 ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ret.comp4[i][j] = v1.comp4[i][j] * v2;
            }
        }
        return ret;
    } DEF_END

    DECL_FUNC(float12) mat3_div_float(const float12 &v1, float v2) {
        float12 ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ret.comp4[i][j] = v1.comp4[i][j] / v2;
            }
        }
        return ret;
    } DEF_END

    DECL_FUNC(float4) mat3_get(const float12 &vec, int i) {
        return vec.vec4[i];
    } DEF_END

        DECL_FUNC(void) mat3_set(float12 &vec, int i, const float4 &v) {
        vec.vec4[i] = v;
    } DEF_END

    DECL_FUNC(float12) mat3_comp_mul(const float12 &v1, const float12 &v2) {
        float12 ret;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ret.comp4[i][j] = v1.comp4[i][j] * v2.comp4[i][j];
            }
        }
        return ret;
    } DEF_END

    // mat4
    DECL_FUNC(void) mat4_init1(float16 &vec, float val) {
        vec.comp4[0][0] = vec.comp4[1][1] = vec.comp4[2][2] = vec.comp4[3][3] = val;
        vec.comp4[0][1] = vec.comp4[0][2] = vec.comp4[0][3] =
            vec.comp4[1][0] = vec.comp4[1][2] = vec.comp4[1][3] =
            vec.comp4[2][0] = vec.comp4[2][1] = vec.comp4[2][3] =
            vec.comp4[3][0] = vec.comp4[3][1] = vec.comp4[3][2] = 0;
    } DEF_END

    DECL_FUNC(void) mat4_init16(float16 &vec, float v00, float v01, float v02, float v03,
                                              float v10, float v11, float v12, float v13,
                                              float v20, float v21, float v22, float v23,
                                              float v30, float v31, float v32, float v33) {
        vec.comp4[0][0] = v00; vec.comp4[0][1] = v01; vec.comp4[0][2] = v02; vec.comp4[0][3] = v03;
        vec.comp4[1][0] = v10; vec.comp4[1][1] = v11; vec.comp4[1][2] = v12; vec.comp4[1][3] = v13;
        vec.comp4[2][0] = v20; vec.comp4[2][1] = v21; vec.comp4[2][2] = v22; vec.comp4[2][3] = v23;
        vec.comp4[3][0] = v30; vec.comp4[3][1] = v31; vec.comp4[3][2] = v32; vec.comp4[3][3] = v33;
    } DEF_END

    DECL_FUNC(void) mat4_init4(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3) {
        vec.vec4[0] = v0;
        vec.vec4[1] = v1;
        vec.vec4[2] = v2;
        vec.vec4[3] = v3;
    } DEF_END

    DECL_FUNC(bool) mat4_eq_mat4(const float16 &m1, const float16 &m2) {
        return m1.comp[0] == m2.comp[0] && m1.comp[1] == m2.comp[1] && m1.comp[2] == m2.comp[2] && m1.comp[3] == m2.comp[3] &&
            m1.comp[4] == m2.comp[4] && m1.comp[5] == m2.comp[5] && m1.comp[6] == m2.comp[6] && m1.comp[7] == m2.comp[7] &&
            m1.comp[8] == m2.comp[8] && m1.comp[9] == m2.comp[9] && m1.comp[10] == m2.comp[10] && m1.comp[11] == m2.comp[11] &&
            m1.comp[12] == m2.comp[12] && m1.comp[13] == m2.comp[13] && m1.comp[14] == m2.comp[14] && m1.comp[15] == m2.comp[15];
    }

    DECL_FUNC(float16) mat4_add_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        for (int i = 0; i < 16; i++) {
            ret.comp[i] = v1.comp[i] + v2.comp[i];
        }
        return ret;
    } DEF_END

    DECL_FUNC(float16) mat4_sub_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        for (int i = 0; i < 16; i++) {
            ret.comp[i] = v1.comp[i] - v2.comp[i];
        }
        return ret;
    } DEF_END

    DECL_FUNC(float16) mat4_mul_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        for (int i = 0; i < 16; i += 4) {
            for (int j = 0; j < 4; j++) {
                ret.comp[i + j] = (v1.comp[i + 0] * v2.comp[j + 0])
                    + (v1.comp[i + 1] * v2.comp[j + 4])
                    + (v1.comp[i + 2] * v2.comp[j + 8])
                    + (v1.comp[i + 3] * v2.comp[j + 12]);
            }
        }
        return ret;
    } DEF_END

    DECL_FUNC(float16) mat4_div_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        for (int i = 0; i < 16; i++) {
            ret.comp[i] = v1.comp[i] / v2.comp[i];
        }
        return ret;
    } DEF_END

    DECL_FUNC(float16) mat4_mul_float(const float16 &v1, float v2) {
        float16 ret;
        for (int i = 0; i < 16; i++) {
            ret.comp[i] = v1.comp[i] * v2;
        }
        return ret;
    } DEF_END

    DECL_FUNC(float16) mat4_div_float(const float16 &v1, float v2) {
        float16 ret;
        for (int i = 0; i < 16; i++) {
            ret.comp[i] = v1.comp[i] / v2;
        }
        return ret;
    } DEF_END

    DECL_FUNC(float4) mat4_get(const float16 &vec, int i) {
        return vec.vec4[i];
    } DEF_END

        DECL_FUNC(void) mat4_set(float16 &vec, int i, const float4 &v) {
        vec.vec4[i] = v;
    } DEF_END

    DECL_FUNC(float16) mat4_comp_mul(const float16 &v1, const float16 &v2) {
        float16 ret;
        for (int i = 0; i < 16; i++) {
            ret.comp[i] = v1.comp[i] * v2.comp[i];
        }
        return ret;
    } DEF_END

    // comb
    DECL_FUNC(float4) mat4_mul_vec4(const float16 &v1, const float4 &v2) {
        float4 ret;
        for (int i = 0; i < 4; i++) {
            ret.comp[i] = v1.comp4[i][0] * v2.comp[0] +
                v1.comp4[i][1] * v2.comp[1] +
                v1.comp4[i][2] * v2.comp[2] +
                v1.comp4[i][3] * v2.comp[3];
        }
        return ret;
    } DEF_END
}
}

#else

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
    DECL_FUNC(void) vec3_init1(float4 &vec, float val);
    DECL_FUNC(void) vec3_init3(float4 &vec, float v0, float v1, float v2);
    DECL_FUNC(bool) vec3_eq_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_add_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_sub_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_mul_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_div_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float) vec3_get(const float4 &vec, int i);
    DECL_FUNC(void) vec3_set(float4 &vec, int i, float v);
    DECL_FUNC(float) vec3_length(const float4 &vec);
    DECL_FUNC(float) vec3_dot(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_cross(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_normalize(const float4 &vec);
    DECL_FUNC(float4) vec3_normalize_fast(const float4 &vec);
    DECL_FUNC(float4) vec3_sin(const float4 &v);
    DECL_FUNC(float4) vec3_cos(const float4 &v);
    DECL_FUNC(float4) vec3_tan(const float4 &v);
    DECL_FUNC(float4) vec3_asin(const float4 &v);
    DECL_FUNC(float4) vec3_acos(const float4 &v);
    DECL_FUNC(float4) vec3_atan(const float4 &v);

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

    // mat3
    DECL_FUNC(void) mat3_init1(float12 &vec, float val);
    DECL_FUNC(void) mat3_init9(float12 &vec, float v00, float v01, float v02,
                                             float v10, float v11, float v12,
                                             float v20, float v21, float v22);
    DECL_FUNC(void) mat3_init3(float12 &vec, const float4 &v0, const float4 &v1, const float4 &v2);
    DECL_FUNC(bool) mat3_eq_mat3(const float12 &m1, const float12 &m2);
    DECL_FUNC(float12) mat3_add_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_sub_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_mul_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_div_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_mul_float(const float12 &v1, float v2);
    DECL_FUNC(float12) mat3_div_float(const float12 &v1, float v2);
    DECL_FUNC(float4) mat3_get(const float12 &vec, int i);
    DECL_FUNC(void) mat3_set(float12 &vec, int i, const float4 &v);
    DECL_FUNC(float12) mat3_comp_mul(const float12 &v1, const float12 &v2);

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

    // comb
    DECL_FUNC(float4) mat4_mul_vec4(const float16 &v1, const float4 &v2);
}
}

#endif