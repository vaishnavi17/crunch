//
// Created by Vaishnavi Gupta on 6/23/20.
//

#include "chunkwriter.h"
#include <vector>

chunkwriter::chunkwriter(string output_file) {
    out.open(output_file, ios::out);
    primary_buffer = 0;
    space = 8;
}

void chunkwriter::push(vector<bool> &code) {
    unsigned char mask = 0;
    for (bool i : code) {
        mask = (mask << 1) + (i ? 1 : 0);
    }
    if (code.size() >= space) {
        out.put(primary_buffer + (mask >> (code.size() - space)));
        primary_buffer = mask % (1 << (code.size() - space));
        space += 8 - code.size();
    } else {
        primary_buffer += mask << (space - code.size());
        space -= code.size();
    }
}

void chunkwriter::close() {
    out.put(primary_buffer);
    out.close();
}