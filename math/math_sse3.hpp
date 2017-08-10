#include "math_sse2.hpp"

#if !defined(MATH_NO_INLINE) || defined(MATH_IMPL)
#pragma once

#ifdef __GNUC__
#pragma GCC push_options
#pragma GCC target ("sse3")
#endif

#if defined(__SSE3__)
#include <pmmintrin.h>
#endif

namespace math {
namespace sse3 {
    using namespace sse2;

#if defined(__SSE3__)
    const __m128 zero_last_mask = _mm_castsi128_ps(_mm_set_epi32(0, 0xffffffff, 0xffffffff, 0xffffffff));

    // vec3
    DEF_FUNC(float) vec3_length(const float3 &v) {
        __m128 mul_res, shuf_reg, sums_reg;

        __m128 vv = _mm_setr_ps(v.comp[0], v.comp[1], v.comp[2], 0);
        mul_res = _mm_mul_ps(vv, vv);

        shuf_reg = _mm_movehdup_ps(mul_res);
        sums_reg = _mm_add_ps(mul_res, shuf_reg);
        shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);

        return _mm_cvtss_f32(_mm_sqrt_ss(sums_reg));
    } DEF_END

    DEF_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2) {
        __m128 mul_res, shuf_reg, sums_reg;

        __m128 vv1 = _mm_setr_ps(v1.comp[0], v1.comp[1], v1.comp[2], 0);
        __m128 vv2 = _mm_setr_ps(v2.comp[0], v2.comp[1], v2.comp[2], 0);
        mul_res = _mm_mul_ps(vv1, vv2);

        shuf_reg = _mm_movehdup_ps(mul_res);
        sums_reg = _mm_add_ps(mul_res, shuf_reg);
        shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);
        return _mm_cvtss_f32(sums_reg);
    } DEF_END

    // vec4
    DEF_FUNC(float) vec4_length(const float4 &v) {
        __m128 mul_res, shuf_reg, sums_reg;

        mul_res = _mm_mul_ps(v.vec, v.vec);

        shuf_reg = _mm_movehdup_ps(mul_res);
        sums_reg = _mm_add_ps(mul_res, shuf_reg);
        shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);

        return _mm_cvtss_f32(_mm_sqrt_ss(sums_reg));
    } DEF_END

    DEF_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2) {
        __m128 mul_res, shuf_reg, sums_reg;

        mul_res = _mm_mul_ps(v1.vec, v2.vec);

        shuf_reg = _mm_movehdup_ps(mul_res);
        sums_reg = _mm_add_ps(mul_res, shuf_reg);
        shuf_reg = _mm_movehl_ps(shuf_reg, sums_reg);
        sums_reg = _mm_add_ss(sums_reg, shuf_reg);
        return _mm_cvtss_f32(sums_reg);

        /*__m128 r;
        r = _mm_mul_ps(v1.vec, v2.vec);
        r = _mm_hadd_ps(r, r);
        r = _mm_hadd_ps(r, r);
        return _mm_cvtss_f32(r);*/
    } DEF_END
#endif
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#else

namespace math {
namespace sse3 {
    using namespace sse2;

#if defined(__SSE3__)    
    // vec3
    DECL_FUNC(float) vec3_length(const float3 &v);
    DECL_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2);

    // vec4
    DECL_FUNC(float) vec4_length(const float4 &v);
    DECL_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2);
#endif
}
}

#endif
