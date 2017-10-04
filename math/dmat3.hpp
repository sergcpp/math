#pragma once

#include "dvec3.hpp"

namespace math {
	//class mat4;
    //class quat;

    class dmat3 {
        double9 vec_;

        friend class dmat4;
    public:
        dmat3(e_noinit) { assert(is_aligned(this, alignment)); }
        dmat3() : dmat3(1.0f) {}
        explicit dmat3(double v) : dmat3(noinit) { dmat3_init1(vec_, v); }
        dmat3(double v00, double v01, double v02,
              double v10, double v11, double v12,
              double v20, double v21, double v22) : dmat3(noinit) {
            dmat3_init9(vec_, v00, v01, v02, v10, v11, v12, v20, v21, v22);
        }
        dmat3(const dvec3 &v0, const dvec3 &v1, const dvec3 &v2) : dmat3(noinit) {
            dmat3_init3(vec_, v0.vec_, v1.vec_, v2.vec_);
        }
        dmat3(const double9 &v) : dmat3(noinit) { vec_ = v; }
        dmat3(const dmat3 &v) : dmat3(noinit) { vec_ = v.vec_; }
		dmat3(const dmat4 &v);

        class deref {
            double9 &v_; int i_;
        public:
            deref(double9 &v, int i) : v_(v), i_(i) {}
            operator dvec3() const { return dmat3_get(v_, i_); }
            deref operator=(const dvec3 &rhs) { dmat3_set(v_, i_, rhs.vec_); return *this; }
            deref operator=(const deref &rhs) { return operator=((dvec3)rhs); }

            dvec3::deref operator[] (int i) const { return dvec3::deref(v_.vec3[i_], i); }

            deref operator+=(const dvec3 &rhs) { *this = dvec3(*this) + rhs; return *this; }
            deref operator-=(const dvec3 &rhs) { *this = dvec3(*this) - rhs; return *this; }
            deref operator*=(const dvec3 &rhs) { *this = dvec3(*this) * rhs; return *this; }
            deref operator/=(const dvec3 &rhs) { *this = dvec3(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        dvec3 operator[] (int i) const { return dvec3(vec_.vec3[i]); }

        dmat3 &operator++() { (*this) = (*this) + dmat3(1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        dmat3 operator++(int) { dmat3 temp = (*this); ++(*this); return temp; }
        dmat3 &operator--() { (*this) = (*this) - dmat3(1, 1, 1, 1, 1, 1, 1, 1, 1); return *this; }
        dmat3 operator--(int) { dmat3 temp = (*this); --(*this); return temp; }

        dmat3 &operator+=(const dmat3 &rhs) { (*this) = (*this) + rhs; return *this; }
        dmat3 &operator-=(const dmat3 &rhs) { (*this) = (*this) - rhs; return *this; }
        dmat3 &operator*=(const dmat3 &rhs) { (*this) = (*this) * rhs; return *this; }
        dmat3 &operator/=(const dmat3 &rhs) { (*this) = (*this) / rhs; return *this; }

        dmat3 operator-() const { return matrix_comp_mult((*this), dmat3(-1, -1, -1, -1, -1, -1, -1, -1, -1)); }

        friend bool operator==(const dmat3 &m1, const dmat3 &m2);

        friend dmat3 operator+(const dmat3 &m1, const dmat3 &m2);
        friend dmat3 operator-(const dmat3 &m1, const dmat3 &m2);
        friend dmat3 operator*(const dmat3 &m1, const dmat3 &m2);
        friend dmat3 operator/(const dmat3 &m1, const dmat3 &m2);

        friend dmat3 operator*(const dmat3 &m1, double v1);
        friend dmat3 operator/(const dmat3 &m1, double v1);

        friend dvec3 operator*(const dmat3 &m, const dvec3 &v);
        friend dvec3 operator*(const dvec3 &v, const dmat3 &m);

        friend dmat3 matrix_comp_mult(const dmat3 &m1, const dmat3 &m2);

        friend dmat3 inverse(const dmat3 &m);

        friend const double *value_ptr(const dmat3 &m);

        //friend dquat to_quat(const dmat3 &m);

        static const size_t alignment = alignment_m32;
		using scalar_type = double;
    };

    inline bool operator==(const dmat3 &m1, const dmat3 &m2) { return dmat3_eq_dmat3(m1.vec_, m2.vec_); }
    inline bool operator!=(const dmat3 &m1, const dmat3 &m2) { return !operator==(m1, m2); }

    inline dmat3 operator+(const dmat3 &m1, const dmat3 &m2) { return dmat3(dmat3_add_dmat3(m1.vec_, m2.vec_)); }
    inline dmat3 operator-(const dmat3 &m1, const dmat3 &m2) { return dmat3(dmat3_sub_dmat3(m1.vec_, m2.vec_)); }
    inline dmat3 operator*(const dmat3 &m1, const dmat3 &m2) { return dmat3(dmat3_mul_dmat3(m1.vec_, m2.vec_)); }
    inline dmat3 operator/(const dmat3 &m1, const dmat3 &m2) { return dmat3(dmat3_div_dmat3(m1.vec_, m2.vec_)); }

    inline dmat3 operator*(const dmat3 &m1, double v1) { return dmat3_mul_double(m1.vec_, v1); }
    inline dmat3 operator*(double v1, const dmat3 &m1) { return operator*(m1, v1); }
    inline dmat3 operator/(const dmat3 &m1, double v1) { return dmat3_div_double(m1.vec_, v1); }

    inline dmat3 matrix_comp_mult(const dmat3 &m1, const dmat3 &m2) { return dmat3_comp_mul(m1.vec_, m2.vec_); }

    inline dmat3 make_dmat3(const double v[9]) {
        return dmat3(v[0], v[1], v[2], 
                     v[3], v[4], v[5], 
                     v[6], v[7], v[8]);
    }

    inline const double *value_ptr(const dmat3 &m) {
        return &m.vec_.comp[0];
    }

    inline dvec3 operator*(const dmat3 &m, const dvec3 &v) { return dvec3(dmat3_mul_dvec3(m.vec_, v.vec_)); }
    inline dvec3 operator*(const dvec3 &v, const dmat3 &m) { return dvec3(dvec3_mul_dmat3(v.vec_, m.vec_)); }
}

//#include "dmat4.hpp"
//#include "dquat.hpp"

namespace math {
	//inline dmat3::dmat3(const dmat4 &v) : dmat3(v[0][0], v[0][1], v[0][2], v[1][0], v[1][1], v[1][2], v[2][0], v[2][1], v[2][2]) {}

    //inline dquat to_quat(const dmat3 &m) { return dquat(dmat3_to_dquat(m.vec_)); }
}