cmake_minimum_required(VERSION 2.8.12.2)

project (SOCKET_SERVER模拟)

include_directories( include )

aux_source_directory(src SRC_LIST)

add_executable(main  ${SRC_LIST})
