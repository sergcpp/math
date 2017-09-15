#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class dvec3;
    class dvec4;
    class vec2;

    class dvec2 {
        double2 vec_;

        friend class mat2;
    public:
        dvec2(e_noinit) { assert(is_aligned(this, alignment)); }
        dvec2() : dvec2(noinit) { dvec2_init1(vec_, 0); }
        explicit dvec2(double v) : dvec2(noinit) { dvec2_init1(vec_, v); }
        dvec2(double v0, double v1) { dvec2_init2(vec_, v0, v1); }
        dvec2(const double2 &v) { vec_ = v; }
        dvec2(const dvec3 &v);
        dvec2(const dvec4 &v);
        explicit dvec2(const vec2 &v);

        class deref {
            double2 &v_; int i_;
        public:
            deref(double2 &v, int i) : v_(v), i_(i) {}
            operator double() const { return dvec2_get(v_, i_); }
            deref operator=(const double rhs) { dvec2_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((double)rhs); }

            deref operator+=(double rhs) { *this = double(*this) + rhs; return *this; }
            deref operator-=(double rhs) { *this = double(*this) - rhs; return *this; }
            deref operator*=(double rhs) { *this = double(*this) * rhs; return *this; }
            deref operator/=(double rhs) { *this = double(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        double operator[] (int i) const { return dvec2_get(vec_, i); }

        double x() const { return (*this)[0]; }
        double y() const { return (*this)[1]; }

        double r() const { return (*this)[0]; }
        double g() const { return (*this)[1]; }

        double s() const { return (*this)[0]; }
        double t() const { return (*this)[1]; }

        dvec2 &operator++() { (*this) = (*this) + dvec2(1); return *this; }
        dvec2 operator++(int) { dvec2 temp = (*this); ++(*this); return temp; }
        dvec2 &operator--() { (*this) = (*this) - dvec2(1); return *this; }
        dvec2 operator--(int) { dvec2 temp = (*this); --(*this); return temp; }

        dvec2 &operator+=(const dvec2 &rhs) { (*this) = (*this) + rhs; return *this; }
        dvec2 &operator-=(const dvec2 &rhs) { (*this) = (*this) - rhs; return *this; }
        dvec2 &operator*=(const dvec2 &rhs) { (*this) = (*this) * rhs; return *this; }
        dvec2 &operator/=(const dvec2 &rhs) { (*this) = (*this) / rhs; return *this; }

        inline dvec2 operator-() const;

        friend bool operator==(const dvec2 &v1, const dvec2 &v2);

        friend dvec2 operator+(const dvec2 &v1, const dvec2 &v2);
        friend dvec2 operator-(const dvec2 &v1, const dvec2 &v2);
        friend dvec2 operator*(const dvec2 &v1, const dvec2 &v2);
        friend dvec2 operator/(const dvec2 &v1, const dvec2 &v2);

        //friend dvec2 operator*(const mat2 &m, const vec2 &v);
        //friend dvec2 operator*(const vec2 &v, const mat2 &m);

        friend const double *value_ptr(const dvec2 &v);

        friend double length(const dvec2 &vec);
        /*friend float dot(const vec2 &v1, const vec2 &v2);
        friend vec2 normalize(const vec2 &v);
        friend vec2 normalize_fast(const vec2 &v);

        friend vec2 sin(const vec2 &angle);
        friend vec2 cos(const vec2 &angle);
        friend vec2 tan(const vec2 &angle);
        friend vec2 asin(const vec2 &angle);
        friend vec2 acos(const vec2 &angle);
        friend vec2 atan(const vec2 &angle);*/

        static const size_t alignment = alignment_m128;
		using scalar_type = double;
    };

    inline bool operator==(const dvec2 &v1, const dvec2 &v2) { return dvec2_eq_dvec2(v1.vec_, v2.vec_); }
    inline bool operator!=(const dvec2 &v1, const dvec2 &v2) { return !operator==(v1, v2); }

    inline dvec2 operator+(const dvec2 &v1, const dvec2 &v2) { return dvec2(dvec2_add_dvec2(v1.vec_, v2.vec_)); }
    inline dvec2 operator-(const dvec2 &v1, const dvec2 &v2) { return dvec2(dvec2_sub_dvec2(v1.vec_, v2.vec_)); }
    inline dvec2 operator*(const dvec2 &v1, const dvec2 &v2) { return dvec2(dvec2_mul_dvec2(v1.vec_, v2.vec_)); }
    inline dvec2 operator/(const dvec2 &v1, const dvec2 &v2) { return dvec2(dvec2_div_dvec2(v1.vec_, v2.vec_)); }

    inline dvec2 operator+(const dvec2 &v, double f) { return v + dvec2(f); }
    inline dvec2 operator+(double f, const dvec2 &v) { return dvec2(f) + v; }
    inline dvec2 operator-(const dvec2 &v, double f) { return v - dvec2(f); }
    inline dvec2 operator-(double f, const dvec2 &v) { return dvec2(f) - v; }
    inline dvec2 operator*(const dvec2 &v, double f) { return v * dvec2(f); }
    inline dvec2 operator*(double f, const dvec2 &v) { return dvec2(f) * v; }
    inline dvec2 operator/(const dvec2 &v, double f) { return v / dvec2(f); }
    inline dvec2 operator/(double f, const dvec2 &v) { return dvec2(f) / v; }

    dvec2 dvec2::operator-() const { return (*this) * -1.0; }

    inline dvec2 make_dvec2(const float v[2]) { return dvec2(v[0], v[1]); }
    inline const double *value_ptr(const dvec2 &v) { return &v.vec_.comp[0]; }
}

#include "dvec3.hpp"
#include "dvec4.hpp"
#include "vec2.hpp"

namespace math {
    inline dvec2::dvec2(const dvec3 &v) { dvec2_init2(vec_, v[0], v[1]); }
    inline dvec2::dvec2(const dvec4 &v) { dvec2_init2(vec_, v[0], v[1]); }
    inline dvec2::dvec2(const vec2 &v) : dvec2(noinit) { dvec2_init2(vec_, double(v[0]), double(v[1])); }

    //inline vec2 operator*(const mat2 &m, const vec2 &v) { return vec2(mat2_mul_vec2(m.vec_, v.vec_)); }
    //inline vec2 operator*(const vec2 &v, const mat2 &m) { return vec2(vec2_mul_mat2(v.vec_, m.vec_)); }

    inline double operator*(double f1, const dvec2::deref &f2) { return f1 * double(f2); }
    inline double operator/(double f1, const dvec2::deref &f2) { return f1 / double(f2); }
    inline dvec2 operator*(const dvec2 &v, const dvec2::deref &f) { return v * double(f); }
    inline dvec2 operator/(const dvec2 &v, const dvec2::deref &f) { return v / double(f); }
    inline dvec3 operator*(const dvec3 &v, const dvec2::deref &f) { return v * double(f); }
    inline dvec3 operator/(const dvec3 &v, const dvec2::deref &f) { return v / double(f); }
    inline dvec4 operator*(const dvec4 &v, const dvec2::deref &f) { return v * double(f); }
    inline dvec4 operator/(const dvec4 &v, const dvec2::deref &f) { return v / double(f); }
}