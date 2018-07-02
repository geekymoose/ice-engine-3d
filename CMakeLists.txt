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
# Executable
# ------------------------------------------------------------------------------

file(GLOB_RECURSE srcFilesCPP "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE srcFilesC "${CMAKE_SOURCE_DIR}/src/*.c")

include_directories("${CMAKE_SOURCE_DIR}/include")
add_executable(ice-engine ${srcFilesCPP} ${srcFilesC})
target_link_libraries(ice-engine
    "dl"
    "glfw"
    "GL"
    "X11"
    "pthread"
    "Xrandr"
    "Xi"
    )
add_custom_target(runEngine ice-engine)

# Copy shaders
set(SHADERS_SRC "${CMAKE_SOURCE_DIR}/shader/")
set(SHADERS_BIN "${CMAKE_BINARY_DIR}/shader/")
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


