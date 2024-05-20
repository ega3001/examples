project(number_convertion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(MAIN_PROJECT_SRC_LIST main.cpp)

add_executable(main ${MAIN_PROJECT_SRC_LIST})
add_subdirectory(src)

target_link_libraries(main lib)