#include "encoding.h"
using namespace std;

Map<char, int> buildFrequencyTable(istream& input) {
    Map<char, int> freqTable = unordered_map<char, int>();
    while (input.peek() != EOF) {
        char c;
        input.get(c);
        if (freqTable.find(c) != mymap.end()) {
            freqTable[c]++;
        }
        else freqTable[c] = 1;
    }  
    freqTable[EOF] = 1;
    return freqTable;
}

HuffmanNode* buildEncodingTree(const Map<int, int>& freqTable) {
    // TODO: implement this function
    return NULL;   // this is just a placeholder so it will compile
}

Map<int, string> buildEncodingMap(HuffmanNode* encodingTree) {
    // TODO: implement this function
    Map<int, string> encodingMap;   // this is just a placeholder so it will compile
    return encodingMap;             // this is just a placeholder so it will compile
}

void encodeData(istream& input, const Map<int, string>& encodingMap, obitstream& output) {
    // TODO: implement this function
}

void decodeData(ibitstream& input, HuffmanNode* encodingTree, ostream& output) {
    // TODO: implement this function
}

void compress(istream& input, obitstream& output) {
    // TODO: implement this function
}

void decompress(ibitstream& input, ostream& output) {
    // TODO: implement this function
}

void freeTree(HuffmanNode* node) {
    // TODO: implement this function
}
