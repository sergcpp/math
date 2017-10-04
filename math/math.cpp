#include "math.hpp"

#include <cassert>

#ifdef _WIN32

//  Windows
#include <intrin.h>
#ifdef __GNUC__
#include <cpuid.h>
void cpuid(int info[4], int InfoType) {
    __cpuid_count(InfoType, 0, info[0], info[1], info[2], info[3]);
}
#else
#define cpuid(info, x)    __cpuidex(info, x, 0)
#endif

#else

#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
//  GCC Intrinsics
#include <cpuid.h>
void cpuid(int info[4], int InfoType) {
    __cpuid_count(InfoType, 0, info[0], info[1], info[2], info[3]);
}
#endif

#endif

#if defined(__arm__)
    #ifdef __ARM_NEON__
        #include "internal/math_neon.hpp"
    #endif
#elif defined(__EMSCRIPTEN__)
    #include "internal/math_sse2.hpp"
    #include "internal/math_sse3.hpp"
#else
    #include "internal/math_sse2.hpp"
    #include "internal/math_sse3.hpp"
    #include "internal/math_sse4_1.hpp"
    #include "internal/math_avx.hpp"
#endif

#define FUNC_LIST(NS)                                   \
    NS::vec3_init1, NS::vec3_init3,                     \
    NS::vec3_add_vec3, NS::vec3_sub_vec3,               \
    NS::vec3_mul_vec3, NS::vec3_div_vec3,               \
                                                        \
    NS::vec3_length,                                    \
    NS::vec3_dot,                                       \
    NS::vec3_cross,                                     \
    NS::vec3_normalize,                                 \
    NS::vec3_normalize_fast,                            \
                                                        \
    NS::vec4_init1, NS::vec4_init4,                     \
    NS::vec4_eq_vec4,                                   \
    NS::vec4_add_vec4, NS::vec4_sub_vec4,               \
    NS::vec4_mul_vec4, NS::vec4_div_vec4,               \
                                                        \
    NS::vec4_length,                                    \
    NS::vec4_dot,                                       \
    NS::vec4_normalize,                                 \
    NS::vec4_normalize_fast,                            \
                                                        \
    NS::mat2_init4,                                     \
    NS::mat2_add_mat2, NS::mat2_sub_mat2,               \
    NS::mat2_mul_mat2, NS::mat2_div_mat2,               \
                                                        \
    NS::mat2_comp_mul,                                  \
    NS::mat2_inverse,                                   \
                                                        \
    NS::mat3_init1, NS::mat3_init3, NS::mat3_init9,     \
    NS::mat3_add_mat3, NS::mat3_sub_mat3,               \
    NS::mat3_mul_mat3, NS::mat3_div_mat3,               \
                                                        \
    NS::mat3_mul_float, NS::mat3_div_float,             \
                                                        \
    NS::mat3_comp_mul,                                  \
    NS::mat3_inverse,                                   \
                                                        \
    NS::mat4_init1, NS::mat4_init4, NS::mat4_init16,    \
    NS::mat4_add_mat4, NS::mat4_sub_mat4,               \
    NS::mat4_mul_mat4, NS::mat4_div_mat4,               \
                                                        \
    NS::mat4_mul_float, NS::mat4_div_float,             \
                                                        \
    NS::mat4_comp_mul,                                  \
    NS::mat4_inverse,                                   \
                                                        \
    NS::mat4_mul_vec4,                                  \
														\
	NS::dmat2_init4,									\
	NS::dmat2_add_dmat2, NS::dmat2_sub_dmat2,			\
	NS::dmat2_mul_dmat2, NS::dmat2_div_dmat2,			\
														\
	NS::dmat2_comp_mul,									\
	NS::dmat2_inverse,									\
														\
	NS::dmat3_init1, NS::dmat3_init3, NS::dmat3_init9,	\
	NS::dmat3_add_dmat3, NS::dmat3_sub_dmat3,			\
	NS::dmat3_mul_dmat3, NS::dmat3_div_dmat3,			\
														\
	NS::dmat3_mul_double, NS::dmat3_div_double,			\
														\
	NS::dmat3_comp_mul,									\
	NS::dmat3_inverse,									\
                                                        \
    NS::ivec2_init1, NS::ivec2_init2,                   \
    NS::ivec2_add_ivec2, NS::ivec2_sub_ivec2,           \
    NS::ivec2_mul_ivec2, NS::ivec2_div_ivec2,           \
                                                        \
    NS::ivec3_init1, NS::ivec3_init3,                   \
    NS::ivec3_add_ivec3, NS::ivec3_sub_ivec3,           \
    NS::ivec3_mul_ivec3, NS::ivec3_div_ivec3,           \
                                                        \
    NS::ivec4_init1, NS::ivec4_init4,                   \
    NS::ivec4_add_ivec4, NS::ivec4_sub_ivec4,           \
    NS::ivec4_mul_ivec4, NS::ivec4_div_ivec4,           \
                                                        \
    NS::quat_init4,                                     \
    NS::quat_add_quat, NS::quat_mul_quat,               \
    NS::quat_mul_float, NS::quat_div_float,             \
                                                        \
    NS::dvec2_init1, NS::dvec2_init2,                   \
    NS::dvec2_add_dvec2, NS::dvec2_sub_dvec2,           \
    NS::dvec2_mul_dvec2, NS::dvec2_div_dvec2,           \
                                                        \
    NS::dvec3_init1, NS::dvec3_init3,                   \
    NS::dvec3_add_dvec3, NS::dvec3_sub_dvec3,           \
    NS::dvec3_mul_dvec3, NS::dvec3_div_dvec3,           \
                                                        \
    NS::dvec4_init1, NS::dvec4_init4,                   \
    NS::dvec4_add_dvec4, NS::dvec4_sub_dvec4,           \
    NS::dvec4_mul_dvec4, NS::dvec4_div_dvec4,

