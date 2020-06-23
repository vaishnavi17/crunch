//
// Created by Vaishnavi Gupta on 6/23/20.
//

#ifndef HUFFMAN_CODING_CHUNKREADER_H
#define HUFFMAN_CODING_CHUNKREADER_H


#include <cstddef>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>
#include <ostream>
#include <istream>
using namespace std;

class chunkreader {

public:
    chunkreader(istream &input);
    vector<bool>& get();
};


#endif