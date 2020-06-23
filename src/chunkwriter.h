//
// Created by Vaishnavi Gupta on 6/23/20.
//

#ifndef HUFFMAN_CODING_CHUNKWRITER_H
#define HUFFMAN_CODING_CHUNKWRITER_H

#include <cstddef>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>
#include <ostream>
using namespace std;

class chunkwriter {
    public:
        chunkwriter(ostream &output);
        void push(vector<bool>& code);
};


#endif