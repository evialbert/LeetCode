class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0 ; i<nums.size() ; i++){
            if(st.find(nums[i]) != st.end()){
                return true;
            }
            else{
                st.insert(nums[i]);
            }
        }
        return false;
    }
};