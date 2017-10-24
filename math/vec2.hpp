#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec2;
    class mat2;
    class vec3;
    class vec4;

    class vec2 {
    public:
		union {
			float2 vec_;
			struct { float x, y; };
			struct { float r, g; };
			struct { float s, t; };
		};

        vec2(e_noinit) {}
        vec2() { vec2_init1(vec_, 0); }
        explicit vec2(float v) { vec2_init1(vec_, v); }
        vec2(float v0, float v1) { vec2_init2(vec_, v0, v1); }
        vec2(const float2 &v) { vec_ = v; }
        vec2(const vec3 &v);
        vec2(const vec4 &v);
        explicit vec2(const ivec2 &v);

        float &operator[] (int i) { return vec_.comp[i]; }
        float operator[] (int i) const { return vec_.comp[i]; }

        vec2 &operator++();
        vec2 operator++(int);
        vec2 &operator--();
        vec2 operator--(int);

        vec2 &operator+=(const vec2 &rhs);
        vec2 &operator-=(const vec2 &rhs);
        vec2 &operator*=(const vec2 &rhs);
        vec2 &operator/=(const vec2 &rhs);

        vec2 &operator+=(float rhs);
        vec2 &operator-=(float rhs);
        vec2 &operator*=(float rhs);
        vec2 &operator/=(float rhs);

        vec2 operator-() const;

        static const size_t alignment = 1;
		using scalar_type = float;
    };

    inline bool operator==(const vec2 &v1, const vec2 &v2) { return vec2_eq_vec2(v1.vec_, v2.vec_); }
    inline bool operator!=(const vec2 &v1, const vec2 &v2) { return !operator==(v1, v2); }

    inline vec2 operator+(const vec2 &v1, const vec2 &v2) { return vec2(vec2_add_vec2(v1.vec_, v2.vec_)); }
    inline vec2 operator-(const vec2 &v1, const vec2 &v2) { return vec2(vec2_sub_vec2(v1.vec_, v2.vec_)); }
    inline vec2 operator*(const vec2 &v1, const vec2 &v2) { return vec2(vec2_mul_vec2(v1.vec_, v2.vec_)); }
    inline vec2 operator/(const vec2 &v1, const vec2 &v2) { return vec2(vec2_div_vec2(v1.vec_, v2.vec_)); }

    inline vec2 operator+(const vec2 &v, float f) { return v + vec2(f); }
    inline vec2 operator+(float f, const vec2 &v) { return vec2(f) + v; }
    inline vec2 operator-(const vec2 &v, float f) { return v - vec2(f); }
    inline vec2 operator-(float f, const vec2 &v) { return vec2(f) - v; }
    inline vec2 operator*(const vec2 &v, float f) { return v * vec2(f); }
    inline vec2 operator*(float f, const vec2 &v) { return vec2(f) * v; }
    inline vec2 operator/(const vec2 &v, float f) { return v / vec2(f); }
    inline vec2 operator/(float f, const vec2 &v) { return vec2(f) / v; }

    inline vec2 &vec2::operator+=(float rhs) { (*this) = (*this) + rhs; return *this; }
    inline vec2 &vec2::operator-=(float rhs) { (*this) = (*this) - rhs; return *this; }
    inline vec2 &vec2::operator*=(float rhs) { (*this) = (*this) * rhs; return *this; }
    inline vec2 &vec2::operator/=(float rhs) { (*this) = (*this) / rhs; return *this; }

	inline vec2 &vec2::operator++() { (*this) = (*this) + vec2(1); return *this; }
	inline vec2 vec2::operator++(int) { vec2 temp = (*this); ++(*this); return temp; }
	inline vec2 &vec2::operator--() { (*this) = (*this) - vec2(1); return *this; }
	inline vec2 vec2::operator--(int) { vec2 temp = (*this); --(*this); return temp; }

	inline vec2 &vec2::operator+=(const vec2 &rhs) { (*this) = (*this) + rhs; return *this; }
	inline vec2 &vec2::operator-=(const vec2 &rhs) { (*this) = (*this) - rhs; return *this; }
	inline vec2 &vec2::operator*=(const vec2 &rhs) { (*this) = (*this) * rhs; return *this; }
	inline vec2 &vec2::operator/=(const vec2 &rhs) { (*this) = (*this) / rhs; return *this; }

    inline vec2 vec2::operator-() const { return (*this) * -1.0f; }

    inline vec2 make_vec2(const float v[2]) { return vec2(v[0], v[1]); }
    inline const float *value_ptr(const vec2 &v) { return &v.vec_.comp[0]; }
}

#include "ivec2.hpp"
#include "mat2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

namespace math {
    inline vec2::vec2(const vec3 &v) { vec2_init2(vec_, v[0], v[1]); }
    inline vec2::vec2(const vec4 &v) { vec2_init2(vec_, v[0], v[1]); }
    inline vec2::vec2(const ivec2 &v) { vec2_init2(vec_, float(v[0]), float(v[1])); }

    inline vec2 operator*(const mat2 &m, const vec2 &v) { return vec2(mat2_mul_vec2(m.vec_, v.vec_)); }
    inline vec2 operator*(const vec2 &v, const mat2 &m) { return vec2(vec2_mul_mat2(v.vec_, m.vec_)); }
}