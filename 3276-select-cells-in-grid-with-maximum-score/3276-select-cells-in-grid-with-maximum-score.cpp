class Solution {
public:


   int dp[105][2000];
    
    int find(int index,int n ,vector<pair<int,int>> &v,int mask){

        if(index == v.size()){

            return 0;

        }

        if(dp[index][mask] != -1) return dp[index][mask];

        // take

        int num = v[index].first;
        int row = v[index].second;

        int option1 = INT_MIN;

        if ( (mask & (1<<row)) == 0){
            // current row not taken
          
            auto it = lower_bound(v.begin(),v.end(),make_pair(num+1,0));

            int index2 = it - v.begin();
            // cout<<num<<"row is  "<<row<< " " <<endl;
            

             option1 = find(index2,n,v, mask | (1<<row));
                if(option1 != INT_MIN) {
                    option1 += num;
                }

            
        }

        int option2 = find(index+1,n,v,mask);

        return dp[index][mask] = max(option1,option2);

    }


    int maxScore(vector<vector<int>>& grid) {

        vector<pair<int,int>> v;

        int n = grid.size();

        for(int i = 0;i<n;i++){

            for(int j=0;j<grid[0].size();j++){
                v.push_back({grid[i][j],i});
            }
        }

        sort(v.begin(),v.end());

        memset(dp,-1,sizeof(dp));

        return find(0,n,v,0);
        
    }
};