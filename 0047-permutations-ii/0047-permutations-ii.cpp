class Solution {
public:
    void help(vector<vector<int>> &ans,vector<int> &perm,unordered_map<int,int> &count,int n){
        if(perm.size()==n)
        {
            ans.push_back(perm);
            return;
        }
        unordered_map<int,int> :: iterator it=count.begin();
        while(it!=count.end())
        {
            if(it->second!=0)
            {
                perm.push_back(it->first);
                it->second--;
                help(ans,perm,count,n);
                it->second++;
                perm.pop_back();
            }
            it++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> perm;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++)
            count[nums[i]]++;
        
        help(ans,perm,count,nums.size());
        return ans;
    }
};