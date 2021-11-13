cmake_minimum_required(VERSION 3.20)
project(dfy_v1)

set(CMAKE_CXX_STANDARD 23)

add_executable(dfy_v1 main.cpp File.cpp File.h HashMap.cpp HashMap.h Folder.cpp Folder.h)
