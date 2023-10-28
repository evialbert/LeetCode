class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            int distinct  = 0;
            for(int j=i;j<n;j++){
                if(st.find(nums[j])==st.end()){
                    distinct++;
                }
                st.insert(nums[j]);
                ans += (distinct *distinct);
            }
        }
        return ans;
    }
};