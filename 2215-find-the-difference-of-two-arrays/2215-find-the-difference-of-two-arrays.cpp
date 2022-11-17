class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        unordered_set<int> set1;
        for(auto i: nums1){
            set1.insert(i);
        }
        unordered_set<int> set2;
        for(auto i: nums2){
            set2.insert(i);
        }
        for(auto i: nums1){
            if(!set2.count(i)){
                result[0].push_back(i);
                set2.insert(i);
            }
        }
        
        for(auto i: nums2){
            if(!set1.count(i)){
                result[1].push_back(i);
                set1.insert(i);
            }
        }
        return result;
    }
};