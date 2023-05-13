class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> m1;
        for(int i=0;i<nums.size();i++)
            m1[nums[i]]++;
        unordered_map<int,int> m2;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            m2[nums[i]]++;
            m1[nums[i]]--;
            if(m1[nums[i]]==0)
                m1.erase(nums[i]);
            int diff=m2.size()-m1.size();
            v.push_back(diff);
        }
        return v;
    }
};