#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1032;

/*
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
*/

void test1()
{

  Trie trie;

  trie.insert("apple");
  cout << "Expect to see 1: " << trie.search("apple") << endl;   // returns true
  cout << "Expect to see 0: " << trie.search("app") << endl;     // returns false
  cout << "Expect to see 1: " << trie.startsWith("app") << endl; // returns true
  trie.insert("app");
  cout << "Expect to see 1: " << trie.search("app") << endl; // returns true
}

main()
{
  test1();

  return 0;
}