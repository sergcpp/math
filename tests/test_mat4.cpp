#include "test_assert.h"

#include <iostream>
#include <random>

#include "../math.hpp"

void test_mat4(math::e_arch arch, unsigned seed) {
    using namespace math;

    init(arch);

    const int NUM_REPEATS = 1000;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> dist(-1000000, 1000000);

    std::cout << "\t" << math::arch_name[arch] << " ...";

    // basic usage
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen),
              r7 = dist(gen), r8 = dist(gen), r9 = dist(gen), r10 = dist(gen), r11 = dist(gen), r12 = dist(gen),
              r13 = dist(gen), r14 = dist(gen), r15 = dist(gen), r16 = dist(gen), r17 = dist(gen), r18 = dist(gen),
              r19 = dist(gen), r20 = dist(gen), r21 = dist(gen), r22 = dist(gen), r23 = dist(gen), r24 = dist(gen),
              r25 = dist(gen), r26 = dist(gen), r27 = dist(gen), r28 = dist(gen), r29 = dist(gen), r30 = dist(gen),
              r31 = dist(gen), r32 = dist(gen), r33 = dist(gen), r34 = dist(gen), r35 = dist(gen), r36 = dist(gen),
              r37 = dist(gen), r38 = dist(gen);

        mat4 m1, m2(r1),
             m3(r2, r3, r4, r5,
                r6, r7, r8, r9,
                r10, r11, r12, r13,
                r14, r15, r16, r17),
             m4(vec4{ r18 }, vec4{ r19 }, vec4{ r20 }, vec4{ r21 });

        assert(m1[0] == Approx4(1, 0, 0, 0));
        assert(m1[1] == Approx4(0, 1, 0, 0));
        assert(m1[2] == Approx4(0, 0, 1, 0));
        assert(m1[3] == Approx4(0, 0, 0, 1));

        assert(m2[0] == Approx4(r1, 0, 0, 0));
        assert(m2[1] == Approx4(0, r1, 0, 0));
        assert(m2[2] == Approx4(0, 0, r1, 0));
        assert(m2[3] == Approx4(0, 0, 0, r1));

        assert(m3[0] == Approx4(r2, r3, r4, r5));
        assert(m3[1] == Approx4(r6, r7, r8, r9));
        assert(m3[2] == Approx4(r10, r11, r12, r13));
        assert(m3[3] == Approx4(r14, r15, r16, r17));

        assert(m4[0] == Approx4(r18, r18, r18, r18));
        assert(m4[1] == Approx4(r19, r19, r19, r19));
        assert(m4[2] == Approx4(r20, r20, r20, r20));
        assert(m4[3] == Approx4(r21, r21, r21, r21));

        m1[0] = vec4(r22, r23, r24, r25);
        m1[1] = vec4(r26, r27, r28, r29);

        assert(m1[0] == Approx4(r22, r23, r24, r25));
        assert(m1[1] == Approx4(r26, r27, r28, r29));
        assert(m1[2] == Approx4(0, 0, 1, 0));
        assert(m1[3] == Approx4(0, 0, 0, 1));

        m1[0][1] = r30;
        m1[1][1] = r31;

        assert(m1[0] == Approx4(r22, r30, r24, r25));
        assert(m1[1] == Approx4(r26, r31, r28, r29));
        assert(m1[2] == Approx4(0, 0, 1, 0));
        assert(m1[3] == Approx4(0, 0, 0, 1));

        mat4 m5 = m1 + m2, m6 = m2 + m3;

        assert(m5[0] == Approx4(r22 + r1, r30, r24, r25) &&
               m5[1] == Approx4(r26, r31 + r1, r28, r29) &&
               m5[2] == Approx4(0, 0, 1 + r1, 0) &&
               m5[3] == Approx4(0, 0, 0, 1 + r1));
        assert(m6[0] == Approx4(r1 + r2, r3, r4, r5) &&
               m6[1] == Approx4(r6, r1 + r7, r8, r9) &&
               m6[2] == Approx4(r10, r11, r1 + r12, r13) &&
               m6[3] == Approx4(r14, r15, r16, r1 + r17));

        mat4 m7 = m1 - m2, m8 = m2 - m3;

        assert(m7[0] == Approx4(r22 - r1, r30, r24, r25) &&
               m7[1] == Approx4(r26, r31 - r1, r28, r29) &&
               m7[2] == Approx4(0, 0, 1 - r1, 0) &&
               m7[3] == Approx4(0, 0, 0, 1 - r1));
        assert(m8[0] == Approx4(r1 - r2, -r3, -r4, -r5) &&
               m8[1] == Approx4(-r6, r1 - r7, -r8, -r9) &&
               m8[2] == Approx4(-r10, -r11, r1 - r12, -r13) &&
               m8[3] == Approx4(-r14, -r15, -r16, r1 - r17));

        //mat4 m9 = m1 * m2, m10 = m2 * m3;

        //assert(m9[0] == Approx4(2.3, 6.9, 6.9, 9.2) &&
        //       m9[1] == Approx4(6.9, 18.4, 11.5, 13.8) &&
        //       m9[2] == Approx4(0, 0, 2.3, 0) &&
        //       m9[3] == Approx4(0, 0, 0, 2.3));
        //assert(m10[0] == Approx4(0, 2.3, 4.6, 6.9) &&
        //       m10[1] == Approx4(9.2, 11.5, 13.8, 16.1) &&
        //       m10[2] == Approx4(18.4, 20.7, 23, 25.3) &&
        //       m10[3] == Approx4(27.6, 29.9, 32.2, 34.5));

        m1[2] = { r30, r31, r32, r33 };
        m1[3] = { r34, r35, r36, r37 };

        mat4 m11 = m2 / m1;

        assert(m11[0] == Approx4(r1 / r22, 0, 0, 0) &&
               m11[1] == Approx4(0, r1 / r31, 0, 0) &&
               m11[2] == Approx4(0, 0, r1 / r32, 0) &&
               m11[3] == Approx4(0, 0, 0, r1 / r37));

        mat4 m13 = matrix_comp_mult(m1, m3);

        assert(m13[0] == Approx4(r22 * r2, r30 * r3, r24 * r4, r25 * r5) &&
               m13[1] == Approx4(r26 * r6, r31 * r7, r28 * r8, r29 * r9) &&
               m13[2] == Approx4(r30 * r10, r31 * r11, r32 * r12, r33 * r13) &&
               m13[3] == Approx4(r34 * r14, r35 * r15, r36 * r16, r37 * r17));

        mat4 m14 = r38 * m1,
             m15 = m1 * r38,
             m16 = m1 / r38;

        assert(m14[0] == Approx4(r38 * r22, r38 * r30, r38 * r24, r38 * r25));
        assert(m14[1] == Approx4(r38 * r26, r38 * r31, r38 * r28, r38 * r29));
        assert(m14[2] == Approx4(r38 * r30, r38 * r31, r38 * r32, r38 * r33));
        assert(m14[3] == Approx4(r38 * r34, r38 * r35, r38 * r36, r38 * r37));

        assert(m15[0] == Approx4(r38 * r22, r38 * r30, r38 * r24, r38 * r25));
        assert(m15[1] == Approx4(r38 * r26, r38 * r31, r38 * r28, r38 * r29));
        assert(m15[2] == Approx4(r38 * r30, r38 * r31, r38 * r32, r38 * r33));
        assert(m15[3] == Approx4(r38 * r34, r38 * r35, r38 * r36, r38 * r37));

        assert(m16[0] == Approx4(r22 / r38, r30 / r38, r24 / r38, r25 / r38));
        assert(m16[1] == Approx4(r26 / r38, r31 / r38, r28 / r38, r29 / r38));
        assert(m16[2] == Approx4(r30 / r38, r31 / r38, r32 / r38, r33 / r38));
        assert(m16[3] == Approx4(r34 / r38, r35 / r38, r36 / r38, r37 / r38));
    }

    {
        // matrix multiplication
        extern std::vector<float> mat4_mul_mat4_test_data;

        for (size_t i = 0; i < mat4_mul_mat4_test_data.size(); i += 48) {
            mat4 m1 = make_mat4(&mat4_mul_mat4_test_data[i + 0]),
                 m2 = make_mat4(&mat4_mul_mat4_test_data[i + 16]);
            mat4 m3 = m1 * m2;

            assert(m3[0] == Approx4(mat4_mul_mat4_test_data[i + 32], mat4_mul_mat4_test_data[i + 33], mat4_mul_mat4_test_data[i + 34], mat4_mul_mat4_test_data[i + 35]));
            assert(m3[1] == Approx4(mat4_mul_mat4_test_data[i + 36], mat4_mul_mat4_test_data[i + 37], mat4_mul_mat4_test_data[i + 38], mat4_mul_mat4_test_data[i + 39]));
            assert(m3[2] == Approx4(mat4_mul_mat4_test_data[i + 40], mat4_mul_mat4_test_data[i + 41], mat4_mul_mat4_test_data[i + 42], mat4_mul_mat4_test_data[i + 43]));
            assert(m3[3] == Approx4(mat4_mul_mat4_test_data[i + 44], mat4_mul_mat4_test_data[i + 45], mat4_mul_mat4_test_data[i + 46], mat4_mul_mat4_test_data[i + 47]));

            mat4 m4 = m1;
            m4 *= m2;

            assert(m4[0] == Approx4(mat4_mul_mat4_test_data[i + 32], mat4_mul_mat4_test_data[i + 33], mat4_mul_mat4_test_data[i + 34], mat4_mul_mat4_test_data[i + 35]));
            assert(m4[1] == Approx4(mat4_mul_mat4_test_data[i + 36], mat4_mul_mat4_test_data[i + 37], mat4_mul_mat4_test_data[i + 38], mat4_mul_mat4_test_data[i + 39]));
            assert(m4[2] == Approx4(mat4_mul_mat4_test_data[i + 40], mat4_mul_mat4_test_data[i + 41], mat4_mul_mat4_test_data[i + 42], mat4_mul_mat4_test_data[i + 43]));
            assert(m4[3] == Approx4(mat4_mul_mat4_test_data[i + 44], mat4_mul_mat4_test_data[i + 45], mat4_mul_mat4_test_data[i + 46], mat4_mul_mat4_test_data[i + 47]));
        }
    }

    // additional constructors
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen),
              r7 = dist(gen), r8 = dist(gen), r9 = dist(gen), r10 = dist(gen), r11 = dist(gen), r12 = dist(gen),
              r13 = dist(gen), r14 = dist(gen), r15 = dist(gen), r16 = dist(gen);

        mat4 m0 = { { r1, r2, r3, r4 },
            { r5, r6, r7, r8 },
            { r9, r10, r11, r12 },
            { r13, r14, r15, r16 }
        }, m1(m0), m2 = m0;

        assert(m0[0] == Approx4(r1, r2, r3, r4) &&
               m0[1] == Approx4(r5, r6, r7, r8) &&
               m0[2] == Approx4(r9, r10, r11, r12) &&
               m0[3] == Approx4(r13, r14, r15, r16));
        assert(m1[0] == Approx4(r1, r2, r3, r4) &&
               m1[1] == Approx4(r5, r6, r7, r8) &&
               m1[2] == Approx4(r9, r10, r11, r12) &&
               m1[3] == Approx4(r13, r14, r15, r16));
        assert(m2[0] == Approx4(r1, r2, r3, r4) &&
               m2[1] == Approx4(r5, r6, r7, r8) &&
               m2[2] == Approx4(r9, r10, r11, r12) &&
               m2[3] == Approx4(r13, r14, r15, r16));
    }

    // additional operators
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen),
              r7 = dist(gen), r8 = dist(gen), r9 = dist(gen), r10 = dist(gen), r11 = dist(gen), r12 = dist(gen),
              r13 = dist(gen), r14 = dist(gen), r15 = dist(gen), r16 = dist(gen), r17 = dist(gen), r18 = dist(gen),
              r19 = dist(gen), r20 = dist(gen), r21 = dist(gen), r22 = dist(gen), r23 = dist(gen), r24 = dist(gen),
              r25 = dist(gen), r26 = dist(gen), r27 = dist(gen), r28 = dist(gen), r29 = dist(gen), r30 = dist(gen),
              r31 = dist(gen), r32 = dist(gen), r33 = dist(gen), r34 = dist(gen), r35 = dist(gen), r36 = dist(gen),
              r37 = dist(gen), r38 = dist(gen), r39 = dist(gen), r40 = dist(gen), r41 = dist(gen), r42 = dist(gen),
              r43 = dist(gen), r44 = dist(gen), r45 = dist(gen), r46 = dist(gen), r47 = dist(gen), r48 = dist(gen);

        mat4 m0 = { { r1, r2, r3, r4 },
            { r5, r6, r7, r8 },
            { r9, r10, r11, r12 },
            { r13, r14, r15, r16 }
        },
        m1 = { r17, r18, r19, r20,
               r21, r22, r23, r24,
               r25, r26, r27, r28,
               r29, r30, r31, r32
             },
        m2 = m0, m3 = m1;

        mat4 m4 = m0++, m5 = ++m1;

        assert(m0[0] == Approx4(r1 + 1, r2 + 1, r3 + 1, r4 + 1) &&
               m0[1] == Approx4(r5 + 1, r6 + 1, r7 + 1, r8 + 1) &&
               m0[2] == Approx4(r9 + 1, r10 + 1, r11 + 1, r12 + 1) &&
               m0[3] == Approx4(r13 + 1, r14 + 1, r15 + 1, r16 + 1));
        assert(m1[0] == Approx4(r17 + 1, r18 + 1, r19 + 1, r20 + 1) &&
               m1[1] == Approx4(r21 + 1, r22 + 1, r23 + 1, r24 + 1) &&
               m1[2] == Approx4(r25 + 1, r26 + 1, r27 + 1, r28 + 1) &&
               m1[3] == Approx4(r29 + 1, r30 + 1, r31 + 1, r32 + 1));
        assert(m4[0] == Approx4(r1, r2, r3, r4) &&
               m4[1] == Approx4(r5, r6, r7, r8) &&
               m4[2] == Approx4(r9, r10, r11, r12) &&
               m4[3] == Approx4(r13, r14, r15, r16));
        assert(m5[0] == Approx4(r17 + 1, r18 + 1, r19 + 1, r20 + 1) &&
               m5[1] == Approx4(r21 + 1, r22 + 1, r23 + 1, r24 + 1) &&
               m5[2] == Approx4(r25 + 1, r26 + 1, r27 + 1, r28 + 1) &&
               m5[3] == Approx4(r29 + 1, r30 + 1, r31 + 1, r32 + 1));

        mat4 m6 = m2--, m7 = --m3;

        assert(m2[0] == Approx4(r1 - 1, r2 - 1, r3 - 1, r4 - 1) &&
               m2[1] == Approx4(r5 - 1, r6 - 1, r7 - 1, r8 - 1) &&
               m2[2] == Approx4(r9 - 1, r10 - 1, r11 - 1, r12 - 1) &&
               m2[3] == Approx4(r13 - 1, r14 - 1, r15 - 1, r16 - 1));
        assert(m3[0] == Approx4(r17 - 1, r18 - 1, r19 - 1, r20 - 1) &&
               m3[1] == Approx4(r21 - 1, r22 - 1, r23 - 1, r24 - 1) &&
               m3[2] == Approx4(r25 - 1, r26 - 1, r27 - 1, r28 - 1) &&
               m3[3] == Approx4(r29 - 1, r30 - 1, r31 - 1, r32 - 1));
        assert(m6[0] == Approx4(r1, r2, r3, r4) &&
               m6[1] == Approx4(r5, r6, r7, r8) &&
               m6[2] == Approx4(r9, r10, r11, r12) &&
               m6[3] == Approx4(r13, r14, r15, r16));
        assert(m7[0] == Approx4(r17 - 1, r18 - 1, r19 - 1, r20 - 1) &&
               m7[1] == Approx4(r21 - 1, r22 - 1, r23 - 1, r24 - 1) &&
               m7[2] == Approx4(r25 - 1, r26 - 1, r27 - 1, r28 - 1) &&
               m7[3] == Approx4(r29 - 1, r30 - 1, r31 - 1, r32 - 1));

        mat4 m8 = { r33, r34, r35, r36,
                    r37, r38, r39, r40,
                    r41, r42, r43, r44,
                    r45, r46, r47, r48
                  }, m9 = m8, m10 = m8, m11 = m8;

        mat4 mm = { 1, 1, 1, 1,
                    2, 2, 2, 2,
                    3, 3, 3, 3,
                    4, 4, 4, 4
                  };

        m8 += mm;
        m9 -= mm;
        //m10 *= mm;
        m11 /= mm;

        assert(m8[0] == Approx4(r33 + 1, r34 + 1, r35 + 1, r36 + 1) &&
               m8[1] == Approx4(r37 + 2, r38 + 2, r39 + 2, r40 + 2) &&
               m8[2] == Approx4(r41 + 3, r42 + 3, r43 + 3, r44 + 3) &&
               m8[3] == Approx4(r45 + 4, r46 + 4, r47 + 4, r48 + 4));
        assert(m9[0] == Approx4(r33 - 1, r34 - 1, r35 - 1, r36 - 1) &&
               m9[1] == Approx4(r37 - 2, r38 - 2, r39 - 2, r40 - 2) &&
               m9[2] == Approx4(r41 - 3, r42 - 3, r43 - 3, r44 - 3) &&
               m9[3] == Approx4(r45 - 4, r46 - 4, r47 - 4, r48 - 4));
        //assert(m10[0] == Approx4(4, 8, 12, 16) &&
        //       m10[1] == Approx4(8, 16, 24, 32) &&
        //       m10[2] == Approx4(12, 24, 36, 48) &&
        //       m10[3] == Approx4(16, 32, 48, 64));
        assert(m11[0] == Approx4(r33 / 1, r34 / 1, r35 / 1, r36 / 1) &&
               m11[1] == Approx4(r37 / 2, r38 / 2, r39 / 2, r40 / 2) &&
               m11[2] == Approx4(r41 / 3, r42 / 3, r43 / 3, r44 / 3) &&
               m11[3] == Approx4(r45 / 4, r46 / 4, r47 / 4, r48 / 4));

        mat4 m12 = { r33, r34, r35, r36,
                     r37, r38, r39, r40,
                     r41, r42, r43, r44,
                     r45, r46, r47, r48
                   };
        m12 = -m12;

        assert(m12[0] == Approx4(-r33, -r34, -r35, -r36) &&
               m12[1] == Approx4(-r37, -r38, -r39, -r40) &&
               m12[2] == Approx4(-r41, -r42, -r43, -r44) &&
               m12[3] == Approx4(-r45, -r46, -r47, -r48));

        mat4 m13 = m12;

        assert(m12 == m13);
        assert(m11 != m13);

        mat4 m14 = { r33, r34, r35, r36,
                     r37, r38, r39, r40,
                     r41, r42, r43, r44,
                     r45, r46, r47, r48
                   };

        m14[0] += { 1, 1, 1, 1 };
        m14[1] -= { 1, 1, 1, 1 };
        m14[2] *= { 2, 2, 2, 2 };
        m14[3] /= { 2, 2, 2, 2 };

        assert(m14[0] == Approx4(r33 + 1, r34 + 1, r35 + 1, r36 + 1) &&
               m14[1] == Approx4(r37 - 1, r38 - 1, r39 - 1, r40 - 1) &&
               m14[2] == Approx4(r41 * 2, r42 * 2, r43 * 2, r44 * 2) &&
               m14[3] == Approx4(r45 / 2, r46 / 2, r47 / 2, r48 / 2));
    }

    std::cout << "OK" << std::endl;
}

void test_mat4() {
    std::random_device rd;
    auto seed = rd();

    std::cout << "test_mat4 (seed " << seed << ")" << std::endl;

    test_mat4(math::Scalar, seed);
#ifndef __arm__
    test_mat4(math::SSE2, seed);
    test_mat4(math::SSE3, seed);
    test_mat4(math::SSE4_1, seed);
    test_mat4(math::AVX, seed);
#else
    test_mat4(math::NEON, seed);
#endif
}
