class Solution {
public:
    string getKey(int a, int b)
    {
        return to_string(a)+"#"+to_string(b);
    }
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // map of subnodes
		map <string, int> u;                                
        int ans = 0;
        map<int,vector<int>>m;
		vector<bool> visited(n,0);
        for(int i=0;i<edges.size();i++)
        {
            u[getKey(edges[i][0],edges[i][1])]=edges[i][2];
            u[getKey(edges[i][1],edges[i][0])]=edges[i][2];
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        priority_queue<pair<int,int>> maxH;
        pair<int,int> p={++maxMoves,0};            // ++maxMoves to account for the starting point Node 0
        maxH.push(p);
        while(!maxH.empty())
        {
            p=maxH.top();
            maxH.pop();
            if(visited[p.second]==true)
                        continue;
             visited[p.second]=1;
            if(p.first>0)
            {   p.first--;
                ans++;}
            if(p.first>=0)
            {   
                for(int i=0;i<m[p.second].size();i++)
                {
                    int x=m[p.second][i];
                    int tmp=min(p.first,u[getKey(p.second,x)]);
                    u[getKey(p.second,x)]-=tmp;
                    u[getKey(x,p.second)]-=tmp;
                    ans+=tmp;
                    maxH.push({p.first - tmp,x});  
                }
            }
        }
        return ans;
    }
};