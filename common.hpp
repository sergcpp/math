#pragma once

#include <cmath>

#include "allocator.hpp"
#include "dvec2.hpp"
#include "dvec3.hpp"
#include "dvec4.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "quat.hpp"

namespace math {
    template <typename T, std::size_t Alignment = T::alignment>
    using aligned_vector = std::vector<T, aligned_allocator<T, Alignment>>;

	template<class T> struct is_single_precision : std::false_type {};
	template<class T> struct is_double_precision : std::false_type {};

	template<class T> struct is_scalar : std::false_type {};
	template<class T> struct is_tvec2 : std::false_type {};
	template<class T> struct is_tvec3 : std::false_type {};
	template<class T> struct is_tvec4 : std::false_type {};
	template<class T> struct is_tvecx : std::false_type {};
	template<class T> struct is_tquat : std::false_type {};

	template<> struct is_single_precision<float> : std::true_type {};
	template<> struct is_single_precision<vec2> : std::true_type {};
	template<> struct is_single_precision<vec3> : std::true_type {};
	template<> struct is_single_precision<vec4> : std::true_type {};
	template<> struct is_single_precision<mat2> : std::true_type {};
	template<> struct is_single_precision<mat3> : std::true_type {};
	template<> struct is_single_precision<mat4> : std::true_type {};

	template<> struct is_double_precision<double> : std::true_type {};
	template<> struct is_double_precision<dvec2> : std::true_type {};
	template<> struct is_double_precision<dvec3> : std::true_type {};
	template<> struct is_double_precision<dvec4> : std::true_type {};

	template<> struct is_scalar<int> : std::true_type {};
	template<> struct is_scalar<float> : std::true_type {};
	template<> struct is_scalar<double> : std::true_type {};

	template<> struct is_tvec2<ivec2> : std::true_type {};
	template<> struct is_tvec2<vec2> : std::true_type {};
	template<> struct is_tvec2<dvec2> : std::true_type {};

	template<> struct is_tvec3<ivec3> : std::true_type {};
	template<> struct is_tvec3<vec3> : std::true_type {};
	template<> struct is_tvec3<dvec3> : std::true_type {};

	template<> struct is_tvec4<ivec4> : std::true_type {};
	template<> struct is_tvec4<vec4> : std::true_type {};
	template<> struct is_tvec4<dvec4> : std::true_type {};

	template<> struct is_tvecx<ivec2> : std::true_type {};
	template<> struct is_tvecx<vec2> : std::true_type {};
	template<> struct is_tvecx<dvec2> : std::true_type {};

	template<> struct is_tvecx<ivec3> : std::true_type {};
	template<> struct is_tvecx<vec3> : std::true_type {};
	template<> struct is_tvecx<dvec3> : std::true_type {};

	template<> struct is_tvecx<ivec4> : std::true_type {};
	template<> struct is_tvecx<vec4> : std::true_type {};
	template<> struct is_tvecx<dvec4> : std::true_type {};

	template<> struct is_tquat<quat> : std::true_type {};

    // absolute value
	template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type abs(T x) { return std::abs(x); }
	template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type abs(const T &x) { return T(abs(x[0]), abs(x[1])); }
	template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type abs(const T &x) { return T(abs(x[0]), abs(x[1]), abs(x[2])); }
	template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type abs(const T &x) { return T(abs(x[0]), abs(x[1]), abs(x[2]), abs(x[3])); }

