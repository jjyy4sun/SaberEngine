aux_source_directory(. SRCS)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(utils SHARED ${SRCS})

target_compile_options(utils PUBLIC -fPIC)