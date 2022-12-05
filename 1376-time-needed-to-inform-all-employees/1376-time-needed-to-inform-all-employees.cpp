class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //hashmap to store cost to inform
        unordered_map<int,int>info;
        for(int i=0;i<informTime.size();i++){
            info[i]=informTime[i];
        }
        queue<int>q;
        q.push(headID);
        //hashmap for graph
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        //start bfs
        while(!q.empty()){
            auto start=q.front();
            q.pop();
            for(auto num:adj[start]){
				// update time to send out message
                info[num]+=info[start];
                q.push(num);
            }
        }
        int res=0;
        for(auto it:info){
		//get the maximum time 
            res=max(res,it.second);
        }
        return res;
    }
};