#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec3;
    class ivec4;
    class vec2;

    class ivec2 {
    public:
		union {
			int2 vec_;
			struct { int x, y; };
			struct { int r, g; };
			struct { int s, t; };
		};

        ivec2(e_noinit) { assert(is_aligned(this, alignment)); }
        ivec2() : ivec2(noinit) { ivec2_init1(vec_, 0); }
        explicit ivec2(int v) : ivec2(noinit) { ivec2_init1(vec_, v); }
        ivec2(int v0, int v1) : ivec2(noinit) { ivec2_init2(vec_, v0, v1); }
        ivec2(const int2 &v) : ivec2(noinit) { vec_ = v; }
        ivec2(const ivec3 &v);
        ivec2(const ivec4 &v);
        explicit ivec2(const vec2 &v);

        int &operator[] (int i) { return vec_.comp[i]; }
        int operator[] (int i) const { return vec_.comp[i]; }

        ivec2 &operator++();
        ivec2 operator++(int);
        ivec2 &operator--();
        ivec2 operator--(int);

        ivec2 &operator+=(const ivec2 &rhs);
        ivec2 &operator-=(const ivec2 &rhs);
        ivec2 &operator*=(const ivec2 &rhs);
        ivec2 &operator/=(const ivec2 &rhs);

        ivec2 operator-() const;

        static const size_t alignment = alignment_m64;
		using scalar_type = int;
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

	inline ivec2 &ivec2::operator++() { (*this) = (*this) + ivec2(1); return *this; }
	inline ivec2 ivec2::operator++(int) { ivec2 temp = (*this); ++(*this); return temp; }
	inline ivec2 &ivec2::operator--() { (*this) = (*this) - ivec2(1); return *this; }
	inline ivec2 ivec2::operator--(int) { ivec2 temp = (*this); --(*this); return temp; }

	inline ivec2 &ivec2::operator+=(const ivec2 &rhs) { (*this) = (*this) + rhs; return *this; }
	inline ivec2 &ivec2::operator-=(const ivec2 &rhs) { (*this) = (*this) - rhs; return *this; }
	inline ivec2 &ivec2::operator*=(const ivec2 &rhs) { (*this) = (*this) * rhs; return *this; }
	inline ivec2 &ivec2::operator/=(const ivec2 &rhs) { (*this) = (*this) / rhs; return *this; }

    inline ivec2 ivec2::operator-() const { return (*this) * -1; }

	inline const int *value_ptr(const ivec2 &v) { return &v.vec_.comp[0]; }
}

#include "ivec3.hpp"
#include "ivec4.hpp"
#include "vec2.hpp"

namespace math {
    inline ivec2::ivec2(const ivec3 &v) { ivec2_init2(vec_, v[0], v[1]); }
    inline ivec2::ivec2(const ivec4 &v) { ivec2_init2(vec_, v[0], v[1]); }
    inline ivec2::ivec2(const vec2 &v) { ivec2_init2(vec_, int(v[0]), int(v[1])); }
}