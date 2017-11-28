#include "test_assert.h"

#include "../math.hpp"

#include <iostream>
#include <random>

void test_ivec2(math::e_arch arch, unsigned seed) {
    using namespace math;

    init(arch);

	const int NUM_REPEATS = 1000;
	std::mt19937 gen(seed);
	std::uniform_int_distribution<int> dist(-1000, 1000);

	std::cout << "\t" << math::arch_name[arch] << " ...";

    // basic usage
	for (int i = 0; i < NUM_REPEATS; i++) {
		int r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen);
		if (r4 == 0 || r2 == 0 || r3 == 0) continue;

        ivec2 v1, v2(r1), v3(r2, r3);

        assert(v2[0] == r1 && v2[1] == r1);

        v2[0] = v2[1] = r4;

        assert(v1[0] == 0 && v1[1] == 0);
        assert(v2[0] == r4 && v2[1] == r4);
        assert(v3[0] == r2 && v3[1] == r3);
        assert(v3.x == r2 && v3.y == r3);
        assert(v3.r == r2 && v3.g == r3);
        assert(v3.s == r2 && v3.t == r3);

        ivec2 v4 = v1 + v2, v5 = v2 + v3;

        assert(v4[0] == r4 && v4[1] == r4);
        assert(v5[0] == r4 + r2 && v5[1] == r4 + r3);

        ivec2 v6 = v1 - v2, v7 = v2 - v3;

        assert(v6[0] == -r4 && v6[1] == -r4);
        assert(v7[0] == r4 - r2 && v7[1] == r4 - r3);

        ivec2 v8 = v1 * v2, v9 = v2 * v3;

        assert(v8[0] == 0 && v8[1] == 0);
        assert(v9[0] == r4 * r2 && v9[1] == r4 * r3);

        ivec2 v10 = v1 / v2, v11 = v2 / v3;

        assert(v10[0] == 0 && v10[1] == 0);
        assert(v11[0] == r4 / r2 && v11[1] == r4 / r3);
    }

    // additional constructors
	for (int i = 0; i < NUM_REPEATS; i++) {
		int r1 = dist(gen), r2 = dist(gen);

        ivec2 v0 = { r1, r2 }, v1(v0), v2 = v0;

        assert(v0 == ivec2(r1, r2)); assert(v1 == ivec2(r1, r2)); assert(v2 == ivec2(r1, r2));
    }

    // additional operators
	for (int i = 0; i < NUM_REPEATS; i++) {
		int r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen),
			r7 = dist(gen), r8 = dist(gen), r9 = dist(gen), r10 = dist(gen), r11 = dist(gen), r12 = dist(gen),
			r13 = dist(gen), r14 = dist(gen);
		if (r11 == 0 || r12 == 0) continue;

        ivec2 v0 = { r1, r2 }, v1 = { r3, r4 }, v2 = { r5, r6 }, v3 = { r7, r8 };

        ivec2 v4 = v0++, v5 = ++v1;

        assert(v0 == ivec2(r1 + 1, r2 + 1)); assert(v1 == ivec2(r3 + 1, r4 + 1));
		assert(v4 == ivec2(r1, r2)); assert(v5 == ivec2(r3 + 1, r4 + 1));

        ivec2 v6 = v2--, v7 = --v3;

        assert(v2 == ivec2(r5 - 1, r6 - 1)); assert(v3 == ivec2(r7 - 1, r8 - 1));
		assert(v6 == ivec2(r5, r6)); assert(v7 == ivec2(r7 - 1, r8 - 1));

        ivec2 v8 = { r9, r10 }, v9 = { r9, r10 }, v10 = { r9, r10 }, v11 = { r9, r10 };

        v8 += ivec2{ r11, r12 };
        v9 -= ivec2{ r11, r12 };
        v10 *= ivec2{ r11, r12 };
        v11 /= ivec2{ r11, r12 };

        assert(v8 == ivec2(r9 + r11, r10 + r12));
        assert(v9 == ivec2(r9 - r11, r10 - r12));
        assert(v10 == ivec2(r9 * r11, r10 * r12));
        assert(v11 == ivec2(r9 / r11, r10 / r12));

        ivec2 v12 = { r13, r14 };
        v12 = -v12;

        assert(v12 == ivec2(-r13, -r14));

        ivec2 v13 = v12;

        assert(v12 == v13);
        assert(v11 != v13);

        ivec2 v14 = { r13, r14 };

        v14[0] += 1;
        v14[1] -= 1;

        assert(v14 == ivec2(r13 + 1, r14 - 1));

        v14[0] *= 2;
        v14[1] /= 2;

        assert(v14 == ivec2((r13 + 1) * 2, (r14 - 1) / 2));
    }

    // arithmetics with deref
	for (int i = 0; i < NUM_REPEATS; i++) {
		int r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen),
			r7 = dist(gen), r8 = dist(gen), r9 = dist(gen), r10 = dist(gen), r11 = dist(gen), r12 = dist(gen);

        ivec2 vv{ r1, r2 };
        
        int f1 = r3;
        ivec2 v1 = { r4, r5 };
        ivec3 v2 = { r6, r7, r8 };
        ivec4 v3 = { r9, r10, r11, r12 };
        //imat2 m1;
        //imat3 m2;
        //imat4 m3;

        f1 = f1 * vv[0];
        v1 = v1 * vv[0];
        v2 = v2 * vv[0];
        v3 = v3 * vv[0];
        //m1 = m1 * vv[0];
        //m2 = m2 * vv[0];
        //m3 = m3 * vv[0];

        assert(f1 == r3 * r1);
        assert(v1 == ivec2(r4 * r1, r5 * r1));
        assert(v2 == ivec3(r6 * r1, r7 * r1, r8 * r1));
        assert(v3 == ivec4(r9 * r1, r10 * r1, r11 * r1, r12 * r1));

        //assert(m1[0] == ivec2(2, 0));
        //assert(m1[1] == ivec2(0, 2));
        //assert(m2[0] == ivec3(2, 0, 0));
        //assert(m2[1] == ivec3(0, 2, 0));
        //assert(m2[2] == ivec3(0, 0, 2));
        //assert(m3[0] == ivec4(2, 0, 0, 0));
        //assert(m3[1] == ivec4(0, 2, 0, 0));
        //assert(m3[2] == ivec4(0, 0, 2, 0));
        //assert(m3[3] == ivec4(0, 0, 0, 2));

		const int *p1 = value_ptr(vv);
		const int *p2 = &vv[0];
		assert(p1 == p2);
    }

	std::cout << "OK" << std::endl;
}

void test_ivec2() {
	std::random_device rd;
	auto seed = rd();

	std::cout << "test_ivec2 (seed " << seed << ")" << std::endl;

    test_ivec2(math::Scalar, seed);
#ifndef __arm__
    test_ivec2(math::SSE2, seed);
    test_ivec2(math::SSE3, seed);
    test_ivec2(math::SSE4_1, seed);
    test_ivec2(math::AVX, seed);
#else
    test_ivec2(math::NEON, seed);
#endif
}
