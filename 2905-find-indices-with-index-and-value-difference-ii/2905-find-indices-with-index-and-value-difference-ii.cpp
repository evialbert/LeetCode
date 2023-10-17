class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
       int maxidx=0;
        int n = nums.size();
        for(int i=0 ; i<n-indexDifference ; i++){
             if(nums[i]>nums[maxidx]) maxidx = i;
            if(abs(nums[maxidx] - nums[i+indexDifference]) >= valueDifference) return {maxidx,i+indexDifference};
           
        }   
        int minidx=0;
        for(int i=0 ; i<n-indexDifference ; i++){
            if(nums[i]<nums[minidx]) minidx = i;
            if(abs(nums[minidx] - nums[i+indexDifference]) >= valueDifference) return {minidx,i+indexDifference};
            
        }   
        return {-1,-1};
    }
};