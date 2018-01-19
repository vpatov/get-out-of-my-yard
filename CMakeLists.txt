# CMake entry point
cmake_minimum_required (VERSION 3.0)
project(get-out-of-my-yard)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Freetype REQUIRED)

include_directories(${FREETYPE_INCLUDE_DIRS})

find_package(GLEW REQUIRED)

if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
endif()

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    glfw
    ${FREETYPE_LIBRARIES}
    ${GLEW_LIBRARIES}
)


# User playground
add_executable(getout
    getout.cpp
    utils.cpp
    keymap.cpp
)


include_directories(
	${OPENGL_INCLUDE_DIR}
	/usr/local/include/GLFW
)
target_link_libraries(getout ${ALL_LIBS})
