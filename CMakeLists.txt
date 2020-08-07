cmake_minimum_required(VERSION 3.15)
project(huffman_coding)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(crunch
        src/crunchmain.cpp
        src/encoding.cpp
        src/encoding.h
        src/HuffmanNode.cpp
        src/HuffmanNode.h
        src/chunkwriter.cpp src/chunkwriter.h
        src/chunkreader.cpp src/chunkreader.h)
