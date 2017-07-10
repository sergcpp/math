
#include <chrono>
#include <iostream>
#include <vector>

#include "../math.hpp"

math::aligned_vector<math::vec2> create_vec2s(size_t N) {
    math::aligned_vector<math::vec2> vecs(N, math::uninitialize);
    for (size_t i = 0; i < N; i++) {
        vecs[i] = math::vec2(float(i), float(i + 1));
    }
    return vecs;
}

math::aligned_vector<math::vec3> create_vec3s(size_t N) {
    math::aligned_vector<math::vec3> vecs(N, math::uninitialize);
    for (size_t i = 0; i < N; i++) {
        vecs[i] = math::vec3(float(i), float(i + 1), float(i + 2));
    }
    return vecs;
}

math::aligned_vector<math::vec4> create_vec4s(size_t N) {
    math::aligned_vector<math::vec4> vecs(N, math::uninitialize);
    for (size_t i = 0; i < N; i++) {
        vecs[i] = math::vec4(float(i), float(i + 1), float(i + 2), float(i + 3));
    }
    return vecs;
}

math::aligned_vector<math::mat2> create_mat2s(size_t N) {
    math::aligned_vector<math::mat2> mats(N, math::uninitialize);
    for (size_t i = 0; i < N; i++) {
        mats[i] = math::mat2(float(i), float(i + 1), float(i + 2), float(i + 3));
    }
    return mats;
}

math::aligned_vector<math::mat3> create_mat3s(size_t N) {
    math::aligned_vector<math::mat3> mats(N, math::uninitialize);
    for (size_t i = 0; i < N; i++) {
        mats[i] = math::mat3(float(i), float(i + 1), float(i + 2),
                             float(i), float(i + 1), float(i + 2),
                             float(i), float(i + 1), float(i + 2));
    }
    return mats;
}

math::aligned_vector<math::mat4> create_mat4s(size_t N) {
    math::aligned_vector<math::mat4> mats(N, math::uninitialize);
    for (size_t i = 0; i < N; i++) {
        mats[i] = math::mat4(float(i), float(i + 1), float(i + 2), float(i + 3),
                             float(i), float(i + 1), float(i + 2), float(i + 3),
                             float(i), float(i + 1), float(i + 2), float(i + 3),
                             float(i), float(i + 1), float(i + 2), float(i + 3));
    }
    return mats;
}

struct test_timer {
    const char *name;
    math::e_arch arch;
    std::chrono::system_clock::time_point t1;

    test_timer(const char *_name, math::e_arch _arch) : name(_name), arch(_arch), t1(std::chrono::system_clock::now()) {}

    ~test_timer() {
        auto t2 = std::chrono::system_clock::now();
        std::cout << " " << name << ":\t" << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms";
        if (!math::supported(arch)) std::cout << " (not supported)";
        std::cout << std::endl;
    }
};

void test_vec2_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] += vecs[i + 1];
        }
    }
}

void test_vec2_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] *= vecs[i + 1];
        }
    }
}

void test_vec2_dot(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    test_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            res += dot(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec2_len(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec2s(N);

    test_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            res += length(vecs[i]);
        }
    }
}

void test_vec3_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] += vecs[i + 1];
        }
    }
}

void test_vec3_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] *= vecs[i + 1];
        }
    }
}

void test_vec3_dot(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    test_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            res += dot(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec3_cross(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] = cross(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec3_len(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    test_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            res += length(vecs[i]);
        }
    }
}

void test_vec3_normalize(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            vecs[i] = normalize(vecs[i]);
        }
    }
}

void test_vec4_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] += vecs[i + 1];
        }
    }
}

void test_vec4_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            vecs[i] *= vecs[i + 1];
        }
    }
}

void test_vec4_dot(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec3s(N);

    test_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            res += dot(vecs[i], vecs[i + 1]);
        }
    }
}

void test_vec4_len(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    test_timer timer = { name, arch };

    volatile float res = 0;
    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            res += length(vecs[i]);
        }
    }
}

void test_vec4_normalize(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto vecs = create_vec4s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i++) {
            vecs[i] = normalize(vecs[i]);
        }
    }
}

void test_mat2_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat2s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] += mats[i + 1];
        }
    }
}

void test_mat2_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat2s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] *= mats[i + 1];
        }
    }
}

void test_mat3_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat3s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] += mats[i + 1];
        }
    }
}

void test_mat3_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat3s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] *= mats[i + 1];
        }
    }
}

