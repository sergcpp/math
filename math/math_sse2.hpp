#include "math_ref.hpp"

#if !defined(MATH_NO_INLINE) || defined(MATH_IMPL)
#pragma once

#ifdef __GNUC__
#pragma GCC push_options
#pragma GCC target ("sse2")
#endif

namespace math {
namespace sse2 {
    using namespace ref;

    const __m128 zero_last_mask = _mm_castsi128_ps(_mm_set_epi32(0, 0xffffffff, 0xffffffff, 0xffffffff));

    // vec3
    DEF_FUNC(void) vec3_init1(float4 &vec, float val) {
        vec.vec = _mm_set_ps1(val);
    } DEF_END

    DEF_FUNC(void) vec3_init3(float4 &vec, float v0, float v1, float v2) {
        vec.vec = _mm_set_ps(0, v2, v1, v0);
    } DEF_END

    DEF_FUNC(float4) vec3_add_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_add_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_sub_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_sub_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_mul_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_mul_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_div_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_div_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float) vec3_length(const float4 &v) {
        __m128 r1, r2;
        r1 = _mm_mul_ps(v.vec, v.vec);
        r1 = _mm_and_ps(r1, zero_last_mask);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        return _mm_cvtss_f32(_mm_sqrt_ss(r1));
    } DEF_END

    DEF_FUNC(float) vec3_dot(const float4 &v1, const float4 &v2) {
        __m128 r1, r2;
        r1 = _mm_mul_ps(v1.vec, v2.vec);
        r1 = _mm_and_ps(r1, zero_last_mask);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        return _mm_cvtss_f32(r1);
    } DEF_END

    DEF_FUNC(float4) vec3_cross(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v1.vec, v1.vec, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(v2.vec, v2.vec, _MM_SHUFFLE(3, 1, 0, 2))),
                             _mm_mul_ps(_mm_shuffle_ps(v1.vec, v1.vec, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(v2.vec, v2.vec, _MM_SHUFFLE(3, 0, 2, 1))));
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_normalize(const float4 &v) {
        __m128 r1, r2;
        r1 = _mm_mul_ps(v.vec, v.vec);
        r1 = _mm_and_ps(r1, zero_last_mask);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        float4 ret;
        ret.vec = _mm_div_ps(v.vec, _mm_sqrt_ps(r1));
        return ret;
    } DEF_END

    // vec4
    DEF_FUNC(void) vec4_init1(float4 &vec, float val) {
        vec.vec = _mm_set_ps1(val);
    } DEF_END

    DEF_FUNC(void) vec4_init4(float4 &vec, float v0, float v1, float v2, float v3) {
        vec.vec = _mm_set_ps(v3, v2, v1, v0);
    } DEF_END

    DEF_FUNC(bool) vec4_eq_vec4(const float4 &v1, const float4 &v2) {
        __m128i vcmp = _mm_castps_si128(_mm_cmpneq_ps(v1.vec, v2.vec));
        int test = _mm_movemask_epi8(vcmp);
        return test == 0;
    } DEF_END

