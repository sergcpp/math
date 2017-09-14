#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec2;
    class mat2;
    class vec3;
    class vec4;

    class vec2 {
        float2 vec_;

        friend class mat2;
    public:
        vec2(e_noinit) {}
        vec2() { vec2_init1(vec_, 0); }
        explicit vec2(float v) { vec2_init1(vec_, v); }
        vec2(float v0, float v1) { vec2_init2(vec_, v0, v1); }
        vec2(const float2 &v) { vec_ = v; }
        vec2(const vec3 &v);
        vec2(const vec4 &v);
        explicit vec2(const ivec2 &v);

        class deref {
            float2 &v_; int i_;
        public:
            deref(float2 &v, int i) : v_(v), i_(i) {}
            operator float() const { return vec2_get(v_, i_); }
            deref operator=(const float rhs) { vec2_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((float)rhs); }

            deref operator+=(float rhs) { *this = float(*this) + rhs; return *this; }
            deref operator-=(float rhs) { *this = float(*this) - rhs; return *this; }
            deref operator*=(float rhs) { *this = float(*this) * rhs; return *this; }
            deref operator/=(float rhs) { *this = float(*this) / rhs; return *this; }
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

        vec2 &operator+=(float rhs);
        vec2 &operator-=(float rhs);
        vec2 &operator*=(float rhs);
        vec2 &operator/=(float rhs);

        vec2 operator-() const;

        friend bool operator==(const vec2 &v1, const vec2 &v2);

        friend vec2 operator+(const vec2 &v1, const vec2 &v2);
        friend vec2 operator-(const vec2 &v1, const vec2 &v2);
        friend vec2 operator*(const vec2 &v1, const vec2 &v2);
        friend vec2 operator/(const vec2 &v1, const vec2 &v2);

        friend vec2 operator*(const mat2 &m, const vec2 &v);
        friend vec2 operator*(const vec2 &v, const mat2 &m);

        friend const float *value_ptr(const vec2 &v);

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

    inline float operator*(float f1, const vec2::deref &f2) { return f1 * float(f2); }
    inline float operator/(float f1, const vec2::deref &f2) { return f1 / float(f2); }
    inline vec2 operator*(const vec2 &v, const vec2::deref &f) { return v * float(f); }
    inline vec2 operator/(const vec2 &v, const vec2::deref &f) { return v / float(f); }
    inline vec3 operator*(const vec3 &v, const vec2::deref &f) { return v * float(f); }
    inline vec3 operator/(const vec3 &v, const vec2::deref &f) { return v / float(f); }
    inline vec4 operator*(const vec4 &v, const vec2::deref &f) { return v * float(f); }
    inline vec4 operator/(const vec4 &v, const vec2::deref &f) { return v / float(f); }
}