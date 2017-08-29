#include "math_ref.hpp"

#if !defined(MATH_NO_INLINE) || defined(MATH_IMPL)
#pragma once

inline float32x4_t vdivq_f32(float32x4_t num, float32x4_t den) {
    const float32x4_t q_inv0 = vrecpeq_f32(den);
    const float32x4_t q_step0 = vrecpsq_f32(q_inv0, den);

    const float32x4_t q_inv1 = vmulq_f32(q_step0, q_inv0);
    return vmulq_f32(num, q_inv1);
}

namespace math {
namespace neon {
    using namespace ref;
    
    // vec3
    /*
    DEF_FUNC(float4) vec3_add_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vaddq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_sub_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vsubq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_mul_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vmulq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec3_div_vec3(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vdivq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END*/

    // vec4
    DEF_FUNC(void) vec4_init1(float4 &vec, float val) {
        vec.vec = vdupq_n_f32(val);
    } DEF_END

    DEF_FUNC(void) vec4_init4(float4 &vec, float v0, float v1, float v2, float v3) {
        float values[4] = { v0, v1, v2, v3 };
        vec.vec = vld1q_f32(values);
    } DEF_END

    DEF_FUNC(float4) vec4_add_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vaddq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec4_sub_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vsubq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec4_mul_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vmulq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float4) vec4_div_vec4(const float4 &v1, const float4 &v2) {
        float4 ret;
        ret.vec = vdivq_f32(v1.vec, v2.vec);
        return ret;
    } DEF_END

    DEF_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2) {
        float32x4_t r1 = vmulq_f32(v1.vec, v2.vec);
        float32x2_t r2 = vadd_f32(vget_high_f32(r1), vget_low_f32(r1));
        return vget_lane_f32(vpadd_f32(r2, r2), 0);
    } DEF_END
}
}

#else

namespace math {
namespace neon {
    using namespace ref;
    
    // vec3
    /*DECL_FUNC(void) vec3_init1(float4 &vec, float val);
    DECL_FUNC(void) vec3_init3(float4 &vec, float v0, float v1, float v2);
    DECL_FUNC(float4) vec3_add_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_sub_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_mul_vec3(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec3_div_vec3(const float4 &v1, const float4 &v2);*/

    // vec4
    DECL_FUNC(void) vec4_init1(float4 &vec, float val);
    DECL_FUNC(void) vec4_init4(float4 &vec, float v0, float v1, float v2, float v3);
    DECL_FUNC(float4) vec4_add_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_sub_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_mul_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float4) vec4_div_vec4(const float4 &v1, const float4 &v2);
    DECL_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2);
}
}

#endif