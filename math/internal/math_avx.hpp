#include "math_sse4_1.hpp"

#if defined(MATH_NO_INLINE) && !defined(MATH_IMPL)

namespace math {
namespace avx {
    using namespace sse4_1;

#if defined(__AVX__) || defined(_MSC_VER)
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

	// dmat2
	DECL_FUNC(void) dmat2_init4(double4 &vec, double v0, double v1, double v2, double v3);
	DECL_FUNC(double4) dmat2_add_mat2(const double4 &v1, const double4 &v2);
	DECL_FUNC(double4) dmat2_sub_mat2(const double4 &v1, const double4 &v2);
	//DECL_FUNC(double4) dmat2_mul_mat2(const double4 &v1, const double4 &v2);
	DECL_FUNC(double4) dmat2_div_mat2(const double4 &v1, const double4 &v2);
	DECL_FUNC(double4) dmat2_comp_mul(const double4 &m1, const double4 &m2);

    // dvec4
    DECL_FUNC(void) dvec4_init1(double4 &vec, double val);
    DECL_FUNC(void) dvec4_init4(double4 &vec, double v0, double v1, double v2, double v3);
    DECL_FUNC(double4) dvec4_add_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_sub_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_mul_dvec4(const double4 &v1, const double4 &v2);
    DECL_FUNC(double4) dvec4_div_dvec4(const double4 &v1, const double4 &v2);

#endif
}
}

#else

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

#if defined(__AVX__) || defined(_MSC_VER)
	#include "math_avx.ipp"
#endif
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#endif
