class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> adjParity(nums.size());
        adjParity[0] = -1;
        
        bool even = false;
        if(nums[0]%2==0)    even = true;
        int lastDiffParity = -1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]%2==0 && !even){
                adjParity[i] = lastDiffParity;
                even = true;
            }
            else if(nums[i]%2!=0 && even){
                adjParity[i] = lastDiffParity;
                even = false;
            }
            else{
                adjParity[i] = i-1;
                lastDiffParity = i-1;
            }
        }
        
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0], end = queries[i][1];
            
            if(adjParity[end] >= start) ans.push_back(false);
            else    ans.push_back(true);
        }
        
        return ans;
    }
};