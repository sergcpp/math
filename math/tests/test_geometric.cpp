#include "test_assert.h"

#include "../math.hpp"

void test_geometric(math::e_arch feat) {
    using namespace math;

    init(feat);

    {   // vec2
        vec2 v0 = { 1, 2 }, v1 = { -1, -2 };

        float l0 = length(v0);

        float d01 = distance(v0, v1);

        float dot01 = dot(v0, v1);

        assert(l0 == Approx(2.23606));
        assert(d01 == Approx(4.47213));
        assert(dot01 == Approx(-5));
    }

    {   // vec3
        vec3 v0 = { 1, 2, 3 }, v1 = { -1, -2, -3 };

        float l0 = length(v0);

        float d01 = distance(v0, v1);

        float dot01 = dot(v0, v1);

        assert(l0 == Approx(3.74165));
        assert(d01 == Approx(7.48331));
        assert(dot01 == Approx(-14));

        vec3 v2 = { 2, 3, 4 }, v3 = { 5, 6, 7 };

        vec3 cross23 = cross(v2, v3);

        assert(cross23[0] == Approx(-3));
        assert(cross23[1] == Approx(6));
        assert(cross23[2] == Approx(-3));

        vec3 v4 = normalize(v0), v5 = normalize_fast(v1);

        assert(v4 == Approx3(0.26726124, 0.53452248, 0.80178372));
        assert(v5 == Approx3(-0.26726124, -0.53452248, -0.80178372).epsilon(0.001));
    }

    {   // vec4
        vec4 v0 = { 1, 2, 3, 4 }, v1 = { -1, -2, -3, -4 };

        float l0 = length(v0);

        float d01 = distance(v0, v1);

        float dot01 = dot(v0, v1);

        assert(l0 == Approx(5.47722));
        assert(d01 == Approx(10.95445));
        assert(dot01 == Approx(-30));

        vec4 v2 = normalize(v0), v3 = normalize_fast(v1);

        assert(v2 == Approx4(0.18257418, 0.36514837, 0.54772255, 0.73029674));
        assert(v3 == Approx4(-0.18257418, -0.36514837, -0.54772255, -0.73029674));
    }
}

void test_geometric() {
    test_geometric(math::Scalar);
#ifndef __arm__
    test_geometric(math::SSE2);
    test_geometric(math::SSE3);
    test_geometric(math::SSE4_1);
    test_geometric(math::AVX);
#else
    test_geometric(math::NEON);
#endif
}
