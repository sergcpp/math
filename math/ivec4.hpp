#pragma once

#include "math_funcs.hpp"

namespace math {
    class ivec2;
    class ivec3;
    class vec4;

    class ivec4 {
        int4 vec_;
    public:
        ivec4(e_uninitialize) { assert(is_aligned(this, alignment)); }
        ivec4() { ivec4_init1(vec_, 0); }
        ivec4(int v) { ivec4_init1(vec_, v); }
        ivec4(int v0, int v1, int v2, int v3) { ivec4_init4(vec_, v0, v1, v2, v3); }
        ivec4(const int4 &v) { vec_ = v; }
        ivec4(const ivec2 &v01, const ivec2 &v23);
        ivec4(const ivec2 &v01, int v2, int v3);
        ivec4(int v0, const ivec2 &v12, int v3);
        ivec4(int v0, int v1, const ivec2 &v23);
        ivec4(const ivec3 &v012, int v3);
        ivec4(int v0, const ivec3 &v123);
        explicit ivec4(const vec4 &v);

        class deref {
            int4 &v_; int i_;
        public:
            deref(int4 &v, int i) : v_(v), i_(i) {}
            operator int() const { return ivec4_get(v_, i_); }
            deref operator=(const int rhs) { ivec4_set(v_, i_, rhs); return *this; }
            deref operator=(const deref &rhs) { return operator=((int)rhs); }

            deref operator+=(int rhs) { *this = int(*this) + rhs; return *this; }
            deref operator-=(int rhs) { *this = int(*this) - rhs; return *this; }
            deref operator*=(int rhs) { *this = int(*this) * rhs; return *this; }
            deref operator/=(int rhs) { *this = int(*this) / rhs; return *this; }
        };

        deref operator[] (int i) { return deref(vec_, i); }
        int operator[] (int i) const { return ivec4_get(vec_, i); }

        int x() const { return (*this)[0]; }
        int y() const { return (*this)[1]; }
        int z() const { return (*this)[2]; }
        int w() const { return (*this)[3]; }

        int r() const { return (*this)[0]; }
        int g() const { return (*this)[1]; }
        int b() const { return (*this)[2]; }
        int a() const { return (*this)[3]; }

        int s() const { return (*this)[0]; }
        int t() const { return (*this)[1]; }
        int p() const { return (*this)[2]; }
        int q() const { return (*this)[3]; }

        ivec4 &operator++() { (*this) = (*this) + ivec4(1); return *this; }
        ivec4 operator++(int) { ivec4 temp = (*this); ++(*this); return temp; }
        ivec4 &operator--() { (*this) = (*this) - ivec4(1); return *this; }
        ivec4 operator--(int) { ivec4 temp = (*this); --(*this); return temp; }

        ivec4 &operator+=(const ivec4 &rhs) { (*this) = (*this) + rhs; return *this; }
        ivec4 &operator-=(const ivec4 &rhs) { (*this) = (*this) - rhs; return *this; }
        ivec4 &operator*=(const ivec4 &rhs) { (*this) = (*this) * rhs; return *this; }
        ivec4 &operator/=(const ivec4 &rhs) { (*this) = (*this) / rhs; return *this; }

        ivec4 operator-() const { return (*this) * -1; }

        friend bool operator==(const ivec4 &v1, const ivec4 &v2);

        friend ivec4 operator+(const ivec4 &v1, const ivec4 &v2);
        friend ivec4 operator-(const ivec4 &v1, const ivec4 &v2);
        friend ivec4 operator*(const ivec4 &v1, const ivec4 &v2);
        friend ivec4 operator/(const ivec4 &v1, const ivec4 &v2);

        static const size_t alignment = alignment_m128;
    };

    inline bool operator==(const ivec4 &v1, const ivec4 &v2) { return ivec4_eq_ivec4(v1.vec_, v2.vec_); }
    inline bool operator!=(const ivec4 &v1, const ivec4 &v2) { return !operator==(v1, v2); }

    inline ivec4 operator+(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_add_ivec4(v1.vec_, v2.vec_)); }
    inline ivec4 operator-(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_sub_ivec4(v1.vec_, v2.vec_)); }
    inline ivec4 operator*(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_mul_ivec4(v1.vec_, v2.vec_)); }
    inline ivec4 operator/(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_div_ivec4(v1.vec_, v2.vec_)); }
}

#include "ivec2.hpp"
#include "ivec3.hpp"
#include "vec4.hpp"

namespace math {
    inline ivec4::ivec4(const ivec2 &v01, const ivec2 &v23) : ivec4(uninitialize) { ivec4_init4(vec_, v01[0], v01[1], v23[0], v23[1]); }
    inline ivec4::ivec4(const ivec2 &v01, int v2, int v3) : ivec4(uninitialize) { ivec4_init4(vec_, v01[0], v01[1], v2, v3); }
    inline ivec4::ivec4(int v0, const ivec2 &v12, int v3) : ivec4(uninitialize) { ivec4_init4(vec_, v0, v12[0], v12[1], v3); }
    inline ivec4::ivec4(int v0, int v1, const ivec2 &v23) : ivec4(uninitialize) { ivec4_init4(vec_, v0, v1, v23[0], v23[1]); }
    inline ivec4::ivec4(const ivec3 &v012, int v3) : ivec4(uninitialize) { ivec4_init4(vec_, v012[0], v012[1], v012[2], v3); }
    inline ivec4::ivec4(int v0, const ivec3 &v123) : ivec4(uninitialize) { ivec4_init4(vec_, v0, v123[0], v123[1], v123[2]); }
    inline ivec4::ivec4(const vec4 &v) : ivec4(uninitialize) { ivec4_init4(vec_, int(v[0]), int(v[1]), int(v[2]), int(v[3])); }

    inline int operator*(int f1, const ivec4::deref &f2) { return f1 * int(f2); }
    inline int operator/(int f1, const ivec4::deref &f2) { return f1 / int(f2); }
    inline ivec2 operator*(const ivec2 &v, const ivec4::deref &f) { return v * int(f); }
    inline ivec2 operator/(const ivec2 &v, const ivec4::deref &f) { return v / int(f); }
    inline ivec3 operator*(const ivec3 &v, const ivec4::deref &f) { return v * int(f); }
    inline ivec3 operator/(const ivec3 &v, const ivec4::deref &f) { return v / int(f); }
    inline ivec4 operator*(const ivec4 &v, const ivec4::deref &f) { return v * int(f); }
    inline ivec4 operator/(const ivec4 &v, const ivec4::deref &f) { return v / int(f); }
}