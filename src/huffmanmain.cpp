/*
 * CS 106X Huffman Encoding
 * This file contains the main program and user interface for running your
 * Huffman Encoder.  It contains a text menu to allow you to test all of the
 * various functions of your program for encoding and decoding data.
 *
 * Please do not modify this provided file. Your turned-in files should work
 * with an unmodified version of all provided code files.
 *
 * Author : Marty Stepp
 * Version: Thu 2013/11/21
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "HuffmanNode.h"
#include "encoding.h"
#include <vector>
#include "huffmanutil.h"

using namespace std;


int main(int argc, char **argv) {
    string invalid = "You have entered an invalid command. Try using --help for instructions.\n\n";
//    while (true) {
//        if (argc == 2 && argv[1]=="--quit");
//        else
    bool quit = false;
    if (argc == 2 && strcmp(argv[1], "--quit")==0) quit = true;
    else if (argc == 5) {
        if (strcmp(argv[1], "--huffman") == 0) {
            if (strcmp(argv[2], "--c") == 0 || strcmp(argv[2], "--compress") == 0) {
                compress(argv[3], argv[4]);
                cout << "File compressed! Enter a new command or use --quit to quit.\n";
            } else if (strcmp(argv[2], "--d") == 0 || strcmp(argv[2], "--decompress") == 0) {
                decompress(argv[3], argv[4]);
                cout << "File decompressed! Enter a new command or use --quit to quit.\n";
            } else cout << invalid;
        } else cout << invalid;
    } else if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        cout << "help :)";
    } else cout << invalid;

    string command;
    while (!quit) {
        getline(cin, command);
//        cin >> command;
//        cout << command;
        istringstream iss(command);
        vector<string> tokens = vector<string>();
//        std::vector<std::string> userInputVec;
//        std::string input;
//        while(cin >> command)
//        {
//            cout << command;
//            tokens.push_back(command);
//        }
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens));
        if (tokens.size() == 1 && tokens[0] == "--quit") break;
        else if (tokens.size() == 4) {
            if (tokens[0] == "--huffman") {
                if (tokens[1] == "--c" || tokens[1] == "--compress") {
                    compress(tokens[2], tokens[3]);
                    cout << tokens[2] << " compressed! Enter a new command or use --quit to quit.\n";
                } else if (tokens[1] == "--d" || tokens[1] == "--decompress") {
                    decompress(tokens[2], tokens[3]);
                    cout << tokens[2] << " decompressed! Enter a new command or use --quit to quit.\n";
                } else cout << invalid;
            } else cout << invalid;
        } else if (tokens.size() == 1 && tokens[0] == "--help") {
            cout << "help :)";
        } else cout << invalid;
    }
//    }
//    compress(R"(C:\Users\fateh\Documents\CS\huffman-coding\res\short.txt)",
//            R"(C:\Users\fateh\Documents\CS\huffman-coding\res\short.huff)");
//    decompress(R"(C:\Users\fateh\Documents\CS\huffman-coding\res\short.huff)",
//             R"(C:\Users\fateh\Documents\CS\huffman-coding\res\dshort.txt)");

//    compress("res/ababcab.txt", "res/out.huff");
//    decompress("res/out.huff", "res/decomp.txt");

//    compress("res/moo.wav", "res/moo.huff");
//    decompress("res/moo.huff", "res/moo_d.wav");

//    compress("res/excellent.wav", "res/excellent.huff");
//    decompress("res/excellent.huff", "res/excellent_d.wav");

//    compress("res/dictionary.txt", "res/dictionary.huff");
//    decompress("res/dictionary.huff", "res/d_dictionary.txt");

//    compress("res/empty.txt", "res/empty.huff");
//    decompress("res/empty.huff", "res/empty_d.txt");

//    compress("res/tomsawyer.txt", "res/tomsawyer.huff");
//    decompress("res/tomsawyer.huff", "res/d_tomsawyer.txt");

//    compress("res/allcharsonce.dat", "res/allcharsonce.huff");
//    decompress("res/allcharsonce.huff", "res/allcharsonce_d.dat");

//    compress("res/hellokitty.bmp", "res/hellokitty.huff");
//    decompress("res/hellokitty.huff", "res/hellokitty_d.bmp");

//    compress("res/dictionary.txt", "res/dictionary.huff");
    // compress("res/bender.jpg", "res/bender.huff");

//   --huffman/lzw --compress/decompress infile outfile

}