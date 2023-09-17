class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
       map<pair<int,int>,int> m;
        int ans=0;
        int n=coordinates.size();
        for(int i=0;i<n;i++)
        {
            vector<int> tp=coordinates[i];
            
            for(int k1=0;k1<=k;k1++)
            {
                int k2=k-k1;
                
                int x=tp[0];
                int y=tp[1];
                int x1=x^k1;
                int y1=y^k2;
                
                
               
                
                
                ans+=m[{x1,y1}];
                
            }
            
            m[{tp[0],tp[1]}]++;
        }
        return ans;
    }
};