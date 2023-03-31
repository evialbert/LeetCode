class Solution {
public:
    
    bool ok(int len, vector<int> &l, vector<int> &r, int m){
        int n = l.size();
        
        for(int i=0; i<n; i++){
            int x = l[i];
            int y = ((i==n-1)?0:r[i+1]);
            if(m-(y+x) <= len)  return true;
        }
        if(m-r[0] <= len)   return true;
        return false;
    }
    
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> l(n), r(n);
        int idx = 0;
        
        for(int i=0; i<n; i++){
            l[i] = ((i==0)?0:l[i-1]);
            if(idx == m)    continue;
            if(s[i] == t[idx]){
                l[i]++;
                ++idx;
            }
        }
        
        idx = m - 1;
        for(int i=n-1; i>=0; i--){
            r[i] = ((i==n-1)?0:r[i+1]);
            if(idx == -1)   continue;
            if(s[i] == t[idx]){
                r[i]++;
                --idx;
            }
        }
        
        int ans = m;
        int lo = -1, hi = m;
        while(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;
            
            if(ok(mid, l, r, m)){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        
        ans = hi;
        return ans;
    }
};