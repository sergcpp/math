#include "test_assert.h"

#include "../math.hpp"

#include <iostream>

#include <random>
#include "glm/ext.hpp"

void test_geometric(math::e_arch arch, unsigned seed) {
    using namespace math;

    init(arch);

	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> dist(-100, 100);

		std::string s;
		for (int i = 0; i < 256; i++) {
			glm::mat4 m1 { dist(gen), dist(gen), dist(gen), dist(gen),
						   dist(gen), dist(gen), dist(gen), dist(gen),
						   dist(gen), dist(gen), dist(gen), dist(gen),
						   dist(gen), dist(gen), dist(gen), dist(gen) };
			glm::mat4 m2 = glm::inverse(m1);

			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					s += std::to_string(m1[j][k]);
					s += "f, ";
				}
			}

			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					s += std::to_string(m2[j][k]);
					s += "f, ";
				}
			}
			s += "\n";
		}

		volatile int ii = 0;
	}

	std::cout << "\t" << math::arch_name[arch] << " ...";

	{	// vec2
		extern std::vector<float> vec2_geo_test_data;

		for (size_t i = 0; i < vec2_geo_test_data.size(); i += 9) {
			vec2 v0 = { vec2_geo_test_data[0], vec2_geo_test_data[1] }, v1 = { vec2_geo_test_data[2], vec2_geo_test_data[3] };

			float l0 = length(v0);
			float ll0 = length2(v0);

			float d01 = distance(v0, v1);
			float dd01 = distance2(v0, v1);

			float dot01 = dot(v0, v1);

			assert(l0 == Approx(vec2_geo_test_data[4]));
			assert(ll0 == Approx(vec2_geo_test_data[5]));
			assert(d01 == Approx(vec2_geo_test_data[6]));
			assert(dd01 == Approx(vec2_geo_test_data[7]));
			assert(dot01 == Approx(vec2_geo_test_data[8]));
		}
	}

    {   // vec3
		extern std::vector<float> vec3_geo_test_data;

		for (size_t i = 0; i < vec3_geo_test_data.size(); i += 17) {
			vec3 v0 = { vec3_geo_test_data[0], vec3_geo_test_data[1], vec3_geo_test_data[2] },
				 v1 = { vec3_geo_test_data[3], vec3_geo_test_data[4], vec3_geo_test_data[5] };

			float l0 = length(v0);
			float ll0 = length2(v0);

			float d01 = distance(v0, v1);
			float dd01 = distance2(v0, v1);

			float dot01 = dot(v0, v1);

			assert(l0 == Approx(vec3_geo_test_data[6]));
			assert(ll0 == Approx(vec3_geo_test_data[7]));
			assert(d01 == Approx(vec3_geo_test_data[8]));
			assert(dd01 == Approx(vec3_geo_test_data[9]));
			assert(dot01 == Approx(vec3_geo_test_data[10]));

			vec3 cross01 = cross(v0, v1);

			assert(cross01[0] == Approx(vec3_geo_test_data[11]));
			assert(cross01[1] == Approx(vec3_geo_test_data[12]));
			assert(cross01[2] == Approx(vec3_geo_test_data[13]));

			vec3 v2 = normalize(v0), v3 = normalize_fast(v0);

			assert(v2 == Approx3(vec3_geo_test_data[14], vec3_geo_test_data[15], vec3_geo_test_data[16]));
			assert(v3 == Approx3(vec3_geo_test_data[14], vec3_geo_test_data[15], vec3_geo_test_data[16]).epsilon(0.001));
		}
    }

    {   // vec4
		extern std::vector<float> vec4_geo_test_data;

		for (size_t i = 0; i < vec4_geo_test_data.size(); i += 17) {
			vec4 v0 = { vec4_geo_test_data[0], vec4_geo_test_data[1], vec4_geo_test_data[2], vec4_geo_test_data[3] },
				 v1 = { vec4_geo_test_data[4], vec4_geo_test_data[5], vec4_geo_test_data[6], vec4_geo_test_data[7] };

			float l0 = length(v0);
			float ll0 = length2(v0);

			float d01 = distance(v0, v1);
			float dd01 = distance2(v0, v1);

			float dot01 = dot(v0, v1);

			assert(l0 == Approx(vec4_geo_test_data[8]));
			assert(ll0 == Approx(vec4_geo_test_data[9]));
			assert(d01 == Approx(vec4_geo_test_data[10]));
			assert(dd01 == Approx(vec4_geo_test_data[11]));
			assert(dot01 == Approx(vec4_geo_test_data[12]));

			vec4 v2 = normalize(v0), v3 = normalize_fast(v0);

			assert(v2 == Approx4(vec4_geo_test_data[13], vec4_geo_test_data[14], vec4_geo_test_data[15], vec4_geo_test_data[16]));
			assert(v3 == Approx4(vec4_geo_test_data[13], vec4_geo_test_data[14], vec4_geo_test_data[15], vec4_geo_test_data[16]));
		}
	}

	std::cout << "OK" << std::endl;
}

void test_geometric() {
	std::random_device rd;
	auto seed = rd();

	std::cout << "test_geometric (seed " << seed << ")" << std::endl;

    test_geometric(math::Scalar, seed);
#ifndef __arm__
    test_geometric(math::SSE2, seed);
    test_geometric(math::SSE3, seed);
    test_geometric(math::SSE4_1, seed);
    test_geometric(math::AVX, seed);
#else
    test_geometric(math::NEON, seed);
#endif
}
