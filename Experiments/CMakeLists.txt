cmake_minimum_required(VERSION 3.29)
project(Experiments)

set(CMAKE_CXX_STANDARD 26)
set(SCHEME ${PROJECT_SOURCE_DIR}/scheme)
set(MESSAGING ${PROJECT_SOURCE_DIR}/messaging)
set(DEST_INCLUDE_FILE ${MESSAGING}/all_headers.h)

include_directories(${SCHEME})

# Get list of "*.fbs" of files in ${SCHEME} folder
file(GLOB FLAT_BUFFERS_FILES ${SCHEME}/**.fbs)

# For each "*.fbs" call 'flatc' command to generate .h files:
foreach (fbs_file ${FLAT_BUFFERS_FILES})
    # message(STATUS "CMD : ${FLAT_BUFF_COMPILER} -o ${MESSAGING} --cpp --no-prefix --scoped-enums ${fbs_file}")
    execute_process(COMMAND ${FLAT_BUFF_COMPILER} -o ${MESSAGING}
            --cpp --no-prefix --scoped-enums --cpp-std c++17 --filename-suffix ""
            ${fbs_file})
endforeach (fbs_file ${FLAT_BUFFERS_FILES})

# Remove 'all_headers.h' file
file(REMOVE ${DEST_INCLUDE_FILE})

# Get list of "*.h" of files in ${MESSAGING} folder
file(GLOB GENERATED_HEADER_FILES ${MESSAGING}/**.h)

foreach (file ${GENERATED_HEADER_FILES})
    get_filename_component(filename ${file} NAME)
    list(APPEND INCL_FILE_CONTENT "#include \"${filename}\"\n")
    # message(STATUS "\tAdding file '${file}' to 'all_headers.h'")
endforeach (file ${GENERATED_HEADER_FILES})

# Create 'all_headers.h' file with 'INCL_FILE_CONTENT' content
file(WRITE ${DEST_INCLUDE_FILE} ${INCL_FILE_CONTENT})

include_directories(${MESSAGING})

add_executable(${PROJECT_NAME}
        main.cpp
        ${DEST_INCLUDE_FILE}
)