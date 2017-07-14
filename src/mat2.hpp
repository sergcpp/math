#pragma once

#include "math_funcs.hpp"
#include "vec2.hpp"

namespace math {
    // column-major !!!!
    class mat2 {
        float4 vec_;
    public:
        mat2(e_uninitialize) { assert(is_aligned(this, alignment)); }
        mat2() : mat2(uninitialize) { mat2_init1(vec_, 0); }
        explicit mat2(float v) : mat2(uninitialize) { mat2_init1(vec_, v); }
        mat2(float v0, float v1, float v2, float v3) : mat2(uninitialize) { mat2_init4(vec_, v0, v1, v2, v3); }
        mat2(const float v[4]) : mat2(uninitialize) { mat2_init4(vec_, v[0], v[1], v[2], v[3]); }
        mat2(const vec2 &v01, const vec2 &v23) : mat2(uninitialize) { mat2_init2(vec_, v01.vec_, v23.vec_); }
        mat2(const float4 &v) : mat2(uninitialize) { vec_ = v; }

        class deref {
            float4 &v_; int i_;
        public:
            deref(float4 &v, int i) : v_(v), i_(i) {}
            operator vec2() const { return mat2_get(v_, i_); }
            deref operator=(const vec2 &rhs) { mat2_set(v_, i_, rhs.vec_); return *this; }
            deref operator=(const deref &rhs) { return operator=((vec2)rhs); }

            vec2::deref operator[] (int i) const { return vec2::deref(v_.vec2[i_], i); }

            deref operator+=(const vec2 &rhs) { *this = vec2(*this) + rhs; return *this; }
            deref operator-=(const vec2 &rhs) { *this = vec2(*this) - rhs; return *this; }
            deref operator*=(const vec2 &rhs) { *this = vec2(*this) * rhs; return *this; }
            deref operator/=(const vec2 &rhs) { *this = vec2(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        vec2 operator[] (int i) const { return vec2(vec_.vec2[i]); }

        mat2 &operator++() { (*this) = (*this) + mat2(1, 1, 1, 1); return *this; }
        mat2 operator++(int) { mat2 temp = (*this); ++(*this); return temp; }
        mat2 &operator--() { (*this) = (*this) - mat2(1, 1, 1, 1); return *this; }
        mat2 operator--(int) { mat2 temp = (*this); --(*this); return temp; }

        mat2 &operator+=(const mat2 &rhs) { (*this) = (*this) + rhs; return *this; }
        mat2 &operator-=(const mat2 &rhs) { (*this) = (*this) - rhs; return *this; }
        mat2 &operator*=(const mat2 &rhs) { (*this) = (*this) * rhs; return *this; }
        mat2 &operator/=(const mat2 &rhs) { (*this) = (*this) / rhs; return *this; }

        mat2 operator-() const { return matrixCompMult((*this), mat2(-1, -1, -1, -1)); }

        friend bool operator==(const mat2 &m1, const mat2 &m2);

        friend mat2 operator+(const mat2 &m1, const mat2 &m2);
        friend mat2 operator-(const mat2 &m1, const mat2 &m2);
        friend mat2 operator*(const mat2 &m1, const mat2 &m2);
        friend mat2 operator/(const mat2 &m1, const mat2 &m2);

        friend mat2 matrixCompMult(const mat2 &m1, const mat2 &m2);

        static const size_t alignment = alignment_m128;
    };

    inline bool operator==(const mat2 &m1, const mat2 &m2) { return mat2_eq_mat2(m1.vec_, m2.vec_); }
    inline bool operator!=(const mat2 &m1, const mat2 &m2) { return !operator==(m1, m2); }

    inline mat2 operator+(const mat2 &m1, const mat2 &m2) { return mat2(mat2_add_mat2(m1.vec_, m2.vec_)); }
    inline mat2 operator-(const mat2 &m1, const mat2 &m2) { return mat2(mat2_sub_mat2(m1.vec_, m2.vec_)); }
    inline mat2 operator*(const mat2 &m1, const mat2 &m2) { return mat2(mat2_mul_mat2(m1.vec_, m2.vec_)); }
    inline mat2 operator/(const mat2 &m1, const mat2 &m2) { return mat2(mat2_div_mat2(m1.vec_, m2.vec_)); }

    inline mat2 operator*(const mat2 &m1, float v1) { return matrixCompMult(m1, mat2(v1, v1, v1, v1)); }
    inline mat2 operator*(float v1, const mat2 &m1) { return operator*(m1, v1); }
    inline mat2 operator/(const mat2 &m1, float v1) { return m1 / mat2(v1, v1, v1, v1); }

    inline mat2 matrixCompMult(const mat2 &m1, const mat2 &m2) { return mat2_comp_mul(m1.vec_, m2.vec_); }
}