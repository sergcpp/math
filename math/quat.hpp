#pragma once

#include "math_funcs.hpp"
#include "vec4.hpp"

namespace math {
    class quat {
        float4 vec_;

    public:
        quat(e_uninitialize) { assert(is_aligned(this, alignment)); }
        quat() : quat(uninitialize) { quat_init4(vec_, 1, 0, 0, 0); }
        quat(float r, float i, float j, float k) : quat(uninitialize) { quat_init4(vec_, r, i, j, k); }
        quat(const vec4 &v) : quat(uninitialize) { vec_ = v.vec_; }

        class deref {
            float4 &v_; int i_;
        public:
            deref(float4 &v, int i) : v_(v), i_(i) {}
            operator float() const { return quat_get(v_, i_); }
            deref operator=(const float rhs) { quat_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((float)rhs); }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        float operator[] (int i) const { return vec4_get(vec_, i); }

        float i() const { return (*this)[0]; }
        float j() const { return (*this)[1]; }
        float k() const { return (*this)[2]; }
        float r() const { return (*this)[3]; }

        float x() const { return (*this)[0]; }
        float y() const { return (*this)[1]; }
        float z() const { return (*this)[2]; }
        float w() const { return (*this)[3]; }

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
    };

    inline bool operator==(const quat &q1, const quat &q2) { return quat_eq_quat(q1.vec_, q2.vec_); }
    inline bool operator!=(const quat &q1, const quat &q2) { return !operator==(q1, q2); }

    inline quat operator+(const quat &q1, const quat &q2) { return quat(quat_add_quat(q1.vec_, q2.vec_)); }
    inline quat operator*(const quat &q1, const quat &q2) { return quat(quat_mul_quat(q1.vec_, q2.vec_)); }

    inline quat operator*(const quat &q, float f) { return quat(quat_mul_float(q.vec_, f)); }
    inline quat operator*(float f, const quat &q) { return quat(quat_mul_float(q.vec_, f)); }
    inline quat operator/(const quat &q, float f) { return quat(quat_div_float(q.vec_, f)); }

    inline quat make_quat(const float v[4]) { return quat(v[0], v[1], v[2], v[3]); }
    inline const float *value_ptr(const quat &q) { return &q.vec_.comp[0]; }
}

#include "mat3.hpp"
#include "mat4.hpp"

namespace math {
    inline mat3 to_mat3(const quat &q) { return mat3(quat_to_mat3(q.vec_)); }
    inline mat4 to_mat4(const quat &q) { return mat4(quat_to_mat3(q.vec_)); }
}