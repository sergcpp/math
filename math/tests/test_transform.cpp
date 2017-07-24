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

    {   // test inverse
        math::mat2 m2 = { 1, 2, 3, 4 };
        math::mat3 m3 = { 1, 2, 3,
                          4, 1, 2,
                          3, 4, 1 };
        math::mat4 m4 = { 1, 2, 3, 4,
                          1, 2, 1, 2,
                          1, 1, 1, 1,
                          3, 2, 1, 1 };

        math::mat2 im2 = math::inverse(m2);
        math::mat3 im3 = math::inverse(m3);
        math::mat4 im4 = math::inverse(m4);

        assert(im2[0] == Approx2(-2, 1));
        assert(im2[1] == Approx2(1.5, -0.5));

        assert(im3[0] == Approx3(-0.194444448, 0.2777777791, 0.027777778));
        assert(im3[1] == Approx3(0.055555556, -0.222222224, 0.277777791));
        assert(im3[2] == Approx3(0.361111104, 0.0555555556, -0.194444448));

        assert(im4[0] == Approx4(0.5, -0.5, -2, 1));
        assert(im4[1] == Approx4(-1, 1, 3, -1));
        assert(im4[2] == Approx4(-0.5, -0.5, 4, -1));
        assert(im4[3] == Approx4(1, 0, -4, 1));
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
