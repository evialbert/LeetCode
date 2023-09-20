class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n = a.size(),l = 0,r = n-1,sm = 0,ans = 1e9;
        
        while(r >= 0 && sm < x){
            sm += a[r];
            r--;
        }
        
        r++;
        if(sm < x){
            return -1;
        }
        
        while(l < n && r < n){
            if(sm == x){
                ans = min(ans,n-r+l);
            }
            sm -= a[r++];
            while(sm < x){
                sm += a[l];
                l++;
            }
        }
        
        if(sm == x){
            ans = min(ans,n-r+l);
        }
        if(ans > 1e8) ans  = -1;
        return ans;
    }
};