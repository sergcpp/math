
#include <chrono>
#include <iostream>
#include <vector>

#include "../math.hpp"

math::aligned_vector<math::vec2> create_vec2s(size_t N) {
    math::aligned_vector<math::vec2> vecs(N, math::noinit);
    for (size_t i = 0; i < N; i++) {
        vecs[i] = math::vec2(float(i), float(i + 1));
    }
    return vecs;
}

math::aligned_vector<math::vec3> create_vec3s(size_t N) {
    math::aligned_vector<math::vec3> vecs(N, math::noinit);
    for (size_t i = 0; i < N; i++) {
        vecs[i] = math::vec3(float(i), float(i + 1), float(i + 2));
    }
    return vecs;
}

math::aligned_vector<math::vec4> create_vec4s(size_t N) {
    math::aligned_vector<math::vec4> vecs(N, math::noinit);
    for (size_t i = 0; i < N; i++) {
        vecs[i] = math::vec4(float(i), float(i + 1), float(i + 2), float(i + 3));
    }
    return vecs;
}

math::aligned_vector<math::mat2> create_mat2s(size_t N) {
    math::aligned_vector<math::mat2> mats(N, math::noinit);
    for (size_t i = 0; i < N; i++) {
        mats[i] = math::mat2(float(i), float(i + 1), float(i + 2), float(i + 3));
    }
    return mats;
}

math::aligned_vector<math::mat3> create_mat3s(size_t N) {
    math::aligned_vector<math::mat3> mats(N, math::noinit);
    for (size_t i = 0; i < N; i++) {
        mats[i] = math::mat3(float(i), float(i + 1), float(i + 2),
                             float(i), float(i + 1), float(i + 2),
                             float(i), float(i + 1), float(i + 2));
    }
    return mats;
}

math::aligned_vector<math::mat4> create_mat4s(size_t N) {
    math::aligned_vector<math::mat4> mats(N, math::noinit);
    for (size_t i = 0; i < N; i++) {
        mats[i] = math::mat4(float(i), float(i + 1), float(i + 2), float(i + 3),
                             float(i), float(i + 1), float(i + 2), float(i + 3),
                             float(i), float(i + 1), float(i + 2), float(i + 3),
                             float(i), float(i + 1), float(i + 2), float(i + 3));
    }
    return mats;
}

math::aligned_vector<math::dvec4> create_dvec4s(size_t N) {
    math::aligned_vector<math::dvec4> vecs(N, math::noinit);
    for (size_t i = 0; i < N; i++) {
        vecs[i] = math::dvec4(double(i), double(i + 1), double(i + 2), double(i + 3));
    }
    return vecs;
}

struct scoped_timer {
    const char *name;
    math::e_arch arch;
    std::chrono::system_clock::time_point t1;

    scoped_timer(const char *_name, math::e_arch _arch) : name(_name), arch(_arch), t1(std::chrono::system_clock::now()) {}

    ~scoped_timer() {
        auto t2 = std::chrono::system_clock::now();
        std::cout << " " << name << ":\t" << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms";
        if (!math::supported(arch)) std::cout << " (not supported)";
        std::cout << std::endl;
    }
};

void test_vec2_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] += vecs[i + 1];
        }
    }
}

void test_vec2_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] *= vecs[i + 1];
        }
    }
}

void test_vec2_dot(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    scoped_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            res += dot(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec2_len(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    scoped_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            res += length(vecs[i]);
        }
    }
}

void test_vec3_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] += vecs[i + 1];
        }
    }
}

void test_vec3_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] *= vecs[i + 1];
        }
    }
}

void test_vec3_dot(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    scoped_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            res += dot(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec3_cross(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] = cross(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec3_len(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    scoped_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            res += length(vecs[i]);
        }
    }
}

void test_vec3_normalize(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            vecs[i] = normalize(vecs[i]);
        }
    }
}

void test_vec4_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] += vecs[i + 1];
        }
    }
}

void test_vec4_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] *= vecs[i + 1];
        }
    }
}

void test_vec4_dot(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    scoped_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            res += dot(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec4_len(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    scoped_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            res += length(vecs[i]);
        }
    }
}

void test_vec4_normalize(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            vecs[i] = normalize(vecs[i]);
        }
    }
}

void test_mat2_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat2s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] += mats[i + 1];
        }
    }
}

void test_mat2_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat2s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] *= mats[i + 1];
        }
    }
}

void test_mat3_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat3s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] += mats[i + 1];
        }
    }
}

void test_mat3_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat3s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] *= mats[i + 1];
        }
    }
}

void test_mat3_comp_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat3s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] = matrix_comp_mult(mats[i], mats[i + 1]);
        }
    }
}

void test_mat4_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat4s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] += mats[i + 1];
        }
    }
}

void test_mat4_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat4s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] *= mats[i + 1];
        }
    }
}

void test_mat4_comp_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto mats = create_mat4s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] = matrix_comp_mult(mats[i], mats[i + 1]);
        }
    }
}

void test_dvec4_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std;
    using namespace math;

    init(arch);

    auto vecs = create_dvec4s(N);

    scoped_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] *= vecs[i + 1];
        }
    }
}

void test_perf() {
    using namespace std;
    using namespace math;

#if !defined(__arm__) && !defined(__aarch64__)
    std::pair<const char *, e_arch> archs[] = { { "Ref", Scalar },
        { "SSE2", SSE2 },
        { "SSE3", SSE3 },
        { "SSE4", SSE4_1 },
        { "AVX", AVX }
    };
#else
    std::pair<const char *, e_arch> archs[] = { { "Ref", Scalar },
        { "NEON", NEON }
    };
#endif

    {
        // warmup cpu a little
        chrono::system_clock::time_point t1 = chrono::system_clock::now();
        while (chrono::system_clock::now() - t1 < chrono::seconds(1));
    }

    const size_t N = 1000, M = 100000;

    std::pair<const char *, void(*)(const char *, math::e_arch, size_t, size_t)> tests[] = {
        //{ "vec2 add", test_vec2_add },
        //{ "vec2 mul", test_vec2_mul },
        //{ "vec2 dot", test_vec2_dot },
        //{ "vec2 len", test_vec2_len },

        { "vec3 add", test_vec3_add },
        { "vec3 mul", test_vec3_mul },
        { "vec3 dot", test_vec3_dot },
        { "vec3 cross", test_vec3_cross },
        { "vec3 len", test_vec3_len },
        { "vec3 norm", test_vec3_normalize},

        { "vec4 add", test_vec4_add },
        { "vec4 mul", test_vec4_mul },
        { "vec4 dot", test_vec4_dot },
        { "vec4 len", test_vec4_len },
        { "vec4 norm", test_vec4_normalize},

        //{ "mat2 add", test_mat2_add },
        //{ "mat2 mul", test_mat2_mul },

        { "mat3 add", test_mat3_add },
        { "mat3 mul", test_mat3_mul },
        { "mat3 comp mul", test_mat3_comp_mul },

        { "mat4 add", test_mat4_add },
        { "mat4 mul", test_mat4_mul },
        { "mat4 comp mul", test_mat4_comp_mul },
    };

    for (const auto &t : tests) {
        cout << "==== " << t.first << " ====" << endl;
        for (auto a : archs) {
            t.second(a.first, a.second, N, M);
        }
        cout << "==================" << endl;
    }
}