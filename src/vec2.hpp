#pragma once

#include "math_funcs.hpp"

namespace math {
    class vec2 {
        float2 vec_;

        friend class mat2;
    public:
        vec2(e_uninitialize) {}
        vec2() { vec2_init1(vec_, 0); }
        vec2(float v) { vec2_init1(vec_, v); }
        vec2(float v0, float v1) { vec2_init2(vec_, v0, v1); }
        vec2(const float v[2]) { vec2_init2(vec_, v[0], v[1]); }
        vec2(const float2 &v) { vec_ = v; }

        class deref {
            float2 &v_; int i_;
        public:
            deref(float2 &v, int i) : v_(v), i_(i) {}
            operator float() const { return vec2_get(v_, i_); }
            deref operator=(const float rhs) { vec2_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((float)rhs); }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        float operator[] (int i) const { return vec2_get(vec_, i); }

        float x() const { return (*this)[0]; }
        float y() const { return (*this)[1]; }

        float r() const { return (*this)[0]; }
        float g() const { return (*this)[1]; }

        float s() const { return (*this)[0]; }
        float t() const { return (*this)[1]; }

        vec2 &operator++() { (*this) = (*this) + vec2(1); return *this; }
        vec2 operator++(int) { vec2 temp = (*this); ++(*this); return temp; }
        vec2 &operator--() { (*this) = (*this) - vec2(1); return *this; }
        vec2 operator--(int) { vec2 temp = (*this); --(*this); return temp; }

        vec2 &operator+=(const vec2 &rhs) { (*this) = (*this) + rhs; return *this; }
        vec2 &operator-=(const vec2 &rhs) { (*this) = (*this) - rhs; return *this; }
        vec2 &operator*=(const vec2 &rhs) { (*this) = (*this) * rhs; return *this; }
        vec2 &operator/=(const vec2 &rhs) { (*this) = (*this) / rhs; return *this; }

        vec2 operator-() const { return (*this) * -1; }

        friend bool operator==(const vec2 &v1, const vec2 &v2);

        friend vec2 operator+(const vec2 &v1, const vec2 &v2);
        friend vec2 operator-(const vec2 &v1, const vec2 &v2);
        friend vec2 operator*(const vec2 &v1, const vec2 &v2);
        friend vec2 operator/(const vec2 &v1, const vec2 &v2);

        friend float length(const vec2 &vec);
        friend float dot(const vec2 &v1, const vec2 &v2);
        friend vec2 normalize(const vec2 &v);
        friend vec2 normalize_fast(const vec2 &v);

        friend vec2 sin(const vec2 &angle);
        friend vec2 cos(const vec2 &angle);
        friend vec2 tan(const vec2 &angle);
        friend vec2 asin(const vec2 &angle);
        friend vec2 acos(const vec2 &angle);
        friend vec2 atan(const vec2 &angle);

        static const size_t alignment = 1;
    };

    inline bool operator==(const vec2 &v1, const vec2 &v2) { return vec2_eq_vec2(v1.vec_, v2.vec_); }
    inline bool operator!=(const vec2 &v1, const vec2 &v2) { return !operator==(v1, v2); }

    inline vec2 operator+(const vec2 &v1, const vec2 &v2) { return vec2(vec2_add_vec2(v1.vec_, v2.vec_)); }
    inline vec2 operator-(const vec2 &v1, const vec2 &v2) { return vec2(vec2_sub_vec2(v1.vec_, v2.vec_)); }
    inline vec2 operator*(const vec2 &v1, const vec2 &v2) { return vec2(vec2_mul_vec2(v1.vec_, v2.vec_)); }
    inline vec2 operator/(const vec2 &v1, const vec2 &v2) { return vec2(vec2_div_vec2(v1.vec_, v2.vec_)); }
}
