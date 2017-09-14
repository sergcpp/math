#include "math_sse3.hpp"

#if !defined(MATH_NO_INLINE) || defined(MATH_IMPL)
#pragma once

#ifdef __GNUC__
#pragma GCC push_options
#pragma GCC target ("sse4.1")
#endif

#if defined(__SSE4_1__)
#include <smmintrin.h>
#endif

namespace math {
namespace sse4_1 {
    using namespace sse3;

#if defined(__SSE4_1__)    
    // vec2

    // vec3
    DEF_FUNC(float) vec3_length(const float3 &v) {
        __m128 vv = load_float3(v);
        return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(vv, vv, 0x71)));
    } DEF_END

    DEF_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2) {
        __m128 vv1 = load_float3(v1);
        __m128 vv2 = load_float3(v2);
        return _mm_cvtss_f32(_mm_dp_ps(vv1, vv2, 0x71));
    } DEF_END

    DEF_FUNC(float3) vec3_normalize(const float3 &v) {
        __m128 vv = load_float3(v);
        __m128 norm = _mm_sqrt_ps(_mm_dp_ps(vv, vv, 0x7F));
        return save_float3(_mm_div_ps(vv, norm));
    } DEF_END

    DEF_FUNC(float3) vec3_normalize_fast(const float3 &v) {
        __m128 vv = load_float3(v);
        __m128 inverse_norm = _mm_rsqrt_ps(_mm_dp_ps(vv, vv, 0x77));
        return save_float3(_mm_mul_ps(vv, inverse_norm));
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
#endif
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#else

namespace math {
namespace sse4_1 {
    using namespace sse3;

#if defined(__SSE4_1__)
    // vec3
    DECL_FUNC(float) vec3_length(const float3 &v);
    DECL_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2);
    DECL_FUNC(float3) vec3_normalize(const float3 &v);
    DECL_FUNC(float3) vec3_normalize_fast(const float3 &v);

    // vec4
    DECL_FUNC(float) vec4_length(const float4 &v);
    DECL_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_normalize(const float4 &v);
    DECL_FUNC(float4) vec4_normalize_fast(const float4 &v);
#endif
}
}

#endif
