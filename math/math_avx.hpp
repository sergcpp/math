#include "math_sse4_1.hpp"

#if !defined(MATH_NO_INLINE) || defined(MATH_IMPL)
#pragma once

#ifdef __GNUC__
#pragma GCC push_options
#pragma GCC target ("avx")
#endif

#ifndef _mm256_set_m128
#define _mm256_set_m128(/* __m128 */ hi, /* __m128 */ lo) \
    _mm256_insertf128_ps(_mm256_castps128_ps256(lo), (hi), 0x1)
#endif

namespace math {
namespace avx {
    using namespace sse4_1;
    
    // mat4
    DEF_FUNC(void) mat4_init1(float16 &vec, float val) {
        vec.vec2[0] = _mm256_set_ps(0, 0, val, 0, 0, 0, 0, val);
        vec.vec2[1] = _mm256_set_ps(val, 0, 0, 0, 0, val, 0, 0);
        _mm256_zeroupper();
    } DEF_END

    DEF_FUNC(void) mat4_init16(float16 &vec, float v00, float v01, float v02, float v03,
                                             float v10, float v11, float v12, float v13,
                                             float v20, float v21, float v22, float v23,
                                             float v30, float v31, float v32, float v33) {
        vec.vec2[0] = _mm256_set_ps(v13, v12, v11, v10, v03, v02, v01, v00);
        vec.vec2[1] = _mm256_set_ps(v33, v32, v31, v30, v23, v22, v21, v20);
        _mm256_zeroupper();
    } DEF_END

    DEF_FUNC(void) mat4_init4(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3) {
        vec.vec2[0] = _mm256_set_m128(v1.vec, v0.vec);
        vec.vec2[1] = _mm256_set_m128(v3.vec, v2.vec);
        _mm256_zeroupper();
    } DEF_END

    DEF_FUNC(float16) mat4_add_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec2[0] = _mm256_add_ps(v1.vec2[0], v2.vec2[0]);
        ret.vec2[1] = _mm256_add_ps(v1.vec2[1], v2.vec2[1]);
        _mm256_zeroupper();
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_sub_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec2[0] = _mm256_sub_ps(v1.vec2[0], v2.vec2[0]);
        ret.vec2[1] = _mm256_sub_ps(v1.vec2[1], v2.vec2[1]);
        _mm256_zeroupper();
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_mul_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;

        __m256 B0 = _mm256_broadcast_ps(&v2.vec[0]), B1 = _mm256_broadcast_ps(&v2.vec[1]),
               B2 = _mm256_broadcast_ps(&v2.vec[2]), B3 = _mm256_broadcast_ps(&v2.vec[3]);

        __m256 out01x, out23x;
        out01x = _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[0], v1.vec2[0], 0x00), B0);
        out23x = _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[1], v1.vec2[1], 0x00), B0);
        out01x = _mm256_add_ps(out01x, _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[0], v1.vec2[0], 0x55), B1));
        out23x = _mm256_add_ps(out23x, _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[1], v1.vec2[1], 0x55), B1));
        out01x = _mm256_add_ps(out01x, _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[0], v1.vec2[0], 0xaa), B2));
        out23x = _mm256_add_ps(out23x, _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[1], v1.vec2[1], 0xaa), B2));
        out01x = _mm256_add_ps(out01x, _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[0], v1.vec2[0], 0xff), B3));
        out23x = _mm256_add_ps(out23x, _mm256_mul_ps(_mm256_shuffle_ps(v1.vec2[1], v1.vec2[1], 0xff), B3));

        ret.vec2[0] = out01x;
        ret.vec2[1] = out23x;

        _mm256_zeroupper();

        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_div_mat4(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec2[0] = _mm256_div_ps(v1.vec2[0], v2.vec2[0]);
        ret.vec2[1] = _mm256_div_ps(v1.vec2[1], v2.vec2[1]);
        _mm256_zeroupper();
        return ret;
    } DEF_END

    DEF_FUNC(float16) mat4_comp_mul(const float16 &v1, const float16 &v2) {
        float16 ret;
        ret.vec2[0] = _mm256_mul_ps(v1.vec2[0], v2.vec2[0]);
        ret.vec2[1] = _mm256_mul_ps(v1.vec2[1], v2.vec2[1]);
        _mm256_zeroupper();
        return ret;
    } DEF_END
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#else

namespace math {
namespace avx {
    using namespace sse4_1;

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
    DECL_FUNC(float16) mat4_comp_mul(const float16 &v1, const float16 &v2);
}
}

#endif