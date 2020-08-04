#include "encoding.h"
#include <functional>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

void print_state (const std::ios& stream) {
    std::cout << " good()=" << stream.good();
    std::cout << " eof()=" << stream.eof();
    std::cout << " fail()=" << stream.fail();
    std::cout << " bad()=" << stream.bad() << '\n';
}

unordered_map<unsigned char, int> buildFrequencyTable(istream &input)
{
    unordered_map<unsigned char, int> freqTable = unordered_map<unsigned char, int>();
    while (input.peek() != EOF)
    {
        unsigned char c;
        c = input.get();
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

HuffmanNode *buildEncodingTree(const unordered_map<unsigned char, int> &freqTable)
{
    auto compare = [](HuffmanNode* a, HuffmanNode* b) { return a->count > b->count; };
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, decltype(compare)> pq(compare);
    for (auto node : freqTable) {
        HuffmanNode* temp = new HuffmanNode(node.first, node.second, NULL, NULL);
        pq.push(temp);
    }
    if (pq.empty()) return NULL;
    while (pq.size()>1) {
        HuffmanNode* t1 = pq.top();
        pq.pop();
        HuffmanNode* t2 = pq.top();
        pq.pop();
        HuffmanNode* n = new HuffmanNode(-1, t1->count + t2->count, t1, t2);
        pq.push(n);
    }
    return pq.top();
}

string tostr(vector<bool>& vec) {
    string ans = "";
    for (bool i : vec) {
        ans+= (i?"1":"0");
    }
    return ans;
}

vector<bool> convertInts(int size, int seq) {
    vector<bool> arr = vector<bool>(size, 0);
    for (int i = size-1; i >=0; i--) {
        arr[i]=(seq%2);
        seq/=2;
    }
    return arr;
}

int codeToPos(vector<bool>& code) {
    int pos = 0;
    for (bool i : code) {
        pos = (pos<<1) + (i ? 2 : 1);
    }
    return pos;
}
void dfs(HuffmanNode *Tree, int size, int seq, unordered_map<unsigned char, vector<bool>> &encodingMap) {
    if (Tree->isLeaf()) {
        auto c = convertInts(size, seq);
        encodingMap[Tree->character] = c;
    }
    else {
        dfs(Tree->one, size + 1, (seq<<1) + 1, encodingMap);
        dfs(Tree->zero, size + 1, seq<<1, encodingMap);
    }
}

unordered_map<unsigned char, vector<bool>> buildEncodingMap(HuffmanNode *encodingTree)
{
    unordered_map<unsigned char, vector<bool>> encodingMap;
    dfs(encodingTree, 0, 0, encodingMap);
    return encodingMap;
}

void writeHeader(chunkwriter& out, unordered_map<unsigned char, vector<bool>>& encodingMap) {
    out.pushByte(encodingMap.size()-1);
    for (auto i : encodingMap) {
        if (i.first != 255) {
            out.pushByte(i.first);
            out.pushByte(i.second.size());
            out.push(i.second);
        }
    }
}

 void compress(string input_file, string output_file)
 {
     ifstream inp;
     inp.open(input_file, ios::in);
     HuffmanNode* tree = buildEncodingTree(buildFrequencyTable(inp));
     auto encodingMap = buildEncodingMap(tree);

     for (auto i : encodingMap) {
         cout << i.first << ' ' << tostr(i.second) << '\n';
     }
     inp.close();

     chunkwriter out = chunkwriter(output_file);
     writeHeader(out, encodingMap);
     inp.open(input_file, ios::in);
     while (inp.peek() != EOF)
     {
         unsigned char c;
         c = inp.get();
         out.push(encodingMap.at(c));
     }
     out.push(encodingMap.at(EOF));
     inp.close();
     out.close();
     freeTree(tree);
 }


 void decompress(string input_file, string output_file)
 {
     chunkreader inp = chunkreader(input_file);
     unsigned char num = inp.getChar(8);
     cout << "size: " << +num << endl;
     unordered_map<int, unsigned char> encodingMap;
     char character;
     unsigned char size = 0;
     vector<bool> code;
     for (int i = 0; i < num; i++) {
         character = inp.getChar(8);
         size = inp.getChar(8);
         code = inp.get(size);
         int pos = codeToPos(code);
         encodingMap[pos] = character;
     }

     ofstream out;
     out.open(output_file, ios::out);

     int curr = 0;
     unsigned char decoded;
     while (inp.hasLeft()) {
         curr<<=1;
         curr += (inp.getBit() ? 2 : 1);
         auto decoded = encodingMap.find(curr);
         if (decoded != encodingMap.end()) {
             out.put(encodingMap[curr]);
             curr = 0;
         }
     }
     out.close();
     inp.close();
 }

void freeTree(HuffmanNode *node)
{
    if (node == NULL) return;
    freeTree(node->zero);
    freeTree(node->one);
    delete node;
}
