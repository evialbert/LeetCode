class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            prefix.push_back(prefix[i-1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return prefix[right];
        }
        return prefix[right] - prefix[left-1];
    }
};