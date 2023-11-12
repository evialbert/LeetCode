class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> visited;

        if(target == source)
            return 0;

        bool targetFlag = false, sourceFlag = false;
        for(int i = 0; i < routes.size(); i++)
        {
            sourceFlag = false;
            targetFlag = false;
            for(int j = 0; j < routes[i].size(); j++)
            {
                if(routes[i][j] == source)
                    sourceFlag = true;
                if(routes[i][j] == target)
                    targetFlag = true;
                mp[routes[i][j]].push_back(i);
            }
            if(targetFlag == true && targetFlag == sourceFlag)
                return 1;
        }

        if(mp[source].size() == 0 || mp[target].size() == 0)
            return -1;

        queue<int> q;
        int res = 0;
        vector<int> ans(routes.size(), INT_MAX);


        for(auto x : mp[source])
        {
            q.push(x);
            ans[x] = 1;
        }
            

        while(!q.empty())
        {
            int bus = q.front(); q.pop();
            
            if(visited[bus] == 0)
            {
                visited[bus] = 1;
                for(auto stop : routes[bus])
                {
                    if(stop == target)
                        return ans[bus];
                    for(auto nextBus : mp[stop])
                    {
                        if(nextBus != bus)
                        {
                            q.push(nextBus);
                            ans[nextBus] = min(ans[nextBus], ans[bus] + 1);
                            //break;
                        }
                           
                    }
                }
            }
        }
        return -1;
    }
};