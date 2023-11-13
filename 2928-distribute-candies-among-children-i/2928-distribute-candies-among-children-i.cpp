class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0,m = min(n,limit);
        for(int i = 0; i<=m;i++) 
            for(int j = 0; j<=m;j++) 
                for(int k = 0; k<=m;k++) 
                    if(n == i+j+k ) ans++;
        return ans;
    }
};