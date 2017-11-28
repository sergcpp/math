#pragma once

#include "internal/math_funcs.hpp"

#include "vec4.hpp"

namespace math {
    class quat {
    public:
        union {
            float4 vec_;
            struct { float i, j, k, r; };
            struct { float x, y, z, w; };
        };

        quat(e_noinit) { assert(is_aligned(this, alignment)); }
        quat() : quat(noinit) { quat_init4(vec_, 1, 0, 0, 0); }
        quat(float r, float i, float j, float k) : quat(noinit) { quat_init4(vec_, r, i, j, k); }
        quat(const vec4 &v) : quat(noinit) { vec_ = v.vec_; }

        float &operator[] (int i) { return vec_.comp[i]; }
        float operator[] (int i) const { return vec_.comp[i]; }

        operator vec4() const { return vec4(vec_); }

        quat &operator+=(const quat &rhs) { (*this) = (*this) + rhs; return *this; }
        quat &operator*=(const quat &rhs) { (*this) = (*this) * rhs; return *this; }

        quat &operator*=(float rhs) { (*this) = (*this) * rhs; return *this; }

        quat operator-() const { return (*this) * -1.0f; }

        friend bool operator==(const quat &q1, const quat &q2);

        friend quat operator+(const quat &q1, const quat &q2);
        friend quat operator*(const quat &q1, const quat &q2);

        friend quat operator*(const quat &q, float f);
        friend quat operator*(float f, const quat &q);
        friend quat operator/(const quat &q, float f);

        friend const float *value_ptr(const quat &q);

        friend mat3 to_mat3(const quat &q);
        friend mat4 to_mat4(const quat &q);

        friend float dot(const quat &q1, const quat &q2);

        static const size_t alignment = alignment_m128;
        using scalar_type = float;
    };

    inline bool operator==(const quat &q1, const quat &q2) { return quat_eq_quat(q1.vec_, q2.vec_); }
    inline bool operator!=(const quat &q1, const quat &q2) { return !operator==(q1, q2); }

    inline quat operator+(const quat &q1, const quat &q2) { return quat(quat_add_quat(q1.vec_, q2.vec_)); }
    inline quat operator*(const quat &q1, const quat &q2) { return quat(quat_mul_quat(q1.vec_, q2.vec_)); }

    inline quat operator*(const quat &q, float f) { return quat(quat_mul_float(q.vec_, f)); }
    inline quat operator*(float f, const quat &q) { return quat(quat_mul_float(q.vec_, f)); }
    inline quat operator/(const quat &q, float f) { return quat(quat_div_float(q.vec_, f)); }

    inline quat make_quat(const float v[4]) { return quat(v[3], v[0], v[1], v[2]); }
    inline const float *value_ptr(const quat &q) { return &q.vec_.comp[0]; }
}

#include "mat3.hpp"
#include "mat4.hpp"

namespace math {
    inline mat3 to_mat3(const quat &q) { return mat3(quat_to_mat3(q.vec_)); }
    inline mat4 to_mat4(const quat &q) { return mat4(quat_to_mat3(q.vec_)); }
}