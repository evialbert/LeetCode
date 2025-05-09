class Solution {
  public:
    int uniqueXorTriplets(vector<int>& nums) {
      vector<int> st(2048);
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
          st[nums[i] ^ nums[j]] = 1;
        }
      }
      int result = 0;
      for (int i = 0; i < 2048; i += 1) {
        for (int j = 0; j < nums.size(); j++) {
          if (st[i ^ nums[j]]) {
            result += 1;
            break;
          }
        }
      }
      return result;
    }
  };