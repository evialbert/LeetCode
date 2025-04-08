class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>st;
        int n=nums.size();

        for(int i=n-1;i>=0;i--){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
            }
            else{
                return ceil(1.0*(i+1)/3);
            }
        }
        return 0;
    }
};