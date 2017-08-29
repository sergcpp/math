#include "test_assert.h"

#include "../math.hpp"

#include <iostream>
#include <random>

void test_comb(math::e_arch arch, unsigned seed) {
    using namespace math;

    init(arch);

	std::cout << "\t" << math::arch_name[arch] << " ...";

    {   // mat - vec multiplication
		extern std::vector<float> mat4_vec4_mult_test_data;

		for (size_t i = 0; i < mat4_vec4_mult_test_data.size(); i += 24) {
			vec4 v1 = make_vec4(&mat4_vec4_mult_test_data[i]);
			mat4 m1 = make_mat4(&mat4_vec4_mult_test_data[i + 4]);

			vec4 res = m1 * v1;

			assert(res == Approx4(mat4_vec4_mult_test_data[i + 20], mat4_vec4_mult_test_data[i + 21],
								  mat4_vec4_mult_test_data[i + 22], mat4_vec4_mult_test_data[i + 23]).epsilon(0.01));
		}

		extern std::vector<float> mat3_vec3_mult_test_data;

		for (size_t i = 0; i < mat3_vec3_mult_test_data.size(); i += 15) {
			vec3 v1 = make_vec3(&mat3_vec3_mult_test_data[i]);
			mat3 m1 = make_mat3(&mat3_vec3_mult_test_data[i + 3]);

			vec3 res = m1 * v1;

			assert(res == Approx3(mat3_vec3_mult_test_data[i + 12], mat3_vec3_mult_test_data[i + 13],
								  mat3_vec3_mult_test_data[i + 14]).epsilon(0.01));
		}

		extern std::vector<float> mat2_vec2_mult_test_data;

		for (size_t i = 0; i < mat2_vec2_mult_test_data.size(); i += 8) {
			vec2 v1 = make_vec2(&mat2_vec2_mult_test_data[i]);
			mat2 m1 = make_mat2(&mat2_vec2_mult_test_data[i + 2]);

			vec2 res = m1 * v1;

			assert(res == Approx2(mat2_vec2_mult_test_data[i + 6], mat2_vec2_mult_test_data[i + 7]).epsilon(0.01));
		}
    }

    {   // vec - mat multiplication
		extern std::vector<float> vec4_mat4_mult_test_data;

		for (size_t i = 0; i < vec4_mat4_mult_test_data.size(); i += 24) {
			vec4 v1 = make_vec4(&vec4_mat4_mult_test_data[i]);
			mat4 m1 = make_mat4(&vec4_mat4_mult_test_data[i + 4]);

			vec4 res = v1 * m1;

			assert(res == Approx4(vec4_mat4_mult_test_data[i + 20], vec4_mat4_mult_test_data[i + 21],
								  vec4_mat4_mult_test_data[i + 22], vec4_mat4_mult_test_data[i + 23]).epsilon(0.01));
		}

		extern std::vector<float> vec3_mat3_mult_test_data;

		for (size_t i = 0; i < vec3_mat3_mult_test_data.size(); i += 15) {
			vec3 v1 = make_vec3(&vec3_mat3_mult_test_data[i]);
			mat3 m1 = make_mat3(&vec3_mat3_mult_test_data[i + 3]);

			vec3 res = v1 * m1;

			assert(res == Approx3(vec3_mat3_mult_test_data[i + 12], vec3_mat3_mult_test_data[i + 13],
								  vec3_mat3_mult_test_data[i + 14]).epsilon(0.01));
		}

		extern std::vector<float> vec2_mat2_mult_test_data;

		for (size_t i = 0; i < vec2_mat2_mult_test_data.size(); i += 8) {
			vec2 v1 = make_vec2(&vec2_mat2_mult_test_data[i]);
			mat2 m1 = make_mat2(&vec2_mat2_mult_test_data[i + 2]);

			vec2 res = v1 * m1;

			assert(res == Approx2(vec2_mat2_mult_test_data[i + 6], vec2_mat2_mult_test_data[i + 7]).epsilon(0.01));
		}
    }

	std::cout << "OK" << std::endl;
}

void test_comb() {
	std::random_device rd;
	auto seed = rd();

	std::cout << "test_comb (seed " << seed << ")" << std::endl;

    test_comb(math::Scalar, seed);
#ifndef __arm__
    test_comb(math::SSE2, seed);
    test_comb(math::SSE3, seed);
    test_comb(math::SSE4_1, seed);
    test_comb(math::AVX, seed);
#else
    test_comb(math::NEON, seed);
#endif
}