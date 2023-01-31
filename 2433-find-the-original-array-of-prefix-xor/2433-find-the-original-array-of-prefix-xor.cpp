class Solution {
public:
    vector<int> findArray(vector<int> &pref) {
        vector<int> result;
        result.push_back(pref[0]);

        for (int i = 1; i < pref.size(); ++i)
            result.push_back(pref[i] ^ pref[i - 1]);
        
        return result;
    }
};