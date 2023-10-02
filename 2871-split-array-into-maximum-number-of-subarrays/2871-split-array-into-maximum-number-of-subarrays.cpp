class Solution {
public:
    int countSubarraysWithBitwiseAndZero(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0] , count = 0 ;
        for(int i = 1 ; i < nums.size() ; i++){
            if(prev == 0){
                count++ ;
                prev = nums[i] ;
            }else{
                prev = prev&nums[i] ;
            }
        }
        if(prev == 0) count++;
        return count ;
    }

    int maxSubarrays(vector<int>& nums) {
        int minAnd = nums[0] ;
        for(auto x : nums) minAnd = minAnd&x ;
        
        if(minAnd != 0) return 1 ;
        return countSubarraysWithBitwiseAndZero(nums) ;
        
    }
};