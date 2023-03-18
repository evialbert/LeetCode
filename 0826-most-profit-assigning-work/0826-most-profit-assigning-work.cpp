class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        int n=diff.size(),m=worker.size(),ans=0;
        map<int,int>table;
        for(int i=0;i<n;i++)
        {   
            if(table.find(diff[i])==table.end()||profit[i]>table[diff[i]])
                table[diff[i]]=profit[i];
        }
        
        for(auto it=++table.begin(),pt=table.begin();pt!=table.end();it++,pt++)
        {
           it->second=max(it->second,pt->second); 
            
            
        }
        
        vector<pair<int,int>>t(table.begin(),table.end());
        n=t.size();
        for(int i=0;i<m;i++)
        {   
            if(worker[i]<t[0].first)
            { //cout<<"0"<<endl;
              continue;
            }
            if(worker[i]>t[n-1].first)
            {
                //cout<<table[n-1].second<<endl;
                ans+=t[n-1].second;
                continue;
            }
                
            int start=0,end=n-1,mid=(start+end)/2;
            while(start<=end)
            {
                if(worker[i]==t[mid].first)
                {
                    
                    break;
                }
                else if(worker[i]<t[mid].first)
                {
                    end=mid-1;
                }
                else
                    start=mid+1;
                mid=(start+end)/2;
            }
            //cout<<table[mid].second<<endl;
            ans+=t[mid].second;
            
            
            
        }
        return ans;
        
    }
};