#pragma once

#include "math_funcs.hpp"

namespace math {
    class mat3 {
        float12 vec_;
    public:
        mat3(e_uninitialize) { assert(is_aligned(this, 16)); }
        mat3() : mat3(uninitialize) { mat3_init1(vec_, 0); }
        explicit mat3(float v) : mat3(uninitialize) { mat3_init1(vec_, v); }
        mat3(float v00, float v01, float v02,
             float v10, float v11, float v12,
             float v20, float v21, float v22) : mat3(uninitialize) {
            mat3_init9(vec_, v00, v01, v02, v10, v11, v12, v20, v21, v22);
        }
        mat3(const float v[3][3]) : mat3(uninitialize) {
            mat3_init9(vec_, v[0][0], v[0][1], v[0][2],
                             v[1][0], v[1][1], v[1][2],
                             v[2][0], v[2][1], v[2][2]);
        }
        mat3(const float v[9]) : mat3(uninitialize) {
            mat3_init9(vec_, v[0], v[1], v[2],
                             v[3], v[4], v[5],
                             v[6], v[7], v[8]);
        }
        mat3(const vec3 &v0, const vec3 &v1, const vec3 &v2) : mat3(uninitialize) {
            mat3_init3(vec_, v0.vec_, v1.vec_, v2.vec_);
        }
        mat3(const float12 &v) : mat3(uninitialize) { vec_ = v; }

        class deref {
            float12 &v_; int i_;
        public:
            deref(float12 &v, int i) : v_(v), i_(i) {}
            operator vec3() const { return mat3_get(v_, i_); }
            deref operator=(const vec3 &rhs) { mat3_set(v_, i_, rhs.vec_); return *this; }
            deref operator=(const deref &rhs) { return operator=((vec3)rhs); }

            vec3::deref operator[] (int i) const { return vec3::deref(v_.vec4[i_], i); }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        vec3 operator[] (int i) const { return vec3(vec_.vec4[i]); }

        mat3 &operator++() { (*this) = (*this) + mat3(1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        mat3 operator++(int) { mat3 temp = (*this); ++(*this); return temp; }
        mat3 &operator--() { (*this) = (*this) - mat3(1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        mat3 operator--(int) { mat3 temp = (*this); --(*this); return temp; }

        mat3 &operator+=(const mat3 &rhs) { (*this) = (*this) + rhs; return *this; }
        mat3 &operator-=(const mat3 &rhs) { (*this) = (*this) - rhs; return *this; }
        mat3 &operator*=(const mat3 &rhs) { (*this) = (*this) * rhs; return *this; }
        mat3 &operator/=(const mat3 &rhs) { (*this) = (*this) / rhs; return *this; }

        mat3 operator-() const { return matrixCompMult((*this), mat3(-1, -1, -1, -1, -1, -1, -1, -1, -1)); }

        friend bool operator==(const mat3 &m1, const mat3 &m2);

        friend mat3 operator+(const mat3 &m1, const mat3 &m2);
        friend mat3 operator-(const mat3 &m1, const mat3 &m2);
        friend mat3 operator*(const mat3 &m1, const mat3 &m2);
        friend mat3 operator/(const mat3 &m1, const mat3 &m2);

        friend mat3 operator*(const mat3 &m1, float v1);
        friend mat3 operator/(const mat3 &m1, float v1);

        friend mat3 matrixCompMult(const mat3 &m1, const mat3 &m2);

        static const size_t alignment = alignment_m128;
    };

    inline bool operator==(const mat3 &m1, const mat3 &m2) { return mat3_eq_mat3(m1.vec_, m2.vec_); }
    inline bool operator!=(const mat3 &m1, const mat3 &m2) { return !operator==(m1, m2); }

    inline mat3 operator+(const mat3 &m1, const mat3 &m2) { return mat3(mat3_add_mat3(m1.vec_, m2.vec_)); }
    inline mat3 operator-(const mat3 &m1, const mat3 &m2) { return mat3(mat3_sub_mat3(m1.vec_, m2.vec_)); }
    inline mat3 operator*(const mat3 &m1, const mat3 &m2) { return mat3(mat3_mul_mat3(m1.vec_, m2.vec_)); }
    inline mat3 operator/(const mat3 &m1, const mat3 &m2) { return mat3(mat3_div_mat3(m1.vec_, m2.vec_)); }

    inline mat3 operator*(const mat3 &m1, float v1) { return mat3_mul_float(m1.vec_, v1); }
    inline mat3 operator*(float v1, const mat3 &m1) { return operator*(m1, v1); }
    inline mat3 operator/(const mat3 &m1, float v1) { return mat3_div_float(m1.vec_, v1); }

    inline mat3 matrixCompMult(const mat3 &m1, const mat3 &m2) { return mat3_comp_mul(m1.vec_, m2.vec_); }
}