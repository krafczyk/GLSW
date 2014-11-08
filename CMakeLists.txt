project(GLSW)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_definitions(-DCMAKE_INSTALL_PREFIX="\\\"${CMAKE_INSTALL_PREFIX}\\\"")

include_directories(include ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})

set(SRCS
	src/glsw.cxx)

add_library(glsw SHARED ${SRCS})
set_target_properties(glsw PROPERTIES SOVERSION 0.0.0)

install(TARGETS glsw DESTINATION lib)
install(DIRECTORY include/GLSW DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY shaders DESTINATION share/glsw FILES_MATCHING PATTERN "*.vs")
install(DIRECTORY shaders DESTINATION share/glsw FILES_MATCHING PATTERN "*.fs")
