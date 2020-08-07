#include <algorithm>
#include <iostream>
#include <string>

#include "encoding.h"
#include <vector>

using namespace std;


int main(int argc, char **argv) {
    string invalid = "You have entered an invalid command. Try using --help for instructions.\n\n";
    string help = "Welcome to Crunch!\n\nTo compress or decompress a file, use this format:\n[compression method tag]"
                  " [compress/decompress tag] [input file path] [output file path]\n\nCompression method tags: Use "
                  "--huffman for Huffman Coding, and --lzw for the LZW algorithm.\n"
                  "Compress/decompress tags: Use --c or --compress to compress, and --d or --decompress to decompress.\n\n"
                  "To quit Crunch, use --q or --quit.\n\nTo display this help menu again, use --help.\n\n";
    bool quit = false;
    if (argc == 2 && (strcmp(argv[1], "--quit")==0 || strcmp(argv[1], "--q")==0)) quit = true;
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
        cout << help;
    } else cout << invalid;

    string command;
    while (!quit) {
        getline(cin, command);
        istringstream iss(command);
        vector<string> tokens = vector<string>();
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens));
        if (tokens.size() == 1 && (tokens[0] == "--quit" || tokens[0] == "--q")) break;
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
            cout << help;
        } else cout << invalid;
    }
}