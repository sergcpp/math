#include "test_assert.h"

#include <iostream>
#include <random>

#include "../math.hpp"

void test_mat2(math::e_arch arch, unsigned seed) {
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
              r13 = dist(gen), r14 = dist(gen), r15 = dist(gen), r16 = dist(gen), r17 = dist(gen), r18 = dist(gen);

        mat2 m1, m2(r1), m3(r2, r3, r4, r5), m4(vec2(r6, r7), vec2(r8, r9));

        assert(m1[0] == Approx2(1, 0));
        assert(m1[1] == Approx2(0, 1));

        assert(m2[0] == Approx2(r1, 0));
        assert(m2[1] == Approx2(0, r1));

        assert(m3[0] == Approx2(r2, r3));
        assert(m3[1] == Approx2(r4, r5));

        assert(m4[0] == Approx2(r6, r7));
        assert(m4[1] == Approx2(r8, r9));

        m1[0] = vec2(r10, r11);
        m1[1] = vec2(r12, r13);

        assert(m1[0] == Approx2(r10, r11));
        assert(m1[1] == Approx2(r12, r13));

        m1[0][1] = r14;
        m1[1][1] = r15;

        assert(m1[0] == Approx2(r10, r14));
        assert(m1[1] == Approx2(r12, r15));

        mat2 m5 = m1 + m2, m6 = m2 + m3;

        assert(m5[0] == Approx2(r10 + r1, r14) && m5[1] == Approx2(r12, r15 + r1));
        assert(m6[0] == Approx2(r1 + r2, r3) && m6[1] == Approx2(r4, r1 + r5));

        mat2 m7 = m1 - m2, m8 = m2 - m3;

        assert(m7[0] == Approx2(r10 - r1, r14) && m7[1] == Approx2(r12, r15 - r1));
        assert(m8[0] == Approx2(r1 - r2, -r3) && m8[1] == Approx2(-r4, r1 - r5));

        mat2 m11 = m2 / m1;

        assert(m11[0] == Approx2(r1 / r10, 0) && m11[1] == Approx2(0, r1 / r15));

        mat2 m13 = matrix_comp_mult(m1, m3);

        assert(m13[0] == Approx2(r10 * r2, r14 * r3));
        assert(m13[1] == Approx2(r12 * r4, r15 * r5));

        mat2 m14 = 2.0f * m1,
             m15 = m1 * 2.0f,
             m16 = m1 / 2.0f;

        assert(m14[0] == Approx2(r10 * 2, r14 * 2));
        assert(m14[1] == Approx2(r12 * 2, r15 * 2));

        assert(m15[0] == Approx2(r10 * 2, r14 * 2));
        assert(m15[1] == Approx2(r12 * 2, r15 * 2));

        assert(m16[0] == Approx2(r10 / 2, r14 / 2));
        assert(m16[1] == Approx2(r12 / 2, r15 / 2));
    }

    {   // matrix multiplication
        extern std::vector<float> mat2_mul_mat2_test_data;

        for (size_t i = 0; i < mat2_mul_mat2_test_data.size(); i += 12) {
            mat2 m1 = make_mat2(&mat2_mul_mat2_test_data[i + 0]),
                 m2 = make_mat2(&mat2_mul_mat2_test_data[i + 4]);
            mat2 m3 = m1 * m2;

            assert(m3[0] == Approx2(mat2_mul_mat2_test_data[i + 8], mat2_mul_mat2_test_data[i + 9]));
            assert(m3[1] == Approx2(mat2_mul_mat2_test_data[i + 10], mat2_mul_mat2_test_data[i + 11]));

            mat2 m4 = m1;
            m4 *= m2;

            assert(m4[0] == Approx2(mat2_mul_mat2_test_data[i + 8], mat2_mul_mat2_test_data[i + 9]));
            assert(m4[1] == Approx2(mat2_mul_mat2_test_data[i + 10], mat2_mul_mat2_test_data[i + 11]));
        }
    }

    // additional constructors
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen);

        mat2 m0 = { { r1, r2 }, { r3, r4 } }, m1(m0), m2 = m0;

        assert(m0[0] == Approx2(r1, r2) && m0[1] == Approx2(r3, r4));
        assert(m1[0] == Approx2(r1, r2) && m1[1] == Approx2(r3, r4));
        assert(m2[0] == Approx2(r1, r2) && m2[1] == Approx2(r3, r4));
    }

    {   // additional operators
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen),
              r5 = dist(gen), r6 = dist(gen), r7 = dist(gen), r8 = dist(gen);

        mat2 m0 = { { r1, r2 }, { r3, r4 } }, m1 = { r1, r2, r3, r4 },
             m2 = { { r1, r2 }, { r3, r4 } }, m3 = { r1, r2, r3, r4 };

        mat2 m4 = m0++, m5 = ++m1;

        assert(m0[0] == Approx2(r1 + 1, r2 + 1) && m0[1] == Approx2(r3 + 1, r4 + 1)); assert(m1[0] == Approx2(r1 + 1, r2 + 1) && m1[1] == Approx2(r3 + 1, r4 + 1));
        assert(m4[0] == Approx2(r1, r2) && m4[1] == Approx2(r3, r4)); assert(m5[0] == Approx2(r1 + 1, r2 + 1) && m5[1] == Approx2(r3 + 1, r4 + 1));

        mat2 m6 = m2--, m7 = --m3;

        assert(m2[0] == Approx2(r1 - 1, r2 - 1) && m2[1] == Approx2(r3 - 1, r4 - 1)); assert(m3[0] == Approx2(r1 - 1, r2 - 1) && m3[1] == Approx2(r3 - 1, r4 - 1));
        assert(m6[0] == Approx2(r1, r2) && m4[1] == Approx2(r3, r4)); assert(m7[0] == Approx2(r1 - 1, r2 - 1) && m7[1] == Approx2(r3 - 1, r4 - 1));

        mat2 m8 = { r1, r2, r3, r4 }, m9 = m8, m10 = m8, m11 = m8;

        m8 += mat2{ r5, r6, r7, r8 };
        m9 -= mat2{ r5, r6, r7, r8 };
        //m10 *= mat2{ r5, r6, r7, r8 };
        m11 /= mat2{ r5, r6, r7, r8 };

        assert(m8[0] == Approx2(r1 + r5, r2 + r6) && m8[1] == Approx2(r3 + r7, r4 + r8));
        assert(m9[0] == Approx2(r1 - r5, r2 - r6) && m9[1] == Approx2(r3 - r7, r4 - r8));
        //assert(m10[0] == Approx2(r1 * r5, r2 * r6) && m10[1] == Approx2(r3 * r7, r4 * r8));
        assert(m11[0] == Approx2(r1 / r5, r2 / r6) && m11[1] == Approx2(r3 / r7, r4 / r8));

        mat2 m12 = { r1, r2, r3, r4 };
        m12 = -m12;

        assert(m12[0] == Approx2(-r1, -r2) && m12[1] == Approx2(-r3, -r4));

        mat2 m13 = m12;

        assert(m12 == m13);
        assert(m11 != m13);

        mat2 m14 = { r1, r2, r3, r4 };

        m14[0] += { r5, r6 };
        m14[1] -= { r5, r6 };
        
        assert(m14[0] == Approx2(r1 + r5, r2 + r6) && m14[1] == Approx2(r3 - r5, r4 - r6));

        mat2 m15 = { r1, r2, r3, r4 };

        m15[0] *= { r5, r6 };
        m15[1] /= { r5, r6 };

        assert(m15[0] == Approx2(r1 * r5, r2 * r6) && m15[1] == Approx2(r3 / r5, r4 / r6));
    }

    std::cout << "OK" << std::endl;
}

void test_mat2() {
    std::random_device rd;
    auto seed = rd();

    std::cout << "test_mat2 (seed " << seed << ")" << std::endl;

    test_mat2(math::Scalar, seed);
#ifndef __arm__
    test_mat2(math::SSE2, seed);
    test_mat2(math::SSE3, seed);
    test_mat2(math::SSE4_1, seed);
    test_mat2(math::AVX, seed);
#else
    test_mat2(math::NEON, seed);
#endif
}

