class Solution {
public:
    int check(vector<int> &nums,int val){
        int sum=0,c=0;
        for(auto x: nums){
            sum+=x;
            if(sum<=val)
                c++;
        }
        return c;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(auto x: queries){
            ans.push_back(check(nums,x));
        }
        return ans;
    }
};