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

    // should be faster than _mm_setr_ps as it uses only 3 loads
    inline __m128 load_float3(const float3& v) {
        __m128 x = _mm_load_ss(&v.comp[0]);
        __m128 y = _mm_load_ss(&v.comp[1]);
        __m128 z = _mm_load_ss(&v.comp[2]);
        __m128 xy = _mm_movelh_ps(x, y);
        return _mm_shuffle_ps(xy, z, _MM_SHUFFLE(2, 0, 2, 0));
    }

    inline float3 save_float3(const __m128 &v) {
        union {
            float3 f;
            __m128 v;
        } res;
        res.v = v;
        return res.f;
    }

    // vec3
    DEF_FUNC(float3) vec3_add_vec3(const float3 &v1, const float3 &v2) {
        __m128 res = _mm_add_ps(load_float3(v1), load_float3(v2));
        return save_float3(res);
    } DEF_END

    DEF_FUNC(float3) vec3_sub_vec3(const float3 &v1, const float3 &v2) {
        __m128 res = _mm_sub_ps(load_float3(v1), load_float3(v2));
        return save_float3(res);
    } DEF_END

    DEF_FUNC(float3) vec3_mul_vec3(const float3 &v1, const float3 &v2) {
        __m128 res = _mm_mul_ps(load_float3(v1), load_float3(v2));
        return save_float3(res);
    } DEF_END

    DEF_FUNC(float3) vec3_div_vec3(const float3 &v1, const float3 &v2) {
        __m128 res = _mm_div_ps(load_float3(v1), load_float3(v2));
        return save_float3(res);
    } DEF_END

    DEF_FUNC(float) vec3_length(const float3 &v) {
        __m128 r1, r2;
        __m128 vv = _mm_setr_ps(v.comp[0], v.comp[1], v.comp[2], 0);
        r1 = _mm_mul_ps(vv, vv);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        return _mm_cvtss_f32(_mm_sqrt_ss(r1));
    } DEF_END

    DEF_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2) {
        __m128 r1, r2;
        __m128 vv1 = _mm_setr_ps(v1.comp[0], v1.comp[1], v1.comp[2], 0);
        __m128 vv2 = _mm_setr_ps(v2.comp[0], v2.comp[1], v2.comp[2], 0);
        r1 = _mm_mul_ps(vv1, vv2);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        return _mm_cvtss_f32(r1);
    } DEF_END

    DEF_FUNC(float3) vec3_cross(const float3 &v1, const float3 &v2) {
        __m128 vv1 = _mm_setr_ps(v1.comp[0], v1.comp[1], v1.comp[2], 0);
        __m128 vv2 = _mm_setr_ps(v2.comp[0], v2.comp[1], v2.comp[2], 0);
        __m128 res = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(vv1, vv1, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(vv2, vv2, _MM_SHUFFLE(3, 1, 0, 2))),
                                _mm_mul_ps(_mm_shuffle_ps(vv1, vv1, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(vv2, vv2, _MM_SHUFFLE(3, 0, 2, 1))));
        return save_float3(res);
    } DEF_END

    DEF_FUNC(float3) vec3_normalize(const float3 &v) {
        __m128 r1, r2;
        __m128 vv = _mm_setr_ps(v.comp[0], v.comp[1], v.comp[2], 0);
        r1 = _mm_mul_ps(vv, vv);

        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(2, 3, 0, 1));
        r1 = _mm_add_ps(r1, r2);
        r2 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(0, 1, 2, 3));
        r1 = _mm_add_ps(r1, r2);

        __m128 res = _mm_div_ps(vv, _mm_sqrt_ps(r1));
        return save_float3(res);
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
    DEF_FUNC(float9) mat3_add_mat3(const float9 &v1, const float9 &v2) {
        float9 ret;
        ret.vec3[0] = save_float3(_mm_add_ps(load_float3(v1.vec3[0]), load_float3(v2.vec3[0])));
        ret.vec3[1] = save_float3(_mm_add_ps(load_float3(v1.vec3[1]), load_float3(v2.vec3[1])));
        ret.vec3[2] = save_float3(_mm_add_ps(load_float3(v1.vec3[2]), load_float3(v2.vec3[2])));
        return ret;
    } DEF_END

    DEF_FUNC(float9) mat3_sub_mat3(const float9 &v1, const float9 &v2) {
        float9 ret;
        ret.vec3[0] = save_float3(_mm_sub_ps(load_float3(v1.vec3[0]), load_float3(v2.vec3[0])));
        ret.vec3[1] = save_float3(_mm_sub_ps(load_float3(v1.vec3[1]), load_float3(v2.vec3[1])));
        ret.vec3[2] = save_float3(_mm_sub_ps(load_float3(v1.vec3[2]), load_float3(v2.vec3[2])));
        return ret;
    } DEF_END

    DEF_FUNC(float9) mat3_mul_mat3(const float9 &v1, const float9 &v2) {
        float9 ret;

        __m128 r1, r2,
               A0 = load_float3(v1.vec3[0]), A1 = load_float3(v1.vec3[1]), A2 = load_float3(v1.vec3[2]),
               B0 = load_float3(v2.vec3[0]), B1 = load_float3(v2.vec3[1]), B2 = load_float3(v2.vec3[2]);

        r1 = _mm_mul_ps(_mm_shuffle_ps(B0, B0, 0x00), A0);
        r2 = _mm_mul_ps(_mm_shuffle_ps(B1, B1, 0x00), A0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(B0, B0, 0x55), A1));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(B1, B1, 0x55), A1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(B0, B0, 0xAA), A2));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(B1, B1, 0xAA), A2));
        ret.vec3[0] = save_float3(r1);
        ret.vec3[1] = save_float3(r2);

        r1 = _mm_mul_ps(_mm_shuffle_ps(B2, B2, 0x00), A0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(B2, B2, 0x55), A1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(B2, B2, 0xAA), A2));
        ret.vec3[2] = save_float3(r1);

        return ret;
    } DEF_END

    DEF_FUNC(float9) mat3_div_mat3(const float9 &v1, const float9 &v2) {
        float9 ret;
        ret.vec3[0] = save_float3(_mm_div_ps(load_float3(v1.vec3[0]), load_float3(v2.vec3[0])));
        ret.vec3[1] = save_float3(_mm_div_ps(load_float3(v1.vec3[1]), load_float3(v2.vec3[1])));
        ret.vec3[2] = save_float3(_mm_div_ps(load_float3(v1.vec3[2]), load_float3(v2.vec3[2])));
        return ret;
    } DEF_END

    DEF_FUNC(float9) mat3_comp_mul(const float9 &v1, const float9 &v2) {
        float9 ret;
        ret.vec3[0] = save_float3(_mm_mul_ps(load_float3(v1.vec3[0]), load_float3(v2.vec3[0])));
        ret.vec3[1] = save_float3(_mm_mul_ps(load_float3(v1.vec3[1]), load_float3(v2.vec3[1])));
        ret.vec3[2] = save_float3(_mm_mul_ps(load_float3(v1.vec3[2]), load_float3(v2.vec3[2])));
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
               A0 = v1.vec[0], A1 = v1.vec[1], A2 = v1.vec[2], A3 = v1.vec[3];

        r1 = _mm_mul_ps(_mm_shuffle_ps(v2.vec[0], v2.vec[0], 0x00), A0);
        r2 = _mm_mul_ps(_mm_shuffle_ps(v2.vec[1], v2.vec[1], 0x00), A0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v2.vec[0], v2.vec[0], 0x55), A1));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v2.vec[1], v2.vec[1], 0x55), A1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v2.vec[0], v2.vec[0], 0xAA), A2));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v2.vec[1], v2.vec[1], 0xAA), A2));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v2.vec[0], v2.vec[0], 0xFF), A3));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v2.vec[1], v2.vec[1], 0xFF), A3));
        ret.vec[0] = r1;
        ret.vec[1] = r2;

        r1 = _mm_mul_ps(_mm_shuffle_ps(v2.vec[2], v2.vec[2], 0x00), A0);
        r2 = _mm_mul_ps(_mm_shuffle_ps(v2.vec[3], v2.vec[3], 0x00), A0);
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v2.vec[2], v2.vec[2], 0x55), A1));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v2.vec[3], v2.vec[3], 0x55), A1));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v2.vec[2], v2.vec[2], 0xAA), A2));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v2.vec[3], v2.vec[3], 0xAA), A2));
        r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(v2.vec[2], v2.vec[2], 0xFF), A3));
        r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(v2.vec[3], v2.vec[3], 0xFF), A3));
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

    // comb
    DECL_FUNC(float4) mat4_mul_vec4(const float16 &m, const float4 &v) {
        float4 ret;
        __m128 v0 = _mm_shuffle_ps(v.vec, v.vec, _MM_SHUFFLE(0, 0, 0, 0));
        __m128 v1 = _mm_shuffle_ps(v.vec, v.vec, _MM_SHUFFLE(1, 1, 1, 1));
        __m128 v2 = _mm_shuffle_ps(v.vec, v.vec, _MM_SHUFFLE(2, 2, 2, 2));
        __m128 v3 = _mm_shuffle_ps(v.vec, v.vec, _MM_SHUFFLE(3, 3, 3, 3));

        __m128 m0 = _mm_mul_ps(m.vec[0], v0);
        __m128 m1 = _mm_mul_ps(m.vec[1], v1);
        __m128 a0 = _mm_add_ps(m0, m1);

        __m128 m2 = _mm_mul_ps(m.vec[2], v2);
        __m128 m3 = _mm_mul_ps(m.vec[3], v3);
        __m128 a1 = _mm_add_ps(m2, m3);

        __m128 a2 = _mm_add_ps(a0, a1);

        ret.vec = a2;
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
}
}

#endif