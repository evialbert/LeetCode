class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
       int maxi, sum=0;
       for(int i = 0 ; i < nums.size(); i++)  
            sort(nums[i].begin(), nums[i].end());
            
       
int n = nums[0].size();
for(int i = 0; i<n; i++)
{
    maxi  =INT_MIN;
    for(int j = 0; j<nums.size(); j++)
    {
        if(nums[j][i]>maxi)
            maxi = nums[j][i];
    }
    sum += maxi;
}

        return sum;
    }
};