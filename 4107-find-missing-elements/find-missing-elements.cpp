class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size() , i , j;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        
        i = 0 , j = 1;
        while(i < n-1){
            if(nums[i]+1 != nums[j]){
                int k = nums[i]+1;
                while(k != nums[j]){
                    ans.push_back(k++);
                }
            }
            i++;
            j++;
        }
        return ans;
    }
};