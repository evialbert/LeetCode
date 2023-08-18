class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
          vector<unordered_set<int>> vec(n);
     for (auto road: roads) {
            vec[road[0]].insert(road[1]);
            vec[road[1]].insert(road[0]);
        }
        int mx=0,count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 count=vec[i].size();
                count+=vec[j].size();
                if(vec[j].count(i))
                    count--;
         mx=max(mx,count);

            }
        }
        return mx;
    }
};