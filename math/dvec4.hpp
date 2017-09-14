#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class dvec2;
    class dvec3;
    class vec4;

    class dvec4 {
        double4 vec_;

    public:
        dvec4(e_noinit) { assert(is_aligned(this, alignment)); }
        dvec4() : dvec4(noinit) { dvec4_init1(vec_, 0); }
        dvec4(double v) : dvec4(noinit) { dvec4_init1(vec_, v); }
        dvec4(double v0, double v1, double v2, double v3) : dvec4(noinit) { dvec4_init4(vec_, v0, v1, v2, v3); }
        dvec4(const double4 &v) : dvec4(noinit) { vec_ = v; }
        dvec4(const dvec2 &v01, const dvec2 &v23);
        dvec4(const dvec2 &v01, double v2, double v3);
        dvec4(double v0, const dvec2 &v12, double v3);
        dvec4(double v0, double v1, const dvec2 &v23);
        dvec4(const dvec3 &v012, double v3);
        dvec4(double v0, const dvec3 &v123);
        explicit dvec4(const vec4 &v);

        class deref {
            double4 &v_; int i_;
        public:
            deref(double4 &v, int i) : v_(v), i_(i) {}
            operator double() const { return dvec4_get(v_, i_); }
            deref operator=(const double rhs) { dvec4_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((double)rhs); }

            deref operator+=(double rhs) { *this = double(*this) + rhs; return *this; }
            deref operator-=(double rhs) { *this = double(*this) - rhs; return *this; }
            deref operator*=(double rhs) { *this = double(*this) * rhs; return *this; }
            deref operator/=(double rhs) { *this = double(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        double operator[] (int i) const { return dvec4_get(vec_, i); }

        double x() const { return (*this)[0]; }
        double y() const { return (*this)[1]; }
        double z() const { return (*this)[2]; }
        double w() const { return (*this)[3]; }

        double r() const { return (*this)[0]; }
        double g() const { return (*this)[1]; }
        double b() const { return (*this)[2]; }
        double a() const { return (*this)[3]; }

        double s() const { return (*this)[0]; }
        double t() const { return (*this)[1]; }
        double p() const { return (*this)[2]; }
        double q() const { return (*this)[3]; }

        dvec4 &operator++() { (*this) = (*this) + dvec4(1); return *this; }
        dvec4 operator++(int) { dvec4 temp = (*this); ++(*this); return temp; }
        dvec4 &operator--() { (*this) = (*this) - dvec4(1); return *this; }
        dvec4 operator--(int) { dvec4 temp = (*this); --(*this); return temp; }

        dvec4 &operator+=(const dvec4 &rhs) { (*this) = (*this) + rhs; return *this; }
        dvec4 &operator-=(const dvec4 &rhs) { (*this) = (*this) - rhs; return *this; }
        dvec4 &operator*=(const dvec4 &rhs) { (*this) = (*this) * rhs; return *this; }
        dvec4 &operator/=(const dvec4 &rhs) { (*this) = (*this) / rhs; return *this; }

        dvec4 operator-() const { return (*this) * -1; }

        friend bool operator==(const dvec4 &v1, const dvec4 &v2);

        friend dvec4 operator+(const dvec4 &v1, const dvec4 &v2);
        friend dvec4 operator-(const dvec4 &v1, const dvec4 &v2);
        friend dvec4 operator*(const dvec4 &v1, const dvec4 &v2);
        friend dvec4 operator/(const dvec4 &v1, const dvec4 &v2);

        //friend dvec4 operator*(const mat4 &m, const vec4 &v);
        //friend dvec4 operator*(const vec4 &v, const mat4 &m);

        friend const double *value_ptr(const dvec4 &v);

        friend double length(const dvec4 &v);
        /*friend float dot(const vec4 &v1, const vec4 &v2);
        friend vec4 normalize(const vec4 &v);
        friend vec4 normalize_fast(const vec4 &v);

        friend vec4 sin(const vec4 &angle);
        friend vec4 cos(const vec4 &angle);
        friend vec4 tan(const vec4 &angle);
        friend vec4 asin(const vec4 &angle);
        friend vec4 acos(const vec4 &angle);
        friend vec4 atan(const vec4 &angle);*/

        static const size_t alignment = alignment_m256;
    };

    inline bool operator==(const dvec4 &v1, const dvec4 &v2) { return dvec4_eq_dvec4(v1.vec_, v2.vec_); }
    inline bool operator!=(const dvec4 &v1, const dvec4 &v2) { return !operator==(v1, v2); }

    inline dvec4 operator+(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_add_dvec4(v1.vec_, v2.vec_)); }
    inline dvec4 operator-(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_sub_dvec4(v1.vec_, v2.vec_)); }
    inline dvec4 operator*(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_mul_dvec4(v1.vec_, v2.vec_)); }
    inline dvec4 operator/(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_div_dvec4(v1.vec_, v2.vec_)); }

    inline dvec4 make_dvec4(const double v[4]) { return dvec4(v[0], v[1], v[2], v[3]); }
    inline const double *value_ptr(const dvec4 &v) { return &v.vec_.comp[0]; }
}

#include "dvec2.hpp"
#include "dvec3.hpp"

namespace math {
    inline dvec4::dvec4(const dvec2 &v01, const dvec2 &v23) : dvec4(noinit) { dvec4_init4(vec_, v01[0], v01[1], v23[0], v23[1]); }
    inline dvec4::dvec4(const dvec2 &v01, double v2, double v3) : dvec4(noinit) { dvec4_init4(vec_, v01[0], v01[1], v2, v3); }
    inline dvec4::dvec4(double v0, const dvec2 &v12, double v3) : dvec4(noinit) { dvec4_init4(vec_, v0, v12[0], v12[1], v3); }
    inline dvec4::dvec4(double v0, double v1, const dvec2 &v23) : dvec4(noinit) { dvec4_init4(vec_, v0, v1, v23[0], v23[1]); }
    inline dvec4::dvec4(const dvec3 &v012, double v3) : dvec4(noinit) { dvec4_init4(vec_, v012[0], v012[1], v012[2], v3); }
    inline dvec4::dvec4(double v0, const dvec3 &v123) : dvec4(noinit) { dvec4_init4(vec_, v0, v123[0], v123[1], v123[2]); }
    inline dvec4::dvec4(const vec4 &v) : dvec4(noinit) { dvec4_init4(vec_, double(v[0]), double(v[1]), double(v[2]), double(v[3])); }

    //inline vec4 operator*(const mat4 &m, const vec4 &v) { return vec4(mat4_mul_vec4(m.vec_, v.vec_)); }
    //inline vec4 operator*(const vec4 &v, const mat4 &m) { return vec4(vec4_mul_mat4(v.vec_, m.vec_)); }

    inline double operator*(double f1, const dvec4::deref &f2) { return f1 * double(f2); }
    inline double operator/(double f1, const dvec4::deref &f2) { return f1 / double(f2); }
    inline dvec2 operator*(const dvec2 &v, const dvec4::deref &f) { return v * double(f); }
    inline dvec2 operator/(const dvec2 &v, const dvec4::deref &f) { return v / double(f); }
    inline dvec3 operator*(const dvec3 &v, const dvec4::deref &f) { return v * double(f); }
    inline dvec3 operator/(const dvec3 &v, const dvec4::deref &f) { return v / double(f); }
    inline dvec4 operator*(const dvec4 &v, const dvec4::deref &f) { return v * double(f); }
    inline dvec4 operator/(const dvec4 &v, const dvec4::deref &f) { return v / double(f); }
}