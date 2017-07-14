
void test_vec2();
void test_vec3();
void test_vec4();
void test_mat2();
void test_mat3();
void test_mat4();
void test_geometric();
void test_trigonometric();
void test_common();

void test_perf();

int main() {
    test_vec2();
    test_vec3();
    test_vec4();
    test_mat2();
    test_mat3();
    test_mat4();
    test_geometric();
    test_trigonometric();
    test_common();

    // no reason to test in debug mode
#ifdef NDEBUG
    test_perf();
#endif
}