#include "test_assert.h"

#include "../math.hpp"

void test_vec2(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        vec2 v1, v2(2.3f), v3(1, 2);

        assert(v2[0] == Approx(2.3) && v2[1] == Approx(2.3));

        v2[0] = v2[1] = 1.3f;

        assert(v1[0] == Approx(0) && v1[1] == Approx(0));
        assert(v2[0] == Approx(1.3) && v2[1] == Approx(1.3));
        assert(v3[0] == Approx(1) && v3[1] == Approx(2));
        assert(v3.x() == Approx(1) && v3.y() == Approx(2));
        assert(v3.r() == Approx(1) && v3.g() == Approx(2));
        assert(v3.s() == Approx(1) && v3.t() == Approx(2));

        vec2 v4 = v1 + v2, v5 = v2 + v3;

        assert(v4[0] == Approx(1.3) && v4[1] == Approx(1.3));
        assert(v5[0] == Approx(2.3) && v5[1] == Approx(3.3));

        vec2 v6 = v1 - v2, v7 = v2 - v3;

        assert(v6[0] == Approx(-1.3) && v6[1] == Approx(-1.3));
        assert(v7[0] == Approx(0.3) && v7[1] == Approx(-0.7));

        vec2 v8 = v1 * v2, v9 = v2 * v3;

        assert(v8[0] == Approx(0) && v8[1] == Approx(0));
        assert(v9[0] == Approx(1.3) && v9[1] == Approx(2.6));

        vec2 v10 = v1 / v2, v11 = v2 / v3;

        assert(v10[0] == Approx(0) && v10[1] == Approx(0));
        assert(v11[0] == Approx(1.3) && v11[1] == Approx(0.65));
    }

    {   // additional constructors
        vec2 v0 = { 1, 2 }, v1(v0), v2 = v0;

        assert(v0 == Approx2(1, 2)); assert(v1 == Approx2(1, 2)); assert(v2 == Approx2(1, 2));
    }

    {   // additional operators
        vec2 v0 = { 1, 2 }, v1 = { 1, 2 }, v2 = { 4.5f, 3 }, v3 = { 4.5f, 3 };

        vec2 v4 = v0++, v5 = ++v1;

        assert(v0 == Approx2(2, 3)); assert(v1 == Approx2(2, 3)); assert(v4 == Approx2(1, 2)); assert(v5 == Approx2(2, 3));

        vec2 v6 = v2--, v7 = --v3;

        assert(v2 == Approx2(3.5, 2)); assert(v3 == Approx2(3.5, 2)); assert(v6 == Approx2(4.5, 3)); assert(v7 == Approx2(3.5, 2));

        vec2 v8 = { 1, 2 }, v9 = { 1, 2 }, v10 = { 1, 2 }, v11 = { 1, 2 };

        v8 += vec2{ 1, 2 };
        v9 -= vec2{ 1, 2 };
        v10 *= vec2{ 1, 2 };
        v11 /= vec2{ 1, 2 };

        assert(v8 == Approx2(2, 4));
        assert(v9 == Approx2(0, 0));
        assert(v10 == Approx2(1, 4));
        assert(v11 == Approx2(1, 1));

        vec2 v12 = { 1, 2 };
        v12 = -v12;

        assert(v12 == Approx2(-1, -2));

        vec2 v13 = v12;

        assert(v12 == v13);
        assert(v11 != v13);

        vec2 v14 = { 1, 2 };

        v14[0] += 1;
        v14[1] -= 1;

        assert(v14 == Approx2(2, 1));

        v14[0] *= 2;
        v14[1] /= 2;

        assert(v14 == Approx2(4, 0.5));
    }

    {   // arithmetics with deref
        vec2 vv{ 2, 2 };
        
        float f1 = 2;
        vec2 v1 = { 1, 2 };
        vec3 v2 = { 1, 2, 3 };
        vec4 v3 = { 1, 2, 3, 4 };
        mat2 m1;
        mat3 m2;
        mat4 m3;

        f1 = f1 * vv[0];
        v1 = v1 * vv[0];
        v2 = v2 * vv[0];
        v3 = v3 * vv[0];
        m1 = m1 * vv[0];
        m2 = m2 * vv[0];
        m3 = m3 * vv[0];

        assert(f1 == Approx(4));
        assert(v1 == Approx2(2, 4));
        assert(v2 == Approx3(2, 4, 6));
        assert(v3 == Approx4(2, 4, 6, 8));

        assert(m1[0] == Approx2(2, 0));
        assert(m1[1] == Approx2(0, 2));
        assert(m2[0] == Approx3(2, 0, 0));
        assert(m2[1] == Approx3(0, 2, 0));
        assert(m2[2] == Approx3(0, 0, 2));
        assert(m3[0] == Approx4(2, 0, 0, 0));
        assert(m3[1] == Approx4(0, 2, 0, 0));
        assert(m3[2] == Approx4(0, 0, 2, 0));
        assert(m3[3] == Approx4(0, 0, 0, 2));
    }
}

void test_vec2() {
    test_vec2(math::Scalar);
#ifndef __arm__
    test_vec2(math::SSE2);
    test_vec2(math::SSE3);
    test_vec2(math::SSE4_1);
    test_vec2(math::AVX);
#else
    test_vec2(math::NEON);
#endif
}
