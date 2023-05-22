class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map <int,int> m1;
        //The elements are inserted in a Map
        for(int i = 0; i < nums.size(); i++){
            m1[nums[i]]++;
        }
        vector<int> counts = {};
        //A vector which contains all the counts is created
        for(auto it = m1.begin(); it != m1.end(); it++){
            counts.push_back(it->second);
        }
        //The Vector is then sorted in Decreasing Order
        sort(counts.begin(),counts.end());
        reverse(counts.begin(),counts.end());
        vector<int> ans = {};
        int a = 0;
        //The Most Frequent K elements are inserted in the ans vector
        while(ans.size() != k){
            for(auto it = m1.begin(); it != m1.end(); it++){
                if(it->second == counts[a] && a < k){
                    ans.push_back(it->first);
                    a++;
                }
            }
        }
        return ans;
    }
};