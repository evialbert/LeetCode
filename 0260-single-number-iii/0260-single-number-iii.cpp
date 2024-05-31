class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> M;
        for(auto n:nums)
            M[n]++;
        vector<int> A;
        for(auto i:M){
            if(i.second==1)
                A.push_back(i.first);
        }
        return A;
    }
};