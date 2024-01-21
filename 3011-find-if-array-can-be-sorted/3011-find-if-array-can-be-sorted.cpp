class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int count = __builtin_popcount(nums[i]);
            v[i]=count;
        }
        int i=0;
        while(i<nums.size()){
            int j=i;
            while(j<nums.size() && v[i]==v[j]){
                j++;
            }
            sort(nums.begin()+i,nums.begin()+j);
            i=j;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        
        return true;
    }
};