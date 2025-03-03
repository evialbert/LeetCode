class Solution {
public:

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int  i = 0, j = n-1, st = 0, e = n-1;
        vector<int> ans (n, 0);

        while(i < n){
            if(nums[i] < pivot){
                ans[st] = nums[i];
                st++;
            }
            if(nums[j] > pivot){
                ans[e] = nums[j];
                e--;
            }
            i++; j--;
        }

        while(st <= e)
        ans[st++] = pivot;
        
        return ans;
    }
};