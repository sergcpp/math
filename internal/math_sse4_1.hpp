#include "math_sse3.hpp"

#if defined(MATH_NO_INLINE) && !defined(MATH_IMPL)

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

#else

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
	#include "math_sse4_1.ipp"
#endif
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#endif
