#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec3;
    class mat3;
    class vec2;
    class vec4;

    class vec3 {
        float3 vec_;

        friend class mat3;
    public:
        vec3(e_noinit) { assert(is_aligned(this, alignment)); }
        vec3() : vec3(noinit) { vec3_init1(vec_, 0); }
        explicit vec3(float v) : vec3(noinit) { vec3_init1(vec_, v); }
        vec3(float v0, float v1, float v2) : vec3(noinit) { vec3_init3(vec_, v0, v1, v2); }
        vec3(const float3 &v) : vec3(noinit) { vec_ = v; }
        vec3(const vec2 &v01, float v2);
        vec3(float v0, const vec2 &v12);
        vec3(const vec4 &v);
        explicit vec3(const ivec3 &v);

        class deref {
            float3 &v_; int i_;
        public:
            deref(float3 &v, int i) : v_(v), i_(i) {}
            operator float() const { return vec3_get(v_, i_); }
            deref operator=(const float rhs) { vec3_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((float)rhs); }

            deref operator+=(float rhs) { *this = float(*this) + rhs; return *this; }
            deref operator-=(float rhs) { *this = float(*this) - rhs; return *this; }
            deref operator*=(float rhs) { *this = float(*this) * rhs; return *this; }
            deref operator/=(float rhs) { *this = float(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        float operator[] (int i) const { return vec3_get(vec_, i); }

        float x() const { return (*this)[0]; }
        float y() const { return (*this)[1]; }
        float z() const { return (*this)[2]; }

        float r() const { return (*this)[0]; }
        float g() const { return (*this)[1]; }
        float b() const { return (*this)[2]; }

        float s() const { return (*this)[0]; }
        float t() const { return (*this)[1]; }
        float p() const { return (*this)[2]; }

        vec3 &operator++() { (*this) = (*this) + vec3(1); return *this; }
        vec3 operator++(int) { vec3 temp = (*this); ++(*this); return temp; }
        vec3 &operator--() { (*this) = (*this) - vec3(1); return *this; }
        vec3 operator--(int) { vec3 temp = (*this); --(*this); return temp; }

        vec3 &operator+=(const vec3 &rhs) { (*this) = (*this) + rhs; return *this; }
        vec3 &operator-=(const vec3 &rhs) { (*this) = (*this) - rhs; return *this; }
        vec3 &operator*=(const vec3 &rhs) { (*this) = (*this) * rhs; return *this; }
        vec3 &operator/=(const vec3 &rhs) { (*this) = (*this) / rhs; return *this; }

        vec3 &operator+=(float rhs);
        vec3 &operator-=(float rhs);
        vec3 &operator*=(float rhs);
        vec3 &operator/=(float rhs);

        vec3 operator-() const;

        friend bool operator==(const vec3 &v1, const vec3 &v2);

        friend vec3 operator+(const vec3 &v1, const vec3 &v2);
        friend vec3 operator-(const vec3 &v1, const vec3 &v2);
        friend vec3 operator*(const vec3 &v1, const vec3 &v2);
        friend vec3 operator/(const vec3 &v1, const vec3 &v2);

        friend vec3 operator*(const mat3 &m, const vec3 &v);
        friend vec3 operator*(const vec3 &v, const mat3 &m);

        friend const float *value_ptr(const vec3 &v);

        friend float length(const vec3 &v);
        friend float dot(const vec3 &v1, const vec3 &v2);
        friend vec3 cross(const vec3 &v1, const vec3 &v2);
        friend vec3 normalize(const vec3 &v);
        friend vec3 normalize_fast(const vec3 &v);

        friend vec3 sin(const vec3 &angle);
        friend vec3 cos(const vec3 &angle);
        friend vec3 tan(const vec3 &angle);
        friend vec3 asin(const vec3 &angle);
        friend vec3 acos(const vec3 &angle);
        friend vec3 atan(const vec3 &angle);

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

    inline float operator*(float f1, const vec3::deref &f2) { return f1 * float(f2); }
    inline float operator/(float f1, const vec3::deref &f2) { return f1 / float(f2); }
    inline vec2 operator*(const vec2 &v, const vec3::deref &f) { return v * float(f); }
    inline vec2 operator/(const vec2 &v, const vec3::deref &f) { return v / float(f); }
    inline vec3 operator*(const vec3 &v, const vec3::deref &f) { return v * float(f); }
    inline vec3 operator/(const vec3 &v, const vec3::deref &f) { return v / float(f); }
    inline vec4 operator*(const vec4 &v, const vec3::deref &f) { return v * float(f); }
    inline vec4 operator/(const vec4 &v, const vec3::deref &f) { return v / float(f); }
}