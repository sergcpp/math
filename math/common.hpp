#pragma once

#include <cmath>

#include "dvec2.hpp"
#include "dvec3.hpp"
#include "dvec4.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "quat.hpp"

#include "internal/allocator.hpp"

namespace math {
	template<class T> struct is_double_precision : std::false_type {};

	template<> struct is_double_precision<double> : std::true_type {};
	template<> struct is_double_precision<dvec2> : std::true_type {};
	template<> struct is_double_precision<dvec3> : std::true_type {};
	template<> struct is_double_precision<dvec4> : std::true_type {};

    // absolute value
    inline float abs(float x) { return fabs(x); }
    inline vec2 abs(const vec2 &x) { return vec2(abs(x[0]), abs(x[1])); }
    inline vec3 abs(const vec3 &x) { return vec3(abs(x[0]), abs(x[1]), abs(x[2])); }
    inline vec4 abs(const vec4 &x) { return vec4(abs(x[0]), abs(x[1]), abs(x[2]), abs(x[3])); }

	inline double abs(double x) { return abs(x); }
	inline dvec2 abs(const dvec2 &x) { return dvec2(abs(x[0]), abs(x[1])); }
	inline dvec3 abs(const dvec3 &x) { return dvec3(abs(x[0]), abs(x[1]), abs(x[2])); }
	inline dvec4 abs(const dvec4 &x) { return dvec4(abs(x[0]), abs(x[1]), abs(x[2]), abs(x[3])); }

    // returns -1.0, 0.0, or 1.0
    inline float sign(float x) { return x < 0 ? -1.0f : (x > 0 ? 1.0f : 0.0f); }
    inline vec2 sign(const vec2 &x) { return vec2(sign(x[0]), sign(x[1])); }
    inline vec3 sign(const vec3 &x) { return vec3(sign(x[0]), sign(x[1]), sign(x[2])); }
    inline vec4 sign(const vec4 &x) { return vec4(sign(x[0]), sign(x[1]), sign(x[2]), sign(x[3])); }

    // nearest integer <= x
    inline float floor(float x) { return std::floor(x); }
    inline vec2 floor(const vec2 &x) { return vec2(floor(x[0]), floor(x[1])); }
    inline vec3 floor(const vec3 &x) { return vec3(floor(x[0]), floor(x[1]), floor(x[2])); }
    inline vec4 floor(const vec4 &x) { return vec4(floor(x[0]), floor(x[1]), floor(x[2]), floor(x[3])); }

    // nearest integer >= x
    inline float ceil(float x) { return std::ceil(x); }
    inline vec2 ceil(const vec2 &x) { return vec2(ceil(x[0]), ceil(x[1])); }
    inline vec3 ceil(const vec3 &x) { return vec3(ceil(x[0]), ceil(x[1]), ceil(x[2])); }
    inline vec4 ceil(const vec4 &x) { return vec4(ceil(x[0]), ceil(x[1]), ceil(x[2]), ceil(x[3])); }

    // x - floor(x)
    inline float fract(float x) { return x - std::floor(x); }
    inline vec2 fract(const vec2 &x) { return vec2(fract(x[0]), fract(x[1])); }
    inline vec3 fract(const vec3 &x) { return vec3(fract(x[0]), fract(x[1]), fract(x[2])); }
    inline vec4 fract(const vec4 &x) { return vec4(fract(x[0]), fract(x[1]), fract(x[2]), fract(x[3])); }

    // modulus
    template <typename T>
    T mod(const T &x, const T &y) { return x - y * floor(x / y); }

    inline vec2 mod(const vec2 &x, float y) { return mod(x, vec2(y)); }
    inline vec3 mod(const vec3 &x, float y) { return mod(x, vec3(y)); }
    inline vec4 mod(const vec4 &x, float y) { return mod(x, vec4(y)); }

    // minimum value
    inline int min(int x, int y) { return x < y ? x : y; }
    inline float min(float x, float y) { return std::fmin(x, y); }
    inline vec2 min(const vec2 &x, const vec2 &y) { return vec2(min(x[0], y[0]), min(x[1], y[1])); }
    inline vec3 min(const vec3 &x, const vec3 &y) { return vec3(min(x[0], y[0]), min(x[1], y[1]), min(x[2], y[2])); }
    inline vec4 min(const vec4 &x, const vec4 &y) { return vec4(min(x[0], y[0]), min(x[1], y[1]), min(x[2], y[2]), min(x[3], y[3])); }

