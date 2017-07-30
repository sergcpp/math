#pragma once

#include <cmath>

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "quat.hpp"

#include "dvec2.hpp"
#include "dvec3.hpp"
#include "dvec4.hpp"

namespace math {
    // length of vector
    inline float length(float v) { return fabs(v); }
    inline float length(const vec2 &v) { return vec2_length(v.vec_); }
    inline float length(const vec3 &v) { return vec3_length(v.vec_); }
    inline float length(const vec4 &v) { return vec4_length(v.vec_); }

    inline float length2(float v) { return v * v; }
    inline float length2(const vec2 &v) { return dot(v, v); }
    inline float length2(const vec3 &v) { return dot(v, v); }
    inline float length2(const vec4 &v) { return dot(v, v); }

    inline double length(double v) { return fabs(v); }
    inline double length(const dvec2 &v) { return dvec2_length(v.vec_); }
    inline double length(const dvec3 &v) { return dvec3_length(v.vec_); }
    inline double length(const dvec4 &v) { return dvec4_length(v.vec_); }

    // distance between points
    template <typename T>
    float distance(const T &v1, const T &v2) { return length(v1 - v2); }

    template <typename T>
    float distance2(const T &v1, const T &v2) { return dot(v1 - v2, v1 - v2); }

    // dot product
    inline float dot(const vec2 &v1, const vec2 &v2) { return vec2_dot(v1.vec_, v2.vec_); }
    inline float dot(const vec3 &v1, const vec3 &v2) { return vec3_dot(v1.vec_, v2.vec_); }
    inline float dot(const vec4 &v1, const vec4 &v2) { return vec4_dot(v1.vec_, v2.vec_); }
    inline float dot(const quat &q1, const quat &q2) { return vec4_dot(q1.vec_, q2.vec_); }

    // cross product
    inline vec3 cross(const vec3 &v1, const vec3 &v2) { return vec3(vec3_cross(v1.vec_, v2.vec_)); }

    // normalize vector to length 1
    inline vec2 normalize(const vec2 &v) { return vec2(vec2_normalize(v.vec_)); }
    inline vec3 normalize(const vec3 &v) { return vec3(vec3_normalize(v.vec_)); }
    inline vec4 normalize(const vec4 &v) { return vec4(vec4_normalize(v.vec_)); }

    inline vec2 normalize_fast(const vec2 &v) { return vec2(vec2_normalize_fast(v.vec_)); }
    inline vec3 normalize_fast(const vec3 &v) { return vec3(vec3_normalize_fast(v.vec_)); }
    inline vec4 normalize_fast(const vec4 &v) { return vec4(vec4_normalize_fast(v.vec_)); }

    // returns N if dot(Nref, I) < 0, else -N
    template <typename T>
    T faceforward(const T &N, const T &I, const T &Nref) { return dot(Nref, I) < 0 ? N : -N; }

    // reflection direction I - 2 * dot(N, I) * N
    template <typename T>
    T reflect(const T &I, const T &N) { return I - 2 * dot(N, I) * N; }
}