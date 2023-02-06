class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> arr;
        int z=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        arr = nums;
        for(auto it : arr){
            if(it==0) z++;
        }
        vector<int> t;
        for(auto it : arr) if(it!=0) t.push_back(it);
        for(int i=0;i<z;i++){
            t.push_back(0);
        }
        return t;
    }
};