    DEF_FUNC(float4) vec4_add_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_add_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec4_sub_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_sub_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec4_mul_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_mul_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec4_div_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_div_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float) vec4_length(const float4 &v) {
        __m128 r1, r2;
        r1 = _mm_mul_ps(v.vec, v.vec);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        return _mm_cvtss_f32(_mm_sqrt_ss(r1));
    } DEF_END

    DEF_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2) {
        __m128 r1, r2;
        r1 = _mm_mul_ps(v1.vec, v2.vec);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        return _mm_cvtss_f32(r1);
    } DEF_END

    DEF_FUNC(float4) vec4_normalize(const float4 &v) {
        __m128 r1, r2;
        r1 = _mm_mul_ps(v.vec, v.vec);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        float4 ret;
        ret.vec = _mm_div_ps(v.vec, _mm_sqrt_ps(r1));
        return ret;
    } DEF_END

    // mat2
    DEF_FUNC(void) mat2_init4(float4 &vec, float v0, float v1, float v2, float v3) {
        vec.vec = _mm_set_ps(v3, v2, v1, v0);
    } DEF_END

    DEF_FUNC(float4) mat2_add_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_add_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) mat2_sub_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_sub_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) mat2_mul_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v1.vec, v1.vec, _MM_SHUFFLE(2, 2, 0, 0)),
                                        _mm_shuffle_ps(v2.vec, v2.vec, _MM_SHUFFLE(1, 0, 1, 0))),
                             _mm_mul_ps(_mm_shuffle_ps(v1.vec, v1.vec, _MM_SHUFFLE(3, 3, 1, 1)),
                                        _mm_shuffle_ps(v2.vec, v2.vec, _MM_SHUFFLE(3, 2, 3, 2))));
        return ret;
    } DEF_END

    DEF_FUNC(float4) mat2_div_mat2(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = _mm_div_ps(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) mat2_comp_mul(const float4 &m1, const float4 &m2) {
        float4 ret;
        ret.vec = _mm_mul_ps(m1.vec, m2.vec);
        return ret;
    } DEF_END

    // mat3
    DEF_FUNC(void) mat3_init1(float12 &vec, float val) {
        vec.vec[0] = _mm_set_ps(0, 0, 0, val);
        vec.vec[1] = _mm_set_ps(0, 0, val, 0);
        vec.vec[2] = _mm_set_ps(0, val, 0, 0);
    } DEF_END

    DEF_FUNC(void) mat3_init9(float12 &vec, float v00, float v01, float v02,
                                             float v10, float v11, float v12,
                                             float v20, float v21, float v22) {
        vec.vec[0] = _mm_set_ps(0, v02, v01, v00);
        vec.vec[1] = _mm_set_ps(0, v12, v11, v10);
        vec.vec[2] = _mm_set_ps(0, v22, v21, v20);
    } DEF_END

    DEF_FUNC(void) mat3_init3(float12 &vec, const float4 &v0, const float4 &v1, const float4 &v2) {
        vec.vec[0] = v0.vec;
        vec.vec[1] = v1.vec;
        vec.vec[2] = v2.vec;
    } DEF_END

    DEF_FUNC(float12) mat3_add_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;
        ret.vec[0] = _mm_add_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_add_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_add_ps(v1.vec[2], v2.vec[2]);
        return ret;
    } DEF_END

    DEF_FUNC(float12) mat3_sub_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;
        ret.vec[0] = _mm_sub_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_sub_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_sub_ps(v1.vec[2], v2.vec[2]);
        return ret;
    } DEF_END

    DEF_FUNC(float12) mat3_mul_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;

        __m128 r1, r2,
               B0 = v2.vec[0], B1 = v2.vec[1], B2 = v2.vec[2];

        r1 = _mm_mul_ps(_mm_shuffle_ps(v1.vec[0], v1.vec[0], 0x00), B0);
        r2 = _mm_mul_ps(_mm_shuffle_ps(v1.vec[1], v1.vec[1], 0x00), B0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[0], v1.vec[0], 0x55), B1));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[1], v1.vec[1], 0x55), B1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[0], v1.vec[0], 0xAA), B2));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[1], v1.vec[1], 0xAA), B2));
        ret.vec[0] = r1;
        ret.vec[1] = r2;

        r1 = _mm_mul_ps(_mm_shuffle_ps(v1.vec[2], v1.vec[2], 0x00), B0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[2], v1.vec[2], 0x55), B1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[2], v1.vec[2], 0xAA), B2));
        ret.vec[2] = r1;

        return ret;
    } DEF_END

    DEF_FUNC(float12) mat3_div_mat3(const float12 &v1, const float12 &v2) {
        float12 ret;
        ret.vec[0] = _mm_div_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_div_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_div_ps(v1.vec[2], v2.vec[2]);
        return ret;
    } DEF_END

    DEF_FUNC(float12) mat3_comp_mul(const float12 &v1, const float12 &v2) {
        float12 ret;
        ret.vec[0] = _mm_mul_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_mul_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_mul_ps(v1.vec[2], v2.vec[2]);
        return ret;
    } DEF_END

    // mat4
    DEF_FUNC(void) mat4_init1(float16 &vec, float val) {
        vec.vec[0] = _mm_set_ps(0, 0, 0, val);
        vec.vec[1] = _mm_set_ps(0, 0, val, 0);
        vec.vec[2] = _mm_set_ps(0, val, 0, 0);
        vec.vec[3] = _mm_set_ps(val, 0, 0, 0);
    } DEF_END

    DEF_FUNC(void) mat4_init16(float16 &vec, float v00, float v01, float v02, float v03,
                                              float v10, float v11, float v12, float v13,
                                              float v20, float v21, float v22, float v23,
                                              float v30, float v31, float v32, float v33) {
        vec.vec[0] = _mm_set_ps(v03, v02, v01, v00);
        vec.vec[1] = _mm_set_ps(v13, v12, v11, v10);
        vec.vec[2] = _mm_set_ps(v23, v22, v21, v20);
        vec.vec[3] = _mm_set_ps(v33, v32, v31, v30);
    } DEF_END

    DEF_FUNC(void) mat4_init4(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3) {
        vec.vec[0] = v0.vec;
        vec.vec[1] = v1.vec;
        vec.vec[2] = v2.vec;
        vec.vec[3] = v3.vec;
    } DEF_END

    DEF_FUNC(float16) mat4_add_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec[0] = _mm_add_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_add_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_add_ps(v1.vec[2], v2.vec[2]);
        ret.vec[3] = _mm_add_ps(v1.vec[3], v2.vec[3]);
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_sub_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec[0] = _mm_sub_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_sub_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_sub_ps(v1.vec[2], v2.vec[2]);
        ret.vec[3] = _mm_sub_ps(v1.vec[3], v2.vec[3]);
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_mul_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;

        __m128 r1, r2,
               B0 = v2.vec[0], B1 = v2.vec[1], B2 = v2.vec[2], B3 = v2.vec[3];

        r1 = _mm_mul_ps(_mm_shuffle_ps(v1.vec[0], v1.vec[0], 0x00), B0);
        r2 = _mm_mul_ps(_mm_shuffle_ps(v1.vec[1], v1.vec[1], 0x00), B0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[0], v1.vec[0], 0x55), B1));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[1], v1.vec[1], 0x55), B1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[0], v1.vec[0], 0xAA), B2));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[1], v1.vec[1], 0xAA), B2));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[0], v1.vec[0], 0xFF), B3));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[1], v1.vec[1], 0xFF), B3));
        ret.vec[0] = r1;
        ret.vec[1] = r2;

        r1 = _mm_mul_ps(_mm_shuffle_ps(v1.vec[2], v1.vec[2], 0x00), B0);
        r2 = _mm_mul_ps(_mm_shuffle_ps(v1.vec[3], v1.vec[3], 0x00), B0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[2], v1.vec[2], 0x55), B1));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[3], v1.vec[3], 0x55), B1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[2], v1.vec[2], 0xAA), B2));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[3], v1.vec[3], 0xAA), B2));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v1.vec[2], v1.vec[2], 0xFF), B3));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v1.vec[3], v1.vec[3], 0xFF), B3));
        ret.vec[2] = r1;
        ret.vec[3] = r2;

        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_div_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec[0] = _mm_div_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_div_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_div_ps(v1.vec[2], v2.vec[2]);
        ret.vec[3] = _mm_div_ps(v1.vec[3], v2.vec[3]);
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_mul_float(const float16 &v1, float v2) {
        float16 ret;
        __m128 _v2 = _mm_set1_ps(v2);
        ret.vec[0] = _mm_mul_ps(v1.vec[0], _v2);
        ret.vec[1] = _mm_mul_ps(v1.vec[1], _v2);
        ret.vec[2] = _mm_mul_ps(v1.vec[2], _v2);
        ret.vec[3] = _mm_mul_ps(v1.vec[3], _v2);
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_div_float(const float16 &v1, float v2) {
        float16 ret;
        __m128 _v2 = _mm_set1_ps(v2);
        ret.vec[0] = _mm_div_ps(v1.vec[0], _v2);
        ret.vec[1] = _mm_div_ps(v1.vec[1], _v2);
        ret.vec[2] = _mm_div_ps(v1.vec[2], _v2);
        ret.vec[3] = _mm_div_ps(v1.vec[3], _v2);
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_comp_mul(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec[0] = _mm_mul_ps(v1.vec[0], v2.vec[0]);
        ret.vec[1] = _mm_mul_ps(v1.vec[1], v2.vec[1]);
        ret.vec[2] = _mm_mul_ps(v1.vec[2], v2.vec[2]);
        ret.vec[3] = _mm_mul_ps(v1.vec[3], v2.vec[3]);
        return ret;
    } DEF_END
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#else

namespace math {
namespace sse2 {
    using namespace ref;

    // vec3
    DECL_FUNC(void) vec3_init1(float4 &vec, float val);
    DECL_FUNC(void) vec3_init3(float4 &vec, float v0, float v1, float v2);
    DECL_FUNC(float4) vec3_add_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_sub_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_mul_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_div_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float) vec3_length(const float4 &v);
    DECL_FUNC(float) vec3_dot(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_cross(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_normalize(const float4 &v);

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
    DECL_FUNC(void) mat3_init1(float12 &vec, float val);
    DECL_FUNC(void) mat3_init9(float12 &vec, float v00, float v01, float v02,
                                             float v10, float v11, float v12,
                                             float v20, float v21, float v22);
    DECL_FUNC(void) mat3_init3(float12 &vec, const float4 &v0, const float4 &v1, const float4 &v2);
    DECL_FUNC(float12) mat3_add_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_sub_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_mul_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_div_mat3(const float12 &v1, const float12 &v2);
    DECL_FUNC(float12) mat3_comp_mul(const float12 &v1, const float12 &v2);

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
}
}

#endif