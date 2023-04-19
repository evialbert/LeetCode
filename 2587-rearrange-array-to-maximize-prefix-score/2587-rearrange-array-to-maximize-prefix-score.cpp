class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        sort(begin(nums),end(nums),greater<>());
        
        long long sum = 0, res = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > 0)
                res++;
            else
                break;
        }
        
        return res;
    }
};