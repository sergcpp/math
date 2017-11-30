#include "test_assert.h"

#include <iostream>
#include <random>

#include "../math.hpp"

void test_mat3(math::e_arch arch, unsigned seed) {
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
              r25 = dist(gen);

        mat3 m1, m2(r1),
             m3(r2, r3, r4,
                r5, r6, r7,
                r8, r9, r10),
             m4(vec3{ r11 }, vec3{ r12 }, vec3{ r13 });

        require(m1[0] == Approx3(1, 0, 0));
        require(m1[1] == Approx3(0, 1, 0));
        require(m1[2] == Approx3(0, 0, 1));

        require(m2[0] == Approx3(r1, 0, 0));
        require(m2[1] == Approx3(0, r1, 0));
        require(m2[2] == Approx3(0, 0, r1));

        require(m3[0] == Approx3(r2, r3, r4));
        require(m3[1] == Approx3(r5, r6, r7));
        require(m3[2] == Approx3(r8, r9, r10));

        require(m4[0] == Approx3(r11, r11, r11));
        require(m4[1] == Approx3(r12, r12, r12));
        require(m4[2] == Approx3(r13, r13, r13));

        m1[0] = vec3(r14, r15, r16);
        m1[1] = vec3(r17, r18, r19);

        require(m1[0] == Approx3(r14, r15, r16));
        require(m1[1] == Approx3(r17, r18, r19));
        require(m1[2] == Approx3(0, 0, 1));

        m1[0][1] = r20;
        m1[1][1] = r21;

        require(m1[0] == Approx3(r14, r20, r16));
        require(m1[1] == Approx3(r17, r21, r19));
        require(m1[2] == Approx3(0, 0, 1));

        mat3 m5 = m1 + m2, m6 = m2 + m3;

        require(m5[0] == Approx3(r1 + r14, r20, r16) &&
               m5[1] == Approx3(r17, r1 + r21, r19) &&
               m5[2] == Approx3(0, 0, r1 + 1));
        require(m6[0] == Approx3(r1 + r2, r3, r4) &&
               m6[1] == Approx3(r5, r1 + r6, r7) &&
               m6[2] == Approx3(r8, r9, r1 + r10));

        mat3 m7 = m1 - m2, m8 = m2 - m3;

        require(m7[0] == Approx3(r14 - r1, r20, r16) &&
               m7[1] == Approx3(r17, r21 - r1, r19) &&
               m7[2] == Approx3(0, 0, 1 - r1));
        require(m8[0] == Approx3(r1 - r2, -r3, -r4) &&
               m8[1] == Approx3(-r5, r1 - r6, -r7) &&
               m8[2] == Approx3(-r8, -r9, r1 - r10));

        //mat3 m9 = m1 * m2, m10 = m2 * m3;

        //require(m9[0] == Approx3(2.3, 6.9, 6.9) &&
        //       m9[1] == Approx3(6.9, 18.4, 11.5) &&
        //       m9[2] == Approx3(0, 0, 2.3));
        //require(m10[0] == Approx3(0, 2.3, 4.6) &&
        //       m10[1] == Approx3(9.2, 11.5, 13.8) &&
        //       m10[2] == Approx3(18.4, 20.7, 23));

        m1[2] = { r22, r23, r24 };

        mat3 m11 = m2 / m1;

        require(m11[0] == Approx3(r1 / r14, 0, 0) &&
               m11[1] == Approx3(0, r1 / r21, 0) &&
               m11[2] == Approx3(0, 0, r1 / r24));

        mat3 m13 = matrix_comp_mult(m1, m3);

        require(m13[0] == Approx3(r14 * r2, r20 * r3, r16 * r4));
        require(m13[1] == Approx3(r17 * r5, r21 * r6, r19 * r7));
        require(m13[2] == Approx3(r22 * r8, r23 * r9, r24 * r10));

        mat3 m14 = r25 * m1,
             m15 = m1 * r25,
             m16 = m1 / r25;

        require(m14[0] == Approx3(r14 * r25, r20 * r25, r16 * r25) &&
               m14[1] == Approx3(r17 * r25, r21 * r25, r19 * r25) &&
               m14[2] == Approx3(r22 * r25, r23 * r25, r24 * r25));

        require(m15[0] == Approx3(r14 * r25, r20 * r25, r16 * r25) &&
               m15[1] == Approx3(r17 * r25, r21 * r25, r19 * r25) &&
               m15[2] == Approx3(r22 * r25, r23 * r25, r24 * r25));

        require(m16[0] == Approx3(r14 / r25, r20 / r25, r16 / r25) &&
               m16[1] == Approx3(r17 / r25, r21 / r25, r19 / r25) &&
               m16[2] == Approx3(r22 / r25, r23 / r25, r24 / r25));
    }

    {
        // matrix multiplication
        extern std::vector<float> mat3_mul_mat3_test_data;

        for (size_t i = 0; i < mat3_mul_mat3_test_data.size(); i += 27) {
            mat3 m1 = make_mat3(&mat3_mul_mat3_test_data[i + 0]),
                 m2 = make_mat3(&mat3_mul_mat3_test_data[i + 9]);
            mat3 m3 = m1 * m2;

            require(m3[0] == Approx3(mat3_mul_mat3_test_data[i + 18], mat3_mul_mat3_test_data[i + 19], mat3_mul_mat3_test_data[i + 20]));
            require(m3[1] == Approx3(mat3_mul_mat3_test_data[i + 21], mat3_mul_mat3_test_data[i + 22], mat3_mul_mat3_test_data[i + 23]));
            require(m3[2] == Approx3(mat3_mul_mat3_test_data[i + 24], mat3_mul_mat3_test_data[i + 25], mat3_mul_mat3_test_data[i + 26]));

            mat3 m4 = m1;
            m4 *= m2;

            require(m4[0] == Approx3(mat3_mul_mat3_test_data[i + 18], mat3_mul_mat3_test_data[i + 19], mat3_mul_mat3_test_data[i + 20]));
            require(m4[1] == Approx3(mat3_mul_mat3_test_data[i + 21], mat3_mul_mat3_test_data[i + 22], mat3_mul_mat3_test_data[i + 23]));
            require(m4[2] == Approx3(mat3_mul_mat3_test_data[i + 24], mat3_mul_mat3_test_data[i + 25], mat3_mul_mat3_test_data[i + 26]));
        }
    }

    // additional constructors
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen),
              r7 = dist(gen), r8 = dist(gen), r9 = dist(gen);

        mat3 m0 = { { r1, r2, r3 },
            { r4, r5, r6 },
            { r7, r8, r9 }
        }, m1(m0), m2 = m0;

        require(m0[0] == Approx3(r1, r2, r3) &&
               m0[1] == Approx3(r4, r5, r6) &&
               m0[2] == Approx3(r7, r8, r9));
        require(m1[0] == Approx3(r1, r2, r3) &&
               m1[1] == Approx3(r4, r5, r6) &&
               m1[2] == Approx3(r7, r8, r9));
        require(m2[0] == Approx3(r1, r2, r3) &&
               m2[1] == Approx3(r4, r5, r6) &&
               m2[2] == Approx3(r7, r8, r9));
    }

    // additional operators
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen),
              r7 = dist(gen), r8 = dist(gen), r9 = dist(gen);

        mat3 m0 = { { r1, r2, r3 },
            { r4, r5, r6 },
            { r7, r8, r9 }
        },
        m1 = { r1, r2, r3,
               r4, r5, r6,
               r7, r8, r9
             },
        m2 = m0, m3 = m1;

        mat3 m4 = m0++, m5 = ++m1;

        require(m0[0] == Approx3(r1 + 1, r2 + 1, r3 + 1) &&
               m0[1] == Approx3(r4 + 1, r5 + 1, r6 + 1) &&
               m0[2] == Approx3(r7 + 1, r8 + 1, r9 + 1));
        require(m1[0] == Approx3(r1 + 1, r2 + 1, r3 + 1) &&
               m1[1] == Approx3(r4 + 1, r5 + 1, r6 + 1) &&
               m1[2] == Approx3(r7 + 1, r8 + 1, r9 + 1));
        require(m4[0] == Approx3(r1, r2, r3) &&
               m4[1] == Approx3(r4, r5, r6) &&
               m4[2] == Approx3(r7, r8, r9));
        require(m5[0] == Approx3(r1 + 1, r2 + 1, r3 + 1) &&
               m5[1] == Approx3(r4 + 1, r5 + 1, r6 + 1) &&
               m5[2] == Approx3(r7 + 1, r8 + 1, r9 + 1));

        mat3 m6 = m2--, m7 = --m3;

        require(m2[0] == Approx3(r1 - 1, r2 - 1, r3 - 1) &&
               m2[1] == Approx3(r4 - 1, r5 - 1, r6 - 1) &&
               m2[2] == Approx3(r7 - 1, r8 - 1, r9 - 1));
        require(m3[0] == Approx3(r1 - 1, r2 - 1, r3 - 1) &&
               m3[1] == Approx3(r4 - 1, r5 - 1, r6 - 1) &&
               m3[2] == Approx3(r7 - 1, r8 - 1, r9 - 1));
        require(m6[0] == Approx3(r1, r2, r3) &&
               m6[1] == Approx3(r4, r5, r6) &&
               m6[2] == Approx3(r7, r8, r9));
        require(m7[0] == Approx3(r1 - 1, r2 - 1, r3 - 1) &&
               m7[1] == Approx3(r4 - 1, r5 - 1, r6 - 1) &&
               m7[2] == Approx3(r7 - 1, r8 - 1, r9 - 1));

        mat3 m8 = { r1, r2, r3,
                    r4, r5, r6,
                    r7, r8, r9
                  }, m9 = m8, m10 = m8, m11 = m8;

        mat3 mm = { 1, 1, 1,
                    2, 2, 2,
                    3, 3, 3
                  };

        m8 += mm;
        m9 -= mm;
        //m10 *= mm;
        m11 /= mm;

        require(m8[0] == Approx3(r1 + 1, r2 + 1, r3 + 1) &&
               m8[1] == Approx3(r4 + 2, r5 + 2, r6 + 2) &&
               m8[2] == Approx3(r7 + 3, r8 + 3, r9 + 3));
        require(m9[0] == Approx3(r1 - 1, r2 - 1, r3 - 1) &&
               m9[1] == Approx3(r4 - 2, r5 - 2, r6 - 2) &&
               m9[2] == Approx3(r7 - 3, r8 - 3, r9 - 3));
        //require(m10[0] == Approx3(r1 * 1, r2 * 1, r3 * 1) &&
        //       m10[1] == Approx3(r4 * 2, r5 * 2, r6 * 2) &&
        //       m10[2] == Approx3(r7 * 3, r8 * 3, r9 * 3));
        require(m11[0] == Approx3(r1 / 1, r2 / 1, r3 / 1) &&
               m11[1] == Approx3(r4 / 2, r5 / 2, r6 / 2) &&
               m11[2] == Approx3(r7 / 3, r8 / 3, r9 / 3));

        mat3 m12 = { r1, r2, r3,
                     r4, r5, r6,
                     r7, r8, r9
                   };
        m12 = -m12;

        require(m12[0] == Approx3(-r1, -r2, -r3) &&
               m12[1] == Approx3(-r4, -r5, -r6) &&
               m12[2] == Approx3(-r7, -r8, -r9));

        mat3 m13 = m12;

        require(m12 == m13);
        require(m11 != m13);

        mat3 m14 = { r1, r2, r3,
                     r4, r5, r6,
                     r7, r8, r9
                   };

        m14[0] += { 1, 1, 1 };
        m14[1] -= { 1, 1, 1 };
        m14[2] *= { 2, 2, 2 };

        require(m14[0] == Approx3(r1 + 1, r2 + 1, r3 + 1) &&
               m14[1] == Approx3(r4 - 1, r5 - 1, r6 - 1) &&
               m14[2] == Approx3(r7 * 2, r8 * 2, r9 * 2));

        m14[0] /= { 2, 2, 2 };

        require(m14[0] == Approx3((r1 + 1) / 2, (r2 + 1) / 2, (r3 + 1) / 2) &&
               m14[1] == Approx3(r4 - 1, r5 - 1, r6 - 1) &&
               m14[2] == Approx3(r7 * 2, r8 * 2, r9 * 2));
    }

    std::cout << "OK" << std::endl;
}

void test_mat3() {
    std::random_device rd;
    auto seed = rd();

    std::cout << "test_mat3 (seed " << seed << ")" << std::endl;

    test_mat3(math::Scalar, seed);
#ifndef __arm__
    test_mat3(math::SSE2, seed);
    test_mat3(math::SSE3, seed);
    test_mat3(math::SSE4_1, seed);
    test_mat3(math::AVX, seed);
#else
    test_mat3(math::NEON, seed);
#endif
}
