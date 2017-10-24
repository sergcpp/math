#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec3;
    class mat3;
    class vec2;
    class vec4;

    class vec3 {
    public:
		union {
			float3 vec_;
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float s, t, p; };
		};

        vec3(e_noinit) { assert(is_aligned(this, alignment)); }
        vec3() : vec3(noinit) { vec3_init1(vec_, 0); }
        explicit vec3(float v) : vec3(noinit) { vec3_init1(vec_, v); }
        vec3(float v0, float v1, float v2) : vec3(noinit) { vec3_init3(vec_, v0, v1, v2); }
        vec3(const float3 &v) : vec3(noinit) { vec_ = v; }
        vec3(const vec2 &v01, float v2);
        vec3(float v0, const vec2 &v12);
        vec3(const vec4 &v);
        explicit vec3(const ivec3 &v);

        float &operator[] (int i) { return vec_.comp[i]; }
        float operator[] (int i) const { return vec_.comp[i]; }

        vec3 &operator++();
        vec3 operator++(int);
        vec3 &operator--();
        vec3 operator--(int);

        vec3 &operator+=(const vec3 &rhs);
        vec3 &operator-=(const vec3 &rhs);
        vec3 &operator*=(const vec3 &rhs);
        vec3 &operator/=(const vec3 &rhs);

        vec3 &operator+=(float rhs);
        vec3 &operator-=(float rhs);
        vec3 &operator*=(float rhs);
        vec3 &operator/=(float rhs);

        vec3 operator-() const;

        static const size_t alignment = alignment_m32;
		using scalar_type = float;
    };

    inline bool operator==(const vec3 &v1, const vec3 &v2) { return vec3_eq_vec3(v1.vec_, v2.vec_); }
    inline bool operator!=(const vec3 &v1, const vec3 &v2) { return !operator==(v1, v2); }

    inline vec3 operator+(const vec3 &v1, const vec3 &v2) { return vec3(vec3_add_vec3(v1.vec_, v2.vec_)); }
    inline vec3 operator-(const vec3 &v1, const vec3 &v2) { return vec3(vec3_sub_vec3(v1.vec_, v2.vec_)); }
    inline vec3 operator*(const vec3 &v1, const vec3 &v2) { return vec3(vec3_mul_vec3(v1.vec_, v2.vec_)); }
    inline vec3 operator/(const vec3 &v1, const vec3 &v2) { return vec3(vec3_div_vec3(v1.vec_, v2.vec_)); }

    inline vec3 operator+(const vec3 &v, float f) { return v + vec3(f); }
    inline vec3 operator+(float f, const vec3 &v) { return vec3(f) + v; }
    inline vec3 operator-(const vec3 &v, float f) { return v - vec3(f); }
    inline vec3 operator-(float f, const vec3 &v) { return vec3(f) - v; }
    inline vec3 operator*(const vec3 &v, float f) { return v * vec3(f); }
    inline vec3 operator*(float f, const vec3 &v) { return vec3(f) * v; }
    inline vec3 operator/(const vec3 &v, float f) { return v / vec3(f); }
    inline vec3 operator/(float f, const vec3 &v) { return vec3(f) / v; }

	inline vec3 &vec3::operator++() { (*this) = (*this) + vec3(1); return *this; }
	inline vec3 vec3::operator++(int) { vec3 temp = (*this); ++(*this); return temp; }
	inline vec3 &vec3::operator--() { (*this) = (*this) - vec3(1); return *this; }
	inline vec3 vec3::operator--(int) { vec3 temp = (*this); --(*this); return temp; }

	inline vec3 &vec3::operator+=(const vec3 &rhs) { (*this) = (*this) + rhs; return *this; }
	inline vec3 &vec3::operator-=(const vec3 &rhs) { (*this) = (*this) - rhs; return *this; }
	inline vec3 &vec3::operator*=(const vec3 &rhs) { (*this) = (*this) * rhs; return *this; }
	inline vec3 &vec3::operator/=(const vec3 &rhs) { (*this) = (*this) / rhs; return *this; }

    inline vec3 &vec3::operator+=(float rhs) { (*this) = (*this) + rhs; return *this; }
    inline vec3 &vec3::operator-=(float rhs) { (*this) = (*this) - rhs; return *this; }
    inline vec3 &vec3::operator*=(float rhs) { (*this) = (*this) * rhs; return *this; }
    inline vec3 &vec3::operator/=(float rhs) { (*this) = (*this) / rhs; return *this; }

    inline vec3 vec3::operator-() const { return (*this) * -1.0f; }

    inline vec3 make_vec3(const float v[3]) { return vec3(v[0], v[1], v[2]); }
    inline const float *value_ptr(const vec3 &v) { return &v.vec_.comp[0]; }
}

#include "ivec3.hpp"
#include "mat3.hpp"
#include "vec2.hpp"
#include "vec4.hpp"

namespace math {
    inline vec3::vec3(const vec2 &v01, float v2) : vec3(noinit) { vec3_init3(vec_, v01[0], v01[1], v2); }
    inline vec3::vec3(float v0, const vec2 &v12) : vec3(noinit) { vec3_init3(vec_, v0, v12[0], v12[1]); }
    inline vec3::vec3(const vec4 &v) : vec3(noinit) { vec3_init3(vec_, v[0], v[1], v[2]); }
    inline vec3::vec3(const ivec3 &v) : vec3(noinit) { vec3_init3(vec_, float(v[0]), float(v[1]), float(v[2])); }
}