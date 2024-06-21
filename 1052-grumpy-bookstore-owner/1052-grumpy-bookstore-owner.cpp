class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = grumpy.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
      if (!grumpy[i]) {
        total += customers[i];
      }
    }
    int cur = 0;
    for (int i = 0; i < minutes; i++) {
      if (grumpy[i]) {
        cur += customers[i];
      }
    }
    int ans = total + cur;
    for (int i = minutes; i < n; i++) {
      cur += grumpy[i] * customers[i];
      cur -= grumpy[i - minutes] * customers[i - minutes];
      ans = max(ans, total + cur);
    }
    return ans;
  }
};