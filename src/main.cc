#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
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
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    for (const auto& t : times) graph[t[0] - 1].emplace_back({t[1] - 1, t[2]});
    vector<int> dis(n, 6001);
    vector<bool> vis(n, false);
    dis[k] = 0;
    for (int i = 0; i < n; i++) {
      int u = -1, MIN = 6001;
      for (int j = 0; j < n; j++) {
        if (!vis[j] && dis[j] < MIN) {
          u = j;
          MIN = dis[j];
        }
      }
      if (u == -1) break;
      vis[u] = true;
      for (const auto& node : graph[u]) {
        if (vis[node.first] == false)
          dis[node.first] = min(dis[node.first], dis[u] + node.second);
      }
    }
    return *max_element(dis.begin(), dis.end());
  }
};
