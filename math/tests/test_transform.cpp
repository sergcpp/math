#include "test_assert.h"

#include "../math.hpp"

void test_transform(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // test translate
        mat4 m1;
        mat4 m2 = translate(m1, { 1, 2, 3 });

        assert(m2[0] == Approx4(1, 0, 0, 0));
        assert(m2[1] == Approx4(0, 1, 0, 0));
        assert(m2[2] == Approx4(0, 0, 1, 0));
        assert(m2[3] == Approx4(1, 2, 3, 1));
    }

    {   // test rotate
        mat4 m1;
        mat4 m2 = rotate(m1, radians(45), { 0, 1, 0 });

        assert(m2[0] == Approx4(0.707106, 0, -0.707106, 0));
        assert(m2[1] == Approx4(0, 1, 0, 0));
        assert(m2[2] == Approx4(0.707106, 0, 0.707106, 0));
        assert(m2[3] == Approx4(0, 0, 0, 1));
    }

    {   // test scale
        mat4 m1;
        mat4 m2 = scale(m1, { 1, 2, 3 });

        assert(m2[0] == Approx4(1, 0, 0, 0));
        assert(m2[1] == Approx4(0, 2, 0, 0));
        assert(m2[2] == Approx4(0, 0, 3, 0));
        assert(m2[3] == Approx4(0, 0, 0, 1));
    }
}

void test_transform() {
    test_transform(math::Scalar);
#ifndef __arm__
    test_transform(math::SSE2);
    test_transform(math::SSE3);
    test_transform(math::SSE4_1);
    test_transform(math::AVX);
#else
    test_transform(math::NEON);
#endif
}
