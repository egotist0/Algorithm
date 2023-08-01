#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Trie {
 private:
  struct Node {
    vector<Node*> children;
    bool isWord;
    Node() : children(26, nullptr), isWord(false) {}
    ~Node() {
      for (auto& child : children) delete child;
    }
  };

  Node* root;

 public:
  Trie() { this->root = new Node(); }

  void insert(string word) {
    Node* p = root;
    for (const auto& c : word) {
      int i = c - 'a';
      if (!p->children[i]) p->children[i] = new Node();
      p = p->children[i];
    }
    p->isWord = true;
  }

  bool search(string word) {
    Node* p = root;
    for (const auto& c : word) {
      int i = c - 'a';
      if (!p->children[i]) return false;
      p = p->children[i];
    }
    return p->isWord;
  }

  bool startsWith(string prefix) {
    Node* p = root;
    for (const auto& c : prefix) {
      int i = c - 'a';
      if (!p->children[i]) return false;
      p = p->children[i];
    }
    return true;
  }
};

// int main() {
//   vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
//   Solution s;
//   int res = s.minCostConnectPoints(points);
//   cout << res << endl;
//   return 0;
// }
