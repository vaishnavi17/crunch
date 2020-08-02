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
//    cout << "push called" << '\n';
    int n = code.size();
    unsigned char mask = 0;

    for (int i = 0; i < min(n, space); i++) {
        mask = (mask << 1) + (code[i] ? 1 : 0);
    }
//    cout << "space left " << space << '\n';
//    cout << "mask " << +mask << '\n';
    int done;
    if (n >= space) {
        done = space;
        out.put(primary_buffer + mask);
        primary_buffer = 0;
        space = 8;
    } else {
        done = n;
        primary_buffer += mask << (space - n);
        space -= n;
    }

//    cout << "done " << done << '\n' << "n " << n << '\n';
    while (done < n) {
//        cout << "done is less than n" << '\n';
        mask = 0;
        for (int j = done ; j < min(done + 8, n); j++) {
            mask = (mask << 1) + (code[j] ? 1 : 0);
        }
//        cout << "mask " << +mask << '\n';
        if (done + 8 <= n) {
            out.put(mask);
        }
        else {
            primary_buffer += mask << (8 + done - n);
            space -= (n - done);
//            cout << "primary buff " << +primary_buffer << '\n';
        }
        done +=8;
    }
}

void chunkwriter::pushByte(unsigned char b) {
    vector<bool> slot(8, 0);
    int i = 0;
    while (b > 0) {
        slot[7-i] = b % 2;
        b >>= 1;
        i++;
    }
    push(slot);
}

void chunkwriter::close() {
    out.put(primary_buffer);
    out.close();
}