#include "test_assert.h"

#include "../math.hpp"

//#include "glm/glm.hpp"

void test_vec4(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        vec4 v1, v2(2.3f), v3(1, 2, 3, 4);

        assert(v2[0] == Approx(2.3)); assert(v2[1] == Approx(2.3)); assert(v2[2] == Approx(2.3)); assert(v2[3] == Approx(2.3));

        v2[0] = v2[1] = v2[2] = v2[3] = 1.3f;

        assert(v1[0] == Approx(0)); assert(v1[1] == Approx(0)); assert(v1[2] == Approx(0)); assert(v1[3] == Approx(0));
        assert(v2[0] == Approx(1.3)); assert(v2[1] == Approx(1.3)); assert(v2[2] == Approx(1.3)); assert(v2[3] == Approx(1.3));
        assert(v3[0] == Approx(1)); assert(v3[1] == Approx(2)); assert(v3[2] == Approx(3)); assert(v3[3] == Approx(4));
        assert(v3.x() == Approx(1)); assert(v3.y() == Approx(2)); assert(v3.z() == Approx(3)); assert(v3.w() == Approx(4));
        assert(v3.r() == Approx(1)); assert(v3.g() == Approx(2)); assert(v3.b() == Approx(3)); assert(v3.a() == Approx(4));
        assert(v3.s() == Approx(1)); assert(v3.t() == Approx(2)); assert(v3.p() == Approx(3)); assert(v3.q() == Approx(4));

        vec4 v4 = v1 + v2, v5 = v2 + v3;

        assert(v4[0] == Approx(1.3)); assert(v4[1] == Approx(1.3)); assert(v4[2] == Approx(1.3)); assert(v4[3] == Approx(1.3));
        assert(v5[0] == Approx(2.3)); assert(v5[1] == Approx(3.3)); assert(v5[2] == Approx(4.3)); assert(v5[3] == Approx(5.3));

        vec4 v6 = v1 - v2, v7 = v2 - v3;

        assert(v6[0] == Approx(-1.3)); assert(v6[1] == Approx(-1.3)); assert(v6[2] == Approx(-1.3)); assert(v6[3] == Approx(-1.3));
        assert(v7[0] == Approx(0.3)); assert(v7[1] == Approx(-0.7)); assert(v7[2] == Approx(-1.7)); assert(v7[3] == Approx(-2.7));

        vec4 v8 = v1 * v2, v9 = v2 * v3;

        assert(v8[0] == Approx(0)); assert(v8[1] == Approx(0)); assert(v8[2] == Approx(0)); assert(v8[3] == Approx(0));
        assert(v9[0] == Approx(1.3)); assert(v9[1] == Approx(2.6)); assert(v9[2] == Approx(3.9)); assert(v9[3] == Approx(5.2));

        vec4 v10 = v1 / v2, v11 = v2 / v3;

        assert(v10[0] == Approx(0)); assert(v10[1] == Approx(0)); assert(v10[2] == Approx(0)); assert(v10[3] == Approx(0));
        assert(v11[0] == Approx(1.3)); assert(v11[1] == Approx(0.65)); assert(v11[2] == Approx(0.43333)); assert(v11[3] == Approx(0.325));
    }

    {   // additional constructors
        vec2 v0 = { 0, 1 }, v1 = { 2, 3 };
        vec3 v2 = { 3, 2, 8 };
        vec4 v3 = { v0, v1 }, v4 = { v0, 5, 6.5f }, v5 = { 4.5f, v0, 6.3f}, v6 = { 5, 7.5f, v1 },
             v7 = { v2, 4.5f }, v8 = { 7.8f, v2 }, v9(v3), v10 = v3;

        assert(v3 == Approx4(0, 1, 2, 3)); assert(v4 == Approx4(0, 1, 5, 6.5));
        assert(v5 == Approx4(4.5, 0, 1, 6.3)); assert(v6 == Approx4(5, 7.5, 2, 3));
        assert(v7 == Approx4(3, 2, 8, 4.5)); assert(v8 == Approx4(7.8, 3, 2, 8));
        assert(v9 == Approx4(0, 1, 2, 3)); assert(v10 == Approx4(0, 1, 2, 3));
    }

    {   // additional operators
        vec4 v0 = { 1, 2, 3, 4 }, v1 = { 1, 2, 3, 4 }, v2 = { 4.5f, 3, 8, 5.5f }, v3 = { 4.5f, 3, 8, 5.5f };

        vec4 v4 = v0++, v5 = ++v1;

        assert(v0 == Approx4(2, 3, 4, 5)); assert(v1 == Approx4(2, 3, 4, 5));
        assert(v4 == Approx4(1, 2, 3, 4)); assert(v5 == Approx4(2, 3, 4, 5));

        vec4 v6 = v2--, v7 = --v3;

        assert(v2 == Approx4(3.5, 2, 7, 4.5)); assert(v3 == Approx4(3.5, 2, 7, 4.5));
        assert(v6 == Approx4(4.5, 3, 8, 5.5)); assert(v7 == Approx4(3.5, 2, 7, 4.5));

        vec4 v8 = { 1, 2, 3, 4 }, v9 = { 1, 2, 3, 4 }, v10 = { 1, 2, 3, 4 }, v11 = { 1, 2, 3, 4 };

        v8 += vec4{ 1, 2, 3, 4 };
        v9 -= vec4{ 1, 2, 3, 4 };
        v10 *= vec4{ 1, 2, 3, 4 };
        v11 /= vec4{ 1, 2, 3, 4 };

        assert(v8 == Approx4(2, 4, 6, 8)); assert(v9 == Approx4(0, 0, 0, 0));
        assert(v10 == Approx4(1, 4, 9, 16)); assert(v11 == Approx4(1, 1, 1, 1));

        vec4 v12 = { 1, 2, 3, 4 };
        v12 = -v12;

        assert(v12 == Approx4(-1, -2, -3, -4));

        vec4 v13 = v12;

        assert(v12 == v13);
        assert(v11 != v13);

        vec4 v14 = { 1, 2, 3, 4 };

        v14[0] += 1;
        v14[1] -= 1;
        v14[2] *= 2;
        v14[3] /= 2;

        assert(v14 == Approx4(2, 1, 6, 2));
    }

    /*glm::vec4 v1;
    glm::mat4 m1;

    v1 = m1 * v1;*/
}

void test_vec4() {
    test_vec4(math::Scalar);
#ifndef __arm__
    test_vec4(math::SSE2);
    test_vec4(math::SSE3);
    test_vec4(math::SSE4_1);
    test_vec4(math::AVX);
#else
    test_vec4(math::NEON);
#endif
}
