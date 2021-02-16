
add_executable(crow-tutorial.exe main.cpp)
add_executable(using_test test.cpp)
add_executable(template_test template_test.cpp)
target_link_libraries(crow-tutorial.exe z pthread)