/*
 * CS 106X Huffman Encoding
 * This file implements the members of the HuffmanNode structure that you will
 * use in your Huffman encoding tree.  See HuffmanNode.h for documentation of
 * each member.
 *
 * Please do not modify this provided file. Your turned-in files should work
 * with an unmodified version of all provided code files.
 *
 * Author : Marty Stepp
 * Version: Thu 2013/11/14
 */

#include <cctype>
#include "HuffmanNode.h"
#include "huffmanutil.h"
using namespace std;

static void printHuffmanNode(ostream& out, const HuffmanNode& node, bool showAddress = false);

HuffmanNode::HuffmanNode(short character, int count, HuffmanNode* zero, HuffmanNode* one) {
    this->character = character;
    this->count = count;
    this->zero = zero;
    this->one = one;
}

bool HuffmanNode::isLeaf() const {
    return zero == NULL && one == NULL;
}

