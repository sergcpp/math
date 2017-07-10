#pragma once

#include <cmath>

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

namespace math {
    // x ^ y
    inline float pow(float x, float y) { return powf(x, y); }
    inline vec2 pow(const vec2 &x, const vec2 &y) { return vec2(pow(x[0], y[0]), pow(x[1], y[1])); }
    inline vec3 pow(const vec3 &x, const vec3 &y) { return vec3(pow(x[0], y[0]), pow(x[1], y[1]), pow(x[2], y[2])); }
    inline vec4 pow(const vec4 &x, const vec4 &y) { return vec4(pow(x[0], y[0]), pow(x[1], y[1]), pow(x[2], y[2]), pow(x[3], y[3])); }

    // e ^ x
    inline float exp(float x) { return expf(x); }
    inline vec2 exp(const vec2 &x) { return vec2(exp(x[0]), exp(x[1])); }
    inline vec3 exp(const vec3 &x) { return vec3(exp(x[0]), exp(x[1]), exp(x[2])); }
    inline vec4 exp(const vec4 &x) { return vec4(exp(x[0]), exp(x[1]), exp(x[2]), exp(x[3])); }

    // ln
    inline float log(float x) { return logf(x); }
    inline vec2 log(const vec2 &x) { return vec2(log(x[0]), log(x[1])); }
    inline vec3 log(const vec3 &x) { return vec3(log(x[0]), log(x[1]), log(x[2])); }
    inline vec4 log(const vec4 &x) { return vec4(log(x[0]), log(x[1]), log(x[2]), log(x[3])); }

    // 2 ^ x
    inline float exp2(float x) { return std::exp2f(x); }
    inline vec2 exp2(const vec2 &x) { return vec2(exp2(x[0]), exp2(x[1])); }
    inline vec3 exp2(const vec3 &x) { return vec3(exp2(x[0]), exp2(x[1]), exp2(x[2])); }
    inline vec4 exp2(const vec4 &x) { return vec4(exp2(x[0]), exp2(x[1]), exp2(x[2]), exp2(x[3])); }

    // log_2
    inline float log2(float x) { return std::log2f(x); }
    inline vec2 log2(const vec2 &x) { return vec2(log2(x[0]), log2(x[1])); }
    inline vec3 log2(const vec3 &x) { return vec3(log2(x[0]), log2(x[1]), log2(x[2])); }
    inline vec4 log2(const vec4 &x) { return vec4(log2(x[0]), log2(x[1]), log2(x[2]), log2(x[3])); }

    // square root
    inline float sqrt(float x) { return sqrtf(x); }
    inline vec2 sqrt(const vec2 &x) { return vec2(sqrt(x[0]), sqrt(x[1])); }
    inline vec3 sqrt(const vec3 &x) { return vec3(sqrt(x[0]), sqrt(x[1]), sqrt(x[2])); }
    inline vec4 sqrt(const vec4 &x) { return vec4(sqrt(x[0]), sqrt(x[1]), sqrt(x[2]), sqrt(x[3])); }

    // inverse square root
    inline float inversesqrt(float x) { return 1.0f/::sqrtf(x); }
    inline vec2 inversesqrt(const vec2 &x) { return vec2(inversesqrt(x[0]), inversesqrt(x[1])); }
    inline vec3 inversesqrt(const vec3 &x) { return vec3(inversesqrt(x[0]), inversesqrt(x[1]), inversesqrt(x[2])); }
    inline vec4 inversesqrt(const vec4 &x) { return vec4(inversesqrt(x[0]), inversesqrt(x[1]), inversesqrt(x[2]), inversesqrt(x[3])); }
}
