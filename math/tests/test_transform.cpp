#include "test_assert.h"

#include "../math.hpp"

#include <iostream>
#include <random>

void test_transform(math::e_arch arch, unsigned seed) {
    using namespace math;

    init(arch);

	const int NUM_REPEATS = 1000;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(-100, 100);

	std::cout << "\t" << math::arch_name[arch] << " ...";

    // test translate
	for (int i = 0; i < NUM_REPEATS; i++) {
		float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen);

        mat4 m1;
        mat4 m2 = translate(m1, { r1, r2, r3 });

        assert(m2[0] == Approx4(1, 0, 0, 0));
        assert(m2[1] == Approx4(0, 1, 0, 0));
        assert(m2[2] == Approx4(0, 0, 1, 0));
        assert(m2[3] == Approx4(r1, r2, r3, 1));
    }

    {   // test rotate
		extern std::vector<float> mat_rotate_test_data;

		for (size_t i = 0; i < mat_rotate_test_data.size(); i += 20) {
			mat4 m1;
			mat4 m2 = rotate(m1, radians(mat_rotate_test_data[0]), make_vec3(&mat_rotate_test_data[1]));

			assert(m2[0] == Approx4(mat_rotate_test_data[4], mat_rotate_test_data[5], mat_rotate_test_data[6], mat_rotate_test_data[7]));
			assert(m2[1] == Approx4(mat_rotate_test_data[8], mat_rotate_test_data[9], mat_rotate_test_data[10], mat_rotate_test_data[11]));
			assert(m2[2] == Approx4(mat_rotate_test_data[12], mat_rotate_test_data[13], mat_rotate_test_data[14], mat_rotate_test_data[15]));
			assert(m2[3] == Approx4(mat_rotate_test_data[16], mat_rotate_test_data[17], mat_rotate_test_data[18], mat_rotate_test_data[19]));
		}
    }

    // test scale
	for (int i = 0; i < NUM_REPEATS; i++) {
		float r1 = dist(gen), r2 = dist(gen), r3 = dist(gen);

        mat4 m1;
        mat4 m2 = scale(m1, { r1, r2, r3 });

        assert(m2[0] == Approx4(r1, 0, 0, 0));
        assert(m2[1] == Approx4(0, r2, 0, 0));
        assert(m2[2] == Approx4(0, 0, r3, 0));
        assert(m2[3] == Approx4(0, 0, 0, 1));
    }

    {   // test inverse
		extern std::vector<float> mat2_inverse_test_data;

		for (size_t i = 0; i < mat2_inverse_test_data.size(); i += 8) {
			mat2 m1 = make_mat2(&mat2_inverse_test_data[i]);
			mat2 im1 = inverse(m1);

			assert(im1[0] == Approx2(mat2_inverse_test_data[i + 4], mat2_inverse_test_data[i + 5]));
			assert(im1[1] == Approx2(mat2_inverse_test_data[i + 6], mat2_inverse_test_data[i + 7]));
		}

		extern std::vector<float> mat3_inverse_test_data;

		for (size_t i = 0; i < mat3_inverse_test_data.size(); i += 18) {
			mat3 m1 = make_mat3(&mat3_inverse_test_data[i]);
			mat3 im1 = inverse(m1);

			assert(im1[0] == Approx3(mat3_inverse_test_data[i + 9], mat3_inverse_test_data[i + 10], mat3_inverse_test_data[i + 11]));
			assert(im1[1] == Approx3(mat3_inverse_test_data[i + 12], mat3_inverse_test_data[i + 13], mat3_inverse_test_data[i + 14]));
			assert(im1[2] == Approx3(mat3_inverse_test_data[i + 15], mat3_inverse_test_data[i + 16], mat3_inverse_test_data[i + 17]));
		}

		extern std::vector<float> mat4_inverse_test_data;

		for (size_t i = 0; i < mat4_inverse_test_data.size(); i += 32) {
			mat4 m1 = make_mat4(&mat4_inverse_test_data[i]);
			mat4 im1 = inverse(m1);

			assert(im1[0] == Approx4(mat4_inverse_test_data[i + 16], mat4_inverse_test_data[i + 17], mat4_inverse_test_data[i + 18], mat4_inverse_test_data[i + 19]));
			assert(im1[1] == Approx4(mat4_inverse_test_data[i + 20], mat4_inverse_test_data[i + 21], mat4_inverse_test_data[i + 22], mat4_inverse_test_data[i + 23]));
			assert(im1[2] == Approx4(mat4_inverse_test_data[i + 24], mat4_inverse_test_data[i + 25], mat4_inverse_test_data[i + 26], mat4_inverse_test_data[i + 27]));
			assert(im1[3] == Approx4(mat4_inverse_test_data[i + 28], mat4_inverse_test_data[i + 29], mat4_inverse_test_data[i + 30], mat4_inverse_test_data[i + 31]));
		}
    }

	std::cout << "OK" << std::endl;
}

void test_transform() {
	std::random_device rd;
	auto seed = rd();

	std::cout << "test_transform (seed " << seed << ")" << std::endl;

    test_transform(math::Scalar, seed);
#ifndef __arm__
    test_transform(math::SSE2, seed);
    test_transform(math::SSE3, seed);
    test_transform(math::SSE4_1, seed);
    test_transform(math::AVX, seed);
#else
    test_transform(math::NEON, seed);
#endif
}
