
void test_vec2();
void test_vec3();
void test_vec4();
void test_mat2();
void test_mat3();
void test_mat4();
void test_ivec2();
void test_ivec3();
void test_ivec4();
void test_quat();

void test_dvec2();
void test_dvec3();
void test_dvec4();

void test_geometric();
void test_transform();
void test_trigonometric();
void test_common();
void test_comb();

void test_perf();

int main() {
    test_vec2();
    test_vec3();
    test_vec4();
    test_mat2();
    test_mat3();
    test_mat4();
    test_ivec2();
    test_ivec3();
    test_ivec4();
    test_quat();

    test_dvec2();
    test_dvec3();
    test_dvec4();

    test_geometric();
    test_transform();
    test_trigonometric();
    test_common();
    test_comb();

    // no reason to test in debug mode
#ifdef NDEBUG
    test_perf();
#endif
}