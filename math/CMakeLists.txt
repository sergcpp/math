cmake_minimum_required(VERSION 2.8.4)
project(math)

#add_definitions(-DCPU_ARCH_AVX)
#add_definitions(-DMATH_NO_INLINE)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES allocator.hpp
                 common.hpp
                 exponential.hpp
                 geometric.hpp
                 mat2.hpp
                 mat3.hpp
                 mat4.hpp
                 math.hpp
                 math.cpp
                 math_avx.hpp
                 math_funcs.hpp
                 math_neon.hpp
                 math_ref.hpp
                 math_sse2.hpp
                 math_sse3.hpp
                 math_sse4_1.hpp
                 transform.hpp
                 trigonometric.hpp
                 types.hpp
                 vec2.hpp
                 vec3.hpp
                 vec4.hpp)

list(APPEND ALL_SOURCE_FILES ${SOURCE_FILES})
source_group("src" FILES ${SOURCE_FILES})

add_library(math ${SOURCE_FILES})

add_subdirectory(tests)
