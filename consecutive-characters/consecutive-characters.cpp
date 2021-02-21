class Solution {
public:
  int maxPower(string s) {
    char p = '?';
    int ans = 0;
    int cur = 0;
    for (char c : s) {
      if (c != p) cur = 0;      
      p = c;
      ans = max(ans, ++cur);
    }
    return ans;
  }
};