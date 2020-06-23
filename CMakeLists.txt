cmake_minimum_required(VERSION 3.15)
project(huffman_coding)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(huffman_coding
        src/encoding.cpp
        src/encoding.h
        src/huffmanmain.cpp
        src/HuffmanNode.cpp
        src/HuffmanNode.h
        src/huffmanutil.cpp
        src/huffmanutil.h src/chunkreader.cpp src/chunkreader.h src/chunkwriter.cpp src/chunkwriter.h)
