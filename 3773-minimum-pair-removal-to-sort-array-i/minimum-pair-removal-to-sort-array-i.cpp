class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(true) 
        {
            vector<int> temp = nums;
            sort(temp.begin(),temp.end());
            if(nums==temp) return ans;
            vector<vector<int>> arr;
            for(int i=0; i<nums.size()-1; i++) 
            {
                int x = nums[i] + nums[i+1];
                arr.push_back({x,i});
            }
            sort(arr.begin(), arr.end());
            int sum = arr[0][0];
            int idx = arr[0][1];
            nums[idx] = sum;
            nums.erase(nums.begin()+idx+1);
            ans++;
        }
        return ans;
    }
};