namespace math {
    CPUFeatures cpu = {};

    const char *arch_name[] = { "Scalar", "SSE2", "SSE3", "SSE4_1", "AVX", "NEON" };

    static void init_cpu(CPUFeatures &cpu);

#if defined(CPU_ARCH_UNKNOWN)
    void (FASTCALL *vec3_init1)(float3 &vec, float val);
    void (FASTCALL *vec3_init3)(float3 &vec, float v0, float v1, float v2);
    float3 (FASTCALL *vec3_add_vec3)(const float3 &v1, const float3 &v2);
    float3 (FASTCALL *vec3_sub_vec3)(const float3 &v1, const float3 &v2);
    float3 (FASTCALL *vec3_mul_vec3)(const float3 &v1, const float3 &v2);
    float3 (FASTCALL *vec3_div_vec3)(const float3 &v1, const float3 &v2);

    float (FASTCALL *vec3_length)(const float3 &vec);
    float (FASTCALL *vec3_dot)(const float3 &v1, const float3 &v2);
    float3 (FASTCALL *vec3_cross)(const float3 &v1, const float3 &v2);
    float3 (FASTCALL *vec3_normalize)(const float3 &vec);
    float3 (FASTCALL *vec3_normalize_fast)(const float3 &vec);

    void (FASTCALL *vec4_init1)(float4 &vec, float val);
    void (FASTCALL *vec4_init4)(float4 &vec, float v0, float v1, float v2, float v3);
    bool (FASTCALL *vec4_eq_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_add_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_sub_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_mul_vec4)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_div_vec4)(const float4 &v1, const float4 &v2);

    float (FASTCALL *vec4_length)(const float4 &vec);
    float (FASTCALL *vec4_dot)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *vec4_normalize)(const float4 &vec);
    float4 (FASTCALL *vec4_normalize_fast)(const float4 &vec);

    void (FASTCALL *mat2_init4)(float4 &vec, float v0, float v1, float v2, float v3);

    float4 (FASTCALL *mat2_add_mat2)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *mat2_sub_mat2)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *mat2_mul_mat2)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *mat2_div_mat2)(const float4 &v1, const float4 &v2);

    float4 (FASTCALL *mat2_comp_mul)(const float4 &m1, const float4 &m2);
    float4 (FASTCALL *mat2_inverse)(const float4 &m);

    void (FASTCALL *mat3_init1)(float9 &vec, float val);
    void (FASTCALL *mat3_init3)(float9 &vec, const float3 &v0, const float3 &v1, const float3 &v2);
    void (FASTCALL *mat3_init9)(float9 &vec, float v00, float v01, float v02,
                                             float v10, float v11, float v12,
                                             float v20, float v21, float v22);

    float9 (FASTCALL *mat3_add_mat3)(const float9 &v1, const float9 &v2);
    float9 (FASTCALL *mat3_sub_mat3)(const float9 &v1, const float9 &v2);
    float9 (FASTCALL *mat3_mul_mat3)(const float9 &v1, const float9 &v2);
    float9 (FASTCALL *mat3_div_mat3)(const float9 &v1, const float9 &v2);

    float9 (FASTCALL *mat3_mul_float)(const float9 &v1, float v2);
    float9 (FASTCALL *mat3_div_float)(const float9 &v1, float v2);

    float9 (FASTCALL *mat3_comp_mul)(const float9 &m1, const float9 &m2);
    float9 (FASTCALL *mat3_inverse)(const float9 &m);

    void (FASTCALL *mat4_init1)(float16 &vec, float val);
    void (FASTCALL *mat4_init4)(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3);
    void (FASTCALL *mat4_init16)(float16 &vec, float v00, float v01, float v02, float v03,
                                               float v10, float v11, float v12, float v13,
                                               float v20, float v21, float v22, float v23,
                                               float v30, float v31, float v32, float v33);

    float16 (FASTCALL *mat4_add_mat4)(const float16 &v1, const float16 &v2);
    float16 (FASTCALL *mat4_sub_mat4)(const float16 &v1, const float16 &v2);
    float16 (FASTCALL *mat4_mul_mat4)(const float16 &v1, const float16 &v2);
    float16 (FASTCALL *mat4_div_mat4)(const float16 &v1, const float16 &v2);

    float16 (FASTCALL *mat4_mul_float)(const float16 &v1, float v2);
    float16 (FASTCALL *mat4_div_float)(const float16 &v1, float v2);

    float16 (FASTCALL *mat4_comp_mul)(const float16 &m1, const float16 &m2);
    float16 (FASTCALL *mat4_inverse)(const float16 &m);

    float4 (FASTCALL *mat4_mul_vec4)(const float16 &v1, const float4 &v2);

	void (FASTCALL *dmat2_init4)(double4 &vec, double v0, double v1, double v2, double v3);

	double4(FASTCALL *dmat2_add_dmat2)(const double4 &v1, const double4 &v2);
	double4(FASTCALL *dmat2_sub_dmat2)(const double4 &v1, const double4 &v2);
	double4(FASTCALL *dmat2_mul_dmat2)(const double4 &v1, const double4 &v2);
	double4(FASTCALL *dmat2_div_dmat2)(const double4 &v1, const double4 &v2);

	double4(FASTCALL *dmat2_comp_mul)(const double4 &m1, const double4 &m2);
	double4(FASTCALL *dmat2_inverse)(const double4 &m);

	void (FASTCALL *dmat3_init1)(double9 &vec, double val);
	void (FASTCALL *dmat3_init3)(double9 &vec, const double3 &v0, const double3 &v1, const double3 &v2);
	void (FASTCALL *dmat3_init9)(double9 &vec, double v00, double v01, double v02,
											   double v10, double v11, double v12,
											   double v20, double v21, double v22);

	double9(FASTCALL *dmat3_add_dmat3)(const double9 &v1, const double9 &v2);
	double9(FASTCALL *dmat3_sub_dmat3)(const double9 &v1, const double9 &v2);
	double9(FASTCALL *dmat3_mul_dmat3)(const double9 &v1, const double9 &v2);
	double9(FASTCALL *dmat3_div_dmat3)(const double9 &v1, const double9 &v2);

	double9(FASTCALL *dmat3_mul_double)(const double9 &v1, double v2);
	double9(FASTCALL *dmat3_div_double)(const double9 &v1, double v2);

	double9(FASTCALL *dmat3_comp_mul)(const double9 &m1, const double9 &m2);
	double9(FASTCALL *dmat3_inverse)(const double9 &m);

    void (FASTCALL *ivec2_init1)(int2 &vec, int val);
    void (FASTCALL *ivec2_init2)(int2 &vec, int v0, int v1);
    int2 (FASTCALL *ivec2_add_ivec2)(const int2 &v1, const int2 &v2);
    int2 (FASTCALL *ivec2_sub_ivec2)(const int2 &v1, const int2 &v2);
    int2 (FASTCALL *ivec2_mul_ivec2)(const int2 &v1, const int2 &v2);
    int2 (FASTCALL *ivec2_div_ivec2)(const int2 &v1, const int2 &v2);

    void (FASTCALL *ivec3_init1)(int3 &vec, int val);
    void (FASTCALL *ivec3_init3)(int3 &vec, int v0, int v1, int v2);
    int3 (FASTCALL *ivec3_add_ivec3)(const int3 &v1, const int3 &v2);
    int3 (FASTCALL *ivec3_sub_ivec3)(const int3 &v1, const int3 &v2);
    int3 (FASTCALL *ivec3_mul_ivec3)(const int3 &v1, const int3 &v2);
    int3 (FASTCALL *ivec3_div_ivec3)(const int3 &v1, const int3 &v2);

    void (FASTCALL *ivec4_init1)(int4 &vec, int val);
    void (FASTCALL *ivec4_init4)(int4 &vec, int v0, int v1, int v2, int v3);
    int4 (FASTCALL *ivec4_add_ivec4)(const int4 &v1, const int4 &v2);
    int4 (FASTCALL *ivec4_sub_ivec4)(const int4 &v1, const int4 &v2);
    int4 (FASTCALL *ivec4_mul_ivec4)(const int4 &v1, const int4 &v2);
    int4 (FASTCALL *ivec4_div_ivec4)(const int4 &v1, const int4 &v2);

    void (FASTCALL *quat_init4)(float4 &vec, float r, float i, float j, float k);
    float4 (FASTCALL *quat_add_quat)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *quat_mul_quat)(const float4 &v1, const float4 &v2);
    float4 (FASTCALL *quat_mul_float)(const float4 &v, float f);
    float4 (FASTCALL *quat_div_float)(const float4 &v, float f);

    void (FASTCALL *dvec2_init1)(double2 &vec, double val);
    void (FASTCALL *dvec2_init2)(double2 &vec, double v0, double v1);
    double2 (FASTCALL *dvec2_add_dvec2)(const double2 &v1, const double2 &v2);
    double2 (FASTCALL *dvec2_sub_dvec2)(const double2 &v1, const double2 &v2);
    double2 (FASTCALL *dvec2_mul_dvec2)(const double2 &v1, const double2 &v2);
    double2 (FASTCALL *dvec2_div_dvec2)(const double2 &v1, const double2 &v2);

    void (FASTCALL *dvec3_init1)(double3 &vec, double val);
    void (FASTCALL *dvec3_init3)(double3 &vec, double v0, double v1, double v2);
    double3 (FASTCALL *dvec3_add_dvec3)(const double3 &v1, const double3 &v2);
    double3 (FASTCALL *dvec3_sub_dvec3)(const double3 &v1, const double3 &v2);
    double3 (FASTCALL *dvec3_mul_dvec3)(const double3 &v1, const double3 &v2);
    double3 (FASTCALL *dvec3_div_dvec3)(const double3 &v1, const double3 &v2);

    void (FASTCALL *dvec4_init1)(double4 &vec, double val);
    void (FASTCALL *dvec4_init4)(double4 &vec, double v0, double v1, double v2, double v3);
    double4 (FASTCALL *dvec4_add_dvec4)(const double4 &v1, const double4 &v2);
    double4 (FASTCALL *dvec4_sub_dvec4)(const double4 &v1, const double4 &v2);
    double4 (FASTCALL *dvec4_mul_dvec4)(const double4 &v1, const double4 &v2);
    double4 (FASTCALL *dvec4_div_dvec4)(const double4 &v1, const double4 &v2);
