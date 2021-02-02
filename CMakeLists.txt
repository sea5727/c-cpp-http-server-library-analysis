cmake_minimum_required(VERSION 3.0.0)
project(tutorial VERSION 0.1.0)

set(tutorial_VERSION_MAJOR 1)
set(tutorial_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include(CTest)
enable_testing()

link_libraries(ssl crypto nghttp2)
include_directories(/usr/local/include/uWebSockets ${PROJECT_SOURCE_DIR}/uSockets/src)

# add_subdirectory(uWebSockets)
# add_subdirectory(beast)
add_subdirectory(nghttp2)
add_subdirectory(crow)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
