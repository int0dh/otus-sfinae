cmake_minimum_required(VERSION 3.2)

project(print_ip)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_NAME "print_ip")

add_executable(${PROJECT_NAME} print_ip.cxx)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20 
	CXX_STANDARD_REQUIRED ON)
target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_VERSION=$ENV{BUILD_VERSION})

target_compile_options(${PROJECT_NAME} PRIVATE
	-Wall -Wextra -pedantic -Werror -fconcepts)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT hit@me.com)
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME})
include(CPack)
