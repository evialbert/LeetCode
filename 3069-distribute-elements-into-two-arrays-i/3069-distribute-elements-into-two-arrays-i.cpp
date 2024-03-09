class Solution {
public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> v1, v2;
    v1.push_back(nums[0]);
    v2.push_back(nums[1]);

    for(int i = 2; i != nums.size(); i++)
      v1.back() >= v2.back() ? v1.push_back(nums[i]) : v2.push_back(nums[i]);

    for(int n : v2) v1.push_back(n);

    return v1;     
  }
};