#endif
    const struct func_table {
        void (FASTCALL *vec3_init1)(float3 &vec, float val);
        void (FASTCALL *vec3_init3)(float3 &vec, float v0, float v1, float v2);
        float3 (FASTCALL *vec3_add_vec3)(const float3 &v1, const float3 &v2);
        float3 (FASTCALL *vec3_sub_vec3)(const float3 &v1, const float3 &v2);
        float3 (FASTCALL *vec3_mul_vec3)(const float3 &v1, const float3 &v2);
        float3 (FASTCALL *vec3_div_vec3)(const float3 &v1, const float3 &v2);

        float (FASTCALL *vec3_length)(const float3 &vec);
        float (FASTCALL *vec3_dot)(const float3 &v1, const float3 &v2);
        float3 (FASTCALL *vec3_cross)(const float3 &v1, const float3 &v2);
        float3 (FASTCALL *vec3_normalize)(const float3 &vec);
        float3 (FASTCALL *vec3_normalize_fast)(const float3 &vec);

        void (FASTCALL *vec4_init1)(float4 &vec, float val);
        void (FASTCALL *vec4_init4)(float4 &vec, float v0, float v1, float v2, float v3);
        bool (FASTCALL *vec4_eq_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_add_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_sub_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_mul_vec4)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_div_vec4)(const float4 &v1, const float4 &v2);

        float (FASTCALL *vec4_length)(const float4 &vec);
        float (FASTCALL *vec4_dot)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *vec4_normalize)(const float4 &vec);
        float4 (FASTCALL *vec4_normalize_fast)(const float4 &vec);

        void (FASTCALL *mat2_init4)(float4 &vec, float v0, float v1, float v2, float v3);

        float4 (FASTCALL *mat2_add_mat2)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *mat2_sub_mat2)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *mat2_mul_mat2)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *mat2_div_mat2)(const float4 &v1, const float4 &v2);

        float4 (FASTCALL *mat2_comp_mul)(const float4 &m1, const float4 &m2);
        float4 (FASTCALL *mat2_inverse)(const float4 &m);

        void (FASTCALL *mat3_init1)(float9 &vec, float val);
        void (FASTCALL *mat3_init3)(float9 &vec, const float3 &v0, const float3 &v1, const float3 &v2);
        void (FASTCALL *mat3_init9)(float9 &vec, float v00, float v01, float v02,
                                                 float v10, float v11, float v12,
                                                 float v20, float v21, float v22);

        float9 (FASTCALL *mat3_add_mat3)(const float9 &v1, const float9 &v2);
        float9 (FASTCALL *mat3_sub_mat3)(const float9 &v1, const float9 &v2);
        float9 (FASTCALL *mat3_mul_mat3)(const float9 &v1, const float9 &v2);
        float9 (FASTCALL *mat3_div_mat3)(const float9 &v1, const float9 &v2);

        float9 (FASTCALL *mat3_mul_float)(const float9 &v1, float v2);
        float9 (FASTCALL *mat3_div_float)(const float9 &v1, float v2);

        float9 (FASTCALL *mat3_comp_mul)(const float9 &m1, const float9 &m2);
        float9 (FASTCALL *mat3_inverse)(const float9 &m);

        void (FASTCALL *mat4_init1)(float16 &vec, float val);
        void (FASTCALL *mat4_init4)(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3);
        void (FASTCALL *mat4_init16)(float16 &vec, float v00, float v01, float v02, float v03,
                                                   float v10, float v11, float v12, float v13,
                                                   float v20, float v21, float v22, float v23,
                                                   float v30, float v31, float v32, float v33);

        float16 (FASTCALL *mat4_add_mat4)(const float16 &v1, const float16 &v2);
        float16 (FASTCALL *mat4_sub_mat4)(const float16 &v1, const float16 &v2);
        float16 (FASTCALL *mat4_mul_mat4)(const float16 &v1, const float16 &v2);
        float16 (FASTCALL *mat4_div_mat4)(const float16 &v1, const float16 &v2);

        float16 (FASTCALL *mat4_mul_float)(const float16 &v1, float v2);
        float16 (FASTCALL *mat4_div_float)(const float16 &v1, float v2);

        float16 (FASTCALL *mat4_comp_mul)(const float16 &m1, const float16 &m2);
        float16 (FASTCALL *mat4_inverse)(const float16 &m);

        float4 (FASTCALL *mat4_mul_vec4)(const float16 &v1, const float4 &v2);

		void (FASTCALL *dmat2_init4)(double4 &vec, double v0, double v1, double v2, double v3);

		double4(FASTCALL *dmat2_add_dmat2)(const double4 &v1, const double4 &v2);
		double4(FASTCALL *dmat2_sub_dmat2)(const double4 &v1, const double4 &v2);
		double4(FASTCALL *dmat2_mul_dmat2)(const double4 &v1, const double4 &v2);
		double4(FASTCALL *dmat2_div_dmat2)(const double4 &v1, const double4 &v2);

		double4(FASTCALL *dmat2_comp_mul)(const double4 &m1, const double4 &m2);
		double4(FASTCALL *dmat2_inverse)(const double4 &m);

		void (FASTCALL *dmat3_init1)(double9 &vec, double val);
		void (FASTCALL *dmat3_init3)(double9 &vec, const double3 &v0, const double3 &v1, const double3 &v2);
		void (FASTCALL *dmat3_init9)(double9 &vec, double v00, double v01, double v02,
												   double v10, double v11, double v12,
												   double v20, double v21, double v22);

		double9(FASTCALL *dmat3_add_dmat3)(const double9 &v1, const double9 &v2);
		double9(FASTCALL *dmat3_sub_dmat3)(const double9 &v1, const double9 &v2);
		double9(FASTCALL *dmat3_mul_dmat3)(const double9 &v1, const double9 &v2);
		double9(FASTCALL *dmat3_div_dmat3)(const double9 &v1, const double9 &v2);

		double9(FASTCALL *dmat3_mul_double)(const double9 &v1, double v2);
		double9(FASTCALL *dmat3_div_double)(const double9 &v1, double v2);

		double9(FASTCALL *dmat3_comp_mul)(const double9 &m1, const double9 &m2);
		double9(FASTCALL *dmat3_inverse)(const double9 &m);

        void (FASTCALL *ivec2_init1)(int2 &vec, int val);
        void (FASTCALL *ivec2_init2)(int2 &vec, int v0, int v1);
        int2 (FASTCALL *ivec2_add_ivec2)(const int2 &v1, const int2 &v2);
        int2 (FASTCALL *ivec2_sub_ivec2)(const int2 &v1, const int2 &v2);
        int2 (FASTCALL *ivec2_mul_ivec2)(const int2 &v1, const int2 &v2);
        int2 (FASTCALL *ivec2_div_ivec2)(const int2 &v1, const int2 &v2);

        void (FASTCALL *ivec3_init1)(int3 &vec, int val);
        void (FASTCALL *ivec3_init3)(int3 &vec, int v0, int v1, int v2);
        int3 (FASTCALL *ivec3_add_ivec3)(const int3 &v1, const int3 &v2);
        int3 (FASTCALL *ivec3_sub_ivec3)(const int3 &v1, const int3 &v2);
        int3 (FASTCALL *ivec3_mul_ivec3)(const int3 &v1, const int3 &v2);
        int3 (FASTCALL *ivec3_div_ivec3)(const int3 &v1, const int3 &v2);

        void (FASTCALL *ivec4_init1)(int4 &vec, int val);
        void (FASTCALL *ivec4_init4)(int4 &vec, int v0, int v1, int v2, int v3);
        int4 (FASTCALL *ivec4_add_ivec4)(const int4 &v1, const int4 &v2);
        int4 (FASTCALL *ivec4_sub_ivec4)(const int4 &v1, const int4 &v2);
        int4 (FASTCALL *ivec4_mul_ivec4)(const int4 &v1, const int4 &v2);
        int4 (FASTCALL *ivec4_div_ivec4)(const int4 &v1, const int4 &v2);

        void (FASTCALL *quat_init4)(float4 &vec, float r, float i, float j, float k);
        float4 (FASTCALL *quat_add_quat)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *quat_mul_quat)(const float4 &v1, const float4 &v2);
        float4 (FASTCALL *quat_mul_float)(const float4 &v, float f);
        float4 (FASTCALL *quat_div_float)(const float4 &v, float f);

        void (FASTCALL *dvec2_init1)(double2 &vec, double val);
        void (FASTCALL *dvec2_init2)(double2 &vec, double v0, double v1);
        double2 (FASTCALL *dvec2_add_dvec2)(const double2 &v1, const double2 &v2);
        double2 (FASTCALL *dvec2_sub_dvec2)(const double2 &v1, const double2 &v2);
        double2 (FASTCALL *dvec2_mul_dvec2)(const double2 &v1, const double2 &v2);
        double2 (FASTCALL *dvec2_div_dvec2)(const double2 &v1, const double2 &v2);

        void (FASTCALL *dvec3_init1)(double3 &vec, double val);
        void (FASTCALL *dvec3_init3)(double3 &vec, double v0, double v1, double v2);
        double3 (FASTCALL *dvec3_add_dvec3)(const double3 &v1, const double3 &v2);
        double3 (FASTCALL *dvec3_sub_dvec3)(const double3 &v1, const double3 &v2);
        double3 (FASTCALL *dvec3_mul_dvec3)(const double3 &v1, const double3 &v2);
        double3 (FASTCALL *dvec3_div_dvec3)(const double3 &v1, const double3 &v2);

        void (FASTCALL *dvec4_init1)(double4 &vec, double val);
        void (FASTCALL *dvec4_init4)(double4 &vec, double v0, double v1, double v2, double v3);
        double4 (FASTCALL *dvec4_add_dvec4)(const double4 &v1, const double4 &v2);
        double4 (FASTCALL *dvec4_sub_dvec4)(const double4 &v1, const double4 &v2);
        double4 (FASTCALL *dvec4_mul_dvec4)(const double4 &v1, const double4 &v2);
        double4 (FASTCALL *dvec4_div_dvec4)(const double4 &v1, const double4 &v2);
    } funcs[] = {   {   // Reference
                        FUNC_LIST(ref)
                    },
                    {   // SSE2
#if !defined(__arm__)
                        FUNC_LIST(sse2)
#endif
                    },
                    {   // SSE3
#if !defined(__arm__)
                        FUNC_LIST(sse3)
#endif
                    },
                    {   // SSE4.1
#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
                        FUNC_LIST(sse4_1)
#endif
                    },
                    {   // AVX
#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
                        FUNC_LIST(avx)
#endif
                    },
                    {   // NEON
#if defined(__ARM_NEON__)
                        FUNC_LIST(neon)
#endif
                    }
    };
}

