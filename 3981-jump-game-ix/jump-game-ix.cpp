class Solution {
public:
    static vector<int> maxValue(vector<int>& nums) {
        const int n=nums.size();
        vector<int> prefMax(n), sufMin(n);
        prefMax[0]=nums[0];
        sufMin[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            const int x=nums[i], y=nums[n-1-i];
            prefMax[i]=max(prefMax[i-1], x);
            sufMin[n-1-i]=min(sufMin[n-i], y);
        }
        vector<int> ans(n);
        ans[n-1]=prefMax[n-1];
        for(int i=n-2; i>=0; i--){
            if (prefMax[i]>sufMin[i+1]) 
                ans[i]=max(prefMax[i], ans[i+1]);
            else ans[i]=prefMax[i];
        }
        return ans;
    }
};