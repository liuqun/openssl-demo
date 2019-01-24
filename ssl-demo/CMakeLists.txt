cmake_minimum_required(VERSION 3.1)
project(demo1 LANGUAGES C)

aux_source_directory(./src/client client_SOURCES)
aux_source_directory(./src/server server_SOURCES)
add_executable(client ${client_SOURCES})
add_executable(server ${server_SOURCES})
set_property(TARGET client PROPERTY C_STANDARD 11)
set_property(TARGET server PROPERTY C_STANDARD 11)

find_package(OpenSSL REQUIRED)
target_include_directories(client PRIVATE ${OPENSSL_INCLUDE_DIR})
target_include_directories(server PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(client PRIVATE
  ${OPENSSL_LIBRARIES}
)
target_link_libraries(server PRIVATE
  ${OPENSSL_LIBRARIES}
)
