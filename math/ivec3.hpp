#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec2;
    class ivec4;
    class vec3;

    class ivec3 {
        int3 vec_;
    public:
        ivec3(e_uninitialize) { assert(is_aligned(this, alignment)); }
        ivec3() : ivec3(uninitialize) { ivec3_init1(vec_, 0); }
        explicit ivec3(int v) : ivec3(uninitialize) { ivec3_init1(vec_, v); }
        ivec3(int v0, int v1, int v2) : ivec3(uninitialize) { ivec3_init3(vec_, v0, v1, v2); }
        ivec3(const int3 &v) : ivec3(uninitialize) { vec_ = v; }
        ivec3(const ivec2 &v01, int v2);
        ivec3(int v0, const ivec2 &v12);
        ivec3(const ivec4 &v);
        explicit ivec3(const vec3 &v);

        class deref {
            int3 &v_; int i_;
        public:
            deref(int3 &v, int i) : v_(v), i_(i) {}
            operator int() const { return ivec3_get(v_, i_); }
            deref operator=(const int rhs) { ivec3_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((int)rhs); }

            deref operator+=(int rhs) { *this = int(*this) + rhs; return *this; }
            deref operator-=(int rhs) { *this = int(*this) - rhs; return *this; }
            deref operator*=(int rhs) { *this = int(*this) * rhs; return *this; }
            deref operator/=(int rhs) { *this = int(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        int operator[] (int i) const { return ivec3_get(vec_, i); }

        int x() const { return (*this)[0]; }
        int y() const { return (*this)[1]; }
        int z() const { return (*this)[2]; }

        int r() const { return (*this)[0]; }
        int g() const { return (*this)[1]; }
        int b() const { return (*this)[2]; }

        int s() const { return (*this)[0]; }
        int t() const { return (*this)[1]; }
        int p() const { return (*this)[2]; }

        ivec3 &operator++() { (*this) = (*this) + ivec3(1); return *this; }
        ivec3 operator++(int) { ivec3 temp = (*this); ++(*this); return temp; }
        ivec3 &operator--() { (*this) = (*this) - ivec3(1); return *this; }
        ivec3 operator--(int) { ivec3 temp = (*this); --(*this); return temp; }

        ivec3 &operator+=(const ivec3 &rhs) { (*this) = (*this) + rhs; return *this; }
        ivec3 &operator-=(const ivec3 &rhs) { (*this) = (*this) - rhs; return *this; }
        ivec3 &operator*=(const ivec3 &rhs) { (*this) = (*this) * rhs; return *this; }
        ivec3 &operator/=(const ivec3 &rhs) { (*this) = (*this) / rhs; return *this; }

        ivec3 operator-() const;

        friend bool operator==(const ivec3 &v1, const ivec3 &v2);

        friend ivec3 operator+(const ivec3 &v1, const ivec3 &v2);
        friend ivec3 operator-(const ivec3 &v1, const ivec3 &v2);
        friend ivec3 operator*(const ivec3 &v1, const ivec3 &v2);
        friend ivec3 operator/(const ivec3 &v1, const ivec3 &v2);

        static const size_t alignment = alignment_m32;
    };

    inline bool operator==(const ivec3 &v1, const ivec3 &v2) { return ivec3_eq_ivec3(v1.vec_, v2.vec_); }
    inline bool operator!=(const ivec3 &v1, const ivec3 &v2) { return !operator==(v1, v2); }

    inline ivec3 operator+(const ivec3 &v1, const ivec3 &v2) { return ivec3(ivec3_add_ivec3(v1.vec_, v2.vec_)); }
    inline ivec3 operator-(const ivec3 &v1, const ivec3 &v2) { return ivec3(ivec3_sub_ivec3(v1.vec_, v2.vec_)); }
    inline ivec3 operator*(const ivec3 &v1, const ivec3 &v2) { return ivec3(ivec3_mul_ivec3(v1.vec_, v2.vec_)); }
    inline ivec3 operator/(const ivec3 &v1, const ivec3 &v2) { return ivec3(ivec3_div_ivec3(v1.vec_, v2.vec_)); }

    inline ivec3 operator+(const ivec3 &v, int f) { return v + ivec3(f); }
    inline ivec3 operator+(int f, const ivec3 &v) { return ivec3(f) + v; }
    inline ivec3 operator-(const ivec3 &v, int f) { return v - ivec3(f); }
    inline ivec3 operator-(int f, const ivec3 &v) { return ivec3(f) - v; }
    inline ivec3 operator*(const ivec3 &v, int f) { return v * ivec3(f); }
    inline ivec3 operator*(int f, const ivec3 &v) { return ivec3(f) * v; }
    inline ivec3 operator/(const ivec3 &v, int f) { return v / ivec3(f); }
    inline ivec3 operator/(int f, const ivec3 &v) { return ivec3(f) / v; }

    inline ivec3 ivec3::operator-() const { return (*this) * -1; }
}

#include "ivec2.hpp"
#include "ivec4.hpp"

namespace math {
    inline ivec3::ivec3(const ivec2 &v01, int v2) : ivec3(uninitialize) { ivec3_init3(vec_, v01[0], v01[1], v2); }
    inline ivec3::ivec3(int v0, const ivec2 &v12) : ivec3(uninitialize) { ivec3_init3(vec_, v0, v12[0], v12[1]); }
    inline ivec3::ivec3(const ivec4 &v) : ivec3(uninitialize) { ivec3_init3(vec_, v[0], v[1], v[2]); }
    inline ivec3::ivec3(const vec3 &v) : ivec3(uninitialize) { ivec3_init3(vec_, int(v[0]), int(v[1]), int(v[2])); }

    inline int operator*(int f1, const ivec3::deref &f2) { return f1 * int(f2); }
    inline int operator/(int f1, const ivec3::deref &f2) { return f1 / int(f2); }
    inline ivec2 operator*(const ivec2 &v, const ivec3::deref &f) { return v * int(f); }
    inline ivec2 operator/(const ivec2 &v, const ivec3::deref &f) { return v / int(f); }
    inline ivec3 operator*(const ivec3 &v, const ivec3::deref &f) { return v * int(f); }
    inline ivec3 operator/(const ivec3 &v, const ivec3::deref &f) { return v / int(f); }
    inline ivec4 operator*(const ivec4 &v, const ivec3::deref &f) { return v * int(f); }
    inline ivec4 operator/(const ivec4 &v, const ivec3::deref &f) { return v / int(f); }
}