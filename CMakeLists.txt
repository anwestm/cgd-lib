cmake_minimum_required(VERSION 3.9)
project(cgd_lib C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_FLAGS “${CMAKE_FLAGS} -lmingw32”)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/lib/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/lib)

add_executable(cgd_lib main.c libcgd/window.c libcgd/window.h libcgd/util.h testscene.c testscene.h libcgd/util.c libcgd/model.c libcgd/model.h libcgd/mesh.c libcgd/mesh.h libcgd/shaderprogram.c libcgd/shaderprogram.h libcgd/files.c libcgd/files.h libcgd/stb_image.h libcgd/texture.c libcgd/texture.h libcgd/camera.c libcgd/camera.h libcgd/linkedlist.c libcgd/linkedlist.h libcgd/stb_image.c libcgd/environment.c libcgd/environment.h libcgd/light.c libcgd/light.h)
target_link_libraries(cgd_lib SDL2 SDL2main glew32 opengl32 cglm)