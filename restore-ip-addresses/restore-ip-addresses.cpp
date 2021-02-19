class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    string ip;
    dfs(0, s, ip, ans);
    return ans;
  }
    
private: 
  void dfs(int d, string s, string ip, vector<string> &ans) {
    int l = s.length();
    if (d == 4) {
      if (l == 0) ans.push_back(ip);
      return;
    }
    
    for (int i = 1; i <= min(3, s[0] == '0' ? 1 : l); i++) {
      string ss = s.substr(0, i);      
      if (i == 3 && stoi(ss) > 255) return;      
      dfs(d + 1, s.substr(i), ip + (d == 0 ? "" : ".") + ss , ans);
    }
  }
};