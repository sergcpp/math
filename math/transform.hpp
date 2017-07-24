#pragma once

#include "mat4.hpp"
#include "vec3.hpp"

#include "geometric.hpp"
#include "trigonometric.hpp"

namespace math {
    inline mat2 inverse(const mat2 &m) { return mat2(mat2_inverse(m.vec_)); }
    inline mat3 inverse(const mat3 &m) { return mat3(mat3_inverse(m.vec_)); }
    inline mat4 inverse(const mat4 &m) { return mat4(mat4_inverse(m.vec_)); }

    inline mat4 translate(const mat4 &m, const vec3 &v) {
        mat4 res;
        res[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
        return res;
    }

    inline mat4 rotate(const mat4 &m, float angle_rad, const vec3 &_axis) {
        const float a = angle_rad;
        const float c = cos(a);
        const float s = sin(a);

        vec3 axis = normalize(_axis);
        vec3 temp = (1.0f - c) * axis;

        mat4 rot(uninitialize);
        rot[0][0] = c + temp[0] * axis[0];
        rot[0][1] = 0 + temp[0] * axis[1] + s * axis[2];
        rot[0][2] = 0 + temp[0] * axis[2] - s * axis[1];

        rot[1][0] = 0 + temp[1] * axis[0] - s * axis[2];
        rot[1][1] = c + temp[1] * axis[1];
        rot[1][2] = 0 + temp[1] * axis[2] + s * axis[0];

        rot[2][0] = 0 + temp[2] * axis[0] + s * axis[1];
        rot[2][1] = 0 + temp[2] * axis[1] - s * axis[0];
        rot[2][2] = c + temp[2] * axis[2];

        mat4 res(uninitialize);
        res[0] = m[0] * rot[0][0] + m[1] * rot[0][1] + m[2] * rot[0][2];
        res[1] = m[0] * rot[1][0] + m[1] * rot[1][1] + m[2] * rot[1][2];
        res[2] = m[0] * rot[2][0] + m[1] * rot[2][1] + m[2] * rot[2][2];
        res[3] = m[3];
        return res;
    }

    inline mat4 scale(const mat4 &m, const vec3 &v) {
        mat4 res(uninitialize);
        res[0] = m[0] * v[0];
        res[1] = m[1] * v[1];
        res[2] = m[2] * v[2];
        res[3] = m[3];
        return res;
    }
}