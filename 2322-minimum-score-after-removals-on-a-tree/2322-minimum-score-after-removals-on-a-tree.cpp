class Solution {
public:
    int time=0;
    int dfs(map<int, vector<int>> &graph, int vertex, int parent, vector<int> &xors, vector<int> &nums, vector<int> &parents, vector<int>& intime, vector<int>& outtime){
        intime[vertex] = time++;
        int val = nums[vertex];
        parents[vertex] = parent;
        for(auto child: graph[vertex]){
            if(child != parent){
                val = val ^ dfs(graph, child, vertex, xors, nums, parents, intime, outtime);
            }
        }
        xors[vertex] = val;
        outtime[vertex] = time++;
        return val;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        time = 0;
        map<int, vector<int>> graph;
        int n = nums.size();
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> parents(nums.size(), 0);
        vector<int> xors(nums.size(), 0);
        vector<int> intime(n),outtime(n);
        dfs(graph, 0, -1, xors, nums, parents, intime, outtime);
        int root = 0;
        
        int minimum = INT_MAX;
        for(int i=1; i < n; i++)
        {
            for(int j=1; j < n; j++)
            {
                if(i==j) continue;
                else if(intime[i] < intime[j] && outtime[i]>outtime[j])
                {
                    int x = xors[j];
                    int y = xors[i] ^ xors[j];
                    int z = xors[root] ^ xors[i];
                    int mini = min(x, min(y,z));
                    int maxi = max(x, max(y,z));
                    minimum = min(minimum, maxi - mini);
                }
                else if(intime[i] > intime[j] && outtime[i] < outtime[j])
                {
                    int x = xors[i];
                    int y = xors[i] ^ xors[j];
                    int z = xors[root] ^ xors[j];
                    int mini = min(x, min(y,z));
                    int maxi = max(x, max(y,z));
                    minimum = min(minimum, maxi - mini);
                }
                else 
                {
                    int x = xors[i];
                    int y = xors[j];
                    int z = xors[root] ^ xors[i] ^ xors[j];
                    int mini = min(x, min(y,z));
                    int maxi = max(x, max(y,z));
                    minimum = min(minimum, maxi - mini);
                }
            }
        }
        return minimum;
        
    }
};