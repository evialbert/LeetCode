class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
      int n=nums.size();
      int sum1=0,sum2=0;
      vector<int>v;
      for(auto x:nums)
      {
          sum1+=x;
      }  
      sort(nums.begin(),nums.end());
      for(int i=n-1;i>=0;i--)
      {
          if(sum2>sum1)
          {
              break;
          }
          else
          {
              sum2+=nums[i];
              v.push_back(nums[i]);
              sum1-=nums[i];
          }
      }
      return v;
    }
};