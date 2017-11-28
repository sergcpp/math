#pragma once

#include "vec2.hpp"

namespace math {
    // column-major !!!!
    class mat2 {
    public:
		union {
			float4 vec_;
			vec2 v[2];;
		};

        mat2(e_noinit) { assert(is_aligned(this, alignment)); }
        mat2() : mat2(1.0f) {}
        explicit mat2(float v) : mat2(noinit) { mat2_init1(vec_, v); }
        mat2(float v0, float v1, float v2, float v3) : mat2(noinit) { mat2_init4(vec_, v0, v1, v2, v3); }
        mat2(const vec2 &v01, const vec2 &v23) : mat2(noinit) { mat2_init2(vec_, v01.vec_, v23.vec_); }
        mat2(const float4 &v) : mat2(noinit) { vec_ = v; }
        mat2(const mat2 &m) : mat2(noinit) { vec_ = m.vec_; }

        vec2 &operator[] (int i) { return v[i]; }
        const vec2 &operator[] (int i) const { return v[i]; }

        mat2 &operator++();
        mat2 operator++(int);
        mat2 &operator--();
        mat2 operator--(int);

        mat2 &operator+=(const mat2 &rhs);
        mat2 &operator-=(const mat2 &rhs);
        mat2 &operator*=(const mat2 &rhs);
        mat2 &operator/=(const mat2 &rhs);

        mat2 operator-() const;

        static const size_t alignment = alignment_m128;
		using scalar_type = float;
    };

    inline bool operator==(const mat2 &m1, const mat2 &m2) { return mat2_eq_mat2(m1.vec_, m2.vec_); }
    inline bool operator!=(const mat2 &m1, const mat2 &m2) { return !operator==(m1, m2); }

    inline mat2 operator+(const mat2 &m1, const mat2 &m2) { return mat2(mat2_add_mat2(m1.vec_, m2.vec_)); }
    inline mat2 operator-(const mat2 &m1, const mat2 &m2) { return mat2(mat2_sub_mat2(m1.vec_, m2.vec_)); }
    inline mat2 operator*(const mat2 &m1, const mat2 &m2) { return mat2(mat2_mul_mat2(m1.vec_, m2.vec_)); }
    inline mat2 operator/(const mat2 &m1, const mat2 &m2) { return mat2(mat2_div_mat2(m1.vec_, m2.vec_)); }

	inline mat2 matrix_comp_mult(const mat2 &m1, const mat2 &m2) { return mat2_comp_mul(m1.vec_, m2.vec_); }

    inline mat2 operator*(const mat2 &m1, float v1) { return matrix_comp_mult(m1, mat2(v1, v1, v1, v1)); }
    inline mat2 operator*(float v1, const mat2 &m1) { return operator*(m1, v1); }
    inline mat2 operator/(const mat2 &m1, float v1) { return m1 / mat2(v1, v1, v1, v1); }

    inline mat2 make_mat2(const float v[4]) {
        return mat2(v[0], v[1], v[2], v[3]);
    }

    inline const float *value_ptr(const mat2 &m) {
        return &m.vec_.comp[0];
    }

	inline mat2 &mat2::operator++() { (*this) = (*this) + mat2(1, 1, 1, 1); return *this; }
	inline mat2 mat2::operator++(int) { mat2 temp = (*this); ++(*this); return temp; }
	inline mat2 &mat2::operator--() { (*this) = (*this) - mat2(1, 1, 1, 1); return *this; }
	inline mat2 mat2::operator--(int) { mat2 temp = (*this); --(*this); return temp; }

	inline mat2 &mat2::operator+=(const mat2 &rhs) { (*this) = (*this) + rhs; return *this; }
	inline mat2 &mat2::operator-=(const mat2 &rhs) { (*this) = (*this) - rhs; return *this; }
	inline mat2 &mat2::operator*=(const mat2 &rhs) { (*this) = (*this) * rhs; return *this; }
	inline mat2 &mat2::operator/=(const mat2 &rhs) { (*this) = (*this) / rhs; return *this; }

	inline mat2 mat2::operator-() const { return matrix_comp_mult((*this), mat2(-1, -1, -1, -1)); }
}