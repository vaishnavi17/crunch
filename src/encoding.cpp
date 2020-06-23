#include "encoding.h"
#include <unordered_map>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

map<int, int> buildFrequencyTable(istream &input)
{
    map<int, int> freqTable = map<int, int>();
    while (input.peek() != EOF)
    {
        char c;
        input.get(c);
        if (freqTable.find(c) != freqTable.end())
        {
            freqTable[c]--;
        }
        else
            freqTable[c] = -1;
    }
    freqTable[EOF] = -1;
    return freqTable;
}

HuffmanNode *buildEncodingTree(const map<int, int> &freqTable)
{
    auto compare = [](HuffmanNode a, HuffmanNode b) { return a.count > b.count; };
    priority_queue<HuffmanNode, vector<HuffmanNode>, decltype(compare)> pq(compare);
    for (auto node : freqTable) {
        HuffmanNode temp = HuffmanNode(node.first, node.second, NULL, NULL);
        pq.push(temp);
    }
    if (pq.empty()) return NULL;
    while (pq.size()>1) {
        HuffmanNode t1 = pq.top();
        pq.pop();
        HuffmanNode t2 = pq.top();
        pq.pop();
        HuffmanNode n = HuffmanNode(-1, t1.count + t2.count, &t1, &t2);
        pq.push(n);
    }
    static HuffmanNode ans = pq.top();
    return &ans;
}

string convertVector(int size, int seq) {
    char arr[size+1];
    arr[size] = '\0';
    for (int i = size-1; i >=0; i--) {
        arr[i] = seq%2;
        seq/=2;
    }
    return arr;
}

vector<bool>& convertInts(int size, int seq) {
    vector<bool> arr(size);
    for (int i = size-1; i >=0; i--) {
        arr[i] = seq%2;
        seq/=2;
    }
    return arr;
}

void dfs(HuffmanNode *Tree, int size, int seq, map<int, vector<bool>> &encodingMap) {
    if (Tree->isLeaf()) {
        encodingMap[Tree->character] = convertInts(size, seq);
    }
    else {
        dfs(Tree->one, size + 1, (seq<<1) + 1, encodingMap);
        dfs(Tree->zero, size + 1, seq<<1, encodingMap);
    }
}

map<int, vector<bool>> buildEncodingMap(HuffmanNode *encodingTree)
{
    map<int, vector<bool>> encodingMap;
    dfs(encodingTree, 0, 0, encodingMap);
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
