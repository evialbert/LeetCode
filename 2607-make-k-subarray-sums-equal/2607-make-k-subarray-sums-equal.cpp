class Solution {
public:
    
    long long solve(vector<int> nums){
        long long sum = 0;
        if(nums.size()==0) return 0;
        sort(begin(nums),end(nums));
        int k = nums.size();
        sum = nums[k/2];
        long long ans = 0;
        for(auto it:nums)
            ans += abs(sum-it);
        return ans;
    }
    
    long long makeSubKSumEqual(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        set<int> st;
        for(int i=0; i<=min(k,n-1); ++i){
            vector<int> arr;
            int j = i;
            while(st.find(j) == st.end()){
                st.insert(j);
                arr.push_back(nums[j]);
                j = (j+k)%n;
            }
            ans += solve(arr);
        }
        return ans;
    }
};