cmake_minimum_required(VERSION 3.21)
project(FlatBuffersCPP)

set(CMAKE_CXX_STANDARD 23)
set(FLAT_BUFFERS_ROOT "/home/andtokm/DiskS/ProjectsUbuntu/Flatbuffers/flatbuffers")
set(FLAT_BUFF_COMPILER "${FLAT_BUFFERS_ROOT}/flatc")

include_directories("${FLAT_BUFFERS_ROOT}/include")

# message(STATUS "FLAT_BUFFERS_ROOT  : ${FLAT_BUFFERS_ROOT}")
# message(STATUS "FLAT_BUFF_COMPILER : ${FLAT_BUFF_COMPILER}")

add_subdirectory(Experiments)
add_subdirectory(LoggerExample)

