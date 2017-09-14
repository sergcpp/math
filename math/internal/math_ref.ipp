
// vec2
DEF_FUNC(void) vec2_init1(float2 &vec, float val) {
    vec.comp[0] = vec.comp[1] = val;
} DEF_END
    
DEF_FUNC(void) vec2_init2(float2 &vec, float v0, float v1) {
    vec.comp[0] = v0; vec.comp[1] = v1;
} DEF_END

DEF_FUNC(bool) vec2_eq_vec2(const float2 &v1, const float2 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1];
} DEF_END

DEF_FUNC(float2) vec2_add_vec2(const float2 &v1, const float2 &v2) {
    float2 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_sub_vec2(const float2 &v1, const float2 &v2) {
    float2 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_mul_vec2(const float2 &v1, const float2 &v2) {
    float2 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_div_vec2(const float2 &v1, const float2 &v2) {
    float2 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(float) vec2_get(const float2 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) vec2_set(float2 &vec, int i, float v) {
    vec.comp[i] = v;
} DEF_END

DEF_FUNC(float) vec2_length(const float2 &vec) {
    return sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1]);
} DEF_END

DEF_FUNC(float) vec2_dot(const float2 &v1, const float2 &v2) {
    return v1.comp[0] * v2.comp[0] + v1.comp[1] * v2.comp[1];
} DEF_END

DEF_FUNC(float2) vec2_normalize(const float2 &vec) {
    float norm = sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1]);
    float2 ret;
    ret.comp[0] = vec.comp[0] / norm;
    ret.comp[1] = vec.comp[1] / norm;
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_normalize_fast(const float2 &vec) {
    float inv_norm = 1.0f / sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1]);
    float2 ret;
    ret.comp[0] = vec.comp[0] * inv_norm;
    ret.comp[1] = vec.comp[1] * inv_norm;
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_sin(const float2 &v) {
    float2 ret;
    ret.comp[0] = sinf(v.comp[0]);
    ret.comp[1] = sinf(v.comp[1]);
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_cos(const float2 &v) {
    float2 ret;
    ret.comp[0] = cosf(v.comp[0]);
    ret.comp[1] = cosf(v.comp[1]);
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_tan(const float2 &v) {
    float2 ret;
    ret.comp[0] = tanf(v.comp[0]);
    ret.comp[1] = tanf(v.comp[1]);
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_asin(const float2 &v) {
    float2 ret;
    ret.comp[0] = asinf(v.comp[0]);
    ret.comp[1] = asinf(v.comp[1]);
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_acos(const float2 &v) {
    float2 ret;
    ret.comp[0] = acosf(v.comp[0]);
    ret.comp[1] = acosf(v.comp[1]);
    return ret;
} DEF_END

DEF_FUNC(float2) vec2_atan(const float2 &v) {
    float2 ret;
    ret.comp[0] = atanf(v.comp[0]);
    ret.comp[1] = atanf(v.comp[1]);
    return ret;
} DEF_END

// vec3
DEF_FUNC(void) vec3_init1(float3 &vec, float val) {
    vec.comp[0] = vec.comp[1] = vec.comp[2] = val;
} DEF_END

DEF_FUNC(void) vec3_init3(float3 &vec, float v0, float v1, float v2) {
    vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2;
} DEF_END

DEF_FUNC(bool) vec3_eq_vec3(const float3 &v1, const float3 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2];
} DEF_END

DEF_FUNC(float3) vec3_add_vec3(const float3 &v1, const float3 &v2) {
    float3 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_sub_vec3(const float3 &v1, const float3 &v2) {
    float3 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    ret.comp[2] = v1.comp[2] - v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_mul_vec3(const float3 &v1, const float3 &v2) {
    float3 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    ret.comp[2] = v1.comp[2] * v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_div_vec3(const float3 &v1, const float3 &v2) {
    float3 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    ret.comp[2] = v1.comp[2] / v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(float) vec3_get(const float3 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) vec3_set(float3 &vec, int i, float v) {
    vec.comp[i] = v;
} DEF_END

DEF_FUNC(float) vec3_length(const float3 &vec) {
    return sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] + vec.comp[2] * vec.comp[2]);
} DEF_END

DEF_FUNC(float) vec3_dot(const float3 &v1, const float3 &v2) {
    return v1.comp[0] * v2.comp[0] + v1.comp[1] * v2.comp[1] + v1.comp[2] * v2.comp[2];
} DEF_END

DEF_FUNC(float3) vec3_cross(const float3 &v1, const float3 &v2) {
    float3 ret;
    ret.comp[0] = v1.comp[1] * v2.comp[2] - v1.comp[2] * v2.comp[1];
    ret.comp[1] = v1.comp[2] * v2.comp[0] - v1.comp[0] * v2.comp[2];
    ret.comp[2] = v1.comp[0] * v2.comp[1] - v1.comp[1] * v2.comp[0];
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_normalize(const float3 &vec) {
    float norm = sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] + vec.comp[2] * vec.comp[2]);
    float3 ret;
    ret.comp[0] = vec.comp[0] / norm;
    ret.comp[1] = vec.comp[1] / norm;
    ret.comp[2] = vec.comp[2] / norm;
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_normalize_fast(const float3 &vec) {
    float inv_norm = 1.0f / sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] + vec.comp[2] * vec.comp[2]);
    float3 ret;
    ret.comp[0] = vec.comp[0] * inv_norm;
    ret.comp[1] = vec.comp[1] * inv_norm;
    ret.comp[2] = vec.comp[2] * inv_norm;
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_sin(const float3 &v) {
    float3 ret;
    ret.comp[0] = sinf(v.comp[0]);
    ret.comp[1] = sinf(v.comp[1]);
    ret.comp[2] = sinf(v.comp[2]);
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_cos(const float3 &v) {
    float3 ret;
    ret.comp[0] = cosf(v.comp[0]);
    ret.comp[1] = cosf(v.comp[1]);
    ret.comp[2] = cosf(v.comp[2]);
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_tan(const float3 &v) {
    float3 ret;
    ret.comp[0] = tanf(v.comp[0]);
    ret.comp[1] = tanf(v.comp[1]);
    ret.comp[2] = tanf(v.comp[2]);
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_asin(const float3 &v) {
    float3 ret;
    ret.comp[0] = asinf(v.comp[0]);
    ret.comp[1] = asinf(v.comp[1]);
    ret.comp[2] = asinf(v.comp[2]);
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_acos(const float3 &v) {
    float3 ret;
    ret.comp[0] = acosf(v.comp[0]);
    ret.comp[1] = acosf(v.comp[1]);
    ret.comp[2] = acosf(v.comp[2]);
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_atan(const float3 &v) {
    float3 ret;
    ret.comp[0] = atanf(v.comp[0]);
    ret.comp[1] = atanf(v.comp[1]);
    ret.comp[2] = atanf(v.comp[2]);
    return ret;
} DEF_END

// vec4
DEF_FUNC(void) vec4_init1(float4 &vec, float val) {
    vec.comp[0] = vec.comp[1] = vec.comp[2] = vec.comp[3] = val;
} DEF_END

DEF_FUNC(void) vec4_init4(float4 &vec, float v0, float v1, float v2, float v3) {
    vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2; vec.comp[3] = v3;
} DEF_END

DEF_FUNC(bool) vec4_eq_vec4(const float4 &v1, const float4 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2] && v1.comp[3] == v2.comp[3];
} DEF_END

DEF_FUNC(float4) vec4_add_vec4(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    ret.comp[3] = v1.comp[3] + v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_sub_vec4(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    ret.comp[2] = v1.comp[2] - v2.comp[2];
    ret.comp[3] = v1.comp[3] - v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_mul_vec4(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    ret.comp[2] = v1.comp[2] * v2.comp[2];
    ret.comp[3] = v1.comp[3] * v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_div_vec4(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    ret.comp[2] = v1.comp[2] / v2.comp[2];
    ret.comp[3] = v1.comp[3] / v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float) vec4_get(const float4 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) vec4_set(float4 &vec, int i, float v) {
    vec.comp[i] = v;
} DEF_END

DEF_FUNC(float) vec4_length(const float4 &vec) {
    return sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] +
        vec.comp[2] * vec.comp[2] + vec.comp[3] * vec.comp[3]);
} DEF_END

DEF_FUNC(float) vec4_dot(const float4 &v1, const float4 &v2) {
    return v1.comp[0] * v2.comp[0] + v1.comp[1] * v2.comp[1] +
        v1.comp[2] * v2.comp[2] + v1.comp[3] * v2.comp[3];
} DEF_END

DEF_FUNC(float4) vec4_normalize(const float4 &vec) {
    float norm = sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] +
        vec.comp[2] * vec.comp[2] + vec.comp[3] * vec.comp[3]);
    float4 ret;
    ret.comp[0] = vec.comp[0] / norm;
    ret.comp[1] = vec.comp[1] / norm;
    ret.comp[2] = vec.comp[2] / norm;
    ret.comp[3] = vec.comp[3] / norm;
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_normalize_fast(const float4 &vec) {
    float inv_norm = 1.0f / sqrtf(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] +
        vec.comp[2] * vec.comp[2] + vec.comp[3] * vec.comp[3]);
    float4 ret;
    ret.comp[0] = vec.comp[0] * inv_norm;
    ret.comp[1] = vec.comp[1] * inv_norm;
    ret.comp[2] = vec.comp[2] * inv_norm;
    ret.comp[3] = vec.comp[3] * inv_norm;
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_sin(const float4 &v) {
    float4 ret;
    ret.comp[0] = sinf(v.comp[0]);
    ret.comp[1] = sinf(v.comp[1]);
    ret.comp[2] = sinf(v.comp[2]);
    ret.comp[3] = sinf(v.comp[3]);
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_cos(const float4 &v) {
    float4 ret;
    ret.comp[0] = cosf(v.comp[0]);
    ret.comp[1] = cosf(v.comp[1]);
    ret.comp[2] = cosf(v.comp[2]);
    ret.comp[3] = cosf(v.comp[3]);
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_tan(const float4 &v) {
    float4 ret;
    ret.comp[0] = tanf(v.comp[0]);
    ret.comp[1] = tanf(v.comp[1]);
    ret.comp[2] = tanf(v.comp[2]);
    ret.comp[3] = tanf(v.comp[3]);
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_asin(const float4 &v) {
    float4 ret;
    ret.comp[0] = asinf(v.comp[0]);
    ret.comp[1] = asinf(v.comp[1]);
    ret.comp[2] = asinf(v.comp[2]);
    ret.comp[3] = asinf(v.comp[3]);
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_acos(const float4 &v) {
    float4 ret;
    ret.comp[0] = acosf(v.comp[0]);
    ret.comp[1] = acosf(v.comp[1]);
    ret.comp[2] = acosf(v.comp[2]);
    ret.comp[3] = acosf(v.comp[3]);
    return ret;
} DEF_END

DEF_FUNC(float4) vec4_atan(const float4 &v) {
    float4 ret;
    ret.comp[0] = atanf(v.comp[0]);
    ret.comp[1] = atanf(v.comp[1]);
    ret.comp[2] = atanf(v.comp[2]);
    ret.comp[3] = atanf(v.comp[3]);
    return ret;
} DEF_END

// mat2
DEF_FUNC(void) mat2_init1(float4 &vec, float val) {
    vec.comp[0] = vec.comp[3] = val;
    vec.comp[1] = vec.comp[2] = 0;
} DEF_END

DEF_FUNC(void) mat2_init2(float4 &vec, const float2 &v01, const float2 &v23) {
    vec.vec2[0] = v01;
    vec.vec2[1] = v23;
} DEF_END

DEF_FUNC(void) mat2_init4(float4 &vec, float v0, float v1, float v2, float v3) {
    vec.comp[0] = v0; vec.comp[1] = v1;
    vec.comp[2] = v2; vec.comp[3] = v3;
} DEF_END

DEF_FUNC(bool) mat2_eq_mat2(const float4 &m1, const float4 &m2) {
    return m1.comp[0] == m2.comp[0] && m1.comp[1] == m2.comp[1] &&
        m1.comp[2] == m2.comp[2] && m1.comp[3] == m2.comp[3];
}

DEF_FUNC(float4) mat2_add_mat2(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    ret.comp[3] = v1.comp[3] + v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float4) mat2_sub_mat2(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    ret.comp[2] = v1.comp[2] - v2.comp[2];
    ret.comp[3] = v1.comp[3] - v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float4) mat2_mul_mat2(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp2[0][0] = v1.comp2[0][0] * v2.comp2[0][0] + v1.comp2[1][0] * v2.comp2[0][1];
    ret.comp2[0][1] = v1.comp2[0][1] * v2.comp2[0][0] + v1.comp2[1][1] * v2.comp2[0][1];
    ret.comp2[1][0] = v1.comp2[0][0] * v2.comp2[1][0] + v1.comp2[1][0] * v2.comp2[1][1];
    ret.comp2[1][1] = v1.comp2[0][1] * v2.comp2[1][0] + v1.comp2[1][1] * v2.comp2[1][1];
    return ret;
} DEF_END

DEF_FUNC(float4) mat2_div_mat2(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    ret.comp[2] = v1.comp[2] / v2.comp[2];
    ret.comp[3] = v1.comp[3] / v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float2) mat2_get(const float4 &vec, int i) {
    return vec.vec2[i];
} DEF_END

DEF_FUNC(void) mat2_set(float4 &vec, int i, const float2 &v) {
    vec.vec2[i] = v;
} DEF_END

DEF_FUNC(float4) mat2_comp_mul(const float4 &m1, const float4 &m2) {
    float4 ret;
    ret.comp[0] = m1.comp[0] * m2.comp[0];
    ret.comp[1] = m1.comp[1] * m2.comp[1];
    ret.comp[2] = m1.comp[2] * m2.comp[2];
    ret.comp[3] = m1.comp[3] * m2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float4) mat2_inverse(const float4 &m) {
    float inv_det = 1.0f / (m.comp2[0][0] * m.comp2[1][1] - m.comp2[1][0] * m.comp2[0][1]);

    float4 ret;
    ret.comp2[0][0] = m.comp2[1][1] * inv_det;
    ret.comp2[0][1] = -m.comp2[0][1] * inv_det;
    ret.comp2[1][0] = -m.comp2[1][0] * inv_det;
    ret.comp2[1][1] = m.comp2[0][0] * inv_det;
    return ret;
} DEF_END

// mat3
DEF_FUNC(void) mat3_init1(float9 &vec, float val) {
    vec.comp3[0][0] = vec.comp3[1][1] = vec.comp3[2][2] = val;
    vec.comp3[0][1] = vec.comp3[0][2] =
        vec.comp3[1][0] = vec.comp3[1][2] =
        vec.comp3[2][0] = vec.comp3[2][1] = 0;
} DEF_END

DEF_FUNC(void) mat3_init9(float9 &vec, float v00, float v01, float v02,
                                        float v10, float v11, float v12,
                                        float v20, float v21, float v22) {
    vec.comp3[0][0] = v00; vec.comp3[0][1] = v01; vec.comp3[0][2] = v02;
    vec.comp3[1][0] = v10; vec.comp3[1][1] = v11; vec.comp3[1][2] = v12;
    vec.comp3[2][0] = v20; vec.comp3[2][1] = v21; vec.comp3[2][2] = v22;
} DEF_END

DEF_FUNC(void) mat3_init3(float9 &vec, const float3 &v0, const float3 &v1, const float3 &v2) {
    vec.vec3[0] = v0;
    vec.vec3[1] = v1;
    vec.vec3[2] = v2;
} DEF_END

DEF_FUNC(bool) mat3_eq_mat3(const float9 &m1, const float9 &m2) {
    return m1.comp3[0][0] == m2.comp3[0][0] && m1.comp3[0][1] == m2.comp3[0][1] && m1.comp3[0][2] == m2.comp3[0][2] &&
            m1.comp3[1][0] == m2.comp3[1][0] && m1.comp3[1][1] == m2.comp3[1][1] && m1.comp3[1][2] == m2.comp3[1][2] &&
            m1.comp3[2][0] == m2.comp3[2][0] && m1.comp3[2][1] == m2.comp3[2][1] && m1.comp3[2][2] == m2.comp3[2][2];
}

DEF_FUNC(float9) mat3_add_mat3(const float9 &v1, const float9 &v2) {
    float9 ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.comp3[i][j] = v1.comp3[i][j] + v2.comp3[i][j];
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float9) mat3_sub_mat3(const float9 &v1, const float9 &v2) {
    float9 ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.comp3[i][j] = v1.comp3[i][j] - v2.comp3[i][j];
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float9) mat3_mul_mat3(const float9 &v1, const float9 &v2) {
    float9 ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.comp3[i][j] = v2.comp3[i][0] * v1.comp3[0][j] +
                                v2.comp3[i][1] * v1.comp3[1][j] +
                                v2.comp3[i][2] * v1.comp3[2][j];
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float9) mat3_div_mat3(const float9 &v1, const float9 &v2) {
    float9 ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.comp3[i][j] = v1.comp3[i][j] / v2.comp3[i][j];
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float9) mat3_mul_float(const float9 &v1, float v2) {
    float9 ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.comp3[i][j] = v1.comp3[i][j] * v2;
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float9) mat3_div_float(const float9 &v1, float v2) {
    float9 ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.comp3[i][j] = v1.comp3[i][j] / v2;
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float3) mat3_get(const float9 &vec, int i) {
    return vec.vec3[i];
} DEF_END

DEF_FUNC(void) mat3_set(float9 &vec, int i, const float3 &v) {
    vec.vec3[i] = v;
} DEF_END

DEF_FUNC(float9) mat3_comp_mul(const float9 &v1, const float9 &v2) {
    float9 ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.comp3[i][j] = v1.comp3[i][j] * v2.comp3[i][j];
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float9) mat3_inverse(const float9 &m) {
    float inv_det = 1.0f / (m.comp3[0][0] * (m.comp3[1][1] * m.comp3[2][2] - m.comp3[2][1] * m.comp3[1][2])
                            - m.comp3[1][0] * (m.comp3[0][1] * m.comp3[2][2] - m.comp3[2][1] * m.comp3[0][2])
                            + m.comp3[2][0] * (m.comp3[0][1] * m.comp3[1][2] - m.comp3[1][1] * m.comp3[0][2]));

    float9 ret;
    ret.comp3[0][0] = +(m.comp3[1][1] * m.comp3[2][2] - m.comp3[2][1] * m.comp3[1][2]) * inv_det;
    ret.comp3[1][0] = -(m.comp3[1][0] * m.comp3[2][2] - m.comp3[2][0] * m.comp3[1][2]) * inv_det;
    ret.comp3[2][0] = +(m.comp3[1][0] * m.comp3[2][1] - m.comp3[2][0] * m.comp3[1][1]) * inv_det;
    ret.comp3[0][1] = -(m.comp3[0][1] * m.comp3[2][2] - m.comp3[2][1] * m.comp3[0][2]) * inv_det;
    ret.comp3[1][1] = +(m.comp3[0][0] * m.comp3[2][2] - m.comp3[2][0] * m.comp3[0][2]) * inv_det;
    ret.comp3[2][1] = -(m.comp3[0][0] * m.comp3[2][1] - m.comp3[2][0] * m.comp3[0][1]) * inv_det;
    ret.comp3[0][2] = +(m.comp3[0][1] * m.comp3[1][2] - m.comp3[1][1] * m.comp3[0][2]) * inv_det;
    ret.comp3[1][2] = -(m.comp3[0][0] * m.comp3[1][2] - m.comp3[1][0] * m.comp3[0][2]) * inv_det;
    ret.comp3[2][2] = +(m.comp3[0][0] * m.comp3[1][1] - m.comp3[1][0] * m.comp3[0][1]) * inv_det;
    return ret;
} DEF_END

// mat4
DEF_FUNC(void) mat4_init1(float16 &vec, float val) {
    vec.comp4[0][0] = vec.comp4[1][1] = vec.comp4[2][2] = vec.comp4[3][3] = val;
    vec.comp4[0][1] = vec.comp4[0][2] = vec.comp4[0][3] =
        vec.comp4[1][0] = vec.comp4[1][2] = vec.comp4[1][3] =
        vec.comp4[2][0] = vec.comp4[2][1] = vec.comp4[2][3] =
        vec.comp4[3][0] = vec.comp4[3][1] = vec.comp4[3][2] = 0;
} DEF_END

DEF_FUNC(void) mat4_init16(float16 &vec, float v00, float v01, float v02, float v03,
                                            float v10, float v11, float v12, float v13,
                                            float v20, float v21, float v22, float v23,
                                            float v30, float v31, float v32, float v33) {
    vec.comp4[0][0] = v00; vec.comp4[0][1] = v01; vec.comp4[0][2] = v02; vec.comp4[0][3] = v03;
    vec.comp4[1][0] = v10; vec.comp4[1][1] = v11; vec.comp4[1][2] = v12; vec.comp4[1][3] = v13;
    vec.comp4[2][0] = v20; vec.comp4[2][1] = v21; vec.comp4[2][2] = v22; vec.comp4[2][3] = v23;
    vec.comp4[3][0] = v30; vec.comp4[3][1] = v31; vec.comp4[3][2] = v32; vec.comp4[3][3] = v33;
} DEF_END

DEF_FUNC(void) mat4_init4(float16 &vec, const float4 &v0, const float4 &v1, const float4 &v2, const float4 &v3) {
    vec.vec4[0] = v0;
    vec.vec4[1] = v1;
    vec.vec4[2] = v2;
    vec.vec4[3] = v3;
} DEF_END

DEF_FUNC(bool) mat4_eq_mat4(const float16 &m1, const float16 &m2) {
    return m1.comp[0] == m2.comp[0] && m1.comp[1] == m2.comp[1] && m1.comp[2] == m2.comp[2] && m1.comp[3] == m2.comp[3] &&
            m1.comp[4] == m2.comp[4] && m1.comp[5] == m2.comp[5] && m1.comp[6] == m2.comp[6] && m1.comp[7] == m2.comp[7] &&
            m1.comp[8] == m2.comp[8] && m1.comp[9] == m2.comp[9] && m1.comp[10] == m2.comp[10] && m1.comp[11] == m2.comp[11] &&
            m1.comp[12] == m2.comp[12] && m1.comp[13] == m2.comp[13] && m1.comp[14] == m2.comp[14] && m1.comp[15] == m2.comp[15];
} DEF_END

DEF_FUNC(float16) mat4_add_mat4(const float16 &v1, const float16 &v2) {
    float16 ret;
    for (int i = 0; i < 16; i++) {
        ret.comp[i] = v1.comp[i] + v2.comp[i];
    }
    return ret;
} DEF_END

DEF_FUNC(float16) mat4_sub_mat4(const float16 &v1, const float16 &v2) {
    float16 ret;
    for (int i = 0; i < 16; i++) {
        ret.comp[i] = v1.comp[i] - v2.comp[i];
    }
    return ret;
} DEF_END

DEF_FUNC(float16) mat4_mul_mat4(const float16 &v1, const float16 &v2) {
    float16 ret;
    for (int i = 0; i < 16; i += 4) {
        for (int j = 0; j < 4; j++) {
            ret.comp[i + j] = (v2.comp[i + 0] * v1.comp[j + 0]) +
                                (v2.comp[i + 1] * v1.comp[j + 4]) +
                                (v2.comp[i + 2] * v1.comp[j + 8]) +
                                (v2.comp[i + 3] * v1.comp[j + 12]);
        }
    }
    return ret;
} DEF_END

DEF_FUNC(float16) mat4_div_mat4(const float16 &v1, const float16 &v2) {
    float16 ret;
    for (int i = 0; i < 16; i++) {
        ret.comp[i] = v1.comp[i] / v2.comp[i];
    }
    return ret;
} DEF_END

DEF_FUNC(float16) mat4_mul_float(const float16 &v1, float v2) {
    float16 ret;
    for (int i = 0; i < 16; i++) {
        ret.comp[i] = v1.comp[i] * v2;
    }
    return ret;
} DEF_END

DEF_FUNC(float16) mat4_div_float(const float16 &v1, float v2) {
    float16 ret;
    for (int i = 0; i < 16; i++) {
        ret.comp[i] = v1.comp[i] / v2;
    }
    return ret;
} DEF_END

DEF_FUNC(float4) mat4_get(const float16 &vec, int i) {
    return vec.vec4[i];
} DEF_END

DEF_FUNC(void) mat4_set(float16 &vec, int i, const float4 &v) {
    vec.vec4[i] = v;
} DEF_END

DEF_FUNC(float16) mat4_comp_mul(const float16 &v1, const float16 &v2) {
    float16 ret;
    for (int i = 0; i < 16; i++) {
        ret.comp[i] = v1.comp[i] * v2.comp[i];
    }
    return ret;
} DEF_END

DEF_FUNC(float16) mat4_inverse(const float16 &m) {
    float A2323 = m.comp4[2][2] * m.comp4[3][3] - m.comp4[2][3] * m.comp4[3][2];
    float A1323 = m.comp4[2][1] * m.comp4[3][3] - m.comp4[2][3] * m.comp4[3][1];
    float A1223 = m.comp4[2][1] * m.comp4[3][2] - m.comp4[2][2] * m.comp4[3][1];
    float A0323 = m.comp4[2][0] * m.comp4[3][3] - m.comp4[2][3] * m.comp4[3][0];
    float A0223 = m.comp4[2][0] * m.comp4[3][2] - m.comp4[2][2] * m.comp4[3][0];
    float A0123 = m.comp4[2][0] * m.comp4[3][1] - m.comp4[2][1] * m.comp4[3][0];
    float A2313 = m.comp4[1][2] * m.comp4[3][3] - m.comp4[1][3] * m.comp4[3][2];
    float A1313 = m.comp4[1][1] * m.comp4[3][3] - m.comp4[1][3] * m.comp4[3][1];
    float A1213 = m.comp4[1][1] * m.comp4[3][2] - m.comp4[1][2] * m.comp4[3][1];
    float A2312 = m.comp4[1][2] * m.comp4[2][3] - m.comp4[1][3] * m.comp4[2][2];
    float A1312 = m.comp4[1][1] * m.comp4[2][3] - m.comp4[1][3] * m.comp4[2][1];
    float A1212 = m.comp4[1][1] * m.comp4[2][2] - m.comp4[1][2] * m.comp4[2][1];
    float A0313 = m.comp4[1][0] * m.comp4[3][3] - m.comp4[1][3] * m.comp4[3][0];
    float A0213 = m.comp4[1][0] * m.comp4[3][2] - m.comp4[1][2] * m.comp4[3][0];
    float A0312 = m.comp4[1][0] * m.comp4[2][3] - m.comp4[1][3] * m.comp4[2][0];
    float A0212 = m.comp4[1][0] * m.comp4[2][2] - m.comp4[1][2] * m.comp4[2][0];
    float A0113 = m.comp4[1][0] * m.comp4[3][1] - m.comp4[1][1] * m.comp4[3][0];
    float A0112 = m.comp4[1][0] * m.comp4[2][1] - m.comp4[1][1] * m.comp4[2][0];

    float inv_det = 1.0f / (m.comp4[0][0] * (m.comp4[1][1] * A2323 - m.comp4[1][2] * A1323 + m.comp4[1][3] * A1223)
                            - m.comp4[0][1] * (m.comp4[1][0] * A2323 - m.comp4[1][2] * A0323 + m.comp4[1][3] * A0223)
                            + m.comp4[0][2] * (m.comp4[1][0] * A1323 - m.comp4[1][1] * A0323 + m.comp4[1][3] * A0123)
                            - m.comp4[0][3] * (m.comp4[1][0] * A1223 - m.comp4[1][1] * A0223 + m.comp4[1][2] * A0123));

    float16 ret;
    ret.comp4[0][0] = inv_det *   (m.comp4[1][1] * A2323 - m.comp4[1][2] * A1323 + m.comp4[1][3] * A1223);
    ret.comp4[0][1] = inv_det * -(m.comp4[0][1] * A2323 - m.comp4[0][2] * A1323 + m.comp4[0][3] * A1223);
    ret.comp4[0][2] = inv_det *   (m.comp4[0][1] * A2313 - m.comp4[0][2] * A1313 + m.comp4[0][3] * A1213);
    ret.comp4[0][3] = inv_det * -(m.comp4[0][1] * A2312 - m.comp4[0][2] * A1312 + m.comp4[0][3] * A1212);
    ret.comp4[1][0] = inv_det * -(m.comp4[1][0] * A2323 - m.comp4[1][2] * A0323 + m.comp4[1][3] * A0223);
    ret.comp4[1][1] = inv_det *   (m.comp4[0][0] * A2323 - m.comp4[0][2] * A0323 + m.comp4[0][3] * A0223);
    ret.comp4[1][2] = inv_det * -(m.comp4[0][0] * A2313 - m.comp4[0][2] * A0313 + m.comp4[0][3] * A0213);
    ret.comp4[1][3] = inv_det *   (m.comp4[0][0] * A2312 - m.comp4[0][2] * A0312 + m.comp4[0][3] * A0212);
    ret.comp4[2][0] = inv_det *   (m.comp4[1][0] * A1323 - m.comp4[1][1] * A0323 + m.comp4[1][3] * A0123);
    ret.comp4[2][1] = inv_det * -(m.comp4[0][0] * A1323 - m.comp4[0][1] * A0323 + m.comp4[0][3] * A0123);
    ret.comp4[2][2] = inv_det *   (m.comp4[0][0] * A1313 - m.comp4[0][1] * A0313 + m.comp4[0][3] * A0113);
    ret.comp4[2][3] = inv_det * -(m.comp4[0][0] * A1312 - m.comp4[0][1] * A0312 + m.comp4[0][3] * A0112);
    ret.comp4[3][0] = inv_det * -(m.comp4[1][0] * A1223 - m.comp4[1][1] * A0223 + m.comp4[1][2] * A0123);
    ret.comp4[3][1] = inv_det *   (m.comp4[0][0] * A1223 - m.comp4[0][1] * A0223 + m.comp4[0][2] * A0123);
    ret.comp4[3][2] = inv_det * -(m.comp4[0][0] * A1213 - m.comp4[0][1] * A0213 + m.comp4[0][2] * A0113);
    ret.comp4[3][3] = inv_det *   (m.comp4[0][0] * A1212 - m.comp4[0][1] * A0212 + m.comp4[0][2] * A0112);
    return ret;
} DEF_END

// ivec2
DEF_FUNC(void) ivec2_init1(int2 &vec, int val) {
    vec.comp[0] = vec.comp[1] = val;
} DEF_END

DEF_FUNC(void) ivec2_init2(int2 &vec, int v0, int v1) {
    vec.comp[0] = v0; vec.comp[1] = v1;
} DEF_END

DEF_FUNC(bool) ivec2_eq_ivec2(const int2 &v1, const int2 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1];
} DEF_END

DEF_FUNC(int2) ivec2_add_ivec2(const int2 &v1, const int2 &v2) {
    int2 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(int2) ivec2_sub_ivec2(const int2 &v1, const int2 &v2) {
    int2 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(int2) ivec2_mul_ivec2(const int2 &v1, const int2 &v2) {
    int2 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(int2) ivec2_div_ivec2(const int2 &v1, const int2 &v2) {
    int2 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(int) ivec2_get(const int2 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) ivec2_set(int2 &vec, int i, int v) {
    vec.comp[i] = v;
} DEF_END

// ivec3
DEF_FUNC(void) ivec3_init1(int3 &vec, int val) {
    vec.comp[0] = vec.comp[1] = vec.comp[2] = val;
} DEF_END

DEF_FUNC(void) ivec3_init3(int3 &vec, int v0, int v1, int v2) {
    vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2;
} DEF_END

DEF_FUNC(bool) ivec3_eq_ivec3(const int3 &v1, const int3 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2];
} DEF_END

DEF_FUNC(int3) ivec3_add_ivec3(const int3 &v1, const int3 &v2) {
    int3 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(int3) ivec3_sub_ivec3(const int3 &v1, const int3 &v2) {
    int3 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    ret.comp[2] = v1.comp[2] - v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(int3) ivec3_mul_ivec3(const int3 &v1, const int3 &v2) {
    int3 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    ret.comp[2] = v1.comp[2] * v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(int3) ivec3_div_ivec3(const int3 &v1, const int3 &v2) {
    int3 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    ret.comp[2] = v1.comp[2] / v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(int) ivec3_get(const int3 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) ivec3_set(int3 &vec, int i, int v) {
    vec.comp[i] = v;
} DEF_END

// ivec4
DEF_FUNC(void) ivec4_init1(int4 &vec, int val) {
    vec.comp[0] = vec.comp[1] = vec.comp[2] = vec.comp[3] = val;
} DEF_END

DEF_FUNC(void) ivec4_init4(int4 &vec, int v0, int v1, int v2, int v3) {
    vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2; vec.comp[3] = v3;
} DEF_END

DEF_FUNC(bool) ivec4_eq_ivec4(const int4 &v1, const int4 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] &&
            v1.comp[2] == v2.comp[2] && v1.comp[3] == v2.comp[3];
} DEF_END

DEF_FUNC(int4) ivec4_add_ivec4(const int4 &v1, const int4 &v2) {
    int4 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    ret.comp[3] = v1.comp[3] + v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(int4) ivec4_sub_ivec4(const int4 &v1, const int4 &v2) {
    int4 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    ret.comp[2] = v1.comp[2] - v2.comp[2];
    ret.comp[3] = v1.comp[3] - v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(int4) ivec4_mul_ivec4(const int4 &v1, const int4 &v2) {
    int4 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    ret.comp[2] = v1.comp[2] * v2.comp[2];
    ret.comp[3] = v1.comp[3] * v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(int4) ivec4_div_ivec4(const int4 &v1, const int4 &v2) {
    int4 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    ret.comp[2] = v1.comp[2] / v2.comp[2];
    ret.comp[3] = v1.comp[3] / v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(int) ivec4_get(const int4 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) ivec4_set(int4 &vec, int i, int v) {
    vec.comp[i] = v;
} DEF_END

// quat
DEF_FUNC(void) quat_init4(float4 &vec, float r, float i, float j, float k) {
    vec.comp[0] = i; vec.comp[1] = j; vec.comp[2] = k; vec.comp[3] = r;
} DEF_END

DEF_FUNC(bool) quat_eq_quat(const float4 &v1, const float4 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2] && v1.comp[3] == v2.comp[3];
} DEF_END

DEF_FUNC(float4) quat_add_quat(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    ret.comp[3] = v1.comp[3] + v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(float4) quat_mul_quat(const float4 &v1, const float4 &v2) {
    float4 ret;
    ret.comp[3] = v1.comp[3] * v2.comp[3] - v1.comp[0] * v2.comp[0] - v1.comp[1] * v2.comp[1] - v1.comp[2] * v2.comp[2];
    ret.comp[0] = v1.comp[3] * v2.comp[0] + v1.comp[0] * v2.comp[3] + v1.comp[1] * v2.comp[2] - v1.comp[2] * v2.comp[1];
    ret.comp[1] = v1.comp[3] * v2.comp[1] + v1.comp[1] * v2.comp[3] + v1.comp[2] * v2.comp[0] - v1.comp[0] * v2.comp[2];
    ret.comp[2] = v1.comp[3] * v2.comp[2] + v1.comp[2] * v2.comp[3] + v1.comp[0] * v2.comp[1] - v1.comp[1] * v2.comp[0];
    return ret;
} DEF_END

DEF_FUNC(float4) quat_mul_float(const float4 &v1, const float f) {
    float4 ret;
    ret.comp[0] = v1.comp[0] * f;
    ret.comp[1] = v1.comp[1] * f;
    ret.comp[2] = v1.comp[2] * f;
    ret.comp[3] = v1.comp[3] * f;
    return ret;
} DEF_END

DEF_FUNC(float4) quat_div_float(const float4 &v1, const float f) {
    float4 ret;
    ret.comp[0] = v1.comp[0] / f;
    ret.comp[1] = v1.comp[1] / f;
    ret.comp[2] = v1.comp[2] / f;
    ret.comp[3] = v1.comp[3] / f;
    return ret;
} DEF_END

DEF_FUNC(float) quat_get(const float4 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) quat_set(float4 &vec, int i, float v) {
    vec.comp[i] = v;
} DEF_END

DEF_FUNC(float9) quat_to_mat3(const float4 &vec) {
    float9 ret;

    float qxx = vec.comp[0] * vec.comp[0];
    float qyy = vec.comp[1] * vec.comp[1];
    float qzz = vec.comp[2] * vec.comp[2];
    float qxz = vec.comp[0] * vec.comp[2];
    float qxy = vec.comp[0] * vec.comp[1];
    float qyz = vec.comp[1] * vec.comp[2];
    float qwx = vec.comp[3] * vec.comp[0];
    float qwy = vec.comp[3] * vec.comp[1];
    float qwz = vec.comp[3] * vec.comp[2];

    ret.comp3[0][0] = 1 - 2 * (qyy +  qzz);
    ret.comp3[0][1] = 2 * (qxy + qwz);
    ret.comp3[0][2] = 2 * (qxz - qwy);

    ret.comp3[1][0] = 2 * (qxy - qwz);
    ret.comp3[1][1] = 1 - 2 * (qxx + qzz);
    ret.comp3[1][2] = 2 * (qyz + qwx);

    ret.comp3[2][0] = 2 * (qxz + qwy);
    ret.comp3[2][1] = 2 * (qyz - qwx);
    ret.comp3[2][2] = 1 - 2 * (qxx + qyy);

    return ret;
} DEF_END

DEF_FUNC(float4) mat3_to_quat(const float9 &vec) {
    float fourXSquaredMinus1 = vec.comp3[0][0] - vec.comp3[1][1] - vec.comp3[2][2];
    float fourYSquaredMinus1 = vec.comp3[1][1] - vec.comp3[0][0] - vec.comp3[2][2];
    float fourZSquaredMinus1 = vec.comp3[2][2] - vec.comp3[0][0] - vec.comp3[1][1];
    float fourWSquaredMinus1 = vec.comp3[0][0] + vec.comp3[1][1] + vec.comp3[2][2];

    int biggestIndex = 0;
    float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
    if (fourXSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourXSquaredMinus1;
        biggestIndex = 1;
    }
    if (fourYSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourYSquaredMinus1;
        biggestIndex = 2;
    }
    if (fourZSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourZSquaredMinus1;
        biggestIndex = 3;
    }

    float biggestVal = sqrt(fourBiggestSquaredMinus1 + 1) * 0.5f;
    float mult = 0.25f / biggestVal;

    float4 ret;
    switch (biggestIndex) {
    case 0:
        ret.comp[3] = biggestVal;
        ret.comp[0] = (vec.comp3[1][2] - vec.comp3[2][1]) * mult;
        ret.comp[1] = (vec.comp3[2][0] - vec.comp3[0][2]) * mult;
        ret.comp[2] = (vec.comp3[0][1] - vec.comp3[1][0]) * mult;
        break;
    case 1:
        ret.comp[3] = (vec.comp3[1][2] - vec.comp3[2][1]) * mult;
        ret.comp[0] = biggestVal;
        ret.comp[1] = (vec.comp3[0][1] + vec.comp3[1][0]) * mult;
        ret.comp[2] = (vec.comp3[2][0] + vec.comp3[0][2]) * mult;
        break;
    case 2:
        ret.comp[3] = (vec.comp3[2][0] - vec.comp3[0][2]) * mult;
        ret.comp[0] = (vec.comp3[0][1] + vec.comp3[1][0]) * mult;
        ret.comp[1] = biggestVal;
        ret.comp[2] = (vec.comp3[1][2] + vec.comp3[2][1]) * mult;
        break;
    case 3:
        ret.comp[3] = (vec.comp3[0][1] - vec.comp3[1][0]) * mult;
        ret.comp[0] = (vec.comp3[2][0] + vec.comp3[0][2]) * mult;
        ret.comp[1] = (vec.comp3[1][2] + vec.comp3[2][1]) * mult;
        ret.comp[2] = biggestVal;
        break;
    default:
        break;
    }
    return ret;
} DEF_END

DEF_FUNC(float4) mat4_to_quat(const float16 &vec) {
    float fourXSquaredMinus1 = vec.comp4[0][0] - vec.comp4[1][1] - vec.comp4[2][2];
    float fourYSquaredMinus1 = vec.comp4[1][1] - vec.comp4[0][0] - vec.comp4[2][2];
    float fourZSquaredMinus1 = vec.comp4[2][2] - vec.comp4[0][0] - vec.comp4[1][1];
    float fourWSquaredMinus1 = vec.comp4[0][0] + vec.comp4[1][1] + vec.comp4[2][2];

    int biggestIndex = 0;
    float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
    if (fourXSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourXSquaredMinus1;
        biggestIndex = 1;
    }
    if (fourYSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourYSquaredMinus1;
        biggestIndex = 2;
    }
    if (fourZSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourZSquaredMinus1;
        biggestIndex = 3;
    }

    float biggestVal = sqrt(fourBiggestSquaredMinus1 + 1) * 0.5f;
    float mult = 0.25f / biggestVal;

    float4 ret;
    switch (biggestIndex) {
    case 0:
        ret.comp[3] = biggestVal;
        ret.comp[0] = (vec.comp4[1][2] - vec.comp4[2][1]) * mult;
        ret.comp[1] = (vec.comp4[2][0] - vec.comp4[0][2]) * mult;
        ret.comp[2] = (vec.comp4[0][1] - vec.comp4[1][0]) * mult;
        break;
    case 1:
        ret.comp[3] = (vec.comp4[1][2] - vec.comp4[2][1]) * mult;
        ret.comp[0] = biggestVal;
        ret.comp[1] = (vec.comp4[0][1] + vec.comp4[1][0]) * mult;
        ret.comp[2] = (vec.comp4[2][0] + vec.comp4[0][2]) * mult;
        break;
    case 2:
        ret.comp[3] = (vec.comp4[2][0] - vec.comp4[0][2]) * mult;
        ret.comp[0] = (vec.comp4[0][1] + vec.comp4[1][0]) * mult;
        ret.comp[1] = biggestVal;
        ret.comp[2] = (vec.comp4[1][2] + vec.comp4[2][1]) * mult;
        break;
    case 3:
        ret.comp[3] = (vec.comp4[0][1] - vec.comp4[1][0]) * mult;
        ret.comp[0] = (vec.comp4[2][0] + vec.comp4[0][2]) * mult;
        ret.comp[1] = (vec.comp4[1][2] + vec.comp4[2][1]) * mult;
        ret.comp[2] = biggestVal;
        break;
    default:
        break;
    }
    return ret;
} DEF_END

// dvec2
DEF_FUNC(void) dvec2_init1(double2 &vec, double val) {
    vec.comp[0] = vec.comp[1] = val;
} DEF_END

DEF_FUNC(void) dvec2_init2(double2 &vec, double v0, double v1) {
    vec.comp[0] = v0; vec.comp[1] = v1;
} DEF_END

DEF_FUNC(bool) dvec2_eq_dvec2(const double2 &v1, const double2 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1];
} DEF_END

DEF_FUNC(double2) dvec2_add_dvec2(const double2 &v1, const double2 &v2) {
    double2 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(double2) dvec2_sub_dvec2(const double2 &v1, const double2 &v2) {
    double2 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(double2) dvec2_mul_dvec2(const double2 &v1, const double2 &v2) {
    double2 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(double2) dvec2_div_dvec2(const double2 &v1, const double2 &v2) {
    double2 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    return ret;
} DEF_END

DEF_FUNC(double) dvec2_get(const double2 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) dvec2_set(double2 &vec, int i, double v) {
    vec.comp[i] = v;
} DEF_END

DEF_FUNC(double) dvec2_length(const double2 &vec) {
    return sqrt(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1]);
} DEF_END

// dvec3
DEF_FUNC(void) dvec3_init1(double3 &vec, double val) {
    vec.comp[0] = vec.comp[1] = vec.comp[2] = val;
} DEF_END

DEF_FUNC(void) dvec3_init3(double3 &vec, double v0, double v1, double v2) {
    vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2;
} DEF_END

DEF_FUNC(bool) dvec3_eq_dvec3(const double3 &v1, const double3 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2];
} DEF_END

DEF_FUNC(double3) dvec3_add_dvec3(const double3 &v1, const double3 &v2) {
    double3 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(double3) dvec3_sub_dvec3(const double3 &v1, const double3 &v2) {
    double3 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    ret.comp[2] = v1.comp[2] - v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(double3) dvec3_mul_dvec3(const double3 &v1, const double3 &v2) {
    double3 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    ret.comp[2] = v1.comp[2] * v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(double3) dvec3_div_dvec3(const double3 &v1, const double3 &v2) {
    double3 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    ret.comp[2] = v1.comp[2] / v2.comp[2];
    return ret;
} DEF_END

DEF_FUNC(double) dvec3_get(const double3 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) dvec3_set(double3 &vec, int i, double v) {
    vec.comp[i] = v;
} DEF_END

DEF_FUNC(double) dvec3_length(const double3 &vec) {
    return sqrt(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] + vec.comp[2] * vec.comp[2]);
} DEF_END

// dvec4
DEF_FUNC(void) dvec4_init1(double4 &vec, double val) {
    vec.comp[0] = vec.comp[1] = vec.comp[2] = vec.comp[3] = val;
} DEF_END

DEF_FUNC(void) dvec4_init4(double4 &vec, double v0, double v1, double v2, double v3) {
    vec.comp[0] = v0; vec.comp[1] = v1; vec.comp[2] = v2; vec.comp[3] = v3;
} DEF_END

DEF_FUNC(bool) dvec4_eq_dvec4(const double4 &v1, const double4 &v2) {
    return v1.comp[0] == v2.comp[0] && v1.comp[1] == v2.comp[1] && v1.comp[2] == v2.comp[2] && v1.comp[3] == v2.comp[3];
} DEF_END

DEF_FUNC(double4) dvec4_add_dvec4(const double4 &v1, const double4 &v2) {
    double4 ret;
    ret.comp[0] = v1.comp[0] + v2.comp[0];
    ret.comp[1] = v1.comp[1] + v2.comp[1];
    ret.comp[2] = v1.comp[2] + v2.comp[2];
    ret.comp[3] = v1.comp[3] + v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(double4) dvec4_sub_dvec4(const double4 &v1, const double4 &v2) {
    double4 ret;
    ret.comp[0] = v1.comp[0] - v2.comp[0];
    ret.comp[1] = v1.comp[1] - v2.comp[1];
    ret.comp[2] = v1.comp[2] - v2.comp[2];
    ret.comp[3] = v1.comp[3] - v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(double4) dvec4_mul_dvec4(const double4 &v1, const double4 &v2) {
    double4 ret;
    ret.comp[0] = v1.comp[0] * v2.comp[0];
    ret.comp[1] = v1.comp[1] * v2.comp[1];
    ret.comp[2] = v1.comp[2] * v2.comp[2];
    ret.comp[3] = v1.comp[3] * v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(double4) dvec4_div_dvec4(const double4 &v1, const double4 &v2) {
    double4 ret;
    ret.comp[0] = v1.comp[0] / v2.comp[0];
    ret.comp[1] = v1.comp[1] / v2.comp[1];
    ret.comp[2] = v1.comp[2] / v2.comp[2];
    ret.comp[3] = v1.comp[3] / v2.comp[3];
    return ret;
} DEF_END

DEF_FUNC(double) dvec4_get(const double4 &vec, int i) {
    return vec.comp[i];
} DEF_END

DEF_FUNC(void) dvec4_set(double4 &vec, int i, double v) {
    vec.comp[i] = v;
} DEF_END

DEF_FUNC(double) dvec4_length(const double4 &vec) {
    return sqrt(vec.comp[0] * vec.comp[0] + vec.comp[1] * vec.comp[1] +
                vec.comp[2] * vec.comp[2] + vec.comp[3] * vec.comp[3]);
} DEF_END

// comb
DEF_FUNC(float2) mat2_mul_vec2(const float4 &m, const float2 &v) {
    float2 ret;
    ret.comp[0] = m.comp2[0][0] * v.comp[0] + m.comp2[1][0] * v.comp[1];
    ret.comp[1] = m.comp2[0][1] * v.comp[0] + m.comp2[1][1] * v.comp[1];
    return ret;
} DEF_END

    DEF_FUNC(float3) mat3_mul_vec3(const float9 &m, const float3 &v) {
    float3 ret;
    ret.comp[0] = m.comp3[0][0] * v.comp[0] + m.comp3[1][0] * v.comp[1] + m.comp3[2][0] * v.comp[2];
    ret.comp[1] = m.comp3[0][1] * v.comp[0] + m.comp3[1][1] * v.comp[1] + m.comp3[2][1] * v.comp[2];
    ret.comp[2] = m.comp3[0][2] * v.comp[0] + m.comp3[1][2] * v.comp[1] + m.comp3[2][2] * v.comp[2];
    return ret;
}

DEF_FUNC(float4) mat4_mul_vec4(const float16 &m, const float4 &v) {
    float4 ret;

	ret.comp[0] = m.comp4[0][0] * v.comp[0] + m.comp4[1][0] * v.comp[1] + m.comp4[2][0] * v.comp[2] + m.comp4[3][0] * v.comp[3];
	ret.comp[1] = m.comp4[0][1] * v.comp[0] + m.comp4[1][1] * v.comp[1] + m.comp4[2][1] * v.comp[2] + m.comp4[3][1] * v.comp[3];
	ret.comp[2] = m.comp4[0][2] * v.comp[0] + m.comp4[1][2] * v.comp[1] + m.comp4[2][2] * v.comp[2] + m.comp4[3][2] * v.comp[3];
	ret.comp[3] = m.comp4[0][3] * v.comp[0] + m.comp4[1][3] * v.comp[1] + m.comp4[2][3] * v.comp[2] + m.comp4[3][3] * v.comp[3];

    return ret;
} DEF_END

DEF_FUNC(float2) vec2_mul_mat2(const float2 &v, const float4 &m) {
    float2 ret;
    ret.comp[0] = v.comp[0] * m.comp2[0][0] + v.comp[1] * m.comp2[0][1];
    ret.comp[1] = v.comp[0] * m.comp2[1][0] + v.comp[1] * m.comp2[1][1];
    return ret;
} DEF_END

DEF_FUNC(float3) vec3_mul_mat3(const float3 &v, const float9 &m) {
    float3 ret;
    ret.comp[0] = m.comp3[0][0] * v.comp[0] + m.comp3[0][1] * v.comp[1] + m.comp3[0][2] * v.comp[2];
    ret.comp[1] = m.comp3[1][0] * v.comp[0] + m.comp3[1][1] * v.comp[1] + m.comp3[1][2] * v.comp[2];
    ret.comp[2] = m.comp3[2][0] * v.comp[0] + m.comp3[2][1] * v.comp[1] + m.comp3[2][2] * v.comp[2];
    return ret;
}

DEF_FUNC(float4) vec4_mul_mat4(const float4 &v, const float16 &m) {
    float4 ret;
    ret.comp[0] = m.comp4[0][0] * v.comp[0] + m.comp4[0][1] * v.comp[1] + m.comp4[0][2] * v.comp[2] + m.comp4[0][3] * v.comp[3];
    ret.comp[1] = m.comp4[1][0] * v.comp[0] + m.comp4[1][1] * v.comp[1] + m.comp4[1][2] * v.comp[2] + m.comp4[1][3] * v.comp[3];
    ret.comp[2] = m.comp4[2][0] * v.comp[0] + m.comp4[2][1] * v.comp[1] + m.comp4[2][2] * v.comp[2] + m.comp4[2][3] * v.comp[3];
    ret.comp[3] = m.comp4[3][0] * v.comp[0] + m.comp4[3][1] * v.comp[1] + m.comp4[3][2] * v.comp[2] + m.comp4[3][3] * v.comp[3];
    return ret;
}
