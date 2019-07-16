cmake_minimum_required(VERSION 3.9)
project(cgd_lib C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_FLAGS “${CMAKE_FLAGS} -lmingw32”)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/lib/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/lib)

file(GLOB CGD_LIB_SRC "libcgd/*.c" "libcgd/*.h")


add_executable(cgd_lib main.c ${CGD_LIB_SRC} libcgd-test/lamptest.c libcgd-test/lamptest.h)
target_link_libraries(cgd_lib SDL2 SDL2main glew32 opengl32 assimp zlib cglm)
