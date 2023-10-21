class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i=0,j=0;

        while(i < n){
            nums[j] = nums[i];
            j++;
            while(i < n-1 && nums[i] == nums[i+1]){
                i++;
            }
            
            i++;
        }


        return j;
    }
};