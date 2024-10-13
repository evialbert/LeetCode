class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int mini=INT_MAX;
            int x=0;
            int j=1;
            while((j<<x)<=nums[i]){
              int m=j<<x;
              if(((nums[i]|m)==nums[i])&&((nums[i]-m)|(nums[i]-m+1))==nums[i]){
                 mini=min(mini,nums[i]-m);
              }
                x++;
            }
            if(mini==INT_MAX){
                ans.push_back(-1);
            }
            else ans.push_back(mini);
            
        }
        return ans;
    }
};