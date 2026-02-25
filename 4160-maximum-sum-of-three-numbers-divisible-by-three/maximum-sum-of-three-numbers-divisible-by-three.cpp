class Solution {
    using ll = long long;
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> v(3,vector<int>());
        for(int num : nums){
            v[num % 3].push_back(num);
        }
          ll maxSum = 0;
        for(int i = 0; i< 3; i++){
            sort(v[i].rbegin(),v[i].rend());
        }
            if(v[0].size() >= 3){
                maxSum = max(maxSum,(ll)v[0][0] + v[0][1] + v[0][2]);
            }
            if(v[1].size() >= 3){
                maxSum = max(maxSum,(ll)v[1][0] + v[1][1] + v[1][2]);
            }
            if(v[2].size() >= 3){
                maxSum = max(maxSum,(ll)v[2][0] + v[2][1] + v[2][2]);
            }
            if(!v[0].empty() && !v[1].empty() && !v[2].empty()){
                maxSum = max(maxSum,(ll)v[0][0] + v[1][0] + v[2][0]);
            }
     return (int)maxSum;
 }
};