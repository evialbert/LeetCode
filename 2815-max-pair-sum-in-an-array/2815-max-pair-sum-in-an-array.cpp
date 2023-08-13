class Solution {
  int maxDigit(int num) {
    int res = 0;
    while (num != 0) {
      res = max(res, num % 10);
      num /= 10;
    }
    return res;
  }

public:
  int maxSum(vector<int>& nums) {
    int res = -1;
    // map<max digit, max num>
    int mp[10] = {};
    for (int num : nums) {
      int d = maxDigit(num);
      if (mp[d] != 0) {
        // updating the result.
        res = max(res, num + mp[d]);
      }

      // memorizing current number for the next iteration
      mp[d] = max(mp[d], num);
    }
    return res;
  }
};