//
// Created by Vaishnavi Gupta on 6/23/20.
//

#ifndef HUFFMAN_CODING_CHUNKWRITER_H
#define HUFFMAN_CODING_CHUNKWRITER_H

#include <cstddef>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <ostream>
#include <fstream>
using namespace std;

class chunkwriter {
    unsigned char primary_buffer;
    short space;
    ofstream out;
    public:
        chunkwriter(string output_file);
        void push(vector<bool>& code);
        void close();
};


#endif