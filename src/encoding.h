/*
 * CS 106X Huffman Encoding
 * This file declares the functions that you will need to write in this
 * assignment for your Huffman Encoder in huffmanencoding.cpp.
 *
 * Please do not modify this provided file. Your turned-in files should work
 * with an unmodified version of all provided code files.
 *
 * Author : Marty Stepp
 * Version: Thu 2013/11/14
 */

#ifndef _encoding_h
#define _encoding_h

#include <unordered_map>
#include <iostream>
#include <string>
#include "HuffmanNode.h"
#include "chunkwriter.h"
#include "chunkreader.h"
using namespace std;

/*
 * See huffmanencoding.cpp for documentation of these functions
 * (which you are supposed to write, based on the spec).
 */
unordered_map<unsigned char, int> buildFrequencyTable(istream &input);
HuffmanNode *buildEncodingTree(const unordered_map<unsigned char, int> &freqTable);
unordered_map<short, vector<bool>> buildEncodingMap(HuffmanNode *encodingTree);
void writeHeader(chunkwriter& out, unordered_map<short, vector<bool>>& encodingMap);
void compress(string input_file, string output_file);
// void decodeData(ibitstream &input, HuffmanNode *encodingTree, ostream &output);
void decompress(string input_file, string output_file);
 void freeTree(HuffmanNode *node);

#endif
