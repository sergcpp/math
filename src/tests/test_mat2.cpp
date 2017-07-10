#include "test_assert.h"

#include "../math.hpp"

void test_mat2(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        mat2 m1, m2(2.3f), m3(0, 1, 2, 3), m4(vec2(0, 1), vec2(2, 3));

        assert(m1[0] == Approx2(0, 0));
        assert(m1[1] == Approx2(0, 0));

        assert(m2[0] == Approx2(2.3f, 0));
        assert(m2[1] == Approx2(0, 2.3f));

        assert(m3[0] == Approx2(0, 1));
        assert(m3[1] == Approx2(2, 3));

        assert(m4[0] == Approx2(0, 1));
        assert(m4[1] == Approx2(2, 3));

        m1[0] = vec2(1, 2);
        m1[1] = vec2(3, 4);

        assert(m1[0] == Approx2(1, 2));
        assert(m1[1] == Approx2(3, 4));

        m1[0][1] = 3;
        m1[1][1] = 8;

        assert(m1[0] == Approx2(1, 3));
        assert(m1[1] == Approx2(3, 8));

        mat2 m5 = m1 + m2, m6 = m2 + m3;

        assert(m5[0] == Approx2(3.3, 3) && m5[1] == Approx2(3, 10.3));
        assert(m6[0] == Approx2(2.3, 1) && m6[1] == Approx2(2, 5.3));

        mat2 m7 = m1 - m2, m8 = m2 - m3;

        assert(m7[0] == Approx2(-1.3, 3) && m7[1] == Approx2(3, 5.7));
        assert(m8[0] == Approx2(2.3, -1) && m8[1] == Approx2(-2, -0.7));

        mat2 m9 = m1 * m2, m10 = m2 * m3;

        assert(m9[0] == Approx2(2.3, 6.9) && m9[1] == Approx2(6.9, 18.4));
        assert(m10[0] == Approx2(0, 2.3) && m10[1] == Approx2(4.6, 6.9));

        mat2 m11 = m2 / m1;

        assert(m11[0] == Approx2(2.3, 0) && m11[1] == Approx2(0, 0.2875));

        mat2 m13 = matrixCompMult(m1, m3);

        assert(m13[0] == Approx2(0, 3));
        assert(m13[1] == Approx2(6, 24));

        mat2 m14 = 2.0f * m1,
             m15 = m1 * 2.0f,
             m16 = m1 / 2.0f;

        assert(m14[0] == Approx2(2, 6));
        assert(m14[1] == Approx2(6, 16));

        assert(m15[0] == Approx2(2, 6));
        assert(m15[1] == Approx2(6, 16));

        assert(m16[0] == Approx2(0.5, 1.5));
        assert(m16[1] == Approx2(1.5, 4));
    }

    {   // additional constructors
        mat2 m0 = { { 0, 1 }, { 2, 3 } }, m1(m0), m2 = m0;

        assert(m0[0] == Approx2(0, 1) && m0[1] == Approx2(2, 3));
        assert(m1[0] == Approx2(0, 1) && m1[1] == Approx2(2, 3));
        assert(m2[0] == Approx2(0, 1) && m2[1] == Approx2(2, 3));
    }

    {   // additional operators
        mat2 m0 = { { 0, 1 },{ 2, 3 } }, m1 = { 1, 2, 3, 4 },
             m2 = { { 0, 1 },{ 2, 3 } }, m3 = { 1, 2, 3, 4 };

        mat2 m4 = m0++, m5 = ++m1;

        assert(m0[0] == Approx2(1, 2) && m0[1] == Approx2(3, 4)); assert(m1[0] == Approx2(2, 3) && m1[1] == Approx2(4, 5));
        assert(m4[0] == Approx2(0, 1) && m4[1] == Approx2(2, 3)); assert(m5[0] == Approx2(2, 3) && m5[1] == Approx2(4, 5));

        mat2 m6 = m2--, m7 = --m3;

        assert(m2[0] == Approx2(-1, 0) && m2[1] == Approx2(1, 2)); assert(m3[0] == Approx2(0, 1) && m3[1] == Approx2(2, 3));
        assert(m6[0] == Approx2(0, 1) && m4[1] == Approx2(2, 3)); assert(m7[0] == Approx2(0, 1) && m7[1] == Approx2(2, 3));

        mat2 m8 = { 1, 2, 3, 4 }, m9 = m8, m10 = m8, m11 = m8;

        m8 += mat2{ 1, 2, 3, 4 };
        m9 -= mat2{ 1, 2, 3, 4 };
        m10 *= mat2{ 1, 2, 3, 4 };
        m11 /= mat2{ 1, 2, 3, 4 };

        assert(m8[0] == Approx2(2, 4) && m8[1] == Approx2(6, 8));
        assert(m9[0] == Approx2(0, 0) && m9[1] == Approx2(0, 0));
        assert(m10[0] == Approx2(7, 10) && m10[1] == Approx2(15, 22));
        assert(m11[0] == Approx2(1, 1) && m11[1] == Approx2(1, 1));

        mat2 m12 = { 1, 2, 3, 4 };
        m12 = -m12;

        assert(m12[0] == Approx2(-1, -2) && m12[1] == Approx2(-3, -4));

        mat2 m13 = m12;

        assert(m12 == m13);
        assert(m11 != m13);
    }

}

void test_mat2() {
    test_mat2(math::Scalar);
#ifndef __arm__
    test_mat2(math::SSE2);
    test_mat2(math::SSE3);
    test_mat2(math::SSE4_1);
    test_mat2(math::AVX);
#else
    test_mat2(math::NEON);
#endif
}
