class Solution {
public:
    
    int minimumVisitedCells(vector<vector<int>>& g) {
        int r = g.size(), c = g[0].size();
        vector<set<int>> rem_r(c), rem_c(r);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                rem_r[j].insert(i);
                rem_c[i].insert(j);
            }
        }
        vector<vector<int>> dist(r, vector<int>(c, -1));
        dist[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto pr = q.front();
            q.pop();
            int rr = pr.first;
            int cc = pr.second;
            vector<int>ec;
            for(
                auto it = rem_c[rr].lower_bound(cc + 1);
                it != rem_c[rr].end() && it != rem_c[rr].upper_bound(cc + g[rr][cc]);
                it++
            ){
                dist[rr][*it] = dist[rr][cc] + 1;
                q.push({rr, *it});
                ec.push_back(*it);
            }
            for(auto x : ec) {
                rem_c[rr].erase(x);
                rem_r[x].erase(rr);
            }
            
            vector<int>er;
            for(
                auto it = rem_r[cc].lower_bound(rr + 1);
                it != rem_r[cc].end() && it != rem_r[cc].upper_bound(rr + g[rr][cc]);
                it++
            ){
                dist[*it][cc] = dist[rr][cc] + 1;
                q.push({*it, cc});
                er.push_back(*it);
            }
            for(auto x : er) {
                rem_r[cc].erase(x);
                rem_c[x].erase(cc);
            }
            
        }
        return dist[r - 1][c - 1];
    }
};