void test_mat3_comp_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat3s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] = matrixCompMult(mats[i], mats[i + 1]);
        }
    }
}

void test_mat4_add(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat4s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] += mats[i + 1];
        }
    }
}

void test_mat4_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat4s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] *= mats[i + 1];
        }
    }
}

void test_mat4_comp_mul(const char *name, math::e_arch arch, size_t N, size_t M) {
    using namespace std; using namespace math;

    init(arch);

    auto mats = create_mat4s(N);

    test_timer timer = { name, arch };

    for (size_t j = 0; j < M; j++) {
        for (size_t i = 0; i < N - 1; i += 2) {
            mats[i] = matrixCompMult(mats[i], mats[i + 1]);
        }
    }
}


void test_perf() {
    using namespace std; using namespace math;

#ifndef __arm__
    std::pair<const char *, e_arch> archs[] = { { "Ref", Scalar },
                                                { "SSE2", SSE2 },
                                                { "SSE3", SSE3 },
                                                { "SSE4", SSE4_1 },
                                                { "AVX", AVX } };
#else
    std::pair<const char *, e_arch> archs[] = { { "Ref", Scalar },
                                                { "NEON", NEON } };
#endif

    {   // warmup cpu a little
        chrono::system_clock::time_point t1 = chrono::system_clock::now();
        while (chrono::system_clock::now() - t1 < chrono::seconds(1));
    }

    const size_t N = 1000, M = 100000;

    /*cout << "                " << endl;
    cout << "     [vec2]     " << endl;
    cout << "==== vec2 add ====" << endl;
    for (auto a : archs) {
        test_vec2_add(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec2 mul ====" << endl;
    for (auto a : archs) {
        test_vec2_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec2 dot ====" << endl;
    for (auto a : archs) {
        test_vec2_dot(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec2 len ====" << endl;
    for (auto a : archs) {
        test_vec2_len(a.first, a.second, N, M);
    }
    cout << "==================" << endl;*/

    //////////////////////////////////////////////

    cout << "                " << endl;
    cout << "     [vec3]     " << endl;
    cout << "==== vec3 add ====" << endl;
    for (auto a : archs) {
        test_vec3_add(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec3 mul ====" << endl;
    for (auto a : archs) {
        test_vec3_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec3 dot ====" << endl;
    for (auto a : archs) {
        test_vec3_dot(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "=== vec3 cross ===" << endl;
    for (auto a : archs) {
        test_vec3_cross(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec3 len ===" << endl;
    for (auto a : archs) {
        test_vec3_len(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec3 norm ===" << endl;
    for (auto a : archs) {
        test_vec3_normalize(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    //////////////////////////////////////////////

    cout << "                " << endl;
    cout << "     [vec4]     " << endl;
    cout << "==== vec4 add ====" << endl;
    for (auto a : archs) {
        test_vec3_add(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec4 mul ====" << endl;
    for (auto a : archs) {
        test_vec3_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec4 dot ====" << endl;
    for (auto a : archs) {
        test_vec3_dot(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec4 len ===" << endl;
    for (auto a : archs) {
        test_vec4_len(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "==== vec4 norm ===" << endl;
    for (auto a : archs) {
        test_vec4_normalize(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    //////////////////////////////////////////////

    /*cout << "                " << endl;
    cout << "     [mat2]     " << endl;
    cout << "=== mat2 add  ===" << endl;
    for (auto a : archs) {
        test_mat2_add(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "=== mat2 mul  ===" << endl;
    for (auto a : archs) {
        test_mat2_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;*/

    //////////////////////////////////////////////

    cout << "                " << endl;
    cout << "     [mat3]     " << endl;
    cout << "=== mat3 add  ===" << endl;
    for (auto a : archs) {
        test_mat3_add(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "=== mat3 mul  ===" << endl;
    for (auto a : archs) {
        test_mat3_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "= mat3 comp mul  =" << endl;
    for (auto a : archs) {
        test_mat3_comp_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    //////////////////////////////////////////////

    cout << "                " << endl;
    cout << "     [mat4]     " << endl;
    cout << "=== mat4 add  ===" << endl;
    for (auto a : archs) {
        test_mat4_add(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "=== mat4 mul  ===" << endl;
    for (auto a : archs) {
        test_mat4_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;

    cout << "== mat4 comp mul =" << endl;
    for (auto a : archs) {
        test_mat4_comp_mul(a.first, a.second, N, M);
    }
    cout << "==================" << endl;
}