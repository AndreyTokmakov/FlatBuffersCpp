cmake_minimum_required(VERSION 3.29)
project(Experiments)

set(CMAKE_CXX_STANDARD 23)
set(SCHEME ${PROJECT_SOURCE_DIR}/scheme)
set(DEST_INCLUDE_FILE ${SCHEME}/all_headers.h)

include_directories(${SCHEME})

# Get list of "*.fbs" of files in ${SCHEME} folder
file(GLOB FLAT_BUFFERS_FILES ${SCHEME}/**.fbs)

# For each "*.fbs" call 'flatc' command to generate .h files:
foreach (fbs_file ${FLAT_BUFFERS_FILES})
    # message(STATUS "CMD : ${FLAT_BUFF_COMPILER} -o ${SCHEME} --cpp ${fbs_file}")
    execute_process(COMMAND ${FLAT_BUFF_COMPILER} -o ${SCHEME} --cpp ${fbs_file})
endforeach (fbs_file ${FLAT_BUFFERS_FILES})

# Remove 'all_headers.h' file
file(REMOVE ${DEST_INCLUDE_FILE})

# Get list of "*.h" of files in ${SCHEME} folder
file(GLOB GENERATED_HEADER_FILES ${SCHEME}/**.h)

foreach (file ${GENERATED_HEADER_FILES})
    get_filename_component(filename ${file} NAME)
    list(APPEND INCL_FILE_CONTENT "#include \"${filename}\"\n")
endforeach (file ${GENERATED_HEADER_FILES})

# Create 'all_headers.h' file with 'INCL_FILE_CONTENT' content
file(WRITE ${DEST_INCLUDE_FILE} ${INCL_FILE_CONTENT})

include_directories(${SCHEME})

add_executable(${PROJECT_NAME}
        main.cpp
        ${SCHEME}/all_headers.h
)