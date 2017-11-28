#pragma once

#include <limits>

#include "common.hpp"

namespace math {
    template<typename T>
    typename std::enable_if<is_single_precision<T>::value, T>::type pi() {
        return T(3.14159265358979f);
    }

	template<typename T>
	typename std::enable_if<is_double_precision<T>::value, T>::type pi() {
		return T(3.14159265358979);
	}

    inline float radians(float degrees) { return degrees * (pi<float>() / 180.0f); }
    inline vec2 radians(const vec2 &degrees) { return degrees * (pi<float>() / 180.0f); }
    inline vec3 radians(const vec3 &degrees) { return degrees * (pi<float>() / 180.0f); }
    inline vec4 radians(const vec4 &degrees) { return degrees * (pi<float>() / 180.0f); }

	inline double radians(double degrees) { return degrees * (pi<double>() / 180.0); }
	inline dvec2 radians(const dvec2 &degrees) { return degrees * (pi<double>() / 180.0); }
	inline dvec3 radians(const dvec3 &degrees) { return degrees * (pi<double>() / 180.0); }
	inline dvec4 radians(const dvec4 &degrees) { return degrees * (pi<double>() / 180.0); }

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

    // quat
    inline float roll(const quat &q) {
        return atan2(2.0f * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z);
    }

    inline float pitch(const quat &q) {
        return atan2(2.0f * (q.y * q.z + q.w * q.x), q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z);
    }

    inline float yaw(const quat &q) {
        return asin(clamp(-2.0f * (q.x * q.z - q.w * q.y), -1.0f, 1.0f));
    }

    inline vec3 euler_angles(const quat &q) {
        return vec3(pitch(q), yaw(q), roll(q));
    }

    inline quat slerp(const quat &q0, const quat &q1, float a) {
        quat q2 = q1;

        float cos_theta = dot(q0, q1);

        if (cos_theta < 0) {
            q2 = -q1;
            cos_theta = -cos_theta;
        }

        if (cos_theta > 1 - std::numeric_limits<float>::epsilon()) {
            return quat(mix(q0.w, q1.w, a),
                        mix(q0.x, q1.x, a),
                        mix(q0.y, q1.y, a),
                        mix(q0.z, q1.z, a));
        } else {
            float angle = acos(cos_theta);
            return (sin((1.0f - a) * angle) * q0 + sin(a * angle) * q2) / sin(angle);
        }
    }
}