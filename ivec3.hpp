#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec2;
    class ivec4;
    class vec3;

    class ivec3 {
    public:
        union {
            int3 vec_;
            struct { int x, y, z; };
            struct { int r, g, b; };
            struct { int s, t, p; };
        };

        ivec3(e_noinit) { assert(is_aligned(this, alignment)); }
        ivec3() : ivec3(noinit) { ivec3_init1(vec_, 0); }
        explicit ivec3(int v) : ivec3(noinit) { ivec3_init1(vec_, v); }
        ivec3(int v0, int v1, int v2) : ivec3(noinit) { ivec3_init3(vec_, v0, v1, v2); }
        ivec3(const int3 &v) : ivec3(noinit) { vec_ = v; }
        ivec3(const ivec2 &v01, int v2);
        ivec3(int v0, const ivec2 &v12);
        ivec3(const ivec4 &v);
        explicit ivec3(const vec3 &v);

        int &operator[] (int i) { return vec_.comp[i]; }
        int operator[] (int i) const { return vec_.comp[i]; }

        ivec3 &operator+=(const ivec3 &rhs) { ivec3_add_ivec3(vec_, rhs.vec_); return *this; }
        ivec3 &operator-=(const ivec3 &rhs) { ivec3_sub_ivec3(vec_, rhs.vec_); return *this; }
        ivec3 &operator*=(const ivec3 &rhs) { ivec3_mul_ivec3(vec_, rhs.vec_); return *this; }
        ivec3 &operator/=(const ivec3 &rhs) { ivec3_div_ivec3(vec_, rhs.vec_); return *this; }

        ivec3 &operator++() { (*this) += ivec3(1); return *this; }
        ivec3 operator++(int) { ivec3 temp = (*this); ++(*this); return temp; }
        ivec3 &operator--() { (*this) -= ivec3(1); return *this; }
        ivec3 operator--(int) { ivec3 temp = (*this); --(*this); return temp; }

        ivec3 operator-() const;

        static const size_t alignment = alignment_m32;
        using scalar_type = int;
    };

    inline bool operator==(const ivec3 &v1, const ivec3 &v2) { return ivec3_eq_ivec3(v1.vec_, v2.vec_); }
    inline bool operator!=(const ivec3 &v1, const ivec3 &v2) { return !operator==(v1, v2); }

    inline ivec3 operator+(const ivec3 &v1, const ivec3 &v2) { ivec3 temp = v1; temp += v2; return temp; }
    inline ivec3 operator-(const ivec3 &v1, const ivec3 &v2) { ivec3 temp = v1; temp -= v2; return temp; }
    inline ivec3 operator*(const ivec3 &v1, const ivec3 &v2) { ivec3 temp = v1; temp *= v2; return temp; }
    inline ivec3 operator/(const ivec3 &v1, const ivec3 &v2) { ivec3 temp = v1; temp /= v2; return temp; }

    inline ivec3 operator+(const ivec3 &v, int f) { return v + ivec3(f); }
    inline ivec3 operator+(int f, const ivec3 &v) { return ivec3(f) + v; }
    inline ivec3 operator-(const ivec3 &v, int f) { return v - ivec3(f); }
    inline ivec3 operator-(int f, const ivec3 &v) { return ivec3(f) - v; }
    inline ivec3 operator*(const ivec3 &v, int f) { return v * ivec3(f); }
    inline ivec3 operator*(int f, const ivec3 &v) { return ivec3(f) * v; }
    inline ivec3 operator/(const ivec3 &v, int f) { return v / ivec3(f); }
    inline ivec3 operator/(int f, const ivec3 &v) { return ivec3(f) / v; }

    inline ivec3 ivec3::operator-() const { return (*this) * -1; }

    inline const int *value_ptr(const ivec3 &v) { return &v.vec_.comp[0]; }
}

#include "ivec2.hpp"
#include "ivec4.hpp"

namespace math {
    inline ivec3::ivec3(const ivec2 &v01, int v2) : ivec3(noinit) { ivec3_init3(vec_, v01[0], v01[1], v2); }
    inline ivec3::ivec3(int v0, const ivec2 &v12) : ivec3(noinit) { ivec3_init3(vec_, v0, v12[0], v12[1]); }
    inline ivec3::ivec3(const ivec4 &v) : ivec3(noinit) { ivec3_init3(vec_, v[0], v[1], v[2]); }
    inline ivec3::ivec3(const vec3 &v) : ivec3(noinit) { ivec3_init3(vec_, int(v[0]), int(v[1]), int(v[2])); }
}