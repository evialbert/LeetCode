class Solution {
public:
    //At first sort all the groups
    //Then sort the items present in the group according to the question
    
    //sorting groups...
    bool sortG(int u,  vector<int>G[], vector<int> &vis, vector<int>&v)
    {
        vis[u]=1;
        
        for(auto it: G[u])
        {
            if(!vis[it])
            {
                bool f=sortG(it,G,vis,v);
                    if(!f)
                        return f;
            }
            else if(vis[it]==1)
                return false;
        }
        
        vis[u]=2;
        v.push_back(u);
        
        return true;
    }
    
    //sorting items...
    bool sortI(int u,  int g, vector<int> &vis, vector<int>&v, unordered_map<int,unordered_map<int,vector<int>>> &B4srt)
    {
        vis[u]=1;
        
        for(auto it: B4srt[g][u])
        {
            if(!vis[it])
            {
                bool f=sortI(it,g,vis,v,B4srt);
                    if(!f)
                        return f;
            }
            else if(vis[it]==1)
                return false;
        }
        
        vis[u]=2;
        v.push_back(u);
        
        return true;
    }
    
    
    vector<int> sortItems(int n, int m, vector<int>& g, vector<vector<int>>& b4) 
    {
        int map_minus1=m;
        
        //group==-1 denotes that they are independent of each other...so assign them distinct values
        for(int i=0;i<g.size();i++)
            if(g[i]==-1)
                g[i]=map_minus1++;
        
        vector<int>Gsrt[map_minus1 + 5];
        unordered_map<int,vector<int>>grp;
        unordered_map<int,unordered_map<int,vector<int>>>B4srt;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<b4[i].size();j++)
            {
                //If the current item group is not equal to before item group that means
                //before item group should be ahead of current item group
                
                if(g[i]!=g[b4[i][j]])  
                    Gsrt[g[b4[i][j]]].push_back(g[i]);
                
                //else store the items that are in the same group here current item should come after                      //before item... 
                else
                    B4srt[g[i]][b4[i][j]].push_back(i);
            }
            
            grp[g[i]].push_back(i);
        }
        
        //sorting groups.....
        vector<int>vis(map_minus1,0);
        vector<int>sorted_grps;
        for(int i=0;i<map_minus1;i++)
        {
            if(!vis[i])
            {
                bool fl=sortG(i,Gsrt,vis,sorted_grps);
                if(!fl)
                    return {};
            }
        }
        
        reverse(sorted_grps.begin(),sorted_grps.end());
        
        vector<int>fiSrt;
        
        //sorting items in the groups....
        for(auto it:sorted_grps)
        {
            vector<int>mark(n,0);
            vector<int>Items;
            for(auto i: grp[it])
            {
                if(!mark[i])
                {
                    bool fl=sortI(i,it,mark,Items,B4srt);
                    if(!fl)
                        return {};
                }
            }
            
            reverse(Items.begin(),Items.end());
            
            for(auto z:Items)
                fiSrt.push_back(z);
        }
        
        return fiSrt;
    }
};