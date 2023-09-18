class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<20;j++){
                if(((1<<j)&i)>0) cnt++;
            }
            if(cnt==k) ans+=nums[i];
        }
        return ans;
    }
};