    inline vec2 min(const vec2 &x, float y) { return min(x, vec2(y)); }
    inline vec3 min(const vec3 &x, float y) { return min(x, vec3(y)); }
    inline vec4 min(const vec4 &x, float y) { return min(x, vec4(y)); }

    // maximum value
    inline int max(int x, int y) { return x > y ? x : y; }
    inline float max(float x, float y) { return std::fmax(x, y); }
    inline vec2 max(const vec2 &x, const vec2 &y) { return vec2(max(x[0], y[0]), max(x[1], y[1])); }
    inline vec3 max(const vec3 &x, const vec3 &y) { return vec3(max(x[0], y[0]), max(x[1], y[1]), max(x[2], y[2])); }
    inline vec4 max(const vec4 &x, const vec4 &y) { return vec4(max(x[0], y[0]), max(x[1], y[1]), max(x[2], y[2]), max(x[3], y[3])); }

    inline vec2 max(const vec2 &x, float y) { return max(x, vec2(y)); }
    inline vec3 max(const vec3 &x, float y) { return max(x, vec3(y)); }
    inline vec4 max(const vec4 &x, float y) { return max(x, vec4(y)); }

    // min(max(x, min_val), max_val)
    template <typename T>
    T clamp(const T &x, const T &min_val, const T &max_val) { return min(max(x, min_val), max_val); }

    inline vec2 clamp(const vec2 &x, float min_val, float max_val) { return clamp(x, vec2(min_val), vec2(max_val)); }
    inline vec3 clamp(const vec3 &x, float min_val, float max_val) { return clamp(x, vec3(min_val), vec3(max_val)); }
    inline vec4 clamp(const vec4 &x, float min_val, float max_val) { return clamp(x, vec4(min_val), vec4(max_val)); }

    // linear blend of x and y
    template <typename T>
    T mix(const T &x, const T &y, const T &a) { return x * (1 - a) + y * a; }

    inline vec2 mix(const vec2 &x, const vec2 &y, float a) { return mix(x, y, vec2(a)); }
    inline vec3 mix(const vec3 &x, const vec3 &y, float a) { return mix(x, y, vec3(a)); }
    inline vec4 mix(const vec4 &x, const vec4 &y, float a) { return mix(x, y, vec4(a)); }
}

#include "trigonometric.hpp"

namespace math {
    inline quat mix(const quat &x, const quat &y, float a) {
        const float cos_theta = dot(x, y);

        if (cos_theta > 1.0f - std::numeric_limits<float>::epsilon()) {
            return quat(mix(x.r(), y.r(), a),
                mix(x.i(), y.i(), a),
                mix(x.j(), y.j(), a),
                mix(x.k(), y.k(), a));
        } else {
            float angle = acos(cos_theta);
            return (sin((1.0f - a) * angle) * x + sin(a * angle) * y) / sin(angle);
        }
    }

    // 0.0 if x < edge, else 1.0
    inline float step(float edge, float x) { return x < edge ? 0.0f : 1.0f; }
    inline vec2 step(const vec2 &edge, const vec2 &x) { return vec2(step(edge[0], x[0]), step(edge[1], x[1])); }
    inline vec3 step(const vec3 &edge, const vec3 &x) { return vec3(step(edge[0], x[0]), step(edge[1], x[1]), step(edge[2], x[2])); }
    inline vec4 step(const vec4 &edge, const vec4 &x) { return vec4(step(edge[0], x[0]), step(edge[1], x[1]), step(edge[2], x[2]), step(edge[3], x[3])); }

    inline vec2 step(float edge, const vec2 &x) { return step(vec2(edge), x); }
    inline vec3 step(float edge, const vec3 &x) { return step(vec3(edge), x); }
    inline vec4 step(float edge, const vec4 &x) { return step(vec4(edge), x); }

    // clip and smooth
    template <typename T>
    T smoothstep(const T &edge0, const T &edge1, const T &x) {
        T t = clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
        return t * t * (3.0 - 2.0 * t);
    }

    inline vec2 smoothstep(float edge0, float edge1, const vec2 &x) { return smoothstep(vec2(edge0), vec2(edge1), x); }
    inline vec3 smoothstep(float edge0, float edge1, const vec3 &x) { return smoothstep(vec3(edge0), vec3(edge1), x); }
    inline vec4 smoothstep(float edge0, float edge1, const vec4 &x) { return smoothstep(vec4(edge0), vec4(edge1), x); }

    //
    inline bool isnan(float v) { return std::isnan(v); }
}