#undef FUNC_LIST

void math::init(math::e_arch arch) {
    if (!cpu.initialized) {
        init_cpu(cpu);
    }

#if !defined(__EMSCRIPTEN__)

#if defined(CPU_ARCH_SCALAR)
#elif defined(CPU_ARCH_SSE2)
    assert(cpu.HW_SSE2);
#elif defined(CPU_ARCH_SSE3)
    assert(cpu.HW_SSE3);
#elif defined(CPU_ARCH_SSE4_1)
    assert(cpu.HW_SSE41);
#elif defined(CPU_ARCH_AVX)
    assert(cpu.HW_AVX);
#else

    if (arch == AVX && !cpu.HW_AVX) arch = SSE4_1;
    if (arch == SSE4_1 && !cpu.HW_SSE41) arch = SSE3;
    if (arch == SSE3 && !cpu.HW_SSE3) arch = SSE2;
    if (arch == SSE2 && !cpu.HW_SSE2) arch = Scalar;
#endif

#if defined(CPU_ARCH_UNKNOWN)
    const func_table &t = funcs[arch];

    vec3_init1 = t.vec3_init1;
    vec3_init3 = t.vec3_init3;
    vec3_add_vec3 = t.vec3_add_vec3;
    vec3_sub_vec3 = t.vec3_sub_vec3;
    vec3_mul_vec3 = t.vec3_mul_vec3;
    vec3_div_vec3 = t.vec3_div_vec3;

    vec3_length = t.vec3_length;
    vec3_dot = t.vec3_dot;
    vec3_cross = t.vec3_cross;
    vec3_normalize = t.vec3_normalize;
    vec3_normalize_fast = t.vec3_normalize_fast;

    vec4_init1 = t.vec4_init1;
    vec4_init4 = t.vec4_init4;
    vec4_eq_vec4 = t.vec4_eq_vec4;
    vec4_add_vec4 = t.vec4_add_vec4;
    vec4_sub_vec4 = t.vec4_sub_vec4;
    vec4_mul_vec4 = t.vec4_mul_vec4;
    vec4_div_vec4 = t.vec4_div_vec4;

    vec4_length = t.vec4_length;
    vec4_dot = t.vec4_dot;
    vec4_normalize = t.vec4_normalize;
    vec4_normalize_fast = t.vec4_normalize_fast;

    mat2_init4 = t.mat2_init4;

    mat2_add_mat2 = t.mat2_add_mat2;
    mat2_sub_mat2 = t.mat2_sub_mat2;
    mat2_mul_mat2 = t.mat2_mul_mat2;
    mat2_div_mat2 = t.mat2_div_mat2;

    mat2_comp_mul = t.mat2_comp_mul;
    mat2_inverse = t.mat2_inverse;

    mat3_init1 = t.mat3_init1;
    mat3_init3 = t.mat3_init3;
    mat3_init9 = t.mat3_init9;

    mat3_add_mat3 = t.mat3_add_mat3;
    mat3_sub_mat3 = t.mat3_sub_mat3;
    mat3_mul_mat3 = t.mat3_mul_mat3;
    mat3_div_mat3 = t.mat3_div_mat3;

    mat3_mul_float = t.mat3_mul_float;
    mat3_div_float = t.mat3_div_float;

    mat3_comp_mul = t.mat3_comp_mul;
    mat3_inverse = t.mat3_inverse;

    mat4_init1 = t.mat4_init1;
    mat4_init4 = t.mat4_init4;
    mat4_init16 = t.mat4_init16;

    mat4_add_mat4 = t.mat4_add_mat4;
    mat4_sub_mat4 = t.mat4_sub_mat4;
    mat4_mul_mat4 = t.mat4_mul_mat4;
    mat4_div_mat4 = t.mat4_div_mat4;

    mat4_mul_float = t.mat4_mul_float;
    mat4_div_float = t.mat4_div_float;

    mat4_comp_mul = t.mat4_comp_mul;
    mat4_inverse = t.mat4_inverse;

    mat4_mul_vec4 = t.mat4_mul_vec4;

	dmat2_init4 = t.dmat2_init4;

	dmat2_add_dmat2 = t.dmat2_add_dmat2;
	dmat2_sub_dmat2 = t.dmat2_sub_dmat2;
	dmat2_mul_dmat2 = t.dmat2_mul_dmat2;
	dmat2_div_dmat2 = t.dmat2_div_dmat2;

	dmat2_comp_mul = t.dmat2_comp_mul;
	dmat2_inverse = t.dmat2_inverse;

	dmat3_init1 = t.dmat3_init1;
	dmat3_init3 = t.dmat3_init3;
	dmat3_init9 = t.dmat3_init9;

	dmat3_add_dmat3 = t.dmat3_add_dmat3;
	dmat3_sub_dmat3 = t.dmat3_sub_dmat3;
	dmat3_mul_dmat3 = t.dmat3_mul_dmat3;
	dmat3_div_dmat3 = t.dmat3_div_dmat3;

	dmat3_mul_double = t.dmat3_mul_double;
	dmat3_div_double = t.dmat3_div_double;

	dmat3_comp_mul = t.dmat3_comp_mul;
	dmat3_inverse = t.dmat3_inverse;

    ivec2_init1 = t.ivec2_init1;
    ivec2_init2 = t.ivec2_init2;
    ivec2_add_ivec2 = t.ivec2_add_ivec2;
    ivec2_sub_ivec2 = t.ivec2_sub_ivec2;
    ivec2_mul_ivec2 = t.ivec2_mul_ivec2;
    ivec2_div_ivec2 = t.ivec2_div_ivec2;

    ivec3_init1 = t.ivec3_init1;
    ivec3_init3 = t.ivec3_init3;
    ivec3_add_ivec3 = t.ivec3_add_ivec3;
    ivec3_sub_ivec3 = t.ivec3_sub_ivec3;
    ivec3_mul_ivec3 = t.ivec3_mul_ivec3;
    ivec3_div_ivec3 = t.ivec3_div_ivec3;

    ivec4_init1 = t.ivec4_init1;
    ivec4_init4 = t.ivec4_init4;
    ivec4_add_ivec4 = t.ivec4_add_ivec4;
    ivec4_sub_ivec4 = t.ivec4_sub_ivec4;
    ivec4_mul_ivec4 = t.ivec4_mul_ivec4;
    ivec4_div_ivec4 = t.ivec4_div_ivec4;

    quat_init4 = t.quat_init4;
    quat_add_quat = t.quat_add_quat;
    quat_mul_quat = t.quat_mul_quat;
    quat_mul_float = t.quat_mul_float;
    quat_div_float = t.quat_div_float;

    dvec2_init1 = t.dvec2_init1;
    dvec2_init2 = t.dvec2_init2;
    dvec2_add_dvec2 = t.dvec2_add_dvec2;
    dvec2_sub_dvec2 = t.dvec2_sub_dvec2;
    dvec2_mul_dvec2 = t.dvec2_mul_dvec2;
    dvec2_div_dvec2 = t.dvec2_div_dvec2;

    dvec3_init1 = t.dvec3_init1;
    dvec3_init3 = t.dvec3_init3;
    dvec3_add_dvec3 = t.dvec3_add_dvec3;
    dvec3_sub_dvec3 = t.dvec3_sub_dvec3;
    dvec3_mul_dvec3 = t.dvec3_mul_dvec3;
    dvec3_div_dvec3 = t.dvec3_div_dvec3;

    dvec4_init1 = t.dvec4_init1;
    dvec4_init4 = t.dvec4_init4;
    dvec4_add_dvec4 = t.dvec4_add_dvec4;
    dvec4_sub_dvec4 = t.dvec4_sub_dvec4;
    dvec4_mul_dvec4 = t.dvec4_mul_dvec4;
    dvec4_div_dvec4 = t.dvec4_div_dvec4;
#endif
#endif
}