    // returns -1.0, 0.0, or 1.0
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type sign(T x) { return x < T(0) ? T(-1) : (x > T(0) ? T(1) : T(0)); }
	template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type sign(const T &x) { return T(sign(x[0]), sign(x[1])); }
	template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type sign(const T &x) { return T(sign(x[0]), sign(x[1]), sign(x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type sign(const T &x) { return T(sign(x[0]), sign(x[1]), sign(x[2]), sign(x[3])); }

    // nearest integer <= x
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type floor(T x) { return std::floor(x); }
	template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type floor(const T &x) { return T(floor(x[0]), floor(x[1])); }
	template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type floor(const T &x) { return T(floor(x[0]), floor(x[1]), floor(x[2])); }
	template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type floor(const T &x) { return T(floor(x[0]), floor(x[1]), floor(x[2]), floor(x[3])); }

    // nearest integer >= x
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type ceil(T x) { return std::ceil(x); }
	template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type ceil(const T &x) { return T(ceil(x[0]), ceil(x[1])); }
	template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type ceil(const T &x) { return T(ceil(x[0]), ceil(x[1]), ceil(x[2])); }
	template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type ceil(const T &x) { return T(ceil(x[0]), ceil(x[1]), ceil(x[2]), ceil(x[3])); }

    // x - floor(x)
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type fract(T x) { return x - std::floor(x); }
	template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type fract(const T &x) { return T(fract(x[0]), fract(x[1])); }
	template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type fract(const T &x) { return T(fract(x[0]), fract(x[1]), fract(x[2])); }
	template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type fract(const T &x) { return T(fract(x[0]), fract(x[1]), fract(x[2]), fract(x[3])); }

    // modulus
    template <typename T>
    T mod(const T &x, const T &y) { return x - y * floor(x / y); }

	template <typename T>
	typename std::enable_if<is_tvecx<T>::value, T>::type mod(const T &x, typename T::scalar_type y) { return mod(x, T(y)); }

    // minimum value
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type min(T x, T y) { return x < y ? x : y; }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type min(const T &x, const T &y) { return T(min(x[0], y[0]), min(x[1], y[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type min(const T &x, const T &y) { return T(min(x[0], y[0]), min(x[1], y[1]), min(x[2], y[2])); }
	template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type min(const T &x, const T &y) { return T(min(x[0], y[0]), min(x[1], y[1]), min(x[2], y[2]), min(x[3], y[3])); }

	template <typename T, typename U>
	typename std::enable_if<is_tvecx<T>::value && is_scalar<U>::value, T>::type min(const T &x, U y) { return min(x, T(y)); }

    // maximum value
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type max(T x, T y) { return x > y ? x : y; }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type max(const T &x, const T &y) { return T(max(x[0], y[0]), max(x[1], y[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type max(const T &x, const T &y) { return T(max(x[0], y[0]), max(x[1], y[1]), max(x[2], y[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type max(const T &x, const T &y) { return T(max(x[0], y[0]), max(x[1], y[1]), max(x[2], y[2]), max(x[3], y[3])); }

    template <typename T>
	typename std::enable_if<is_tvecx<T>::value, T>::type max(const T &x, typename T::scalar_type y) { return max(x, T(y)); }

    // min(max(x, min_val), max_val)
    template <typename T>
    T clamp(const T &x, const T &min_val, const T &max_val) { return min(max(x, min_val), max_val); }

	template <typename T>
	typename std::enable_if<is_tvecx<T>::value, T>::type clamp(const T &x, typename T::scalar_type min_val, typename T::scalar_type max_val) { return clamp(x, T(min_val), T(max_val)); }

    // linear blend of x and y
    template <typename T>
    T mix(const T &x, const T &y, const T &a) { return x * (1 - a) + y * a; }

	template <typename T>
	typename std::enable_if<is_tvecx<T>::value, T>::type mix(const T &x, const T &y, typename T::scalar_type a) { return mix(x, y, T(a)); }

	inline float castflt_up(float val) { return val; }

	inline float castflt_up(double val) {
        int32_t b;
        float a = (float)val;

        memcpy(&b, &a, sizeof(float));

        if ((double)a < val)
            b += a > 0 ? -1 : 1;

        memcpy(&a, &b, sizeof(float));

        return a;
	}

	inline float castflt_down(float val) { return val; }
	inline float castflt_down(double val) {
        int32_t b;
        float a = (float)val;

        memcpy(&b, &a, sizeof(float));

        if ((double)a > val)
            b += a > 0 ? -1 : 1;

        memcpy(&a, &b, sizeof(float));

		return a;
	}
}

#include "trigonometric.hpp"

namespace math {
	template <typename T>
	typename std::enable_if<is_tquat<T>::value, T>::type mix(const T &x, const T &y, typename T::scalar_type a) {
        const typename T::scalar_type cos_theta = dot(x, y);

        if (cos_theta > (typename T::scalar_type)(1) - std::numeric_limits<typename T::scalar_type>::epsilon()) {
            return T(mix(x.r, y.r, a),
                     mix(x.i, y.i, a),
                     mix(x.j, y.j, a),
                     mix(x.k, y.k, a));
        } else {
            typename T::scalar_type angle = acos(cos_theta);
            return (sin(((typename T::scalar_type)(1) - a) * angle) * x + sin(a * angle) * y) / sin(angle);
        }
    }

    // 0.0 if x < edge, else 1.0
    template <typename T> typename std::enable_if<is_scalar<T>::value, T>::type step(T edge, T x) { return x < edge ? 0.0f : 1.0f; }
    template <typename T> typename std::enable_if<is_tvec2<T>::value, T>::type step(const T &edge, const T &x) { return T(step(edge[0], x[0]), step(edge[1], x[1])); }
    template <typename T> typename std::enable_if<is_tvec3<T>::value, T>::type step(const T &edge, const T &x) { return T(step(edge[0], x[0]), step(edge[1], x[1]), step(edge[2], x[2])); }
    template <typename T> typename std::enable_if<is_tvec4<T>::value, T>::type step(const T &edge, const T &x) { return T(step(edge[0], x[0]), step(edge[1], x[1]), step(edge[2], x[2]), step(edge[3], x[3])); }

	template <typename T>
	typename std::enable_if<is_tvecx<T>::value, T>::type step(typename T::scalar_type edge, const T &x) { return step(T(edge), x); }

    // clip and smooth
    template <typename T>
    T smoothstep(const T &edge0, const T &edge1, const T &x) {
        T t = clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
        return t * t * (3.0 - 2.0 * t);
    }

	template <typename T>
	typename std::enable_if<is_tvecx<T>::value, T>::type smoothstep(typename T::scalar_type edge0, typename T::scalar_type edge1, const T &x) { return smoothstep(T(edge0), T(edge1), x); }

    //
    inline bool isnan(float v) { return std::isnan(v); }
}