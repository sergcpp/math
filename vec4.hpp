#pragma once

#include "internal/math_funcs.hpp"

namespace math {
    class ivec4;
    class mat4;
    class vec2;
    class vec3;

    class vec4 {
    public:
        union {
            float4 vec_;
            struct { float x, y, z, w; };
            struct { float r, g, b, a; };
            struct { float s, t, p, q; };
        };

        vec4(e_noinit) { assert(is_aligned(this, alignment)); }
        vec4() : vec4(noinit) { vec4_init1(vec_, 0); }
        explicit vec4(float v) : vec4(noinit) { vec4_init1(vec_, v); }
        vec4(float v0, float v1, float v2, float v3) : vec4(noinit) { vec4_init4(vec_, v0, v1, v2, v3); }
        vec4(const float4 &v) : vec4(noinit) { vec_ = v; }
        vec4(const vec2 &v01, const vec2 &v23);
        vec4(const vec2 &v01, float v2, float v3);
        vec4(float v0, const vec2 &v12, float v3);
        vec4(float v0, float v1, const vec2 &v23);
        vec4(const vec3 &v012, float v3);
        vec4(float v0, const vec3 &v123);
        explicit vec4(const ivec4 &v);

        float &operator[] (int i) { return vec_.comp[i]; }
        float operator[] (int i) const { return vec_.comp[i]; }

        vec4 &operator++() { (*this) = (*this) + vec4(1); return *this; }
        vec4 operator++(int) { vec4 temp = (*this); ++(*this); return temp; }
        vec4 &operator--() { (*this) = (*this) - vec4(1); return *this; }
        vec4 operator--(int) { vec4 temp = (*this); --(*this); return temp; }

        vec4 &operator+=(const vec4 &rhs) { (*this) = (*this) + rhs; return *this; }
        vec4 &operator-=(const vec4 &rhs) { (*this) = (*this) - rhs; return *this; }
        vec4 &operator*=(const vec4 &rhs) { (*this) = (*this) * rhs; return *this; }
        vec4 &operator/=(const vec4 &rhs) { (*this) = (*this) / rhs; return *this; }

        vec4 &operator+=(float rhs);
        vec4 &operator-=(float rhs);
        vec4 &operator*=(float rhs);
        vec4 &operator/=(float rhs);

        vec4 operator-() const;

        friend bool operator==(const vec4 &v1, const vec4 &v2);

        friend vec4 operator+(const vec4 &v1, const vec4 &v2);
        friend vec4 operator-(const vec4 &v1, const vec4 &v2);
        friend vec4 operator*(const vec4 &v1, const vec4 &v2);
        friend vec4 operator/(const vec4 &v1, const vec4 &v2);

        friend vec4 operator*(const mat4 &m, const vec4 &v);
        friend vec4 operator*(const vec4 &v, const mat4 &m);

        friend const float *value_ptr(const vec4 &v);

        friend float length(const vec4 &v);
        friend float dot(const vec4 &v1, const vec4 &v2);
        friend vec4 normalize(const vec4 &v);
        friend vec4 normalize_fast(const vec4 &v);

        friend vec4 sin(const vec4 &angle);
        friend vec4 cos(const vec4 &angle);
        friend vec4 tan(const vec4 &angle);
        friend vec4 asin(const vec4 &angle);
        friend vec4 acos(const vec4 &angle);
        friend vec4 atan(const vec4 &angle);

        static const size_t alignment = alignment_m128;
        using scalar_type = float;
    };

    inline bool operator==(const vec4 &v1, const vec4 &v2) { return vec4_eq_vec4(v1.vec_, v2.vec_); }
    inline bool operator!=(const vec4 &v1, const vec4 &v2) { return !operator==(v1, v2); }

    inline vec4 operator+(const vec4 &v1, const vec4 &v2) { return vec4(vec4_add_vec4(v1.vec_, v2.vec_)); }
    inline vec4 operator-(const vec4 &v1, const vec4 &v2) { return vec4(vec4_sub_vec4(v1.vec_, v2.vec_)); }
    inline vec4 operator*(const vec4 &v1, const vec4 &v2) { return vec4(vec4_mul_vec4(v1.vec_, v2.vec_)); }
    inline vec4 operator/(const vec4 &v1, const vec4 &v2) { return vec4(vec4_div_vec4(v1.vec_, v2.vec_)); }

    inline vec4 operator+(const vec4 &v, float f) { return v + vec4(f); }
    inline vec4 operator+(float f, const vec4 &v) { return vec4(f) + v; }
    inline vec4 operator-(const vec4 &v, float f) { return v - vec4(f); }
    inline vec4 operator-(float f, const vec4 &v) { return vec4(f) - v; }
    inline vec4 operator*(const vec4 &v, float f) { return v * vec4(f); }
    inline vec4 operator*(float f, const vec4 &v) { return vec4(f) * v; }
    inline vec4 operator/(const vec4 &v, float f) { return v / vec4(f); }
    inline vec4 operator/(float f, const vec4 &v) { return vec4(f) / v; }

    inline vec4 &vec4::operator+=(float rhs) { (*this) = (*this) + rhs; return *this; }
    inline vec4 &vec4::operator-=(float rhs) { (*this) = (*this) - rhs; return *this; }
    inline vec4 &vec4::operator*=(float rhs) { (*this) = (*this) * rhs; return *this; }
    inline vec4 &vec4::operator/=(float rhs) { (*this) = (*this) / rhs; return *this; }

    inline vec4 vec4::operator-() const { return (*this) * -1.0f; }

    inline vec4 make_vec4(const float v[4]) { return vec4(v[0], v[1], v[2], v[3]); }
    inline const float *value_ptr(const vec4 &v) { return &v.vec_.comp[0]; }
}

#include "mat4.hpp"
#include "vec2.hpp"
#include "vec3.hpp"

namespace math {
    inline vec4::vec4(const vec2 &v01, const vec2 &v23) : vec4(noinit) { vec4_init4(vec_, v01[0], v01[1], v23[0], v23[1]); }
    inline vec4::vec4(const vec2 &v01, float v2, float v3) : vec4(noinit) { vec4_init4(vec_, v01[0], v01[1], v2, v3); }
    inline vec4::vec4(float v0, const vec2 &v12, float v3) : vec4(noinit) { vec4_init4(vec_, v0, v12[0], v12[1], v3); }
    inline vec4::vec4(float v0, float v1, const vec2 &v23) : vec4(noinit) { vec4_init4(vec_, v0, v1, v23[0], v23[1]); }
    inline vec4::vec4(const vec3 &v012, float v3) : vec4(noinit) { vec4_init4(vec_, v012[0], v012[1], v012[2], v3); }
    inline vec4::vec4(float v0, const vec3 &v123) : vec4(noinit) { vec4_init4(vec_, v0, v123[0], v123[1], v123[2]); }
    inline vec4::vec4(const ivec4 &v) : vec4(noinit) { vec4_init4(vec_, float(v[0]), float(v[1]), float(v[2]), float(v[3])); }

    inline vec4 operator*(const mat4 &m, const vec4 &v) { return vec4(mat4_mul_vec4(m.vec_, v.vec_)); }
    inline vec4 operator*(const vec4 &v, const mat4 &m) { return vec4(vec4_mul_mat4(v.vec_, m.vec_)); }
}