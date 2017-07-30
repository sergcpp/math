#pragma once

#include "math_funcs.hpp"

namespace math {
    class dvec2;
    class dvec4;
    class vec3;

    class dvec3 {
        double3 vec_;

        friend class mat3;
    public:
        dvec3(e_uninitialize) { assert(is_aligned(this, alignment)); }
        dvec3() : dvec3(uninitialize) { dvec3_init1(vec_, 0); }
        dvec3(double v) : dvec3(uninitialize) { dvec3_init1(vec_, v); }
        dvec3(double v0, double v1, double v2) : dvec3(uninitialize) { dvec3_init3(vec_, v0, v1, v2); }
        dvec3(const double3 &v) : dvec3(uninitialize) { vec_ = v; }
        dvec3(const dvec2 &v01, double v2);
        dvec3(double v0, const dvec2 &v12);
        dvec3(const dvec4 &v);
        explicit dvec3(const vec3 &v);

        class deref {
            double3 &v_; int i_;
        public:
            deref(double3 &v, int i) : v_(v), i_(i) {}
            operator double() const { return dvec3_get(v_, i_); }
            deref operator=(const double rhs) { dvec3_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((double)rhs); }

            deref operator+=(double rhs) { *this = double(*this) + rhs; return *this; }
            deref operator-=(double rhs) { *this = double(*this) - rhs; return *this; }
            deref operator*=(double rhs) { *this = double(*this) * rhs; return *this; }
            deref operator/=(double rhs) { *this = double(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        double operator[] (int i) const { return dvec3_get(vec_, i); }

        double x() const { return (*this)[0]; }
        double y() const { return (*this)[1]; }
        double z() const { return (*this)[2]; }

        double r() const { return (*this)[0]; }
        double g() const { return (*this)[1]; }
        double b() const { return (*this)[2]; }

        double s() const { return (*this)[0]; }
        double t() const { return (*this)[1]; }
        double p() const { return (*this)[2]; }

        dvec3 &operator++() { (*this) = (*this) + dvec3(1); return *this; }
        dvec3 operator++(int) { dvec3 temp = (*this); ++(*this); return temp; }
        dvec3 &operator--() { (*this) = (*this) - dvec3(1); return *this; }
        dvec3 operator--(int) { dvec3 temp = (*this); --(*this); return temp; }

        dvec3 &operator+=(const dvec3 &rhs) { (*this) = (*this) + rhs; return *this; }
        dvec3 &operator-=(const dvec3 &rhs) { (*this) = (*this) - rhs; return *this; }
        dvec3 &operator*=(const dvec3 &rhs) { (*this) = (*this) * rhs; return *this; }
        dvec3 &operator/=(const dvec3 &rhs) { (*this) = (*this) / rhs; return *this; }

        dvec3 operator-() const { return (*this) * -1; }

        friend bool operator==(const dvec3 &v1, const dvec3 &v2);

        friend dvec3 operator+(const dvec3 &v1, const dvec3 &v2);
        friend dvec3 operator-(const dvec3 &v1, const dvec3 &v2);
        friend dvec3 operator*(const dvec3 &v1, const dvec3 &v2);
        friend dvec3 operator/(const dvec3 &v1, const dvec3 &v2);

        //friend dvec3 operator*(const mat3 &m, const vec3 &v);
        //friend dvec3 operator*(const vec3 &v, const mat3 &m);

        friend const double *value_ptr(const dvec3 &v);

        friend double length(const dvec3 &v);
        /*friend float dot(const vec3 &v1, const vec3 &v2);
        friend vec3 cross(const vec3 &v1, const vec3 &v2);
        friend vec3 normalize(const vec3 &v);
        friend vec3 normalize_fast(const vec3 &v);

        friend vec3 sin(const vec3 &angle);
        friend vec3 cos(const vec3 &angle);
        friend vec3 tan(const vec3 &angle);
        friend vec3 asin(const vec3 &angle);
        friend vec3 acos(const vec3 &angle);
        friend vec3 atan(const vec3 &angle);*/

        static const size_t alignment = alignment_m32;
    };

    inline bool operator==(const dvec3 &v1, const dvec3 &v2) { return dvec3_eq_dvec3(v1.vec_, v2.vec_); }
    inline bool operator!=(const dvec3 &v1, const dvec3 &v2) { return !operator==(v1, v2); }

    inline dvec3 operator+(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_add_dvec3(v1.vec_, v2.vec_)); }
    inline dvec3 operator-(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_sub_dvec3(v1.vec_, v2.vec_)); }
    inline dvec3 operator*(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_mul_dvec3(v1.vec_, v2.vec_)); }
    inline dvec3 operator/(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_div_dvec3(v1.vec_, v2.vec_)); }

    inline dvec3 make_vec3(const double v[3]) { return dvec3(v[0], v[1], v[2]); }
    inline const double *value_ptr(const dvec3 &v) { return &v.vec_.comp[0]; }
}

#include "dvec2.hpp"
#include "dvec4.hpp"
#include "vec3.hpp"

namespace math {
    inline dvec3::dvec3(const dvec2 &v01, double v2) : dvec3(uninitialize) { dvec3_init3(vec_, v01[0], v01[1], v2); }
    inline dvec3::dvec3(double v0, const dvec2 &v12) : dvec3(uninitialize) { dvec3_init3(vec_, v0, v12[0], v12[1]); }
    inline dvec3::dvec3(const dvec4 &v) : dvec3(uninitialize) { dvec3_init3(vec_, v[0], v[1], v[2]); }
    inline dvec3::dvec3(const vec3 &v) : dvec3(uninitialize) { dvec3_init3(vec_, double(v[0]), double(v[1]), double(v[2])); }

    //inline vec3 operator*(const mat3 &m, const vec3 &v) { return vec3(mat3_mul_vec3(m.vec_, v.vec_)); }
    //inline vec3 operator*(const vec3 &v, const mat3 &m) { return vec3(vec3_mul_mat3(v.vec_, m.vec_)); }

    inline double operator*(double f1, const dvec3::deref &f2) { return f1 * double(f2); }
    inline double operator/(double f1, const dvec3::deref &f2) { return f1 / double(f2); }
    inline dvec2 operator*(const dvec2 &v, const dvec3::deref &f) { return v * double(f); }
    inline dvec2 operator/(const dvec2 &v, const dvec3::deref &f) { return v / double(f); }
    inline dvec3 operator*(const dvec3 &v, const dvec3::deref &f) { return v * double(f); }
    inline dvec3 operator/(const dvec3 &v, const dvec3::deref &f) { return v / double(f); }
    inline dvec4 operator*(const dvec4 &v, const dvec3::deref &f) { return v * double(f); }
    inline dvec4 operator/(const dvec4 &v, const dvec3::deref &f) { return v / double(f); }
}