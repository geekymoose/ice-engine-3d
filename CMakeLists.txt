cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(runic-ice)


if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

# Dependencies GLFW3 (Should be installed widely on computer - Linux only)

# Dependencies GLM (In code)
# Dependencies stb_image (In code)
# Dependencies Glad (In code)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------

file(GLOB_RECURSE srcFilesCPP "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE srcFilesC "${CMAKE_SOURCE_DIR}/src/*.c")

include_directories("${CMAKE_SOURCE_DIR}/include")
add_executable(runic-ice ${srcFilesCPP} ${srcFilesC})
target_link_libraries(runic-ice
    "dl"
    "glfw"
    "GL"
    "X11"
    "pthread"
    "Xrandr"
    "Xi"
    )
add_custom_target(run runic-ice)


# ------------------------------------------------------------------------------
# Resources
# ------------------------------------------------------------------------------

# Copy shaders and resources in build
FILE(COPY shaders DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY resources DESTINATION "${CMAKE_BINARY_DIR}")
