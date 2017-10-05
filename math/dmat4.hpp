#pragma once

#include "dvec4.hpp"

namespace math {
    class dmat3;
    //class dquat;

    class dmat4 {
        double16 vec_;
    public:
        dmat4(e_noinit) { assert(is_aligned(this, alignment)); }
        dmat4() : dmat4(1.0) {}
        explicit dmat4(double v) : dmat4(noinit) { dmat4_init1(vec_, v); }
        dmat4(double v00, double v01, double v02, double v03,
              double v10, double v11, double v12, double v13,
              double v20, double v21, double v22, double v23,
              double v30, double v31, double v32, double v33) : dmat4(noinit) {
            dmat4_init16(vec_, v00, v01, v02, v03, v10, v11, v12, v13, v20, v21, v22, v23, v30, v31, v32, v33);
        }
        dmat4(const dvec4 &v0, const dvec4 &v1, const dvec4 &v2, const dvec4 &v3) : dmat4(noinit) {
            dmat4_init4(vec_, v0.vec_, v1.vec_, v2.vec_, v3.vec_);
        }
        dmat4(const double16 &v) : dmat4(noinit) { vec_ = v; }
        dmat4(const double9 &v) : dmat4(noinit) {
            dmat4_init16(vec_, 
                v.comp3[0][0], v.comp3[0][1], v.comp3[0][2], 0,
                v.comp3[1][0], v.comp3[1][1], v.comp3[1][2], 0,
                v.comp3[2][0], v.comp3[2][1], v.comp3[2][2], 0,
                0, 0, 0, 1);
        }
        dmat4(const dmat4 &v) : dmat4(noinit) { vec_ = v.vec_; }
        dmat4(const dmat3 &v);

        class deref {
            double16 &v_; int i_;
        public:
            deref(double16 &v, int i) : v_(v), i_(i) {}
            operator dvec4() const { return dmat4_get(v_, i_); }
            deref operator=(const dvec4 &rhs) { dmat4_set(v_, i_, rhs.vec_); return *this; }
            deref operator=(const deref &rhs) { return operator=((dvec4)rhs); }

            dvec4::deref operator[] (int i) const { return dvec4::deref(v_.vec4[i_], i); }

            deref operator+=(const dvec4 &rhs) { *this = dvec4(*this) + rhs; return *this; }
            deref operator-=(const dvec4 &rhs) { *this = dvec4(*this) - rhs; return *this; }
            deref operator*=(const dvec4 &rhs) { *this = dvec4(*this) * rhs; return *this; }
            deref operator/=(const dvec4 &rhs) { *this = dvec4(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        dvec4 operator[] (int i) const { return dvec4(vec_.vec4[i]); }

        dmat4 &operator++() { (*this) = (*this) + dmat4(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        dmat4 operator++(int) { dmat4 temp = (*this); ++(*this); return temp; }
        dmat4 &operator--() { (*this) = (*this) - dmat4(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        dmat4 operator--(int) { dmat4 temp = (*this); --(*this); return temp; }

        dmat4 &operator+=(const dmat4 &rhs) { (*this) = (*this) + rhs; return *this; }
        dmat4 &operator-=(const dmat4 &rhs) { (*this) = (*this) - rhs; return *this; }
        dmat4 &operator*=(const dmat4 &rhs) { (*this) = (*this) * rhs; return *this; }
        dmat4 &operator/=(const dmat4 &rhs) { (*this) = (*this) / rhs; return *this; }

        dmat4 operator-() const { return matrix_comp_mult((*this), dmat4(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)); }

        friend bool operator==(const dmat4 &m1, const dmat4 &m2);

        friend dmat4 operator+(const dmat4 &m1, const dmat4 &m2);
        friend dmat4 operator-(const dmat4 &m1, const dmat4 &m2);
        friend dmat4 operator*(const dmat4 &m1, const dmat4 &m2);
        friend dmat4 operator/(const dmat4 &m1, const dmat4 &m2);
    
        friend dmat4 operator*(const dmat4 &m1, double v1);
        friend dmat4 operator/(const dmat4 &m1, double v1);

        friend dvec4 operator*(const dmat4 &m, const dvec4 &v);
        friend dvec4 operator*(const dvec4 &v, const dmat4 &m);

        friend dmat4 matrix_comp_mult(const dmat4 &m1, const dmat4 &m2);

        friend dmat4 inverse(const dmat4 &m);

        friend const double *value_ptr(const dmat4 &m);

        //friend dquat to_quat(const dmat4 &m);

        static const size_t alignment = alignment_m256;
		using scalar_type = double;
    };

    inline bool operator==(const dmat4 &m1, const dmat4 &m2) { return dmat4_eq_dmat4(m1.vec_, m2.vec_); }
    inline bool operator!=(const dmat4 &m1, const dmat4 &m2) { return !operator==(m1, m2); }

    inline dmat4 operator+(const dmat4 &m1, const dmat4 &m2) { return dmat4(dmat4_add_dmat4(m1.vec_, m2.vec_)); }
    inline dmat4 operator-(const dmat4 &m1, const dmat4 &m2) { return dmat4(dmat4_sub_dmat4(m1.vec_, m2.vec_)); }
    inline dmat4 operator*(const dmat4 &m1, const dmat4 &m2) { return dmat4(dmat4_mul_dmat4(m1.vec_, m2.vec_)); }
    inline dmat4 operator/(const dmat4 &m1, const dmat4 &m2) { return dmat4(dmat4_div_dmat4(m1.vec_, m2.vec_)); }

    inline dmat4 operator*(const dmat4 &m1, double v1) { return dmat4_mul_double(m1.vec_, v1); }
    inline dmat4 operator*(double v1, const dmat4 &m1) { return operator*(m1, v1); }
    inline dmat4 operator/(const dmat4 &m1, double v1) { return dmat4_div_double(m1.vec_, v1); }

    inline dmat4 matrix_comp_mult(const dmat4 &m1, const dmat4 &m2) { return dmat4_comp_mul(m1.vec_, m2.vec_); }

    inline dmat4 make_mat4(const double v[16]) {
        return dmat4(v[0], v[1], v[2], v[3],
                     v[4], v[5], v[6], v[7],
                     v[8], v[9], v[10], v[11],
                     v[12], v[13], v[14], v[15]);
    }

    inline const double *value_ptr(const dmat4 &m) {
        return &m.vec_.comp[0];
    }

	inline dvec4 operator*(const dmat4 &m, const dvec4 &v) { return dvec4(dmat4_mul_dvec4(m.vec_, v.vec_)); }
	inline dvec4 operator*(const dvec4 &v, const dmat4 &m) { return dvec4(dvec4_mul_dmat4(v.vec_, m.vec_)); }
}

#include "mat3.hpp"
#include "quat.hpp"

namespace math {
    inline dmat4::dmat4(const dmat3 &m) : dmat4(m.vec_) {}

    //inline dquat to_quat(const dmat4 &m) { return dquat(dmat4_to_quat(m.vec_)); }
}