class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> pairs;
        for(int i=0;i<names.size();i++) {
            pairs.push_back({names[i], heights[i]});
        }

        sort(pairs.begin(), pairs.end(), [&](auto& a, auto& b){
            return a.second > b.second;
        });


        vector<string> res;
        for(int i=0;i<pairs.size();i++) {
            res.push_back(pairs[i].first);
        }

        return res;
    }
};