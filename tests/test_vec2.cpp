#include "test_assert.h"

#include <iostream>
#include <random>

#include "../math.hpp"

void test_vec2(math::e_arch arch, unsigned int seed) {
    using namespace math;

    init(arch);

    const int NUM_REPEATS = 1000;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> dist(-1000000, 1000000);

    std::cout << "\t" << math::arch_name[arch] << " ...";

    // basic usage
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen);

        vec2 v1, v2(r1), v3(r2, r3);

        require(v2[0] == Approx(r1) && v2[1] == Approx(r1));

        v2[0] = v2[1] = r4;

        require(v1[0] == Approx(0) && v1[1] == Approx(0));
        require(v2[0] == Approx(r4) && v2[1] == Approx(r4));
        require(v3[0] == Approx(r2) && v3[1] == Approx(r3));
        require(v3.x == Approx(r2) && v3.y == Approx(r3));
        require(v3.r == Approx(r2) && v3.g == Approx(r3));
        require(v3.s == Approx(r2) && v3.t == Approx(r3));

        vec2 v4 = v1 + v2, v5 = v2 + v3;

        require(v4[0] == Approx(r4) && v4[1] == Approx(r4));
        require(v5[0] == Approx(r4 + r2) && v5[1] == Approx(r4 + r3));

        vec2 v6 = v1 - v2, v7 = v2 - v3;

        require(v6[0] == Approx(-r4) && v6[1] == Approx(-r4));
        require(v7[0] == Approx(r4 - r2) && v7[1] == Approx(r4 - r3));

        vec2 v8 = v1 * v2, v9 = v2 * v3;

        require(v8[0] == Approx(0) && v8[1] == Approx(0));
        require(v9[0] == Approx(r4 * r2) && v9[1] == Approx(r4 * r3));

        vec2 v10 = v1 / v2, v11 = v2 / v3;

        require(v10[0] == Approx(0) && v10[1] == Approx(0));
        require(v11[0] == Approx(r4 / r2) && v11[1] == Approx(r4 / r3));
    }

    // additional constructors
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen);

        vec2 v0 = { r1, r2 }, v1(v0), v2 = v0;

        require(v0 == Approx2(r1, r2));
        require(v1 == Approx2(r1, r2));
        require(v2 == Approx2(r1, r2));
    }

    // additional operators
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen), r5 = dist(gen), r6 = dist(gen);

        vec2 v0 = { r1, r2 }, v1 = { r1, r2 }, v2 = { r3, r4 }, v3 = { r3, r4 };

        vec2 v4 = v0++, v5 = ++v1;

        require(v0 == Approx2(r1 + 1, r2 + 1));
        require(v1 == Approx2(r1 + 1, r2 + 1));
        require(v4 == Approx2(r1, r2));
        require(v5 == Approx2(r1 + 1, r2 + 1));

        vec2 v6 = v2--, v7 = --v3;

        require(v2 == Approx2(r3 - 1, r4 - 1));
        require(v3 == Approx2(r3 - 1, r4 - 1));
        require(v6 == Approx2(r3, r4));
        require(v7 == Approx2(r3 - 1, r4 - 1));

        vec2 v8 = { r1, r2 }, v9 = { r1, r2 }, v10 = { r1, r2 }, v11 = { r1, r2 };

        v8 += vec2{ r5, r6 };
        v9 -= vec2{ r5, r6 };
        v10 *= vec2{ r5, r6 };
        v11 /= vec2{ r5, r6 };

        require(v8 == Approx2(r1 + r5, r2 + r6));
        require(v9 == Approx2(r1 - r5, r2 - r6));
        require(v10 == Approx2(r1 * r5, r2 * r6));
        require(v11 == Approx2(r1 / r5, r2 / r6));

        vec2 v12 = { r1, r2 };
        v12 = -v12;

        require(v12 == Approx2(-r1, -r2));

        vec2 v13 = v12;

        require(v12 == v13);
        require(v11 != v13);

        vec2 v14 = { r1, r2 };

        v14[0] += 1;
        v14[1] -= 1;

        require(v14 == Approx2(r1 + 1, r2 - 1));

        v14[0] *= 2;
        v14[1] /= 2;

        require(v14 == Approx2((r1 + 1) * 2, (r2 - 1) / 2));
    }

    // arithmetics with deref
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen), r4 = dist(gen);

        vec2 vv{ r1, r2 };

        float f1 = r1;
        vec2 v1 = { r1, r2 };
        vec3 v2 = { r1, r2, r3 };
        vec4 v3 = { r1, r2, r3, r4 };
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

        require(f1 == Approx(r1 * r1));
        require(v1 == Approx2(r1 * r1, r2 * r1));
        require(v2 == Approx3(r1 * r1, r2 * r1, r3 * r1));
        require(v3 == Approx4(r1 * r1, r2 * r1, r3 * r1, r4 * r1));

        require(m1[0] == Approx2(r1, 0));
        require(m1[1] == Approx2(0, r1));
        require(m2[0] == Approx3(r1, 0, 0));
        require(m2[1] == Approx3(0, r1, 0));
        require(m2[2] == Approx3(0, 0, r1));
        require(m3[0] == Approx4(r1, 0, 0, 0));
        require(m3[1] == Approx4(0, r1, 0, 0));
        require(m3[2] == Approx4(0, 0, r1, 0));
        require(m3[3] == Approx4(0, 0, 0, r1));

        const float *p1 = value_ptr(vv);
        const float *p2 = &vv[0];
        require(p1 == p2);
    }

    std::cout << "OK" << std::endl;
}

void test_vec2() {
    std::random_device rd;
    auto seed = rd();

    std::cout << "test_vec2 (seed " << seed << ")" << std::endl;

    test_vec2(math::Scalar, seed);
#ifndef __arm__
    test_vec2(math::SSE2, seed);
    test_vec2(math::SSE3, seed);
    test_vec2(math::SSE4_1, seed);
    test_vec2(math::AVX, seed);
#else
    test_vec2(math::NEON, seed);
#endif
}
