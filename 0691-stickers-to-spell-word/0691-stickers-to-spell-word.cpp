class Solution {
public:
    string filter(string & a, string & b) {
        string ret = "";
        int idx = 0;
                
        for (char & c: a) {
            bool found = false;
            for (int i = idx; i < b.length() && b[i] <=c; ++i) {
                idx++;
                if (b[i] == c) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ret += c;
            }
        }
        return ret;
    }
    int minStickers(vector<string>& stickers, string target) {
        const int n = (int)stickers.size();
        vector<vector<int>> arr(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            sort(stickers[i].begin(), stickers[i].end());
        }
        sort(target.begin(), target.end());
        
        int ans = 0;
        queue<pair<string,int>> q;
        q.push({target,0});
        string x;
        int t;
        set<string> visited;
        while(!q.empty()) {
            tie(x,t) = q.front();
            q.pop();
            
            for (int i = 0; i < n; ++i) {
                string now = filter(x, stickers[i]);
                
                if (now == "") {
                    return t + 1;
                }
                
                if (now != x && visited.find(now) == visited.end()) {
                    visited.insert(now);
                    q.push({now, t+1});
                }
            }
        }
        return -1;
    }
};