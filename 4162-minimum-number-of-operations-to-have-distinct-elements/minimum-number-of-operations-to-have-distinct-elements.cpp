class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        int idx = -1;
        for(int i=n-1;i>=0;i--){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
            }else{
                idx = i;
                break;
            }
        }
        if(idx == -1){
            return 0;
        }
        idx++;
        return (idx/3+(idx%3==0?0:1));
    }
};