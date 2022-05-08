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
  - root node is a dummy node. Prefixes
    start from root->next[idx]
*/

void Trie::insert(string s)
{
  auto visit = root;
  for (auto c : s)
  {
    auto idx = c - 'a';
    if (visit->next[idx] == nullptr)
      visit->next[idx] = new Node();
    visit = visit->next[idx];
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
    visit = visit->next[idx];
    if (visit == nullptr && i < n - 1)
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
    visit = visit->next[idx];
    if (visit == nullptr && i < n - 1)
      return false;
  }
  return true;
}