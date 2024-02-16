class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> freq;
        vector<int> result;
        
        for(auto num : nums){
            if(freq[num] == 1) result.push_back(num);
            else freq[num]++;
        }
        
        return result;
    }
};