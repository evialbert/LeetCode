class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();

        int lessthan[n+1][n+1];
        for(int i = 0; i <= n; i++) lessthan[i][0] = 0;        
        for(int i = 1; i <= n; i++) 
            for(int j = 0; j <= n; j++) 
                lessthan[j][i] = lessthan[j][i-1] + (nums[i-1] < j);
        
        long long re = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] > nums[j]){
                    
                    long long g = n-nums[i]-(j - lessthan[nums[i]][j+1]);
                    long long l = lessthan[nums[j]][i+1];
                    re += g*l;
                }
            }
        }
        return re;
    }
};