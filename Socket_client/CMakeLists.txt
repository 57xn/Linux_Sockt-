cmake_minimum_required(VERSION 3.0)

project (SOCKET_CLIENT模拟)

include_directories( include )

aux_source_directory(src SRC_LIST)

add_executable(main  ${SRC_LIST})