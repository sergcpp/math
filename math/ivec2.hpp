#pragma once

#include "math_funcs.hpp"

namespace math {
    class ivec3;
    class ivec4;
    class vec2;

    class ivec2 {
        int2 vec_;
    public:
        ivec2(e_uninitialize) { assert(is_aligned(this, alignment)); }
        ivec2() : ivec2(uninitialize) { ivec2_init1(vec_, 0); }
        explicit ivec2(int v) : ivec2(uninitialize) { ivec2_init1(vec_, v); }
        ivec2(int v0, int v1) : ivec2(uninitialize) { ivec2_init2(vec_, v0, v1); }
        ivec2(const int2 &v) : ivec2(uninitialize) { vec_ = v; }
        ivec2(const ivec3 &v);
        ivec2(const ivec4 &v);
        explicit ivec2(const vec2 &v);

        class deref {
            int2 &v_; int i_;
        public:
            deref(int2 &v, int i) : v_(v), i_(i) {}
            operator int() const { return ivec2_get(v_, i_); }
            deref operator=(const int rhs) { ivec2_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((int)rhs); }

            deref operator+=(int rhs) { *this = int(*this) + rhs; return *this; }
            deref operator-=(int rhs) { *this = int(*this) - rhs; return *this; }
            deref operator*=(int rhs) { *this = int(*this) * rhs; return *this; }
            deref operator/=(int rhs) { *this = int(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        int operator[] (int i) const { return ivec2_get(vec_, i); }

        int x() const { return (*this)[0]; }
        int y() const { return (*this)[1]; }

        int r() const { return (*this)[0]; }
        int g() const { return (*this)[1]; }

        int s() const { return (*this)[0]; }
        int t() const { return (*this)[1]; }

        ivec2 &operator++() { (*this) = (*this) + ivec2(1); return *this; }
        ivec2 operator++(int) { ivec2 temp = (*this); ++(*this); return temp; }
        ivec2 &operator--() { (*this) = (*this) - ivec2(1); return *this; }
        ivec2 operator--(int) { ivec2 temp = (*this); --(*this); return temp; }

        ivec2 &operator+=(const ivec2 &rhs) { (*this) = (*this) + rhs; return *this; }
        ivec2 &operator-=(const ivec2 &rhs) { (*this) = (*this) - rhs; return *this; }
        ivec2 &operator*=(const ivec2 &rhs) { (*this) = (*this) * rhs; return *this; }
        ivec2 &operator/=(const ivec2 &rhs) { (*this) = (*this) / rhs; return *this; }

        ivec2 operator-() const;

        friend bool operator==(const ivec2 &v1, const ivec2 &v2);

        friend ivec2 operator+(const ivec2 &v1, const ivec2 &v2);
        friend ivec2 operator-(const ivec2 &v1, const ivec2 &v2);
        friend ivec2 operator*(const ivec2 &v1, const ivec2 &v2);
        friend ivec2 operator/(const ivec2 &v1, const ivec2 &v2);

        static const size_t alignment = alignment_m64;
    };

    inline bool operator==(const ivec2 &v1, const ivec2 &v2) { return ivec2_eq_ivec2(v1.vec_, v2.vec_); }
    inline bool operator!=(const ivec2 &v1, const ivec2 &v2) { return !operator==(v1, v2); }

    inline ivec2 operator+(const ivec2 &v1, const ivec2 &v2) { return ivec2(ivec2_add_ivec2(v1.vec_, v2.vec_)); }
    inline ivec2 operator-(const ivec2 &v1, const ivec2 &v2) { return ivec2(ivec2_sub_ivec2(v1.vec_, v2.vec_)); }
    inline ivec2 operator*(const ivec2 &v1, const ivec2 &v2) { return ivec2(ivec2_mul_ivec2(v1.vec_, v2.vec_)); }
    inline ivec2 operator/(const ivec2 &v1, const ivec2 &v2) { return ivec2(ivec2_div_ivec2(v1.vec_, v2.vec_)); }

    inline ivec2 operator+(const ivec2 &v, int f) { return v + ivec2(f); }
    inline ivec2 operator+(int f, const ivec2 &v) { return ivec2(f) + v; }
    inline ivec2 operator-(const ivec2 &v, int f) { return v - ivec2(f); }
    inline ivec2 operator-(int f, const ivec2 &v) { return ivec2(f) - v; }
    inline ivec2 operator*(const ivec2 &v, int f) { return v * ivec2(f); }
    inline ivec2 operator*(int f, const ivec2 &v) { return ivec2(f) * v; }
    inline ivec2 operator/(const ivec2 &v, int f) { return v / ivec2(f); }
    inline ivec2 operator/(int f, const ivec2 &v) { return ivec2(f) / v; }

    inline ivec2 ivec2::operator-() const { return (*this) * -1; }
}

#include "ivec3.hpp"
#include "ivec4.hpp"
#include "vec2.hpp"

namespace math {
    inline ivec2::ivec2(const ivec3 &v) { ivec2_init2(vec_, v[0], v[1]); }
    inline ivec2::ivec2(const ivec4 &v) { ivec2_init2(vec_, v[0], v[1]); }
    inline ivec2::ivec2(const vec2 &v) { ivec2_init2(vec_, int(v[0]), int(v[1])); }

    inline int operator*(int f1, const ivec2::deref &f2) { return f1 * int(f2); }
    inline int operator/(int f1, const ivec2::deref &f2) { return f1 / int(f2); }
    inline ivec2 operator*(const ivec2 &v, const ivec2::deref &f) { return v * int(f); }
    inline ivec2 operator/(const ivec2 &v, const ivec2::deref &f) { return v / int(f); }
    inline ivec3 operator*(const ivec3 &v, const ivec2::deref &f) { return v * int(f); }
    inline ivec3 operator/(const ivec3 &v, const ivec2::deref &f) { return v / int(f); }
    inline ivec4 operator*(const ivec4 &v, const ivec2::deref &f) { return v * int(f); }
    inline ivec4 operator/(const ivec4 &v, const ivec2::deref &f) { return v / int(f); }
}