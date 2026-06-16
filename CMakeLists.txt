cmake_minimum_required(VERSION 3.30)

project(
    emath
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(emath)

target_sources(emath 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/free_func.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/vec2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/vec3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/vec4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/ivec2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/ivec3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/ivec4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/uvec2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/uvec3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/uvec4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/u16vec4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/mat2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/mat3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/mat4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/quat.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/helpers.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/hash.cpp
    PUBLIC
    FILE_SET headers
      TYPE HEADERS
      BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
      FILES 
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/emath.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/free_func.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/vec2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/vec3.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/vec4.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/ivec2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/ivec3.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/ivec4.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/uvec2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/uvec3.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/uvec4.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/u16vec4.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/mat2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/mat3.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/mat4.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/quat.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/helpers.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/emath/hash.hpp
)

if(EMATH_TESTS)
add_executable(emath-tests tests/main.cpp)
target_link_libraries(emath-tests PRIVATE emath)
endif()