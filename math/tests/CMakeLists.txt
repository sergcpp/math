cmake_minimum_required(VERSION 3.2)
project(test_math)

add_executable(test_math main.cpp
                         test_assert.h
                         test_comb.cpp
                         test_common.cpp
                         test_data.cpp
						 test_dmat2.cpp
                         test_dvec2.cpp
                         test_dvec3.cpp
                         test_dvec4.cpp
                         test_geometric.cpp
                         test_ivec2.cpp
                         test_ivec3.cpp
                         test_ivec4.cpp
                         test_mat2.cpp
                         test_mat3.cpp
                         test_mat4.cpp
                         test_transform.cpp
                         test_trigonometric.cpp
                         test_vec2.cpp
                         test_vec3.cpp
                         test_vec4.cpp
                         test_perf.cpp
                         test_quat.cpp
                       )
target_link_libraries(test_math math)
