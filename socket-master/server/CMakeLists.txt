cmake_minimum_required(VERSION 2.8)
project(TCPSocket)
find_package(CUDA QUIET REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

cuda_add_executable(server server.cc imagTrans.cc imagTrans.h stb_image.h stb_image_write.h process.h process.cpp)
