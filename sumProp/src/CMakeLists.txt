project(NumberConvertion)

set(SOURCES base.cpp numbers.cpp rules.cpp parts.cpp convert.cpp)
set(HEADERS base.hpp numbers.hpp rules.hpp parts.hpp convert.hpp)

add_library(lib ${SOURCES} ${HEADERS})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})