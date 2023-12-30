class Solution {
public:
    
    
    vector<int> dij(string & s,string & t,vector<vector<pair<int,int>>> & g,int i){
        
        vector<int> dis(26,INT_MAX);
        
        priority_queue<pair<int,int>> pq;
        pq.push({0,i});
        dis[i]=0;
        
        
        
        while(!pq.empty()){
            auto [dist,source] = pq.top();
            pq.pop();
            
            for(auto neigh : g[source]){
                if(dis[neigh.first]-neigh.second>dis[source]){
                    dis[neigh.first]=dis[source]+neigh.second;
                        pq.push({dis[neigh.first],neigh.first});
                }
            }
        }
        
        return dis;
    }
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        vector<vector<pair<int,int>>> g(26);
        
        for(int i=0;i<o.size();i++){
            g[o[i]-97].push_back({c[i]-97,cost[i]});
        }
        
        vector<vector<int>> dis ;
        
        for(int i=0;i<26;i++){
            dis.push_back(dij(s,t,g,i));
        }
        
        long long ans=0;
        
        for(int i=0;i<s.length();i++){
            if(dis[s[i]-97][t[i]-97]==INT_MAX)
                return -1;
            ans+=(dis[s[i]-97][t[i]-97]);
        }
        
        return ans;
        
    }
};