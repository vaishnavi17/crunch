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
#include "huffmanutil.h"
using namespace std;

const bool SHOW_TREE_ADDRESSES = false;   // set to true to debug tree pointer issues
const string DEFAULT_COMPRESSED_FILE_EXTENSION = ".huf";
const string DEFAULT_DECOMPRESSED_FILE_EXTENSION = ".txt";

// function prototype declarations; see definitions below for documentation
static void intro();
static string menu();
static istream* openInputStream(string data, bool isFile, bool isBits = false);
static istream* openStringOrFileInputStream(string& data, bool& isFile, bool isBits = false);

int main() {
    intro();

    // these variables maintain state between steps 1-4
    string data;
    bool isFile = false;
    HuffmanNode* encodingTree = NULL;
    map<int, int> freqTable;
    map<int, string> encodingMap;

    // prompt user for options repeatedly
    while (true) {
        string choice = menu();
        if (choice == "Q") {
            break;
        }
//        else if (choice == "1") {
//            test_buildFrequencyTable(freqTable, data, isFile);
//        } else if (choice == "2") {
//            test_buildEncodingTree(freqTable, encodingTree);
//        } else if (choice == "3") {
//            test_buildEncodingMap(encodingTree, encodingMap);
//        } else if (choice == "4") {
//            test_encodeData(encodingMap, data, isFile);
//        } else if (choice == "5") {
//            test_decodeData(encodingTree);
//        } else if (choice == "C") {
//            test_compress();
//        } else if (choice == "D") {
//            test_decompress();
//        } else if (choice == "B") {
//            test_binaryFileViewer();
//        } else if (choice == "T") {
//            test_textFileViewer();
//        } else if (choice == "S") {
//            test_sideBySideComparison();
//        } else if (choice == "F") {
//            test_freeTree(encodingTree);
//            encodingTree = NULL;
//        }
    }

    cout << "Exiting." << endl;
    return 0;
}

/*
 * Sets up the output console and explains the program to the user.
 */
static void intro() {
//    setConsoleSize(850, 550);
//    setConsoleFont("Monospaced-Bold-16");
//    setConsoleEcho(true);
//    setConsolePrintExceptions(true);

    cout << "Welcome to CS 106X Shrink-It!" << endl;
    cout << "This program uses the Huffman coding algorithm for compression." << endl;
    cout << "Any file can be compressed by this method, often with substantial" << endl;
    cout << "savings. Decompression will faithfully reproduce the original." << endl;
}

/*
 * Prints a menu of choices for the user and reads/returns the user's response.
 */
static string menu() {
    cout << endl;
    cout << "1) build character frequency table" << endl;
    cout << "2) build encoding tree" << endl;
    cout << "3) build encoding map" << endl;
    cout << "4) encode data" << endl;
    cout << "5) decode data" << endl;
    cout << endl;
    cout << "C) compress file" << endl;
    cout << "D) decompress file" << endl;
    cout << "F) free tree memory" << endl;
    cout << endl;
    cout << "B) binary file viewer" << endl;
    cout << "T) text file viewer" << endl;
    cout << "S) side-by-side file comparison" << endl;
    cout << "Q) quit" << endl;

    cout << endl;
//    changed stanford getLine to getline
// TODO: implement trim and to uppercase
    string choice;
    getline(cin, choice);
//    string choice = toUpperCase(trim(getline("Your choice? ")));
    return choice;
}