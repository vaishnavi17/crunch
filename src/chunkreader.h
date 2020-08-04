//
// Created by Vaishnavi Gupta on 8/4/20.
//

#ifndef HUFFMAN_CODING_CHUNKREADER_H
#define HUFFMAN_CODING_CHUNKREADER_H
#include <cstddef>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class chunkreader {
    unsigned char primary_buffer;
    int left;
    ifstream in;
public:
    chunkreader(string input_file);
    vector<bool> get(int n);
    unsigned char getChar(int n);
    bool getBit();
    bool hasLeft();
    void close();
};


#endif //HUFFMAN_CODING_CHUNKREADER_H

