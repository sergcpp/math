#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec2;
    class ivec3;
    class vec4;

    class ivec4 {
    public:
		union {
			int4 vec_;
			struct { int x, y, z, w; };
			struct { int r, g, b, a; };
			struct { int s, t, p, q; };
		};

        ivec4(e_noinit) { assert(is_aligned(this, alignment)); }
        ivec4() { ivec4_init1(vec_, 0); }
        explicit ivec4(int v) { ivec4_init1(vec_, v); }
        ivec4(int v0, int v1, int v2, int v3) { ivec4_init4(vec_, v0, v1, v2, v3); }
        ivec4(const int4 &v) { vec_ = v; }
        ivec4(const ivec2 &v01, const ivec2 &v23);
        ivec4(const ivec2 &v01, int v2, int v3);
        ivec4(int v0, const ivec2 &v12, int v3);
        ivec4(int v0, int v1, const ivec2 &v23);
        ivec4(const ivec3 &v012, int v3);
        ivec4(int v0, const ivec3 &v123);
        explicit ivec4(const vec4 &v);

        int &operator[] (int i) { return vec_.comp[i]; }
        int operator[] (int i) const { return vec_.comp[i]; }

        ivec4 &operator++() { (*this) = (*this) + ivec4(1); return *this; }
        ivec4 operator++(int) { ivec4 temp = (*this); ++(*this); return temp; }
        ivec4 &operator--() { (*this) = (*this) - ivec4(1); return *this; }
        ivec4 operator--(int) { ivec4 temp = (*this); --(*this); return temp; }

        ivec4 &operator+=(const ivec4 &rhs) { (*this) = (*this) + rhs; return *this; }
        ivec4 &operator-=(const ivec4 &rhs) { (*this) = (*this) - rhs; return *this; }
        ivec4 &operator*=(const ivec4 &rhs) { (*this) = (*this) * rhs; return *this; }
        ivec4 &operator/=(const ivec4 &rhs) { (*this) = (*this) / rhs; return *this; }

        ivec4 operator-() const;

        friend bool operator==(const ivec4 &v1, const ivec4 &v2);

        friend ivec4 operator+(const ivec4 &v1, const ivec4 &v2);
        friend ivec4 operator-(const ivec4 &v1, const ivec4 &v2);
        friend ivec4 operator*(const ivec4 &v1, const ivec4 &v2);
        friend ivec4 operator/(const ivec4 &v1, const ivec4 &v2);

		friend const int *value_ptr(const ivec4 &v);

        static const size_t alignment = alignment_m128;
		using scalar_type = int;
    };

    inline bool operator==(const ivec4 &v1, const ivec4 &v2) { return ivec4_eq_ivec4(v1.vec_, v2.vec_); }
    inline bool operator!=(const ivec4 &v1, const ivec4 &v2) { return !operator==(v1, v2); }

    inline ivec4 operator+(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_add_ivec4(v1.vec_, v2.vec_)); }
    inline ivec4 operator-(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_sub_ivec4(v1.vec_, v2.vec_)); }
    inline ivec4 operator*(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_mul_ivec4(v1.vec_, v2.vec_)); }
    inline ivec4 operator/(const ivec4 &v1, const ivec4 &v2) { return ivec4(ivec4_div_ivec4(v1.vec_, v2.vec_)); }

    inline ivec4 operator+(const ivec4 &v, int f) { return v + ivec4(f); }
    inline ivec4 operator+(int f, const ivec4 &v) { return ivec4(f) + v; }
    inline ivec4 operator-(const ivec4 &v, int f) { return v - ivec4(f); }
    inline ivec4 operator-(int f, const ivec4 &v) { return ivec4(f) - v; }
    inline ivec4 operator*(const ivec4 &v, int f) { return v * ivec4(f); }
    inline ivec4 operator*(int f, const ivec4 &v) { return ivec4(f) * v; }
    inline ivec4 operator/(const ivec4 &v, int f) { return v / ivec4(f); }
    inline ivec4 operator/(int f, const ivec4 &v) { return ivec4(f) / v; }

    inline ivec4 ivec4::operator-() const { return (*this) * -1; }

	inline const int *value_ptr(const ivec4 &v) { return &v.vec_.comp[0]; }
}

#include "ivec2.hpp"
#include "ivec3.hpp"
#include "vec4.hpp"

namespace math {
    inline ivec4::ivec4(const ivec2 &v01, const ivec2 &v23) : ivec4(noinit) { ivec4_init4(vec_, v01[0], v01[1], v23[0], v23[1]); }
    inline ivec4::ivec4(const ivec2 &v01, int v2, int v3) : ivec4(noinit) { ivec4_init4(vec_, v01[0], v01[1], v2, v3); }
    inline ivec4::ivec4(int v0, const ivec2 &v12, int v3) : ivec4(noinit) { ivec4_init4(vec_, v0, v12[0], v12[1], v3); }
    inline ivec4::ivec4(int v0, int v1, const ivec2 &v23) : ivec4(noinit) { ivec4_init4(vec_, v0, v1, v23[0], v23[1]); }
    inline ivec4::ivec4(const ivec3 &v012, int v3) : ivec4(noinit) { ivec4_init4(vec_, v012[0], v012[1], v012[2], v3); }
    inline ivec4::ivec4(int v0, const ivec3 &v123) : ivec4(noinit) { ivec4_init4(vec_, v0, v123[0], v123[1], v123[2]); }
    inline ivec4::ivec4(const vec4 &v) : ivec4(noinit) { ivec4_init4(vec_, int(v[0]), int(v[1]), int(v[2]), int(v[3])); }
}