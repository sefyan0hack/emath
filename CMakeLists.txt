cmake_minimum_required(VERSION 3.30)

project(
    emath
    LANGUAGES C CXX
    VERSION 0.0.0
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

####################################################################################################
# IPO/LTO
####################################################################################################

include(CheckIPOSupported)
check_ipo_supported(RESULT IPO_SUPPORTED OUTPUT output)

if(IPO_SUPPORTED)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

##################################################################################################
# Snamepp Exe
##################################################################################################
link_libraries(stdc++exp)

add_library(emath)

target_sources(emath 
    PRIVATE
        ${CMAKE_SOURCE_DIR}/emath/vec3.cpp
    PUBLIC
    FILE_SET headers
      TYPE HEADERS
      BASE_DIRS ${CMAKE_SOURCE_DIR}/emath
      FILES 
        ${CMAKE_SOURCE_DIR}/emath/vec3.hpp
)

add_executable(tests
    ${CMAKE_SOURCE_DIR}/tests/main.cpp
)
