#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class dvec3;
    class dvec4;
    class vec2;

    class dvec2 {
    public:
        union {
            double2 vec_;
            struct { double x, y; };
            struct { double r, g; };
            struct { double s, t; };
        };

        dvec2(e_noinit) { assert(is_aligned(this, alignment)); }
        dvec2() : dvec2(noinit) { dvec2_init1(vec_, 0); }
        explicit dvec2(double v) : dvec2(noinit) { dvec2_init1(vec_, v); }
        dvec2(double v0, double v1) { dvec2_init2(vec_, v0, v1); }
        dvec2(const double2 &v) { vec_ = v; }
        dvec2(const dvec3 &v);
        dvec2(const dvec4 &v);
        explicit dvec2(const vec2 &v);

        double &operator[] (int i) { return vec_.comp[i]; }
        double operator[] (int i) const { return vec_.comp[i]; }

        dvec2 &operator++();
        dvec2 operator++(int);
        dvec2 &operator--();
        dvec2 operator--(int);

        dvec2 &operator+=(const dvec2 &rhs);
        dvec2 &operator-=(const dvec2 &rhs);
        dvec2 &operator*=(const dvec2 &rhs);
        dvec2 &operator/=(const dvec2 &rhs);

        inline dvec2 operator-() const;

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

    inline dvec2 &dvec2::operator++() { (*this) = (*this) + dvec2(1); return *this; }
    inline dvec2 dvec2::operator++(int) { dvec2 temp = (*this); ++(*this); return temp; }
    inline dvec2 &dvec2::operator--() { (*this) = (*this) - dvec2(1); return *this; }
    inline dvec2 dvec2::operator--(int) { dvec2 temp = (*this); --(*this); return temp; }

    inline dvec2 &dvec2::operator+=(const dvec2 &rhs) { (*this) = (*this) + rhs; return *this; }
    inline dvec2 &dvec2::operator-=(const dvec2 &rhs) { (*this) = (*this) - rhs; return *this; }
    inline dvec2 &dvec2::operator*=(const dvec2 &rhs) { (*this) = (*this) * rhs; return *this; }
    inline dvec2 &dvec2::operator/=(const dvec2 &rhs) { (*this) = (*this) / rhs; return *this; }

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
}