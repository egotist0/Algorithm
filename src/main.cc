#include <algorithm>
#include <climits>
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

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    const int n = points.size();
    int res = 0;
    vector<int> dis(n, INT_MAX);
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        graph[i][j] =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    priority_queue<int, vector<int>, greater<>> minHeap;
    minHeap.emplace(0);
    dis[0] = 0;
    while (!minHeap.empty()) {
      const auto index = minHeap.top();
      minHeap.pop();
      res += dis[index];
      for (int i = 0; i < n; i++) {
        if (graph[index][i] < dis[i]) {
          dis[i] = graph[index][i];
          minHeap.emplace(i);
        }
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};
  Solution s;
  int res = s.minCostConnectPoints(points);
  cout << res << endl;
  return 0;
}