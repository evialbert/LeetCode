class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)mp[arr[i]].push_back(i);        
        vector<int>vis(arr.size());
        queue<int>q;
        q.push(0);
        vis[0]++;
        int steps=0;
        int sz=arr.size();
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int i=q.front();                
                q.pop();
                if(i==sz-1)return steps;  
                int l=i-1,r=i+1;
                if(l>=0 && !vis[l]){
                    q.push(l);
                    vis[l]++;
                }
                if(r<sz && !vis[r]){
                    q.push(r);
                    vis[r]++;
                }
                for(auto&j:mp[arr[i]]){
                    if(!vis[j]){
                        q.push(j);
                        vis[j]++;
                    }
                }  
                mp.erase(arr[i]);
            }
            steps++;
        }
        return -1;
    }
};