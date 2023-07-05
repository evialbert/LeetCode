class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0 , j=0;
        int c=0;
        int len = 0;
        while(i<=j && j < nums.size()){
            if(nums[j]==0 && c==0){
                j++;
                c=1;
            }
            else if(nums[j] == 1)
                j++;
            
            else if(nums[j] == 0 && c==1){
                while(i<=j && nums[i]!=0) i++;
                i++;
                j++;
            }
            len  = max(len, j-i);
        }
        len  = max(len, j-i);
        return len-1;
    }
};