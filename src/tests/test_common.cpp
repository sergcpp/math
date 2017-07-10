#include "test_assert.h"

#include "../math.hpp"

void test_common(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // abs
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float abs1 = math::abs(v1);
        vec2 abs2 = math::abs(v2);
        vec3 abs3 = math::abs(v3);
        vec4 abs4 = math::abs(v4);

        assert(abs1 == Approx(3.4));
        assert(abs2 == Approx2(3.4, 3.5));
        assert(abs3 == Approx3(3.4, 3.5, 5));
        assert(abs4 == Approx4(3.4, 3.5, 5, 8));
    }

    {   // sign
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float sign1 = math::sign(v1);
        vec2 sign2 = math::sign(v2);
        vec3 sign3 = math::sign(v3);
        vec4 sign4 = math::sign(v4);

        assert(sign1 == Approx(1));
        assert(sign2 == Approx2(1, -1));
        assert(sign3 == Approx3(1, -1, 1));
        assert(sign4 == Approx4(1, -1, 1, -1));
    }

    {   // floor
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float floor1 = math::floor(v1);
        vec2 floor2 = math::floor(v2);
        vec3 floor3 = math::floor(v3);
        vec4 floor4 = math::floor(v4);

        assert(floor1 == Approx(3));
        assert(floor2 == Approx2(3, -4));
        assert(floor3 == Approx3(3, -4, 5));
        assert(floor4 == Approx4(3, -4, 5, -8));
    }

    {   // ceil
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float ceil1 = math::ceil(v1);
        vec2 ceil2 = math::ceil(v2);
        vec3 ceil3 = math::ceil(v3);
        vec4 ceil4 = math::ceil(v4);

        assert(ceil1 == Approx(4));
        assert(ceil2 == Approx2(4, -3));
        assert(ceil3 == Approx3(4, -3, 5));
        assert(ceil4 == Approx4(4, -3, 5, -8));
    }

    {   // fract
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float fract1 = math::fract(v1);
        vec2 fract2 = math::fract(v2);
        vec3 fract3 = math::fract(v3);
        vec4 fract4 = math::fract(v4);

        assert(fract1 == Approx(0.4));
        assert(fract2 == Approx2(0.4, 0.5));
        assert(fract3 == Approx3(0.4, 0.5, 0));
        assert(fract4 == Approx4(0.4, 0.5, 0, 0));
    }

    {   // mod
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float mod1 = math::mod(v1, 2.0f);
        vec2 mod2 = math::mod(v2, vec2(2, 3));
        vec3 mod3 = math::mod(v3, vec3(2, 3, 4));
        vec4 mod4 = math::mod(v4, vec4(2, 3, 4, 5));

        assert(mod1 == Approx(1.4));
        assert(mod2 == Approx2(1.4, 2.5));
        assert(mod3 == Approx3(1.4, 2.5, 1));
        assert(mod4 == Approx4(1.4, 2.5, 1, 2));

        mod2 = math::mod(v2, vec2(2));
        mod3 = math::mod(v3, vec3(3));
        mod4 = math::mod(v4, vec4(4));

        assert(mod2 == Approx2(1.4, 0.5));
        assert(mod3 == Approx3(0.4, 2.5, 2));
        assert(mod4 == Approx4(3.4, 0.5, 1, 0));
    }

    {   // min
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float min1 = math::min(v1, 2);
        vec2 min2 = math::min(v2, { 2, -2.3f });
        vec3 min3 = math::min(v3, { 2, -2.3f, 4 });
        vec4 min4 = math::min(v4, { 2, -2.3f, 4, -9.1f });

        assert(min1 == Approx(2));
        assert(min2 == Approx2(2, -3.5));
        assert(min3 == Approx3(2, -3.5, 4));
        assert(min4 == Approx4(2, -3.5, 4, -9.1));

        min1 = math::min(v1, 2);
        min2 = math::min(v2, 2);
        min3 = math::min(v3, 2);
        min4 = math::min(v4, 2);

        assert(min1 == Approx(2));
        assert(min2 == Approx2(2, -3.5));
        assert(min3 == Approx3(2, -3.5, 2));
        assert(min4 == Approx4(2, -3.5, 2, -8));
    }

    {   // max
        float v1 = 3.4f;
        vec2 v2 = { v1, -3.5f };
        vec3 v3 = { v2, 5 };
        vec4 v4 = { v3, -8 };

        float max1 = math::max(v1, 2);
        vec2 max2 = math::max(v2, { 2, -2.3f });
        vec3 max3 = math::max(v3, { 2, -2.3f, 4 });
        vec4 max4 = math::max(v4, { 2, -2.3f, 4, -9.1f });

        assert(max1 == Approx(3.4));
        assert(max2 == Approx2(3.4, -2.3));
        assert(max3 == Approx3(3.4, -2.3, 5));
        assert(max4 == Approx4(3.4, -2.3, 5, -8));

        max1 = math::max(v1, 2);
        max2 = math::max(v2, 2);
        max3 = math::max(v3, 2);
        max4 = math::max(v4, 2);

        assert(max1 == Approx(3.4));
        assert(max2 == Approx2(3.4, 2));
        assert(max3 == Approx3(3.4, 2, 5));
        assert(max4 == Approx4(3.4, 2, 5, 2));
    }
}

void test_common() {
    test_common(math::Scalar);
#ifndef __arm__
    test_common(math::SSE2);
    test_common(math::SSE3);
    test_common(math::SSE4_1);
    test_common(math::AVX);
#else
    test_common(math::NEON);
#endif
}
