cmake_minimum_required(VERSION 2.8.4)
project(math)

#add_definitions(-DCPU_ARCH_AVX)
#add_definitions(-DMATH_NO_INLINE)

IF(WIN32)

ELSE(WIN32)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
ENDIF(WIN32)

set(SOURCE_FILES allocator.hpp
                 common.hpp
                 dvec2.hpp
                 dvec3.hpp
                 dvec4.hpp
                 exponential.hpp
                 geometric.hpp
                 ivec2.hpp
                 ivec3.hpp
                 ivec4.hpp
                 mat2.hpp
                 mat3.hpp
                 mat4.hpp
                 math.hpp
                 math.cpp
                 quat.hpp
                 transform.hpp
                 trigonometric.hpp
                 vec2.hpp
                 vec3.hpp
                 vec4.hpp)

list(APPEND ALL_SOURCE_FILES ${SOURCE_FILES})
source_group("src" FILES ${SOURCE_FILES})

set(INTERNAL_FILES  internal/types.hpp
                    internal/math_funcs.hpp
                    internal/math_ref.hpp
                    internal/math_ref.ipp
                    internal/math_sse2.hpp
                    internal/math_sse2.ipp
                    internal/math_sse3.hpp
                    internal/math_sse3.ipp
                    internal/math_sse4_1.hpp
                    internal/math_sse4_1.ipp
                    internal/math_avx.hpp
                    internal/math_avx.ipp)

list(APPEND ALL_SOURCE_FILES ${INTERNAL_FILES})
source_group("src\\internal" FILES ${INTERNAL_FILES})

add_library(math ${ALL_SOURCE_FILES})

add_subdirectory(tests)
