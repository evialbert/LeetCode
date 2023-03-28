class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) 
    {
        long long ans = 0;
        int i = 0,j = nums.size()-1;
        string temp = "";
        while(i<j)
        {
            temp = "";
            temp+=to_string(nums[i])+to_string(nums[j]);
            ans+=stoi(temp);
            i++;j--;
        }
        if(nums.size()%2)
        {
            ans+=nums[i];
        }
        return ans;
    }
};