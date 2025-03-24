cmake_minimum_required(VERSION 3.21)
project(FlatBuffersCPP)

set(CMAKE_CXX_STANDARD 26)
add_compile_options(-c -Wall -Wextra -O3 -std=c++26)

# 5.15 - My home Ubuntu-20.04
if (CMAKE_SYSTEM_VERSION MATCHES "5.15")
    set(FLAT_BUFFERS_ROOT "/home/andtokm/DiskS/ProjectsUbuntu/Flatbuffers/flatbuffers")
    # set(EXTRA_LIBS tbb)
else()
    set(FLAT_BUFFERS_ROOT "/home/andtokm/Projects/FlatBuffers/flatbuffers")
endif()

set(FLAT_BUFF_COMPILER "${FLAT_BUFFERS_ROOT}/flatc")
include_directories("${FLAT_BUFFERS_ROOT}/include")

# message(STATUS "FLAT_BUFFERS_ROOT  : ${FLAT_BUFFERS_ROOT}")
# message(STATUS "FLAT_BUFF_COMPILER : ${FLAT_BUFF_COMPILER}")

add_subdirectory(Experiments)
add_subdirectory(LoggerExample)

