#include "test_assert.h"

#include "../math.hpp"

void test_mat3(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        mat3 m1, m2(2.3f), 
             m3(0, 1, 2,
                4, 5, 6,
                8, 9, 10),
             m4(vec3(0.0f), vec3(1), vec3(2));

        assert(m1[0] == Approx3(0, 0, 0));
        assert(m1[1] == Approx3(0, 0, 0));
        assert(m1[2] == Approx3(0, 0, 0));

        assert(m2[0] == Approx3(2.3f, 0, 0));
        assert(m2[1] == Approx3(0, 2.3f, 0));
        assert(m2[2] == Approx3(0, 0, 2.3f));

        assert(m3[0] == Approx3(0, 1, 2));
        assert(m3[1] == Approx3(4, 5, 6));
        assert(m3[2] == Approx3(8, 9, 10));

        assert(m4[0] == Approx3(0, 0, 0));
        assert(m4[1] == Approx3(1, 1, 1));
        assert(m4[2] == Approx3(2, 2, 2));

        m1[0] = vec3(1, 2, 3);
        m1[1] = vec3(3, 4, 5);

        assert(m1[0] == Approx3(1, 2, 3));
        assert(m1[1] == Approx3(3, 4, 5));
        assert(m1[2] == Approx3(0, 0, 0));

        m1[0][1] = 3;
        m1[1][1] = 8;

        assert(m1[0] == Approx3(1, 3, 3));
        assert(m1[1] == Approx3(3, 8, 5));
        assert(m1[2] == Approx3(0, 0, 0));

        mat3 m5 = m1 + m2, m6 = m2 + m3;

        assert(m5[0] == Approx3(3.3, 3, 3) &&
               m5[1] == Approx3(3, 10.3, 5) &&
               m5[2] == Approx3(0, 0, 2.3));
        assert(m6[0] == Approx3(2.3, 1, 2) &&
               m6[1] == Approx3(4, 7.3, 6) &&
               m6[2] == Approx3(8, 9, 12.3));

        mat3 m7 = m1 - m2, m8 = m2 - m3;

        assert(m7[0] == Approx3(-1.3, 3, 3) &&
               m7[1] == Approx3(3, 5.7, 5) &&
               m7[2] == Approx3(0, 0, -2.3));
        assert(m8[0] == Approx3(2.3, -1, -2) &&
               m8[1] == Approx3(-4, -2.7, -6) &&
               m8[2] == Approx3(-8, -9, -7.7));
        
        mat3 m9 = m1 * m2, m10 = m2 * m3;

        assert(m9[0] == Approx3(2.3, 6.9, 6.9) &&
               m9[1] == Approx3(6.9, 18.4, 11.5) &&
               m9[2] == Approx3(0, 0, 0));
        assert(m10[0] == Approx3(0, 2.3, 4.6) &&
               m10[1] == Approx3(9.2, 11.5, 13.8) &&
               m10[2] == Approx3(18.4, 20.7, 23));

        m1[2] = { 1, 1, 1 };

        mat3 m11 = m2 / m1;

        assert(m11[0] == Approx3(2.3, 0, 0) &&
               m11[1] == Approx3(0, 0.2875, 0) &&
               m11[2] == Approx3(0, 0, 2.3));

        mat3 m13 = matrixCompMult(m1, m3);

        assert(m13[0] == Approx3(0, 3, 6));
        assert(m13[1] == Approx3(12, 40, 30));
        assert(m13[2] == Approx3(8, 9, 10));

        mat3 m14 = 2.0f * m1,
             m15 = m1 * 2.0f,
             m16 = m1 / 2.0f;

        assert(m14[0] == Approx3(2, 6, 6) &&
               m14[1] == Approx3(6, 16, 10) &&
               m14[2] == Approx3(2, 2, 2));

        assert(m15[0] == Approx3(2, 6, 6) &&
               m15[1] == Approx3(6, 16, 10) &&
               m15[2] == Approx3(2, 2, 2));

        assert(m16[0] == Approx3(0.5, 1.5, 1.5) &&
               m16[1] == Approx3(1.5, 4, 2.5) &&
               m16[2] == Approx3(0.5, 0.5, 0.5));
    }

    {   // additional constructors
        mat3 m0 = { { 0, 1, 0 }, 
                    { 2, 3, 2 },
                    { 3, 4, 3 } }, m1(m0), m2 = m0;

        assert(m0[0] == Approx3(0, 1, 0) &&
               m0[1] == Approx3(2, 3, 2) &&
               m0[2] == Approx3(3, 4, 3));
        assert(m1[0] == Approx3(0, 1, 0) &&
               m1[1] == Approx3(2, 3, 2) &&
               m1[2] == Approx3(3, 4, 3));
        assert(m2[0] == Approx3(0, 1, 0) &&
               m2[1] == Approx3(2, 3, 2) &&
               m2[2] == Approx3(3, 4, 3));
    }

    {   // additional operators
        mat3 m0 = { { 0, 1, 0 },
                    { 2, 3, 2 },
                    { 4, 5, 4 } }, 
             m1 = { 1, 2, 3,
                    1, 2, 3,
                    1, 2, 3 },
             m2 = m0, m3 = m1;

        mat3 m4 = m0++, m5 = ++m1;

        assert(m0[0] == Approx3(1, 2, 1) &&
               m0[1] == Approx3(3, 4, 3) &&
               m0[2] == Approx3(5, 6, 5));
        assert(m1[0] == Approx3(2, 3, 4) &&
               m1[1] == Approx3(2, 3, 4) &&
               m1[2] == Approx3(2, 3, 4));
        assert(m4[0] == Approx3(0, 1, 0) &&
               m4[1] == Approx3(2, 3, 2) &&
               m4[2] == Approx3(4, 5, 4));
        assert(m5[0] == Approx3(2, 3, 4) &&
               m5[1] == Approx3(2, 3, 4) &&
               m5[2] == Approx3(2, 3, 4));

        mat3 m6 = m2--, m7 = --m3;

        assert(m2[0] == Approx3(-1, 0, -1) &&
               m2[1] == Approx3(1, 2, 1) &&
               m2[2] == Approx3(3, 4, 3));
        assert(m3[0] == Approx3(0, 1, 2) &&
               m3[1] == Approx3(0, 1, 2) &&
               m3[2] == Approx3(0, 1, 2));
        assert(m6[0] == Approx3(0, 1, 0) &&
               m6[1] == Approx3(2, 3, 2) &&
               m6[2] == Approx3(4, 5, 4));
        assert(m7[0] == Approx3(0, 1, 2) &&
               m7[1] == Approx3(0, 1, 2) &&
               m7[2] == Approx3(0, 1, 2));

        mat3 m8 = { 1, 2, 3, 
                    1, 2, 3,
                    1, 2, 3 }, m9 = m8, m10 = m8, m11 = m8;

        mat3 mm = { 1, 1, 1,
                    2, 2, 2,
                    3, 3, 3 };

        m8 += mm;
        m9 -= mm;
        m10 *= mm;
        m11 /= mm;

        assert(m8[0] == Approx3(2, 3, 4) &&
               m8[1] == Approx3(3, 4, 5) &&
               m8[2] == Approx3(4, 5, 6));
        assert(m9[0] == Approx3(0, 1, 2) &&
               m9[1] == Approx3(-1, 0, 1) &&
               m9[2] == Approx3(-2, -1, 0));
        assert(m10[0] == Approx3(14, 14, 14) &&
               m10[1] == Approx3(14, 14, 14) &&
               m10[2] == Approx3(14, 14, 14));
        assert(m11[0] == Approx3(1, 2, 3) &&
               m11[1] == Approx3(0.5, 1, 1.5) &&
               m11[2] == Approx3(0.33333, 0.66666, 1));

        mat3 m12 = { 1, 2, 3,
                     1, 2, 3,
                     1, 2, 3 };
        m12 = -m12;

        assert(m12[0] == Approx3(-1, -2, -3) &&
               m12[1] == Approx3(-1, -2, -3) &&
               m12[2] == Approx3(-1, -2, -3));

        mat3 m13 = m12;

        assert(m12 == m13);
        assert(m11 != m13);
    }
}

void test_mat3() {
    test_mat3(math::Scalar);
#ifndef __arm__
    test_mat3(math::SSE2);
    test_mat3(math::SSE3);
    test_mat3(math::SSE4_1);
    test_mat3(math::AVX);
#else
    test_mat3(math::NEON);
#endif
}
