aux_source_directory(. SRCS)

add_library(utils SHARED ${SRCS})

target_compile_options(utils PUBLIC -fPIC)