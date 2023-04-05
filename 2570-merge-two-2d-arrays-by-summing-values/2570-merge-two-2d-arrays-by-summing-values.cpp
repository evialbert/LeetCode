class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        
        map<int,int> hold;
        for(int i=0;i<nums1.size();i++){
            int val = nums1[i][1];
            hold[nums1[i][0]] += val;
        }
        
        for(int i=0;i<nums2.size();i++){
            int val = nums2[i][1];
            hold[nums2[i][0]] += val;
        }
        vector<vector<int>> ans;
        for(auto i:hold){
            vector<int> temp;
            temp.push_back(i.first);
            temp.push_back(i.second);
            ans.push_back(temp);
        }
        return ans;
    }
};