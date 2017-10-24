#include "test_assert.h"

#include "../math.hpp"

void test_quat(math::e_arch arch) {
    using namespace math;

    init(arch);

    {   // basic usage
        quat q1, q2(0.5f, 0.5f, 0, 0);

        assert(q1 == Approx4(0, 0, 0, 1));
        assert(q2 == Approx4(0.5f, 0, 0, 0.5f));

        assert(q1[0] == Approx(0) && q1[1] == Approx(0) && q1[2] == Approx(0) && q1[3] == Approx(1));
        assert(q2[0] == Approx(0.5) && q2[1] == Approx(0) && q2[2] == Approx(0) && q2[3] == Approx(0.5));
        assert(q1.r == Approx(1) && q1.i == Approx(0) && q1.j == Approx(0) && q1.k == Approx(0));
        assert(q2.r == Approx(0.5) && q2.i == Approx(0.5) && q2.j == Approx(0) && q2.k == Approx(0));

        quat q3(0.8249534f, -0.2835689f, 0.4623645f, 0.1589328f),
             q4(0.2356965f, 0.0823028f, 0.2226638f, 0.9423876f);

        quat q5 = mix(q3, q4, 0.5f);
        assert(q5[0] == Approx(-0.119268775) && q5[1] == Approx(0.405942678) && q5[2] == Approx(0.652634323) && q5[3] == Approx(0.628533244));
    
        quat q6 = q3 * 2.0f;
        assert(q6[0] == Approx(-0.567127778) && q6[1] == Approx(0.924728990) && q6[2] == Approx(0.317865610) && q6[3] == Approx(1.64990675));

        quat q7 = q6 / 2.0f;
        assert(q5[0] == Approx(-0.119268775) && q5[1] == Approx(0.405942678) && q5[2] == Approx(0.652634323) && q5[3] == Approx(0.628533244));

        quat q8 = q3 * q4;
        assert(q8[0] == Approx(0.401397735) && q8[1] == Approx(0.572977364) && q8[2] == Approx(0.713691354) && q8[3] == Approx(-0.0349510014));

        mat3 m1 = to_mat3(q3);
        assert(m1[0] == Approx3(0.521918893, -5.96046448e-008, -0.852995157) &&
               m1[1] == Approx3(-0.524448693, 0.788658082, -0.320892453) &&
               m1[2] == Approx3(0.672721505, 0.614831984, 0.411615491));

        mat4 m2 = to_mat4(q3);
        assert(m2[0] == Approx4(0.521918893, -5.96046448e-008, -0.852995157, 0) &&
               m2[1] == Approx4(-0.524448693, 0.788658082, -0.320892453, 0) &&
               m2[2] == Approx4(0.672721505, 0.614831984, 0.411615491, 0) &&
               m2[3] == Approx4(0, 0, 0, 1));

        mat3 m3 = { 0.521917793f, -5.96046448e-08f, -0.852995157f,
                    -0.524448693f, 0.788658082f, -0.320892453f,
                    0.672721505f, 0.614831984f, 0.411615491f };
        quat q9 = to_quat(m3);
        assert(q9[0] == Approx(-0.2835689) && q9[1] == Approx(0.4623645) && q9[2] == Approx(0.1589328) && q9[3] == Approx(0.8249534));

        mat4 m4 = { 0.521917793f, -5.96046448e-08f, -0.852995157f, 0,
                    -0.524448693f, 0.788658082f, -0.320892453f, 0,
                    0.672721505f, 0.614831984f, 0.411615491f, 0,
                    0, 0, 0, 1 };
        quat q10 = to_quat(m4);
        assert(q10[0] == Approx(-0.2835689) && q10[1] == Approx(0.4623645) && q10[2] == Approx(0.1589328) && q10[3] == Approx(0.8249534));
    }

    {   // additional constructors
        quat q0 = { 1, 2, 3, 4 }, q1(q0), q2 = q0;

        assert(q0 == Approx4(2, 3, 4, 1)); assert(q1 == Approx4(2, 3, 4, 1)); assert(q2 == Approx4(2, 3, 4, 1));
    }

    {   // angles
        quat q0 = { 0.8249534f, -0.2835689f, 0.4623645f, 0.1589328f };

        float p = pitch(q0);
        float y = yaw(q0);
        float r = roll(q0);

        vec3 angles = euler_angles(q0);

        assert(p == Approx(-0.662173092) && y == Approx(1.02169740) && r == Approx(-1.14202898e-07));
        assert(angles[0] == Approx(-0.662173092) && angles[1] == Approx(1.02169740) && angles[2] == Approx(-1.14202898e-07));
    }

    {   // slerp
        math::quat q0 = { 0.8249534f, -0.2835689f, 0.4623645f, 0.1589328f },
                   q1 = { 0.2356965f, 0.0823028f, 0.2226638f, 0.9423876f };

        math::quat q2 = math::slerp(q0, q1, 0.54f);

        assert(q2[0] == Approx(-0.103703402) && q2[1] == Approx(0.395408362) && q2[2] == Approx(0.685032368) && q2[3] == Approx(0.603016138));
    }
}

void test_quat() {
    test_quat(math::Scalar);
#ifndef __arm__
    test_quat(math::SSE2);
    test_quat(math::SSE3);
    test_quat(math::SSE4_1);
    test_quat(math::AVX);
#else
    test_quat(math::NEON);
#endif
}
