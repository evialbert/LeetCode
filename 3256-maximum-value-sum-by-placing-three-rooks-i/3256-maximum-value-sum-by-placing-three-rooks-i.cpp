class Solution {
public:

    long long dp[102][102][102][3] ; 
    // vector <vector <vector <vec>>>
    bool vis[102][102][102][3] ; 

    long long rec(int level , int fir , int sec , int num , int n , int m , vector <vector <pair <int , int>>> &arr){
        if(num > 3) return -1e14 ; 
        if(level == m){
            if(num == 3) return 0 ; 
            return -1e14 ; 
        }
        if(num == 3){
            return 0 ; 
        } 
        if(vis[level][fir][sec][num]){
            return dp[level][fir][sec][num] ; 
        }

        long long ans = -1e11 ;
        ans = max(ans , rec(level +1 , fir ,sec, num , n , m , arr)) ; 
        if(num == 0){
            for(int i = 0 ;i < 3 ; i++){
                ans = max(ans , 1ll*arr[level][i].first + rec(level +1 , arr[level][i].second , sec , num +1 , n , m , arr)) ; 
            }
        } 
        else if(num == 1){
            for(int i = 0 ;i < 3 ; i++){
                if(arr[level][i].second == fir) continue ;
                ans = max(ans , 1ll*arr[level][i].first + rec(level +1 , fir , arr[level][i].second , num+1, n , m , arr)) ; 
            }
        }
        else if(num == 2){
            for(int i = 0 ;i < 3 ; i++){
                if(arr[level][i].second == fir || arr[level][i].second == sec) continue ;
                ans = max(ans , 1ll*arr[level][i].first + rec(level +1 , fir , sec ,num+1, n , m , arr)) ; 
            }
        }
        vis[level][fir][sec][num] = true ; 
        return dp[level][fir][sec][num] =ans ; 

    }


    long long maximumValueSum(vector<vector<int>>& grid) {
        int m = (int)grid.size() ; 
        int n =(int)grid[0].size() ;

        vector <vector <pair <int , int>>> arr (m , vector <pair <int , int>> (3)) ; 
        for(int i =0 ; i < m ; i++){
            set <pair <int , int>> st ;
            for(int j =0 ; j < n ; j++){
                st.insert({grid[i][j] , j+1}) ; 
            }
            auto it = st.rbegin() ; 
            for(int j = 0 ; j < 3 ; j++){
                arr[i][j] = *it ;  
                it++ ; 
            }
        }
        memset(dp , -1 , sizeof(dp)) ; 
        memset(vis , false , sizeof(vis)) ; 
        long long ans = rec(0 , 0 , 0 , 0 , n , m , arr) ; 
        return ans ; 
    }
};