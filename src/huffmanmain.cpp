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


int main() {
    encodeData("res/ababcab.txt", "res/out.huff");
    encodeData("res/hellokitty.bmp", "res/hellokitty.huff");
    encodeData("res/dictionary.txt", "res/dictionary.huff");
}