#pragma once

#include "dvec2.hpp"

namespace math {
    // column-major !!!!
    class dmat2 {
        double4 vec_;
    public:
        dmat2(e_noinit) { assert(is_aligned(this, alignment)); }
        dmat2() : dmat2(1.0) {}
        explicit dmat2(double v) : dmat2(noinit) { dmat2_init1(vec_, v); }
        dmat2(double v0, double v1, double v2, double v3) : dmat2(noinit) { dmat2_init4(vec_, v0, v1, v2, v3); }
        dmat2(const dvec2 &v01, const dvec2 &v23) : dmat2(noinit) { dmat2_init2(vec_, v01.vec_, v23.vec_); }
        dmat2(const double4 &v) : dmat2(noinit) { vec_ = v; }
        dmat2(const dmat2 &m) : dmat2(noinit) { vec_ = m.vec_; }

        class deref {
            double4 &v_; int i_;
        public:
            deref(double4 &v, int i) : v_(v), i_(i) {}
            operator dvec2() const { return dmat2_get(v_, i_); }
            deref operator=(const dvec2 &rhs) { dmat2_set(v_, i_, rhs.vec_); return *this; }
            deref operator=(const deref &rhs) { return operator=((dvec2)rhs); }

            dvec2::deref operator[] (int i) const { return dvec2::deref(v_.vec2[i_], i); }

            deref operator+=(const dvec2 &rhs) { *this = dvec2(*this) + rhs; return *this; }
            deref operator-=(const dvec2 &rhs) { *this = dvec2(*this) - rhs; return *this; }
            deref operator*=(const dvec2 &rhs) { *this = dvec2(*this) * rhs; return *this; }
            deref operator/=(const dvec2 &rhs) { *this = dvec2(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        dvec2 operator[] (int i) const { return dvec2(vec_.vec2[i]); }

        dmat2 &operator++() { (*this) = (*this) + dmat2(1, 1, 1, 1); return *this; }
        dmat2 operator++(int) { dmat2 temp = (*this); ++(*this); return temp; }
        dmat2 &operator--() { (*this) = (*this) - dmat2(1, 1, 1, 1); return *this; }
        dmat2 operator--(int) { dmat2 temp = (*this); --(*this); return temp; }

        dmat2 &operator+=(const dmat2 &rhs) { (*this) = (*this) + rhs; return *this; }
        dmat2 &operator-=(const dmat2 &rhs) { (*this) = (*this) - rhs; return *this; }
        dmat2 &operator*=(const dmat2 &rhs) { (*this) = (*this) * rhs; return *this; }
        dmat2 &operator/=(const dmat2 &rhs) { (*this) = (*this) / rhs; return *this; }

        dmat2 operator-() const { return matrix_comp_mult((*this), dmat2(-1, -1, -1, -1)); }

        friend bool operator==(const dmat2 &m1, const dmat2 &m2);

        friend dmat2 operator+(const dmat2 &m1, const dmat2 &m2);
        friend dmat2 operator-(const dmat2 &m1, const dmat2 &m2);
        friend dmat2 operator*(const dmat2 &m1, const dmat2 &m2);
        friend dmat2 operator/(const dmat2 &m1, const dmat2 &m2);

        friend dvec2 operator*(const dmat2 &m, const dvec2 &v);
        friend dvec2 operator*(const dvec2 &v, const dmat2 &m);

        friend dmat2 matrix_comp_mult(const dmat2 &m1, const dmat2 &m2);

        friend dmat2 inverse(const dmat2 &m);

        friend const double *value_ptr(const dmat2 &m);

        static const size_t alignment = alignment_m256;
		using scalar_type = double;
    };

    inline bool operator==(const dmat2 &m1, const dmat2 &m2) { return dmat2_eq_dmat2(m1.vec_, m2.vec_); }
    inline bool operator!=(const dmat2 &m1, const dmat2 &m2) { return !operator==(m1, m2); }

    inline dmat2 operator+(const dmat2 &m1, const dmat2 &m2) { return dmat2(dmat2_add_dmat2(m1.vec_, m2.vec_)); }
    inline dmat2 operator-(const dmat2 &m1, const dmat2 &m2) { return dmat2(dmat2_sub_dmat2(m1.vec_, m2.vec_)); }
    inline dmat2 operator*(const dmat2 &m1, const dmat2 &m2) { return dmat2(dmat2_mul_dmat2(m1.vec_, m2.vec_)); }
    inline dmat2 operator/(const dmat2 &m1, const dmat2 &m2) { return dmat2(dmat2_div_dmat2(m1.vec_, m2.vec_)); }

    inline dmat2 operator*(const dmat2 &m1, double v1) { return matrix_comp_mult(m1, dmat2(v1, v1, v1, v1)); }
    inline dmat2 operator*(double v1, const dmat2 &m1) { return operator*(m1, v1); }
    inline dmat2 operator/(const dmat2 &m1, double v1) { return m1 / dmat2(v1, v1, v1, v1); }

    inline dmat2 matrix_comp_mult(const dmat2 &m1, const dmat2 &m2) { return dmat2_comp_mul(m1.vec_, m2.vec_); }

    inline dmat2 make_mat2(const double v[4]) {
        return dmat2(v[0], v[1], v[2], v[3]);
    }

    inline const double *value_ptr(const dmat2 &m) {
        return &m.vec_.comp[0];
    }
}