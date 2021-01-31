add_executable(nghttp2-client-asio-1 main.cpp)

target_link_libraries(nghttp2-client-asio-1 pthread nghttp2_asio)

