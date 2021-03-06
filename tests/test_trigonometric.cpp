#include "test_assert.h"

#include "../math.hpp"

#pragma warning(disable : 4244)

void test_trigonometric(math::e_arch arch) {
    using namespace math;

    init(arch);

    {
        // radian/degree conversion
        float deg1 = 4.12f;
        vec2 deg2 = { deg1, 6.5f };
        vec3 deg3 = { deg2, 1.2f };
        vec4 deg4 = { deg3, 5.4f };

        float rad1 = radians(deg1);
        vec2 rad2 = radians(deg2);
        vec3 rad3 = radians(deg3);
        vec4 rad4 = radians(deg4);

        require(rad1 == Approx(0.0719075));
        require(rad2 == Approx2(0.0719075, 0.1134464));
        require(rad3 == Approx3(0.0719075, 0.1134464, 0.0209439));
        require(rad4 == Approx4(0.0719075, 0.1134464, 0.0209439, 0.0942477));

        float _deg1 = degrees(rad1);
        vec2 _deg2 = degrees(rad2);
        vec3 _deg3 = degrees(rad3);
        vec4 _deg4 = degrees(rad4);

        require(_deg1 == Approx(deg1));
        require(_deg2 == Approx(deg2));
        require(_deg3 == Approx(deg3));
        require(_deg4 == Approx(deg4));

        /*int deg_int = 4;
        float rad = radians(deg_int);

        require(rad == Approx(0.0698132));

        int rad_int = 1;
        float deg = degrees(rad_int);

        require(deg == Approx(57.2958));*/
    }

    {
        float angle1 = 0.75f;
        vec2 angle2 = { angle1, 1.4f };
        vec3 angle3 = { angle2, -0.5f };
        vec4 angle4 = { angle3, 0.8f };

        float sin1 = math::sin(angle1);
        vec2 sin2 = math::sin(angle2);
        vec3 sin3 = math::sin(angle3);
        vec4 sin4 = math::sin(angle4);

        require(sin1 == Approx(0.68163876));
        require(sin2 == Approx2(0.68163876, 0.98544972));
        require(sin3 == Approx3(0.68163876, 0.98544972, -0.4794255));
        require(sin4 == Approx4(0.68163876, 0.98544972, -0.4794255, 0.71735609));

        float _angle1 = math::asin(sin1);
        vec2 _angle2 = math::asin(sin2);
        vec3 _angle3 = math::asin(sin3);
        vec4 _angle4 = math::asin(sin4);

        require(_angle1 == Approx(angle1));
        require(_angle2 == Approx(angle2));
        require(_angle3 == Approx(angle3));
        require(_angle4 == Approx(angle4));

        float cos1 = math::cos(angle1);
        vec2 cos2 = math::cos(angle2);
        vec3 cos3 = math::cos(angle3);
        vec4 cos4 = math::cos(angle4);

        require(cos1 == Approx(0.73168886));
        require(cos2 == Approx2(0.73168886, 0.16996714));
        require(cos3 == Approx3(0.73168886, 0.16996714, 0.87758256));
        require(cos4 == Approx4(0.73168886, 0.16996714, 0.87758256, 0.69670670));

        _angle1 = math::acos(cos1);
        _angle2 = math::acos(cos2);
        _angle3 = math::acos(cos3);
        _angle4 = math::acos(cos4);

        require(_angle1 == Approx(angle1));
        require(_angle2 == Approx(angle2));
        require(_angle3[0] == Approx(angle3[0]));
        require(_angle3[1] == Approx(angle3[1]));
        require(_angle3[2] == Approx(-angle3[2]));
        require(_angle4[0] == Approx(angle4[0]));
        require(_angle4[1] == Approx(angle4[1]));
        require(_angle4[2] == Approx(-angle4[2]));
        require(_angle4[3] == Approx(angle4[3]));

        float tan1 = math::tan(angle1);
        vec2 tan2 = math::tan(angle2);
        vec3 tan3 = math::tan(angle3);
        vec4 tan4 = math::tan(angle4);

        require(tan1 == Approx(0.93159645));
        require(tan2 == Approx2(0.93159645, 5.79788371));
        require(tan3 == Approx3(0.93159645, 5.79788371, -0.5463024));
        require(tan4 == Approx4(0.93159645, 5.79788371, -0.5463024, 1.02963855));

        _angle1 = math::atan(tan1);
        _angle2 = math::atan(tan2);
        _angle3 = math::atan(tan3);
        _angle4 = math::atan(tan4);

        require(_angle1 == Approx(angle1));
        require(_angle2 == Approx(angle2));
        require(_angle3 == Approx(angle3));
        require(_angle4 == Approx(angle4));
    }
}

void test_trigonometric() {
    test_trigonometric(math::Scalar);
#if !defined(__arm__) && !defined(__aarch64__)
    test_trigonometric(math::SSE2);
    test_trigonometric(math::SSE3);
    test_trigonometric(math::SSE4_1);
    test_trigonometric(math::AVX);
#else
    test_trigonometric(math::NEON);
#endif
}
