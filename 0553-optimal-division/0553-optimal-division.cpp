class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1)
            return to_string(nums[0]);
        if(nums.size()==0)
            return "";
        if(nums.size()==2)
            return to_string(nums[0])+"/"+to_string(nums[1]);
        string ans="(";
        for(int i=1;i<nums.size();i++)
        {
            ans+=to_string(nums[i]);
            if(i!=nums.size()-1)
                ans+="/";
        }
        ans+=")";
        string res=to_string(nums[0])+"/";
        return res+ans;
    }
};