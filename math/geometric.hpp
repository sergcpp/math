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
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type length(T v) { return std::abs(v); }
    inline float length(const vec2 &v) { return vec2_length(v.vec_); }
    inline float length(const vec3 &v) { return vec3_length(v.vec_); }
    inline float length(const vec4 &v) { return vec4_length(v.vec_); }

	inline double length(const dvec2 &v) { return dvec2_length(v.vec_); }
	inline double length(const dvec3 &v) { return dvec3_length(v.vec_); }
	inline double length(const dvec4 &v) { return dvec4_length(v.vec_); }

    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type length2(T v) { return v * v; }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type::scalar_type length2(const T &v) { return dot(v, v); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type::scalar_type length2(const T &v) { return dot(v, v); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type::scalar_type length2(const T &v) { return dot(v, v); }

    // distance between points
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type distance(T v1, T v2) { return length(v1 - v2); }
	template <typename T> typename std::enable_if<is_tvecx<T>::value, T>::type::scalar_type distance(const T &v1, const T &v2) { return length(v1 - v2); }

    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type distance2(T v1, T v2) { return (v1 - v2) * (v1 - v2); }
	template <typename T> typename std::enable_if<is_tvecx<T>::value, T>::type::scalar_type distance2(const T &v1, const T &v2) { return dot(v1 - v2, v1 - v2); }

    // dot product
    inline float dot(const vec2 &v1, const vec2 &v2) { return vec2_dot(v1.vec_, v2.vec_); }
    inline float dot(const vec3 &v1, const vec3 &v2) { return vec3_dot(v1.vec_, v2.vec_); }
    inline float dot(const vec4 &v1, const vec4 &v2) { return vec4_dot(v1.vec_, v2.vec_); }
    inline float dot(const quat &q1, const quat &q2) { return vec4_dot(q1.vec_, q2.vec_); }

	inline double dot(const dvec2 &v1, const dvec2 &v2) { return dvec2_dot(v1.vec_, v2.vec_); }
	inline double dot(const dvec3 &v1, const dvec3 &v2) { return dvec3_dot(v1.vec_, v2.vec_); }
	inline double dot(const dvec4 &v1, const dvec4 &v2) { return dvec4_dot(v1.vec_, v2.vec_); }

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