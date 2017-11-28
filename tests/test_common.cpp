#include "test_assert.h"

#include <iostream>
#include <random>

#include "../math.hpp"

void test_common(math::e_arch arch, unsigned seed) {
    using namespace math;

    init(arch);

    const int NUM_REPEATS = 1000;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> dist(-1000000, 1000000),
        pos_dist(0, 1000000),
        neg_dist(-1000000, 0);

    std::cout << "\t" << math::arch_name[arch] << " ...";

    // abs
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = pos_dist(gen), r2 = neg_dist(gen), r3 = pos_dist(gen), r4 = neg_dist(gen);

        float v1 = r1;
        vec2 v2 = { v1, r2 };
        vec3 v3 = { v2, r3 };
        vec4 v4 = { v3, r4 };

        float abs1 = math::abs(v1);
        vec2 abs2 = math::abs(v2);
        vec3 abs3 = math::abs(v3);
        vec4 abs4 = math::abs(v4);

        assert(abs1 == Approx(r1));
        assert(abs2 == Approx2(r1, -r2));
        assert(abs3 == Approx3(r1, -r2, r3));
        assert(abs4 == Approx4(r1, -r2, r3, -r4));
    }

    // sign
    for (int i = 0; i < NUM_REPEATS; i++) {
        float r1 = pos_dist(gen), r2 = neg_dist(gen), r3 = pos_dist(gen), r4 = neg_dist(gen);

        float v1 = r1;
        vec2 v2 = { v1, r2 };
        vec3 v3 = { v2, r3 };
        vec4 v4 = { v3, r4 };

        float sign1 = math::sign(v1);
        vec2 sign2 = math::sign(v2);
        vec3 sign3 = math::sign(v3);
        vec4 sign4 = math::sign(v4);

        assert(sign1 == Approx(1));
        assert(sign2 == Approx2(1, -1));
        assert(sign3 == Approx3(1, -1, 1));
        assert(sign4 == Approx4(1, -1, 1, -1));
    }

    {
        // floor
        extern std::vector<float> floor_test_data;

        for (size_t i = 0; i < floor_test_data.size(); i += 8) {
            float v1 = floor_test_data[i];
            vec2 v2 = { v1, floor_test_data[i + 2] };
            vec3 v3 = { v2, floor_test_data[i + 4] };
            vec4 v4 = { v3, floor_test_data[i + 6] };

            float floor1 = math::floor(v1);
            vec2 floor2 = math::floor(v2);
            vec3 floor3 = math::floor(v3);
            vec4 floor4 = math::floor(v4);

            assert(floor1 == Approx(floor_test_data[i + 1]));
            assert(floor2 == Approx2(floor_test_data[i + 1], floor_test_data[i + 3]));
            assert(floor3 == Approx3(floor_test_data[i + 1], floor_test_data[i + 3], floor_test_data[i + 5]));
            assert(floor4 == Approx4(floor_test_data[i + 1], floor_test_data[i + 3], floor_test_data[i + 5], floor_test_data[i + 7]));
        }
    }

    {
        // ceil
        extern std::vector<float> ceil_test_data;

        for (size_t i = 0; i < ceil_test_data.size(); i += 8) {
            float v1 = ceil_test_data[i];
            vec2 v2 = { v1, ceil_test_data[i + 2] };
            vec3 v3 = { v2, ceil_test_data[i + 4] };
            vec4 v4 = { v3, ceil_test_data[i + 6] };

            float ceil1 = math::ceil(v1);
            vec2 ceil2 = math::ceil(v2);
            vec3 ceil3 = math::ceil(v3);
            vec4 ceil4 = math::ceil(v4);

            assert(ceil1 == Approx(ceil_test_data[i + 1]));
            assert(ceil2 == Approx2(ceil_test_data[i + 1], ceil_test_data[i + 3]));
            assert(ceil3 == Approx3(ceil_test_data[i + 1], ceil_test_data[i + 3], ceil_test_data[i + 5]));
            assert(ceil4 == Approx4(ceil_test_data[i + 1], ceil_test_data[i + 3], ceil_test_data[i + 5], ceil_test_data[i + 7]));
        }
    }

    {
        // fract
        extern std::vector<float> fract_test_data;

        for (size_t i = 0; i < fract_test_data.size(); i += 8) {
            float v1 = fract_test_data[i];
            vec2 v2 = { v1, fract_test_data[i + 2] };
            vec3 v3 = { v2, fract_test_data[i + 4] };
            vec4 v4 = { v3, fract_test_data[i + 6] };

            float fract1 = math::fract(v1);
            vec2 fract2 = math::fract(v2);
            vec3 fract3 = math::fract(v3);
            vec4 fract4 = math::fract(v4);

            assert(fract1 == Approx(fract_test_data[i + 1]));
            assert(fract2 == Approx2(fract_test_data[i + 1], fract_test_data[i + 3]));
            assert(fract3 == Approx3(fract_test_data[i + 1], fract_test_data[i + 3], fract_test_data[i + 5]));
            assert(fract4 == Approx4(fract_test_data[i + 1], fract_test_data[i + 3], fract_test_data[i + 5], fract_test_data[i + 7]));
        }
    }

    {
        // mod
        extern std::vector<float> mod_test_data;

        for (size_t i = 0; i < mod_test_data.size(); i += 12) {
            float v1 = mod_test_data[i];
            vec2 v2 = { v1, mod_test_data[i + 3] };
            vec3 v3 = { v2, mod_test_data[i + 6] };
            vec4 v4 = { v3, mod_test_data[i + 9] };

            float mod1 = math::mod(v1, mod_test_data[i + 1]);
            vec2 mod2 = math::mod(v2, vec2(mod_test_data[i + 1], mod_test_data[i + 4]));
            vec3 mod3 = math::mod(v3, vec3(mod_test_data[i + 1], mod_test_data[i + 4], mod_test_data[i + 7]));
            vec4 mod4 = math::mod(v4, vec4(mod_test_data[i + 1], mod_test_data[i + 4], mod_test_data[i + 7], mod_test_data[i + 10]));

            assert(mod1 == Approx(mod_test_data[i + 2]));
            assert(mod2 == Approx2(mod_test_data[i + 2], mod_test_data[i + 5]));
            assert(mod3 == Approx3(mod_test_data[i + 2], mod_test_data[i + 5], mod_test_data[i + 8]));
            assert(mod4 == Approx4(mod_test_data[i + 2], mod_test_data[i + 5], mod_test_data[i + 8], mod_test_data[i + 11]));
        }
    }

    {
        // min
        extern std::vector<float> min_test_data;

        for (size_t i = 0; i < min_test_data.size(); i += 17) {
            float v1 = min_test_data[i];
            vec2 v2 = { v1, min_test_data[i + 3] };
            vec3 v3 = { v2, min_test_data[i + 6] };
            vec4 v4 = { v3, min_test_data[i + 9] };

            float min1 = math::min(v1, min_test_data[i + 1]);
            vec2 min2 = math::min(v2, { min_test_data[i + 1], min_test_data[i + 4] });
            vec3 min3 = math::min(v3, { min_test_data[i + 1], min_test_data[i + 4], min_test_data[i + 7] });
            vec4 min4 = math::min(v4, { min_test_data[i + 1], min_test_data[i + 4], min_test_data[i + 7], min_test_data[i + 10] });

            assert(min1 == Approx(min_test_data[i + 2]));
            assert(min2 == Approx2(min_test_data[i + 2], min_test_data[i + 5]));
            assert(min3 == Approx3(min_test_data[i + 2], min_test_data[i + 5], min_test_data[i + 8]));
            assert(min4 == Approx4(min_test_data[i + 2], min_test_data[i + 5], min_test_data[i + 8], min_test_data[i + 11]));

            min1 = math::min(v1, min_test_data[i + 12]);
            min2 = math::min(v2, min_test_data[i + 12]);
            min3 = math::min(v3, min_test_data[i + 12]);
            min4 = math::min(v4, min_test_data[i + 12]);

            assert(min1 == Approx(min_test_data[i + 13]));
            assert(min2 == Approx2(min_test_data[i + 13], min_test_data[i + 14]));
            assert(min3 == Approx3(min_test_data[i + 13], min_test_data[i + 14], min_test_data[i + 15]));
            assert(min4 == Approx4(min_test_data[i + 13], min_test_data[i + 14], min_test_data[i + 15], min_test_data[i + 16]));
        }
    }

    {
        // max
        extern std::vector<float> max_test_data;

        for (size_t i = 0; i < max_test_data.size(); i += 17) {
            float v1 = max_test_data[i];
            vec2 v2 = { v1, max_test_data[i + 3] };
            vec3 v3 = { v2, max_test_data[i + 6] };
            vec4 v4 = { v3, max_test_data[i + 9] };

            float max1 = math::max(v1, max_test_data[i + 1]);
            vec2 max2 = math::max(v2, { max_test_data[i + 1], max_test_data[i + 4] });
            vec3 max3 = math::max(v3, { max_test_data[i + 1], max_test_data[i + 4], max_test_data[i + 7] });
            vec4 max4 = math::max(v4, { max_test_data[i + 1], max_test_data[i + 4], max_test_data[i + 7], max_test_data[i + 10] });

            assert(max1 == Approx(max_test_data[i + 2]));
            assert(max2 == Approx2(max_test_data[i + 2], max_test_data[i + 5]));
            assert(max3 == Approx3(max_test_data[i + 2], max_test_data[i + 5], max_test_data[i + 8]));
            assert(max4 == Approx4(max_test_data[i + 2], max_test_data[i + 5], max_test_data[i + 8], max_test_data[i + 11]));

            max1 = math::max(v1, max_test_data[i + 12]);
            max2 = math::max(v2, max_test_data[i + 12]);
            max3 = math::max(v3, max_test_data[i + 12]);
            max4 = math::max(v4, max_test_data[i + 12]);

            assert(max1 == Approx(max_test_data[i + 13]));
            assert(max2 == Approx2(max_test_data[i + 13], max_test_data[i + 14]));
            assert(max3 == Approx3(max_test_data[i + 13], max_test_data[i + 14], max_test_data[i + 15]));
            assert(max4 == Approx4(max_test_data[i + 13], max_test_data[i + 14], max_test_data[i + 15], max_test_data[i + 16]));
        }
    }

    std::cout << "OK" << std::endl;
}

void test_common() {
    std::random_device rd;
    auto seed = rd();

    std::cout << "test_common (seed " << seed << ")" << std::endl;

    test_common(math::Scalar, seed);
#ifndef __arm__
    test_common(math::SSE2, seed);
    test_common(math::SSE3, seed);
    test_common(math::SSE4_1, seed);
    test_common(math::AVX, seed);
#else
    test_common(math::NEON, seed);
#endif
}