bool math::supported(e_arch arch) {
    if (!cpu.initialized) {
        init_cpu(cpu);
    }

#if defined(__arm__)
    return arch == Scalar || arch == NEON;
#elif defined(__EMSCRIPTEN__)
    return arch == Scalar || arch == SSE2 || arch == SSE3 || arch == SSE4_1;
#else
    return arch == Scalar ||
           (arch == SSE2 && cpu.HW_SSE2) ||
           (arch == SSE3 && cpu.HW_SSE3) ||
           (arch == SSE4_1 && cpu.HW_SSE41) ||
           (arch == AVX && cpu.HW_AVX);
#endif
}

void math::init_cpu(CPUFeatures &cpu) {
    cpu.initialized = true;

#if !defined(__arm__) && !defined(__EMSCRIPTEN__)
    int info[4];
    cpuid(info, 0);
    int nIds = info[0];

    cpuid(info, 0x80000000);
    unsigned nExIds = info[0];

    //  Detect Features
    if (nIds >= 0x00000001) {
        cpuid(info, 0x00000001);
        cpu.HW_MMX = (info[3] & ((int)1 << 23)) != 0;
        cpu.HW_SSE = (info[3] & ((int)1 << 25)) != 0;
        cpu.HW_SSE2 = (info[3] & ((int)1 << 26)) != 0;
        cpu.HW_SSE3 = (info[2] & ((int)1 << 0)) != 0;

        cpu.HW_SSSE3 = (info[2] & ((int)1 << 9)) != 0;
        cpu.HW_SSE41 = (info[2] & ((int)1 << 19)) != 0;
        cpu.HW_SSE42 = (info[2] & ((int)1 << 20)) != 0;
        cpu.HW_AES = (info[2] & ((int)1 << 25)) != 0;

        cpu.HW_AVX = (info[2] & ((int)1 << 28)) != 0;
        cpu.HW_FMA3 = (info[2] & ((int)1 << 12)) != 0;

        cpu.HW_RDRAND = (info[2] & ((int)1 << 30)) != 0;
    }
    if (nIds >= 0x00000007) {
        cpuid(info, 0x00000007);
        cpu.HW_AVX2 = (info[1] & ((int)1 << 5)) != 0;

        cpu.HW_BMI1 = (info[1] & ((int)1 << 3)) != 0;
        cpu.HW_BMI2 = (info[1] & ((int)1 << 8)) != 0;
        cpu.HW_ADX = (info[1] & ((int)1 << 19)) != 0;
        cpu.HW_SHA = (info[1] & ((int)1 << 29)) != 0;
        cpu.HW_PREFETCHWT1 = (info[2] & ((int)1 << 0)) != 0;

        cpu.HW_AVX512F = (info[1] & ((int)1 << 16)) != 0;
        cpu.HW_AVX512CD = (info[1] & ((int)1 << 28)) != 0;
        cpu.HW_AVX512PF = (info[1] & ((int)1 << 26)) != 0;
        cpu.HW_AVX512ER = (info[1] & ((int)1 << 27)) != 0;
        cpu.HW_AVX512VL = (info[1] & ((int)1 << 31)) != 0;
        cpu.HW_AVX512BW = (info[1] & ((int)1 << 30)) != 0;
        cpu.HW_AVX512DQ = (info[1] & ((int)1 << 17)) != 0;
        cpu.HW_AVX512IFMA = (info[1] & ((int)1 << 21)) != 0;
        cpu.HW_AVX512VBMI = (info[2] & ((int)1 << 1)) != 0;
    }
    if (nExIds >= 0x80000001) {
        cpuid(info, 0x80000001);
        cpu.HW_x64 = (info[3] & ((int)1 << 29)) != 0;
        cpu.HW_ABM = (info[2] & ((int)1 << 5)) != 0;
        cpu.HW_SSE4a = (info[2] & ((int)1 << 6)) != 0;
        cpu.HW_FMA4 = (info[2] & ((int)1 << 16)) != 0;
        cpu.HW_XOP = (info[2] & ((int)1 << 11)) != 0;
    }
#endif
}

#if defined(MATH_NO_INLINE)
#define MATH_IMPL

#include "internal/math_ref.hpp"
#ifndef __arm__
    #include "internal/math_sse2.hpp"
    #include "internal/math_sse3.hpp"
    #include "internal/math_sse4_1.hpp"
    #include "internal/math_avx.hpp"
#else
    #include "internal/math_neon.hpp"
#endif

#undef MATH_IMPL
#endif
