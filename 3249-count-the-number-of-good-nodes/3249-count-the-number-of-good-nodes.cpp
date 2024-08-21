class Solution {
public:
    int goodNodes = 0;
    vector<vector<int>> T;
    int DFS(int u , int p){
        int mini = +1e6 , maxi = -1e6;
        int curr = 0;
        for(int v : T[u]){
            if(v != p){
                int sz = DFS(v , u);
                mini = min(mini , sz);
                maxi = max(maxi , sz);
                curr += sz;
            }
        }
        if(curr == 0 || mini == maxi) goodNodes++;
        return 1 + curr;
    }   
    int countGoodNodes(vector<vector<int>> &Edges){
        T.resize(Edges.size() + 1);
        for(vector<int> &E : Edges){
            T[E[0]].push_back(E[1]);
            T[E[1]].push_back(E[0]);
        }
        DFS(0 , -1);
        return goodNodes;
    }
};