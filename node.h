#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol1032
{
    struct Node
    {
        vector<Node *> chars;
        bool isWord;
        Node() : isWord(false), chars(vector<Node *>(26, nullptr)){};
    };
}
#endif