#pragma once

#include <cmath>

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

namespace math {
    // x ^ y
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type pow(T x, T y) { return std::pow(x, y); }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type pow(const T &x, const T &y) { return T(pow(x[0], y[0]), pow(x[1], y[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type pow(const T &x, const T &y) { return T(pow(x[0], y[0]), pow(x[1], y[1]), pow(x[2], y[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type pow(const T &x, const T &y) { return T(pow(x[0], y[0]), pow(x[1], y[1]), pow(x[2], y[2]), pow(x[3], y[3])); }

    // e ^ x
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type exp(T x) { return std::exp(x); }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type exp(const T &x) { return T(exp(x[0]), exp(x[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type exp(const T &x) { return T(exp(x[0]), exp(x[1]), exp(x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type exp(const T &x) { return T(exp(x[0]), exp(x[1]), exp(x[2]), exp(x[3])); }

    // ln
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type log(T x) { return std::log(x); }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type log(const T &x) { return T(log(x[0]), log(x[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type log(const T &x) { return T(log(x[0]), log(x[1]), log(x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type log(const T &x) { return T(log(x[0]), log(x[1]), log(x[2]), log(x[3])); }

    // 2 ^ x
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type exp2(T x) { return std::exp2(x); }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type exp2(const T &x) { return T(exp2(x[0]), exp2(x[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type exp2(const T &x) { return T(exp2(x[0]), exp2(x[1]), exp2(x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type exp2(const T &x) { return T(exp2(x[0]), exp2(x[1]), exp2(x[2]), exp2(x[3])); }

    // log_2
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type log2(T x) { return std::log2(x); }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type log2(const T &x) { return T(log2(x[0]), log2(x[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type log2(const T &x) { return T(log2(x[0]), log2(x[1]), log2(x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type log2(const T &x) { return T(log2(x[0]), log2(x[1]), log2(x[2]), log2(x[3])); }

    // square root
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type sqrt(T x) { return std::sqrt(x); }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type sqrt(const T &x) { return T(sqrt(x[0]), sqrt(x[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type sqrt(const T &x) { return T(sqrt(x[0]), sqrt(x[1]), sqrt(x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type sqrt(const T &x) { return T(sqrt(x[0]), sqrt(x[1]), sqrt(x[2]), sqrt(x[3])); }

    // inverse square root
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type inversesqrt(T x) { return T(1) / std::sqrt(x); }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type inversesqrt(const T &x) { return T(inversesqrt(x[0]), inversesqrt(x[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type inversesqrt(const T &x) { return T(inversesqrt(x[0]), inversesqrt(x[1]), inversesqrt(x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type inversesqrt(const T &x) { return T(inversesqrt(x[0]), inversesqrt(x[1]), inversesqrt(x[2]), inversesqrt(x[3])); }
}
