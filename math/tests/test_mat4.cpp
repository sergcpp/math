#include "test_assert.h"

#include "../math.hpp"

void test_mat4(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        mat4 m1, m2(2.3f),
             m3(0, 1, 2, 3,
                4, 5, 6, 7,
                8, 9, 10, 11,
                12, 13, 14, 15),
            m4(vec4(0.0f), vec4(1), vec4(2), vec4(3));

        assert(m1[0] == Approx4(1, 0, 0, 0));
        assert(m1[1] == Approx4(0, 1, 0, 0));
        assert(m1[2] == Approx4(0, 0, 1, 0));
        assert(m1[3] == Approx4(0, 0, 0, 1));

        assert(m2[0] == Approx4(2.3f, 0, 0, 0));
        assert(m2[1] == Approx4(0, 2.3f, 0, 0));
        assert(m2[2] == Approx4(0, 0, 2.3f, 0));
        assert(m2[3] == Approx4(0, 0, 0, 2.3f));

        assert(m3[0] == Approx4(0, 1, 2, 3));
        assert(m3[1] == Approx4(4, 5, 6, 7));
        assert(m3[2] == Approx4(8, 9, 10, 11));
        assert(m3[3] == Approx4(12, 13, 14, 15));

        assert(m4[0] == Approx4(0, 0, 0, 0));
        assert(m4[1] == Approx4(1, 1, 1, 1));
        assert(m4[2] == Approx4(2, 2, 2, 2));
        assert(m4[3] == Approx4(3, 3, 3, 3));

        m1[0] = vec4(1, 2, 3, 4);
        m1[1] = vec4(3, 4, 5, 6);

        assert(m1[0] == Approx4(1, 2, 3, 4));
        assert(m1[1] == Approx4(3, 4, 5, 6));
        assert(m1[2] == Approx4(0, 0, 1, 0));
        assert(m1[3] == Approx4(0, 0, 0, 1));

        m1[0][1] = 3;
        m1[1][1] = 8;

        assert(m1[0] == Approx4(1, 3, 3, 4));
        assert(m1[1] == Approx4(3, 8, 5, 6));
        assert(m1[2] == Approx4(0, 0, 1, 0));
        assert(m1[3] == Approx4(0, 0, 0, 1));

        mat4 m5 = m1 + m2, m6 = m2 + m3;

        assert(m5[0] == Approx4(3.3, 3, 3, 4) &&
               m5[1] == Approx4(3, 10.3, 5, 6) &&
               m5[2] == Approx4(0, 0, 3.3, 0) &&
               m5[3] == Approx4(0, 0, 0, 3.3));
        assert(m6[0] == Approx4(2.3, 1, 2, 3) &&
               m6[1] == Approx4(4, 7.3, 6, 7) &&
               m6[2] == Approx4(8, 9, 12.3, 11) &&
               m6[3] == Approx4(12, 13, 14, 17.3));

        mat4 m7 = m1 - m2, m8 = m2 - m3;

        assert(m7[0] == Approx4(-1.3, 3, 3, 4) &&
               m7[1] == Approx4(3, 5.7, 5, 6) &&
               m7[2] == Approx4(0, 0, -1.3, 0) &&
               m7[3] == Approx4(0, 0, 0, -1.3));
        assert(m8[0] == Approx4(2.3, -1, -2, -3) &&
               m8[1] == Approx4(-4, -2.7, -6, -7) &&
               m8[2] == Approx4(-8, -9, -7.7, -11) &&
               m8[3] == Approx4(-12, -13, -14, -12.7));

        mat4 m9 = m1 * m2, m10 = m2 * m3;

        assert(m9[0] == Approx4(2.3, 6.9, 6.9, 9.2) &&
               m9[1] == Approx4(6.9, 18.4, 11.5, 13.8) &&
               m9[2] == Approx4(0, 0, 2.3, 0) &&
               m9[3] == Approx4(0, 0, 0, 2.3));
        assert(m10[0] == Approx4(0, 2.3, 4.6, 6.9) &&
               m10[1] == Approx4(9.2, 11.5, 13.8, 16.1) &&
               m10[2] == Approx4(18.4, 20.7, 23, 25.3) &&
               m10[3] == Approx4(27.6, 29.9, 32.2, 34.5));

        m1[2] = { 1, 1, 1, 1 };
        m1[3] = { 1, 1, 1, 1 };

        mat4 m11 = m2 / m1;

        assert(m11[0] == Approx4(2.3, 0, 0, 0) &&
               m11[1] == Approx4(0, 0.2875, 0, 0) &&
               m11[2] == Approx4(0, 0, 2.3, 0) &&
               m11[3] == Approx4(0, 0, 0, 2.3));

        mat4 m13 = matrixCompMult(m1, m3);

        assert(m13[0] == Approx4(0, 3, 6, 12) &&
               m13[1] == Approx4(12, 40, 30, 42) &&
               m13[2] == Approx4(8, 9, 10, 11) &&
               m13[3] == Approx4(12, 13, 14, 15));

        mat4 m14 = 2.0f * m1,
             m15 = m1 * 2.0f,
             m16 = m1 / 2.0f;

        assert(m14[0] == Approx4(2, 6, 6, 8) &&
               m14[1] == Approx4(6, 16, 10, 12) &&
               m14[2] == Approx4(2, 2, 2, 2) &&
               m14[3] == Approx4(2, 2, 2, 2));

        assert(m15[0] == Approx4(2, 6, 6, 8) &&
               m15[1] == Approx4(6, 16, 10, 12) &&
               m15[2] == Approx4(2, 2, 2, 2) &&
               m15[3] == Approx4(2, 2, 2, 2));

        assert(m16[0] == Approx4(0.5, 1.5, 1.5, 2) &&
               m16[1] == Approx4(1.5, 4, 2.5, 3) &&
               m16[2] == Approx4(0.5, 0.5, 0.5, 0.5) &&
               m16[3] == Approx4(0.5, 0.5, 0.5, 0.5));
    }

    {   // additional constructors
        mat4 m0 = { { 0, 1, 0, 1 },
                    { 2, 3, 2, 3 },
                    { 3, 4, 3, 4 },
                    { 5, 6, 5, 6 } }, m1(m0), m2 = m0;

        assert(m0[0] == Approx4(0, 1, 0, 1) &&
               m0[1] == Approx4(2, 3, 2, 3) &&
               m0[2] == Approx4(3, 4, 3, 4) &&
               m0[3] == Approx4(5, 6, 5, 6));
        assert(m1[0] == Approx4(0, 1, 0, 1) &&
               m1[1] == Approx4(2, 3, 2, 3) &&
               m1[2] == Approx4(3, 4, 3, 4) &&
               m1[3] == Approx4(5, 6, 5, 6));
        assert(m2[0] == Approx4(0, 1, 0, 1) &&
               m2[1] == Approx4(2, 3, 2, 3) &&
               m2[2] == Approx4(3, 4, 3, 4) &&
               m2[3] == Approx4(5, 6, 5, 6));
    }

    {   // additional operators
        mat4 m0 = { { 0, 1, 0, 1 },
                    { 2, 3, 2, 3 },
                    { 4, 5, 4, 5 },
                    { 6, 7, 6, 7 } },
             m1 = { 1, 2, 3, 4,
                    1, 2, 3, 4,
                    1, 2, 3, 4,
                    1, 2, 3, 4 },
             m2 = m0, m3 = m1;

        mat4 m4 = m0++, m5 = ++m1;

        assert(m0[0] == Approx4(1, 2, 1, 2) &&
               m0[1] == Approx4(3, 4, 3, 4) &&
               m0[2] == Approx4(5, 6, 5, 6) &&
               m0[3] == Approx4(7, 8, 7, 8));
        assert(m1[0] == Approx4(2, 3, 4, 5) &&
               m1[1] == Approx4(2, 3, 4, 5) &&
               m1[2] == Approx4(2, 3, 4, 5) &&
               m1[3] == Approx4(2, 3, 4, 5));
        assert(m4[0] == Approx4(0, 1, 0, 1) &&
               m4[1] == Approx4(2, 3, 2, 3) &&
               m4[2] == Approx4(4, 5, 4, 5) &&
               m4[3] == Approx4(6, 7, 6, 7));
        assert(m5[0] == Approx4(2, 3, 4, 5) &&
               m5[1] == Approx4(2, 3, 4, 5) &&
               m5[2] == Approx4(2, 3, 4, 5) &&
               m5[3] == Approx4(2, 3, 4, 5));

        mat4 m6 = m2--, m7 = --m3;

        assert(m2[0] == Approx4(-1, 0, -1, 0) &&
               m2[1] == Approx4(1, 2, 1, 2) &&
               m2[2] == Approx4(3, 4, 3, 4) &&
               m2[3] == Approx4(5, 6, 5, 6));
        assert(m3[0] == Approx4(0, 1, 2, 3) &&
               m3[1] == Approx4(0, 1, 2, 3) &&
               m3[2] == Approx4(0, 1, 2, 3) &&
               m3[3] == Approx4(0, 1, 2, 3));
        assert(m6[0] == Approx4(0, 1, 0, 1) &&
               m6[1] == Approx4(2, 3, 2, 3) &&
               m6[2] == Approx4(4, 5, 4, 5) &&
               m6[3] == Approx4(6, 7, 6, 7));
        assert(m7[0] == Approx4(0, 1, 2, 3) &&
               m7[1] == Approx4(0, 1, 2, 3) &&
               m7[2] == Approx4(0, 1, 2, 3) &&
               m7[3] == Approx4(0, 1, 2, 3));

        mat4 m8 = { 1, 2, 3, 4,
                    1, 2, 3, 4,
                    1, 2, 3, 4,
                    1, 2, 3, 4 }, m9 = m8, m10 = m8, m11 = m8;

        mat4 mm = { 1, 1, 1, 1,
                    2, 2, 2, 2,
                    3, 3, 3, 3,
                    4, 4, 4, 4 };

        m8 += mm;
        m9 -= mm;
        m10 *= mm;
        m11 /= mm;

        assert(m8[0] == Approx4(2, 3, 4, 5) &&
               m8[1] == Approx4(3, 4, 5, 6) &&
               m8[2] == Approx4(4, 5, 6, 7) &&
               m8[3] == Approx4(5, 6, 7, 8));
        assert(m9[0] == Approx4(0, 1, 2, 3) &&
               m9[1] == Approx4(-1, 0, 1, 2) &&
               m9[2] == Approx4(-2, -1, 0, 1) &&
               m9[3] == Approx4(-3, -2, -1, 0));
        assert(m10[0] == Approx4(30, 30, 30, 30) &&
               m10[1] == Approx4(30, 30, 30, 30) &&
               m10[2] == Approx4(30, 30, 30, 30) &&
               m10[3] == Approx4(30, 30, 30, 30));
        assert(m11[0] == Approx4(1, 2, 3, 4) &&
               m11[1] == Approx4(0.5, 1, 1.5, 2) &&
               m11[2] == Approx4(0.33333, 0.66666, 1, 1.33333) &&
               m11[3] == Approx4(0.25, 0.5, 0.75, 1));

        mat4 m12 = { 1, 2, 3, 4,
                     1, 2, 3, 4,
                     1, 2, 3, 4,
                     1, 2, 3, 4 };
        m12 = -m12;

        assert(m12[0] == Approx4(-1, -2, -3, -4) &&
               m12[1] == Approx4(-1, -2, -3, -4) &&
               m12[2] == Approx4(-1, -2, -3, -4) &&
               m12[3] == Approx4(-1, -2, -3, -4));

        mat4 m13 = m12;

        assert(m12 == m13);
        assert(m11 != m13);

        mat4 m14 = { 1, 2, 3, 4,
                     1, 2, 3, 4,
                     1, 2, 3, 4,
                     1, 2, 3, 4 };

        m14[0] += { 1, 1, 1, 1 };
        m14[1] -= { 1, 1, 1, 1 };
        m14[2] *= { 2, 2, 2, 2 };
        m14[3] /= { 2, 2, 2, 2 };

        assert(m14[0] == Approx4(2, 3, 4, 5) &&
               m14[1] == Approx4(0, 1, 2, 3) &&
               m14[2] == Approx4(2, 4, 6, 8) &&
               m14[3] == Approx4(0.5, 1, 1.5, 2));
    }
}

void test_mat4() {
    test_mat4(math::Scalar);
#ifndef __arm__
    test_mat4(math::SSE2);
    test_mat4(math::SSE3);
    test_mat4(math::SSE4_1);
    test_mat4(math::AVX);
#else
    test_mat4(math::NEON);
#endif
}
