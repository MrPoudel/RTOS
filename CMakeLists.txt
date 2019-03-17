#[[This is a simple CMakeLists.txt example.]]
cmake_minimum_required (VERSION 3.7)
project (rtos)

#include_directories ("${PROJECT_SOURCE_DIR}/headers")
add_library (os_lib os.c)

add_executable (os_example os_test.c)
target_link_libraries (os_example os_lib)
