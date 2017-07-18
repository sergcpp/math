#include "test_assert.h"

#include "../math.hpp"

void test_ivec4(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        ivec4 v1, v2(2), v3(1, 2, 3, 4);

        assert(v2[0] == 2); assert(v2[1] == 2); assert(v2[2] == 2); assert(v2[3] == 2);

        v2[0] = v2[1] = v2[2] = v2[3] = 1;

        assert(v1[0] == 0); assert(v1[1] == 0); assert(v1[2] == 0); assert(v1[3] == 0);
        assert(v2[0] == 1); assert(v2[1] == 1); assert(v2[2] == 1); assert(v2[3] == 1);
        assert(v3[0] == 1); assert(v3[1] == 2); assert(v3[2] == 3); assert(v3[3] == 4);
        assert(v3.x() == 1); assert(v3.y() == 2); assert(v3.z() == 3); assert(v3.w() == 4);
        assert(v3.r() == 1); assert(v3.g() == 2); assert(v3.b() == 3); assert(v3.a() == 4);
        assert(v3.s() == 1); assert(v3.t() == 2); assert(v3.p() == 3); assert(v3.q() == 4);

        ivec4 v4 = v1 + v2, v5 = v2 + v3;

        assert(v4[0] == 1); assert(v4[1] == 1); assert(v4[2] == 1); assert(v4[3] == 1);
        assert(v5[0] == 2); assert(v5[1] == 3); assert(v5[2] == 4); assert(v5[3] == 5);

        ivec4 v6 = v1 - v2, v7 = v2 - v3;

        assert(v6[0] == -1); assert(v6[1] == -1); assert(v6[2] == -1); assert(v6[3] == -1);
        assert(v7[0] == 0); assert(v7[1] == -1); assert(v7[2] == -2); assert(v7[3] == -3);

        ivec4 v8 = v1 * v2, v9 = v2 * v3;

        assert(v8[0] == 0); assert(v8[1] == 0); assert(v8[2] == 0); assert(v8[3] == 0);
        assert(v9[0] == 1); assert(v9[1] == 2); assert(v9[2] == 3); assert(v9[3] == 4);

        ivec4 v10 = v1 / v2, v11 = v2 / v3;

        assert(v10[0] == 0); assert(v10[1] == 0); assert(v10[2] == 0); assert(v10[3] == 0);
        assert(v11[0] == 1); assert(v11[1] == 0); assert(v11[2] == 0); assert(v11[3] == 0);
    }

    {   // additional constructors
        ivec2 v0 = { 0, 1 }, v1 = { 2, 3 };
        //ivec3 v2 = { 3, 2, 8 };
        ivec4 v3 = { v0, v1 }, v4 = { v0, 5, 6 }, v5 = { 4, v0, 6 }, v6 = { 5, 7, v1 };
        //      v7 = { v2, 4.5f }, v8 = { 7.8f, v2 }, v9(v3), v10 = v3;

        assert(v3 == ivec4(0, 1, 2, 3)); assert(v4 == ivec4(0, 1, 5, 6));
        assert(v5 == ivec4(4, 0, 1, 6)); assert(v6 == ivec4(5, 7, 2, 3));
        //assert(v7 == ivec4(3, 2, 8, 4.5)); assert(v8 == ivec4(7.8, 3, 2, 8));
        //assert(v9 == ivec4(0, 1, 2, 3)); assert(v10 == ivec4(0, 1, 2, 3));
    }

    {   // additional operators
        ivec4 v0 = { 1, 2, 3, 4 }, v1 = { 1, 2, 3, 4 }, v2 = { 4, 3, 8, 5 }, v3 = { 4, 3, 8, 5 };

        ivec4 v4 = v0++, v5 = ++v1;

        assert(v0 == ivec4(2, 3, 4, 5)); assert(v1 == ivec4(2, 3, 4, 5));
        assert(v4 == ivec4(1, 2, 3, 4)); assert(v5 == ivec4(2, 3, 4, 5));

        ivec4 v6 = v2--, v7 = --v3;

        assert(v2 == ivec4(3, 2, 7, 4)); assert(v3 == ivec4(3, 2, 7, 4));
        assert(v6 == ivec4(4, 3, 8, 5)); assert(v7 == ivec4(3, 2, 7, 4));

        ivec4 v8 = { 1, 2, 3, 4 }, v9 = { 1, 2, 3, 4 }, v10 = { 1, 2, 3, 4 }, v11 = { 1, 2, 3, 4 };

        v8 += ivec4{ 1, 2, 3, 4 };
        v9 -= ivec4{ 1, 2, 3, 4 };
        v10 *= ivec4{ 1, 2, 3, 4 };
        v11 /= ivec4{ 1, 2, 3, 4 };

        assert(v8 == ivec4(2, 4, 6, 8)); assert(v9 == ivec4(0, 0, 0, 0));
        assert(v10 == ivec4(1, 4, 9, 16)); assert(v11 == ivec4(1, 1, 1, 1));

        ivec4 v12 = { 1, 2, 3, 4 };
        v12 = -v12;

        assert(v12 == ivec4(-1, -2, -3, -4));

        ivec4 v13 = v12;

        assert(v12 == v13);
        assert(v11 != v13);

        ivec4 v14 = { 1, 2, 3, 4 };

        v14[0] += 1;
        v14[1] -= 1;
        v14[2] *= 2;
        v14[3] /= 2;

        assert(v14 == ivec4(2, 1, 6, 2));
    }

    {   // arithmetics with deref
        ivec4 vv{ 2, 2, 2, 2 };

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

        //assert(m1[0] == ivec2(2, 0));
        //assert(m1[1] == ivec2(0, 2));
        //assert(m2[0] == ivec3(2, 0, 0));
        //assert(m2[1] == ivec3(0, 2, 0));
        //assert(m2[2] == ivec3(0, 0, 2));
        //assert(m3[0] == ivec4(2, 0, 0, 0));
        //assert(m3[1] == ivec4(0, 2, 0, 0));
        //assert(m3[2] == ivec4(0, 0, 2, 0));
        //assert(m3[3] == ivec4(0, 0, 0, 2));
    }
}

void test_ivec4() {
    test_ivec4(math::Scalar);
#ifndef __arm__
    test_ivec4(math::SSE2);
    test_ivec4(math::SSE3);
    test_ivec4(math::SSE4_1);
    test_ivec4(math::AVX);
#else
    test_ivec4(math::NEON);
#endif
}
