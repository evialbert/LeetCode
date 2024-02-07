class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int, char>> pq;

        for(char c : s) {
            mp[c]++;
        }
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        s = "";
        while(!pq.empty()) {
            for(int i=0;i<pq.top().first;i++) {
                s += pq.top().second;
            }
            pq.pop();
        }
        return s;
    }
};