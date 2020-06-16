#include "encoding.h"
#include <unordered_map>
using namespace std;

map<char, int> buildFrequencyTable(istream &input)
{
    map<char, int> freqTable = map<char, int>();
    while (input.peek() != EOF)
    {
        char c;
        input.get(c);
        if (freqTable.find(c) != freqTable.end())
        {
            freqTable[c]++;
        }
        else
            freqTable[c] = 1;
    }
    freqTable[EOF] = 1;
    return freqTable;
}

HuffmanNode *buildEncodingTree(const map<int, int> &freqTable)
{
    // TODO: implement this function
    return NULL;
}

map<char, string> buildEncodingMap(HuffmanNode *encodingTree)
{
    // TODO: implement this function
    map<char, string> encodingMap;
    return encodingMap;
}

// void encodeData(istream &input, const map<int, string> &encodingMap, obitstream &output)
// {
//     // TODO: implement this function
// }

// void decodeData(ibitstream &input, HuffmanNode *encodingTree, ostream &output)
// {
//     // TODO: implement this function
// }

// void compress(istream &input, obitstream &output)
// {
//     // TODO: implement this function
// }

// void decompress(ibitstream &input, ostream &output)
// {
//     // TODO: implement this function
// }

void freeTree(HuffmanNode *node)
{
    // TODO: implement this function
}
