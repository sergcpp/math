#pragma once

#include "math_funcs.hpp"
#include "vec2.hpp"

namespace math {
    class vec3 {
        float4 vec_;

        friend class mat3;
    public:
        vec3(e_uninitialize) { assert(is_aligned(this, alignment)); }
        vec3() : vec3(uninitialize) { vec3_init1(vec_, 0); }
        vec3(float v) : vec3(uninitialize) { vec3_init1(vec_, v); }
        vec3(float v0, float v1, float v2) : vec3(uninitialize) { vec3_init3(vec_, v0, v1, v2); }
        vec3(const float v[3]) : vec3(uninitialize) { vec3_init3(vec_, v[0], v[1], v[2]); }
        vec3(const float4 &v) : vec3(uninitialize) { vec_ = v; }
        vec3(const vec2 &v01, float v2) : vec3(uninitialize) { vec3_init3(vec_, v01[0], v01[1], v2); }
        vec3(float v0, const vec2 &v12) : vec3(uninitialize) { vec3_init3(vec_, v0, v12[0], v12[1]); }
        vec3(const vec4 &v);

        class deref {
            float4 &v_; int i_;
        public:
            deref(float4 &v, int i) : v_(v), i_(i) {}
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

        vec3 operator-() const { return (*this) * -1; }

        friend bool operator==(const vec3 &v1, const vec3 &v2);

        friend vec3 operator+(const vec3 &v1, const vec3 &v2);
        friend vec3 operator-(const vec3 &v1, const vec3 &v2);
        friend vec3 operator*(const vec3 &v1, const vec3 &v2);
        friend vec3 operator/(const vec3 &v1, const vec3 &v2);

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

        static const size_t alignment = alignment_m128;
    };

    inline bool operator==(const vec3 &v1, const vec3 &v2) { return vec3_eq_vec3(v1.vec_, v2.vec_); }
    inline bool operator!=(const vec3 &v1, const vec3 &v2) { return !operator==(v1, v2); }

    inline vec3 operator+(const vec3 &v1, const vec3 &v2) { return vec3(vec3_add_vec3(v1.vec_, v2.vec_)); }
    inline vec3 operator-(const vec3 &v1, const vec3 &v2) { return vec3(vec3_sub_vec3(v1.vec_, v2.vec_)); }
    inline vec3 operator*(const vec3 &v1, const vec3 &v2) { return vec3(vec3_mul_vec3(v1.vec_, v2.vec_)); }
    inline vec3 operator/(const vec3 &v1, const vec3 &v2) { return vec3(vec3_div_vec3(v1.vec_, v2.vec_)); }
}

#include "vec4.hpp"

inline math::vec3::vec3(const vec4 &v) : vec3(uninitialize) { vec3_init3(vec_, v[0], v[1], v[2]); }