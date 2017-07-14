#pragma once

#include "math_funcs.hpp"

namespace math {
    class mat4;

    class vec4 {
        float4 vec_;

        friend class mat4;
        friend class quat;
    public:
        vec4(e_uninitialize) { assert(is_aligned(this, alignment)); }
        vec4() : vec4(uninitialize) { vec4_init1(vec_, 0); }
        vec4(float v) : vec4(uninitialize) { vec4_init1(vec_, v); }
        vec4(float v0, float v1, float v2, float v3) : vec4(uninitialize) { vec4_init4(vec_, v0, v1, v2, v3); }
        vec4(const float v[4]) : vec4(uninitialize) { vec4_init4(vec_, v[0], v[1], v[2], v[3]); }
        vec4(const float4 &v) : vec4(uninitialize) { vec_ = v; }
        vec4(const vec2 &v01, const vec2 &v23) : vec4(uninitialize) { vec4_init4(vec_, v01[0], v01[1], v23[0], v23[1]); }
        vec4(const vec2 &v01, float v2, float v3) : vec4(uninitialize) { vec4_init4(vec_, v01[0], v01[1], v2, v3); }
        vec4(float v0, const vec2 &v12, float v3) : vec4(uninitialize) { vec4_init4(vec_, v0, v12[0], v12[1], v3); }
        vec4(float v0, float v1, const vec2 &v23) : vec4(uninitialize) { vec4_init4(vec_, v0, v1, v23[0], v23[1]); }
        vec4(const vec3 &v012, float v3) : vec4(uninitialize) { vec4_init4(vec_, v012[0], v012[1], v012[2], v3); }
        vec4(float v0, const vec3 &v123) : vec4(uninitialize) { vec4_init4(vec_, v0, v123[0], v123[1], v123[2]); }

        class deref {
            float4 &v_; int i_;
        public:
            deref(float4 &v, int i) : v_(v), i_(i) {}
            operator float() const { return vec4_get(v_, i_); }
            deref operator=(const float rhs) { vec4_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((float)rhs); }

            deref operator+=(float rhs) { *this = float(*this) + rhs; return *this; }
            deref operator-=(float rhs) { *this = float(*this) - rhs; return *this; }
            deref operator*=(float rhs) { *this = float(*this) * rhs; return *this; }
            deref operator/=(float rhs) { *this = float(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        float operator[] (int i) const { return vec4_get(vec_, i); }

        float x() const { return (*this)[0]; }
        float y() const { return (*this)[1]; }
        float z() const { return (*this)[2]; }
        float w() const { return (*this)[3]; }

        float r() const { return (*this)[0]; }
        float g() const { return (*this)[1]; }
        float b() const { return (*this)[2]; }
        float a() const { return (*this)[3]; }

        float s() const { return (*this)[0]; }
        float t() const { return (*this)[1]; }
        float p() const { return (*this)[2]; }
        float q() const { return (*this)[3]; }

        vec4 &operator++() { (*this) = (*this) + vec4(1); return *this; }
        vec4 operator++(int) { vec4 temp = (*this); ++(*this); return temp; }
        vec4 &operator--() { (*this) = (*this) - vec4(1); return *this; }
        vec4 operator--(int) { vec4 temp = (*this); --(*this); return temp; }

        vec4 &operator+=(const vec4 &rhs) { (*this) = (*this) + rhs; return *this; }
        vec4 &operator-=(const vec4 &rhs) { (*this) = (*this) - rhs; return *this; }
        vec4 &operator*=(const vec4 &rhs) { (*this) = (*this) * rhs; return *this; }
        vec4 &operator/=(const vec4 &rhs) { (*this) = (*this) / rhs; return *this; }

        vec4 operator-() const { return (*this) * -1; }

        friend bool operator==(const vec4 &v1, const vec4 &v2);

        friend vec4 operator+(const vec4 &v1, const vec4 &v2);
        friend vec4 operator-(const vec4 &v1, const vec4 &v2);
        friend vec4 operator*(const vec4 &v1, const vec4 &v2);
        friend vec4 operator/(const vec4 &v1, const vec4 &v2);

        friend vec4 operator*(const mat4 &m, const vec4 &v);

        friend float length(const vec4 &v);
        friend float dot(const vec4 &v1, const vec4 &v2);
        friend vec4 normalize(const vec4 &v);
        friend vec4 normalize_fast(const vec4 &v);

        friend vec4 sin(const vec4 &angle);
        friend vec4 cos(const vec4 &angle);
        friend vec4 tan(const vec4 &angle);
        friend vec4 asin(const vec4 &angle);
        friend vec4 acos(const vec4 &angle);
        friend vec4 atan(const vec4 &angle);

        static const size_t alignment = alignment_m128;
    };

    inline bool operator==(const vec4 &v1, const vec4 &v2) { return vec4_eq_vec4(v1.vec_, v2.vec_); }
    inline bool operator!=(const vec4 &v1, const vec4 &v2) { return !operator==(v1, v2); }

    inline vec4 operator+(const vec4 &v1, const vec4 &v2) { return vec4(vec4_add_vec4(v1.vec_, v2.vec_)); }
    inline vec4 operator-(const vec4 &v1, const vec4 &v2) { return vec4(vec4_sub_vec4(v1.vec_, v2.vec_)); }
    inline vec4 operator*(const vec4 &v1, const vec4 &v2) { return vec4(vec4_mul_vec4(v1.vec_, v2.vec_)); }
    inline vec4 operator/(const vec4 &v1, const vec4 &v2) { return vec4(vec4_div_vec4(v1.vec_, v2.vec_)); }
}

#include "mat4.hpp"

namespace math {
    inline vec4 operator*(const mat4 &m, const vec4 &v) { return vec4(mat4_mul_vec4(m.vec_, v.vec_)); }
}