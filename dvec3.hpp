#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class dvec2;
    class dvec4;
    class vec3;

    class dvec3 {
    public:
		union {
			double3 vec_;
			struct { double x, y, z; };
			struct { double r, g, b; };
			struct { double s, t, p; };
		};

        dvec3(e_noinit) { assert(is_aligned(this, alignment)); }
        dvec3() : dvec3(noinit) { dvec3_init1(vec_, 0); }
        explicit dvec3(double v) : dvec3(noinit) { dvec3_init1(vec_, v); }
        dvec3(double v0, double v1, double v2) : dvec3(noinit) { dvec3_init3(vec_, v0, v1, v2); }
        dvec3(const double3 &v) : dvec3(noinit) { vec_ = v; }
        dvec3(const dvec2 &v01, double v2);
        dvec3(double v0, const dvec2 &v12);
        dvec3(const dvec4 &v);
        explicit dvec3(const vec3 &v);

        double &operator[] (int i) { return vec_.comp[i]; }
        double operator[] (int i) const { return vec_.comp[i]; }

        dvec3 &operator++();
        dvec3 operator++(int);
        dvec3 &operator--();
        dvec3 operator--(int);

        dvec3 &operator+=(const dvec3 &rhs);
        dvec3 &operator-=(const dvec3 &rhs);
        dvec3 &operator*=(const dvec3 &rhs);
        dvec3 &operator/=(const dvec3 &rhs);

        inline dvec3 operator-() const;

        static const size_t alignment = alignment_m32;
		using scalar_type = double;
    };

    inline bool operator==(const dvec3 &v1, const dvec3 &v2) { return dvec3_eq_dvec3(v1.vec_, v2.vec_); }
    inline bool operator!=(const dvec3 &v1, const dvec3 &v2) { return !operator==(v1, v2); }

    inline dvec3 operator+(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_add_dvec3(v1.vec_, v2.vec_)); }
    inline dvec3 operator-(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_sub_dvec3(v1.vec_, v2.vec_)); }
    inline dvec3 operator*(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_mul_dvec3(v1.vec_, v2.vec_)); }
    inline dvec3 operator/(const dvec3 &v1, const dvec3 &v2) { return dvec3(dvec3_div_dvec3(v1.vec_, v2.vec_)); }

    inline dvec3 operator+(const dvec3 &v, double f) { return v + dvec3(f); }
    inline dvec3 operator+(double f, const dvec3 &v) { return dvec3(f) + v; }
    inline dvec3 operator-(const dvec3 &v, double f) { return v - dvec3(f); }
    inline dvec3 operator-(double f, const dvec3 &v) { return dvec3(f) - v; }
    inline dvec3 operator*(const dvec3 &v, double f) { return v * dvec3(f); }
    inline dvec3 operator*(double f, const dvec3 &v) { return dvec3(f) * v; }
    inline dvec3 operator/(const dvec3 &v, double f) { return v / dvec3(f); }
    inline dvec3 operator/(double f, const dvec3 &v) { return dvec3(f) / v; }

	inline dvec3 &dvec3::operator++() { (*this) = (*this) + dvec3(1); return *this; }
	inline dvec3 dvec3::operator++(int) { dvec3 temp = (*this); ++(*this); return temp; }
	inline dvec3 &dvec3::operator--() { (*this) = (*this) - dvec3(1); return *this; }
	inline dvec3 dvec3::operator--(int) { dvec3 temp = (*this); --(*this); return temp; }

	inline dvec3 &dvec3::operator+=(const dvec3 &rhs) { (*this) = (*this) + rhs; return *this; }
	inline dvec3 &dvec3::operator-=(const dvec3 &rhs) { (*this) = (*this) - rhs; return *this; }
	inline dvec3 &dvec3::operator*=(const dvec3 &rhs) { (*this) = (*this) * rhs; return *this; }
	inline dvec3 &dvec3::operator/=(const dvec3 &rhs) { (*this) = (*this) / rhs; return *this; }

    dvec3 dvec3::operator-() const { return (*this) * -1.0; }

    inline dvec3 make_vec3(const double v[3]) { return dvec3(v[0], v[1], v[2]); }
    inline const double *value_ptr(const dvec3 &v) { return &v.vec_.comp[0]; }
}

#include "dvec2.hpp"
#include "dvec4.hpp"
#include "vec3.hpp"

namespace math {
    inline dvec3::dvec3(const dvec2 &v01, double v2) : dvec3(noinit) { dvec3_init3(vec_, v01[0], v01[1], v2); }
    inline dvec3::dvec3(double v0, const dvec2 &v12) : dvec3(noinit) { dvec3_init3(vec_, v0, v12[0], v12[1]); }
    inline dvec3::dvec3(const dvec4 &v) : dvec3(noinit) { dvec3_init3(vec_, v[0], v[1], v[2]); }
    inline dvec3::dvec3(const vec3 &v) : dvec3(noinit) { dvec3_init3(vec_, double(v[0]), double(v[1]), double(v[2])); }

    //inline vec3 operator*(const mat3 &m, const vec3 &v) { return vec3(mat3_mul_vec3(m.vec_, v.vec_)); }
    //inline vec3 operator*(const vec3 &v, const mat3 &m) { return vec3(vec3_mul_mat3(v.vec_, m.vec_)); }
}