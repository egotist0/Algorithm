#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>
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

class Solution {
 private:
  int n;
  vector<vector<string>> res;
  void dfs(int u, vector<string>& g, vector<bool>& col, vector<bool>& djx,
           vector<bool>& fdjx) {
    if (u == n) {
      res.emplace_back(g);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!col[i] && !djx[u + i] && !fdjx[n - u + i]) {
        g[u][i] = 'Q';
        col[i] = djx[u + i] = fdjx[n - u + i] = true;
        dfs(u + 1, g, col, djx, fdjx);
        col[i] = djx[u + i] = fdjx[n - u + i] = false;
        g[u][i] = '.';
      }
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    int N = 20;
    vector<string> g(n, string(n, '.'));
    vector<bool> col(N), djx(N), fdjx(N);

    dfs(0, g, col, djx, fdjx);
    return res;
  }
};

int main() {
  Solution tmp;
  vector<int> v1{1, 2, 3, 4, 5};
  vector<int> v2{3, 4, 5, 1, 2};
  int res = tmp.canCompleteCircuit(v1, v2);
  cout << res << "1" << endl;
  return 0;
}
