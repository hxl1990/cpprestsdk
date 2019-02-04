cmake_minimum_required (VERSION 2.6)

project (cpprestsdk)

aux_source_directory(. SRC_LIST)
add_executable(cpprestsdk ${SRC_LIST})