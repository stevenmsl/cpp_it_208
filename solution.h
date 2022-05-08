
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol1032
{

  class Trie
  {
  private:
    Node *root = new Node();

  public:
    void insert(string s);
    bool search(string key);
    bool startsWith(string prefix);
  };

  class Solution
  {
  private:
  public:
  };
}
#endif