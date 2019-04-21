cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(ice-engine)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Compiler Flags
# ------------------------------------------------------------------------------
message(STATUS "Detected Operating System: ${CMAKE_SYSTEM_NAME}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type set. Use Release")
    message(STATUS "CMAKE_BUILD_TYPE: Debug / Release")
    set(CMAKE_BUILD_TYPE Release)
endif()


# ------------------------------------------------------------------------------
# GLFW dependency
# ------------------------------------------------------------------------------
include(ExternalProject)
ExternalProject_Add(dep_glfw3
    SOURCE_DIR          "${CMAKE_SOURCE_DIR}/extern/glfw3/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/glfw3-build/"
    INSTALL_COMMAND     ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
)
ExternalProject_Get_Property(dep_glfw3 BINARY_DIR)
add_library(libglfw3 STATIC IMPORTED)
set_property(TARGET libglfw3 PROPERTY IMPORTED_LOCATION "${BINARY_DIR}/src/libglfw3.a")
include_directories("${CMAKE_SOURCE_DIR}/extern/glfw3/include/")


# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------
file(GLOB_RECURSE srcFiles "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE depGLAD "${CMAKE_SOURCE_DIR}/extern/glad/glad.c")

include_directories("${CMAKE_SOURCE_DIR}/include/")
include_directories("${CMAKE_SOURCE_DIR}/extern/")

add_executable(ice-engine ${depGLAD} ${srcFiles})
target_link_libraries(ice-engine
    "libglfw3"
    "dl"
    "GL"
    "X11"
    "pthread"
    "Xrandr"
    "Xi"
    )
add_custom_target(runEngine ice-engine)

# Copy shaders
set(SHADERS_SRC "${CMAKE_SOURCE_DIR}/shaders/")
set(SHADERS_BIN "${CMAKE_BINARY_DIR}/shaders/")
add_custom_command(
    OUTPUT "${SHADERS_BIN}"
    DEPENDS "${SHADERS_SRC}"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${SHADERS_SRC}" "${SHADERS_BIN}"
)
add_custom_target(copyShaders ALL DEPENDS "${SHADERS_BIN}")
add_dependencies(runEngine copyShaders)

# Copy resources
set(RESOURCES_SRC "${CMAKE_SOURCE_DIR}/resources/")
set(RESOURCES_BIN "${CMAKE_BINARY_DIR}/resources/")
add_custom_command(
    OUTPUT "${RESOURCES_BIN}"
    DEPENDS "${RESOURCES_SRC}"
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_SRC} ${RESOURCES_BIN}
)
add_custom_target(copyResources ALL DEPENDS "${RESOURCES_BIN}")
add_dependencies(runEngine copyResources)


