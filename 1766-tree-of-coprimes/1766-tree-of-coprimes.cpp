class Solution {
public:
  vector<vector<int>> adjList;
  vector<int> res;
  vector<stack<pair<int, int>>> lowest;
  vector<vector<int>> coprimes;
  vector<bool> visited;
  
  vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
    if (coprimes.empty()) {
      fillCoprimes();
    }
    
    lowest.resize(51);
    buildAdjList(edges, nums.size());
    res.resize(nums.size(), -1);
    visited.resize(nums.size(), false);
    traverse(0, 0, nums);
    return res;
  }
  
  bool coprime(int a, int b) {
    while (a > 1 && b > 1) {
      if (a == b)
        return false;
      if (a > b)
        a = a % b;
      else 
        b = b % a;
    }  
    
    if (a == 0 || b == 0)
      return false;
    return true;
  }
  
  void fillCoprimes() {
    coprimes.resize(51);
    for (int i = 1; i <= 50; ++i) {
      for (int j = i; j <= 50; ++j) {
        if (coprime(i, j)) {
          coprimes[i].push_back(j);
          coprimes[j].push_back(i);
        }
      }
    }
  }
  
  void buildAdjList(const vector<vector<int>>& edges, int n) {
    adjList.resize(n);
    for (const auto& e : edges) {
      adjList[e[0]].push_back(e[1]);
      adjList[e[1]].push_back(e[0]);
    }
  }
  
  void traverse(int k, int depth, const vector<int>& nums) {
    visited[k] = true;
    int bestDepth = -1;
    int bestCo = -1;
    
    for (int co : coprimes[nums[k]]) {
      if (lowest[co].empty())
        continue;
      auto closest = lowest[co].top();
      if (closest.second > bestDepth) { // second is depth
        bestDepth = closest.second;
        bestCo = closest.first;
      }
    }
    
    res[k] = bestCo;
    lowest[nums[k]].push({k, depth});
    
    for (int child : adjList[k])
      if (!visited[child])
      traverse(child, depth + 1, nums);
    
    lowest[nums[k]].pop();
  }
};