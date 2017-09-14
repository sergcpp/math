#include "math_sse2.hpp"

#if defined(MATH_NO_INLINE) && !defined(MATH_IMPL)

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

#else

#pragma once

#if defined(__SSE3__)
#include <pmmintrin.h>
#endif

#ifdef __GNUC__
#pragma GCC push_options
#pragma GCC target ("sse3")
#endif

namespace math {
namespace sse3 {
    using namespace sse2;

#if defined(__SSE3__)
	#include "math_sse3.ipp"
#endif
}
}

#ifdef __GNUC__
#pragma GCC pop_options
#endif

#endif
