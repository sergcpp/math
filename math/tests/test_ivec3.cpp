#include "test_assert.h"

#include "../math.hpp"

void test_ivec3(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        ivec3 v1, v2(2), v3(1, 2, 3);

        assert(v2[0] == 2); assert(v2[1] == 2); assert(v2[2] == 2);

        v2[0] = v2[1] = v2[2] = 1;

        assert(v1[0] == 0); assert(v1[1] == 0); assert(v1[2] == 0);
        assert(v2[0] == 1); assert(v2[1] == 1); assert(v2[2] == 1);
        assert(v3[0] == 1); assert(v3[1] == 2); assert(v3[2] == 3);
        assert(v3.x() == 1); assert(v3.y() == 2); assert(v3.z() == 3);
        assert(v3.r() == 1); assert(v3.g() == 2); assert(v3.b() == 3);
        assert(v3.s() == 1); assert(v3.t() == 2); assert(v3.p() == 3);

        ivec3 v4 = v1 + v2, v5 = v2 + v3;

        assert(v4[0] == 1); assert(v4[1] == 1); assert(v4[2] == 1);
        assert(v5[0] == 2); assert(v5[1] == 3); assert(v5[2] == 4);

        ivec3 v6 = v1 - v2, v7 = v2 - v3;

        assert(v6[0] == -1); assert(v6[1] == -1); assert(v6[2] == -1);
        assert(v7[0] == 0); assert(v7[1] == -1); assert(v7[2] == -2);

        ivec3 v8 = v1 * v2, v9 = v2 * v3;

        assert(v8[0] == 0); assert(v8[1] == 0); assert(v8[2] == 0);
        assert(v9[0] == 1); assert(v9[1] == 2); assert(v9[2] == 3);

        ivec3 v10 = v1 / v2, v11 = v2 / v3;

        assert(v10[0] == 0); assert(v10[1] == 0); assert(v10[2] == 0);
        assert(v11[0] == 1); assert(v11[1] == 0); assert(v11[2] == 0);
    }

    {   // additional constructors
        ivec2 v0 = { 0, 1 };
        ivec3 v1 = { v0, 3 }, v2 = { 5, v0 }, v3(v2), v4 = v2;

        assert(v1 == ivec3(0, 1, 3)); assert(v2 == ivec3(5, 0, 1));
        assert(v3 == ivec3(5, 0, 1)); assert(v4 == ivec3(5, 0, 1));
    }

    {   // additional operators
        ivec3 v0 = { 1, 2, 3 }, v1 = { 1, 2, 3 }, v2 = { 4, 3, 8 }, v3 = { 4, 3, 8 };

        ivec3 v4 = v0++, v5 = ++v1;

        assert(v0 == ivec3(2, 3, 4)); assert(v1 == ivec3(2, 3, 4));
        assert(v4 == ivec3(1, 2, 3)); assert(v5 == ivec3(2, 3, 4));

        ivec3 v6 = v2--, v7 = --v3;

        assert(v2 == ivec3(3, 2, 7)); assert(v3 == ivec3(3, 2, 7));
        assert(v6 == ivec3(4, 3, 8)); assert(v7 == ivec3(3, 2, 7));

        ivec3 v8 = { 1, 2, 3 }, v9 = { 1, 2, 3 }, v10 = { 1, 2, 3 }, v11 = { 1, 2, 3 };

        v8 += ivec3{ 1, 2, 3 };
        v9 -= ivec3{ 1, 2, 3 };
        v10 *= ivec3{ 1, 2, 3 };
        v11 /= ivec3{ 1, 2, 3 };

        assert(v8 == ivec3(2, 4, 6)); assert(v9 == ivec3(0, 0, 0));
        assert(v10 == ivec3(1, 4, 9)); assert(v11 == ivec3(1, 1, 1));

        ivec3 v12 = { 1, 2, 3 };
        v12 = -v12;

        assert(v12 == ivec3(-1, -2, -3));

        ivec3 v13 = v12;

        assert(v12 == v13);
        assert(v11 != v13);

        ivec3 v14 = { 1, 2, 3 };

        v14[0] += 1;
        v14[1] -= 1;
        v14[2] *= 2;

        assert(v14 == ivec3(2, 1, 6));

        v14[1] /= 2;

        assert(v14[1] == 0);
    }

    {   // arithmetics with deref
        ivec3 vv{ 2, 2, 2 };

        int f1 = 2;
        ivec2 v1 = { 1, 2 };
        ivec3 v2 = { 1, 2, 3 };
        ivec4 v3 = { 1, 2, 3, 4 };
        //imat2 m1;
        //imat3 m2;
        //imat4 m3;

        f1 = f1 * vv[0];
        v1 = v1 * vv[0];
        v2 = v2 * vv[0];
        v3 = v3 * vv[0];
        //m1 = m1 * vv[0];
        //m2 = m2 * vv[0];
        //m3 = m3 * vv[0];

        assert(f1 == 4);
        assert(v1 == ivec2(2, 4));
        assert(v2 == ivec3(2, 4, 6));
        assert(v3 == ivec4(2, 4, 6, 8));

        //assert(m1[0] == Approx2(2, 0));
        //assert(m1[1] == Approx2(0, 2));
        //assert(m2[0] == Approx3(2, 0, 0));
        //assert(m2[1] == Approx3(0, 2, 0));
        //assert(m2[2] == Approx3(0, 0, 2));
        //assert(m3[0] == Approx4(2, 0, 0, 0));
        //assert(m3[1] == Approx4(0, 2, 0, 0));
        //assert(m3[2] == Approx4(0, 0, 2, 0));
        //assert(m3[3] == Approx4(0, 0, 0, 2));
    }
}

void test_ivec3() {
    test_ivec3(math::Scalar);
#ifndef __arm__
    test_ivec3(math::SSE2);
    test_ivec3(math::SSE3);
    test_ivec3(math::SSE4_1);
    test_ivec3(math::AVX);
#else
    test_ivec3(math::NEON);
#endif
}
