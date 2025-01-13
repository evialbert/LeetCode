class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        int n1 = list1.size(), n2 = list2.size();
        for(int i=0; i<n1; i++){
            string temp = list1[i];
            for(int j=0; j<n2; j++){
                if(list2[j] == temp){
                    mp[list2[j]] = i+j;
                }
            }
        }

        int mini = INT_MAX;
        for(auto it : mp){
            if(it.second <= mini){
                mini = it.second;
            }
        }
        for(auto it : mp){
            if(it.second == mini){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};