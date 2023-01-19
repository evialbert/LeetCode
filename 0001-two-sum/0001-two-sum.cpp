class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> v;
        vector<int> v2;
        pair<int, int> p;
        for(int i=0; i<nums.size(); i++){
            p.first = nums[i];
            p.second = i;
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        auto it = v.begin(), it2 = v.end();
        it2 --;
        while(it < it2){
            int sum = it->first + it2->first;
            if(sum == target){
                v2.push_back(it->second);
                v2.push_back(it2->second);
                return v2;
            }
            else if(sum < target)
                it ++;
            else 
                it2 --;
        }
            
        return v2;
    }
};