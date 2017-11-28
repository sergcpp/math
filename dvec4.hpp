#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class dvec2;
    class dvec3;
    class vec4;

    class dvec4 {
    public:
        union {
            double4 vec_;
            struct { double x, y, z, w; };
            struct { double r, g, b, a; };
            struct { double s, t, p, q; };
        };

        dvec4(e_noinit) { assert(is_aligned(this, alignment)); }
        dvec4() : dvec4(noinit) { dvec4_init1(vec_, 0); }
        explicit dvec4(double v) : dvec4(noinit) { dvec4_init1(vec_, v); }
        dvec4(double v0, double v1, double v2, double v3) : dvec4(noinit) { dvec4_init4(vec_, v0, v1, v2, v3); }
        dvec4(const double4 &v) : dvec4(noinit) { vec_ = v; }
        dvec4(const dvec2 &v01, const dvec2 &v23);
        dvec4(const dvec2 &v01, double v2, double v3);
        dvec4(double v0, const dvec2 &v12, double v3);
        dvec4(double v0, double v1, const dvec2 &v23);
        dvec4(const dvec3 &v012, double v3);
        dvec4(double v0, const dvec3 &v123);
        explicit dvec4(const vec4 &v);

        double &operator[] (int i) { return vec_.comp[i]; }
        double operator[] (int i) const { return vec_.comp[i]; }

        dvec4 &operator++();
        dvec4 operator++(int);
        dvec4 &operator--();
        dvec4 operator--(int);

        dvec4 &operator+=(const dvec4 &rhs);
        dvec4 &operator-=(const dvec4 &rhs);
        dvec4 &operator*=(const dvec4 &rhs);
        dvec4 &operator/=(const dvec4 &rhs);

        dvec4 operator-() const;

        static const size_t alignment = alignment_m256;
        using scalar_type = double;
    };

    inline bool operator==(const dvec4 &v1, const dvec4 &v2) { return dvec4_eq_dvec4(v1.vec_, v2.vec_); }
    inline bool operator!=(const dvec4 &v1, const dvec4 &v2) { return !operator==(v1, v2); }

    inline dvec4 operator+(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_add_dvec4(v1.vec_, v2.vec_)); }
    inline dvec4 operator-(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_sub_dvec4(v1.vec_, v2.vec_)); }
    inline dvec4 operator*(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_mul_dvec4(v1.vec_, v2.vec_)); }
    inline dvec4 operator/(const dvec4 &v1, const dvec4 &v2) { return dvec4(dvec4_div_dvec4(v1.vec_, v2.vec_)); }

    inline dvec4 operator+(const dvec4 &v, double f) { return v + dvec4(f); }
    inline dvec4 operator+(double f, const dvec4 &v) { return dvec4(f) + v; }
    inline dvec4 operator-(const dvec4 &v, double f) { return v - dvec4(f); }
    inline dvec4 operator-(double f, const dvec4 &v) { return dvec4(f) - v; }
    inline dvec4 operator*(const dvec4 &v, double f) { return v * dvec4(f); }
    inline dvec4 operator*(double f, const dvec4 &v) { return dvec4(f) * v; }
    inline dvec4 operator/(const dvec4 &v, double f) { return v / dvec4(f); }
    inline dvec4 operator/(double f, const dvec4 &v) { return dvec4(f) / v; }

    inline dvec4 &dvec4::operator++() { (*this) = (*this) + dvec4(1); return *this; }
    inline dvec4 dvec4::operator++(int) { dvec4 temp = (*this); ++(*this); return temp; }
    inline dvec4 &dvec4::operator--() { (*this) = (*this) - dvec4(1); return *this; }
    inline dvec4 dvec4::operator--(int) { dvec4 temp = (*this); --(*this); return temp; }

    inline dvec4 &dvec4::operator+=(const dvec4 &rhs) { (*this) = (*this) + rhs; return *this; }
    inline dvec4 &dvec4::operator-=(const dvec4 &rhs) { (*this) = (*this) - rhs; return *this; }
    inline dvec4 &dvec4::operator*=(const dvec4 &rhs) { (*this) = (*this) * rhs; return *this; }
    inline dvec4 &dvec4::operator/=(const dvec4 &rhs) { (*this) = (*this) / rhs; return *this; }

    inline dvec4 dvec4::operator-() const { return (*this) * -1.0; }

    inline dvec4 make_dvec4(const double v[4]) { return dvec4(v[0], v[1], v[2], v[3]); }
    inline const double *value_ptr(const dvec4 &v) { return &v.vec_.comp[0]; }
}

#include "dvec2.hpp"
#include "dvec3.hpp"
#include "vec4.hpp"

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
}