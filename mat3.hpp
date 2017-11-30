#pragma once

#include "vec3.hpp"

namespace math {
    class mat4;
    class quat;
    class vec3;

    class mat3 {
    public:
        union {
            float9 vec_;
            vec3 v[3];;
        };

        mat3(e_noinit) { assert(is_aligned(this, alignment)); }
        mat3() : mat3(1.0f) {}
        explicit mat3(float v) : mat3(noinit) { mat3_init1(vec_, v); }
        mat3(float v00, float v01, float v02,
             float v10, float v11, float v12,
             float v20, float v21, float v22) : mat3(noinit) {
            mat3_init9(vec_, v00, v01, v02, v10, v11, v12, v20, v21, v22);
        }
        mat3(const vec3 &v0, const vec3 &v1, const vec3 &v2) : mat3(noinit) {
            mat3_init3(vec_, v0.vec_, v1.vec_, v2.vec_);
        }
        mat3(const float9 &v) : mat3(noinit) { vec_ = v; }
        mat3(const mat4 &v);

        vec3 &operator[] (int i) { return v[i]; }
        vec3 operator[] (int i) const { return v[i]; }

        mat3 &operator++() { (*this) = (*this) + mat3(1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        mat3 operator++(int) { mat3 temp = (*this); ++(*this); return temp; }
        mat3 &operator--() { (*this) = (*this) - mat3(1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        mat3 operator--(int) { mat3 temp = (*this); --(*this); return temp; }

        mat3 &operator+=(const mat3 &rhs) { (*this) = (*this) + rhs; return *this; }
        mat3 &operator-=(const mat3 &rhs) { (*this) = (*this) - rhs; return *this; }
        mat3 &operator*=(const mat3 &rhs) { (*this) = (*this) * rhs; return *this; }
        mat3 &operator/=(const mat3 &rhs) { (*this) = (*this) / rhs; return *this; }

        mat3 operator-() const { return matrix_comp_mult((*this), mat3(-1, -1, -1, -1, -1, -1, -1, -1, -1)); }

        static const size_t alignment = alignment_m32;
        using scalar_type = float;
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

    inline mat3 matrix_comp_mult(const mat3 &m1, const mat3 &m2) { return mat3_comp_mul(m1.vec_, m2.vec_); }

    inline mat3 make_mat3(const float v[9]) {
        return mat3(v[0], v[1], v[2],
                    v[3], v[4], v[5],
                    v[6], v[7], v[8]);
    }

    inline const float *value_ptr(const mat3 &m) {
        return &m.vec_.comp[0];
    }

    inline vec3 operator*(const mat3 &m, const vec3 &v) { return vec3(mat3_mul_vec3(m.vec_, v.vec_)); }
    inline vec3 operator*(const vec3 &v, const mat3 &m) { return vec3(vec3_mul_mat3(v.vec_, m.vec_)); }
}

#include "mat4.hpp"
#include "quat.hpp"

namespace math {
    inline mat3::mat3(const mat4 &v) : mat3(v[0][0], v[0][1], v[0][2], v[1][0], v[1][1], v[1][2], v[2][0], v[2][1], v[2][2]) {}

    inline quat to_quat(const mat3 &m) { return quat(mat3_to_quat(m.vec_)); }
}