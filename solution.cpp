#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>
using namespace sol1032;
using namespace std;

/*takeaways
  - build a Trie tree

*/

void Trie::insert(string s)
{
  auto visit = root;
  for (auto c : s)
  {
    auto idx = c - 'a';
    if (visit->chars[idx] == nullptr)
      visit->chars[idx] = new Node();
    visit = visit->chars[idx];
  }
  visit->isWord = true;
}
bool Trie::search(string key)
{
  int n = key.size();
  auto visit = root;
  /*
    - root->a->p->p->l->e
    - the prefix starts from root->next[idx] not root!
  */
  for (auto i = 0; i < n; i++)
  {
    auto idx = key[i] - 'a';
    /* why we move to the visit->chars[idx] first?
       - visit needs to point to the last char in the
         key after we exit the loop so we can access
         the isWord property associated with the last
         char node
    */
    visit = visit->chars[idx];
    if (visit == nullptr)
      return false;
  }
  return visit->isWord;
}
bool Trie::startsWith(string prefix)
{
  int n = prefix.size();
  auto visit = root;
  for (auto i = 0; i < n; i++)
  {
    auto idx = prefix[i] - 'a';
    visit = visit->chars[idx];
    if (visit == nullptr)
      return false;
  }
  return true;
}