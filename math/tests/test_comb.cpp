#include "test_assert.h"

#include "../math.hpp"

void test_comb(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // mat - vec multiplication
        mat2 m1 = { 1, 2,
                    3, 4 };
        mat3 m2 = { 1, 2, 3,
                    4, 5, 6,
                    7, 8, 9 };
        mat4 m3 = { 1, 2, 3, 4,
                    5, 6, 7, 8,
                    1, 2, 3, 4,
                    5, 6, 7, 8 };
        vec2 v1 = { 1, 2 };
        vec3 v2 = { 1, 2, 3 };
        vec4 v3 = { 1, 2, 3, 4 };

        v1 = m1 * v1;
        v2 = m2 * v2;
        v3 = m3 * v3;

        assert(v1 == Approx2(7, 10));
        assert(v2 == Approx3(30, 36, 42));
        assert(v3 == Approx4(34, 44, 54, 64));
    }

    {   // vec - mat multiplication
        mat2 m1 = { 1, 2,
                    3, 4 };
        mat3 m2 = { 1, 2, 3,
                    4, 5, 6,
                    7, 8, 9 };
        mat4 m3 = { 1, 2, 3, 4,
                    5, 6, 7, 8,
                    1, 2, 3, 4,
                    5, 6, 7, 8 };
        vec2 v1 = { 1, 2 };
        vec3 v2 = { 1, 2, 3 };
        vec4 v3 = { 1, 2, 3, 4 };

        v1 = v1 * m1;
        v2 = v2 * m2;
        v3 = v3 * m3;

        assert(v1 == Approx2(5, 11));
        assert(v2 == Approx3(14, 32, 50));
        assert(v3 == Approx4(30, 70, 30, 70));
    }
}

void test_comb() {
    test_comb(math::Scalar);
#ifndef __arm__
    test_comb(math::SSE2);
    test_comb(math::SSE3);
    test_comb(math::SSE4_1);
    test_comb(math::AVX);
#else
    test_comb(math::NEON);
#endif
}