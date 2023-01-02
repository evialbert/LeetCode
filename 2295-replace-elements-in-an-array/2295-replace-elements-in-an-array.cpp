class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& ops) 
    {
         map<int,int>mp;
         for(int i=0;i<nums.size();i++)
         {
           mp[nums[i]]=i;
         }       
         for(int i=0;i<ops.size();i++)
         {
            int currele=ops[i][0];
            int newele=ops[i][1];
            nums[mp[currele]]=newele;
            mp[newele]=mp[currele];
         }
         return nums;
    }
};