#pragma once

#include <cmath>

#include "math_funcs.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

namespace math {
    template<typename T>
    T pi() {
        return T(3.14159265358979f);
    }

    inline float radians(float degrees) { return degrees * (pi<float>() / 180.0f); }
    inline vec2 radians(const vec2 &degrees) { return degrees * (pi<float>() / 180.0f); }
    inline vec3 radians(const vec3 &degrees) { return degrees * (pi<float>() / 180.0f); }
    inline vec4 radians(const vec4 &degrees) { return degrees * (pi<float>() / 180.0f); }

    inline float degrees(float radians) { return radians * (180.0f / pi<float>()); }
    inline vec2 degrees(const vec2 &radians) { return radians * (180.0f / pi<float>()); }
    inline vec3 degrees(const vec3 &radians) { return radians * (180.0f / pi<float>()); }
    inline vec4 degrees(const vec4 &radians) { return radians * (180.0f / pi<float>()); }

    inline float sin(float angle) { return sinf(angle); }
    inline vec2 sin(const vec2 &angle) { return vec2(vec2_sin(angle.vec_)); }
    inline vec3 sin(const vec3 &angle) { return vec3(vec3_sin(angle.vec_)); }
    inline vec4 sin(const vec4 &angle) { return vec4(vec4_sin(angle.vec_)); }

    inline float cos(float angle) { return cosf(angle); }
    inline vec2 cos(const vec2 &angle) { return vec2(vec2_cos(angle.vec_)); }
    inline vec3 cos(const vec3 &angle) { return vec3(vec3_cos(angle.vec_)); }
    inline vec4 cos(const vec4 &angle) { return vec4(vec4_cos(angle.vec_)); }

    inline float tan(float angle) { return tanf(angle); }
    inline vec2 tan(const vec2 &angle) { return vec2(vec2_tan(angle.vec_)); }
    inline vec3 tan(const vec3 &angle) { return vec3(vec3_tan(angle.vec_)); }
    inline vec4 tan(const vec4 &angle) { return vec4(vec4_tan(angle.vec_)); }

    inline float asin(float x) { return asinf(x); }
    inline vec2 asin(const vec2 &angle) { return vec2(vec2_asin(angle.vec_)); }
    inline vec3 asin(const vec3 &angle) { return vec3(vec3_asin(angle.vec_)); }
    inline vec4 asin(const vec4 &angle) { return vec4(vec4_asin(angle.vec_)); }

    inline float acos(float x) { return acosf(x); }
    inline vec2 acos(const vec2 &angle) { return vec2(vec2_acos(angle.vec_)); }
    inline vec3 acos(const vec3 &angle) { return vec3(vec3_acos(angle.vec_)); }
    inline vec4 acos(const vec4 &angle) { return vec4(vec4_acos(angle.vec_)); }

    inline float atan(float x) { return atanf(x); }
    inline vec2 atan(const vec2 &angle) { return vec2(vec2_atan(angle.vec_)); }
    inline vec3 atan(const vec3 &angle) { return vec3(vec3_atan(angle.vec_)); }
    inline vec4 atan(const vec4 &angle) { return vec4(vec4_atan(angle.vec_)); }
}