#include "math_sse3.hpp"

#if !defined(MATH_NO_INLINE) || defined(MATH_IMPL)
#pragma once

#ifdef __GNUC__
#pragma GCC push_options
#pragma GCC target ("sse4.1")
#endif

#include <smmintrin.h>

namespace math {
namespace sse4_1 {
    using namespace sse3;

    // vec2

    // vec3

    DEF_FUNC(float) vec3_length(const float4 &v) {
        return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(v.vec, v.vec, 0x71)));
    } DEF_END

    DEF_FUNC(float) vec3_dot(const float4 &v1, const float4 &v2) {
        return _mm_cvtss_f32(_mm_dp_ps(v1.vec, v2.vec, 0x71));
    } DEF_END

    DEF_FUNC(float4) vec3_normalize(const float4 &v) {
        float4 ret;
        __m128 norm = _mm_sqrt_ps(_mm_dp_ps(v.vec, v.vec, 0x7F));
        ret.vec = _mm_div_ps(v.vec, norm);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_normalize_fast(const float4 &v) {
        float4 ret;
        __m128 inverse_norm = _mm_rsqrt_ps(_mm_dp_ps(v.vec, v.vec, 0x77));
        ret.vec = _mm_mul_ps(v.vec, inverse_norm);
        return ret;
    } DEF_END

    // vec4

    DEF_FUNC(float) vec4_length(const float4 &v) {
        return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(v.vec, v.vec, 0xF1)));
    } DEF_END

    DEF_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2) {
        return _mm_cvtss_f32(_mm_dp_ps(v1.vec, v2.vec, 0xF1));
    } DEF_END

    DEF_FUNC(float4) vec4_normalize(const float4 &v) {
        float4 ret;
        __m128 norm = _mm_sqrt_ps(_mm_dp_ps(v.vec, v.vec, 0xFF));
        ret.vec = _mm_div_ps(v.vec, norm);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec4_normalize_fast(const float4 &v) {
        float4 ret;
        __m128 inverse_norm = _mm_rsqrt_ps(_mm_dp_ps(v.vec, v.vec, 0xFF));
        ret.vec = _mm_mul_ps(v.vec, inverse_norm);
        return ret;
    } DEF_END
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#else

namespace math {
namespace sse4_1 {
    using namespace sse3;

    // vec3
    DECL_FUNC(float) vec3_length(const float4 &v);
    DECL_FUNC(float) vec3_dot(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_normalize(const float4 &v);
    DECL_FUNC(float4) vec3_normalize_fast(const float4 &v);

    // vec4
    DECL_FUNC(float) vec4_length(const float4 &v);
    DECL_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_normalize(const float4 &v);
    DECL_FUNC(float4) vec4_normalize_fast(const float4 &v);
}
}

#endif