//
// Created by Vaishnavi Gupta on 8/4/20.
//

#include "chunkreader.h"
#include <vector>

chunkreader::chunkreader(string input_file) {
    in.open(input_file, ios::in);
    primary_buffer = 0;
    left = 0;
}

vector<bool> chunkreader::get(int n) {
    vector<bool> ans;
    while (n > 0) {
        if (left == 0) {
            char temp;
            in.get(temp);
            primary_buffer = (unsigned char) temp;
            left = 8;
        }

        ans.push_back((primary_buffer & ( 1 << (left - 1) )) >> (left - 1));
        left--;
        n--;
    }
    return ans;
}

unsigned char chunkreader::getChar(int n) {
    vector<bool> b = get(n);
    unsigned char ans = 0;
    for (auto i : b) {
        ans = (ans << 1) + (i?1:0);
    }
    return ans;
}

bool chunkreader::getBit() {
    return get(1)[0];
}

bool chunkreader::hasLeft() {
    return !in.eof();
}

void chunkreader::close() {
    in.close();
}