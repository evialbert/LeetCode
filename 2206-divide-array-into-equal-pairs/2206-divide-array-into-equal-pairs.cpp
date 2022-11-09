class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m1;
        for(int i=0;i<nums.size();i++)
        {
            m1[nums[i]]++;
        }
        for(auto i=m1.begin();i!=m1.end();i++)
        {
            int no=i->second;
            if(no%2)
                return false;
        }
        return true;
    }
};