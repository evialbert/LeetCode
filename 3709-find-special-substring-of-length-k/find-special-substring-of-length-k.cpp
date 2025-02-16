class Solution {
public:
    bool hasSpecialSubstring(string& s, int k) {
        int f=1, n=s.size();
        for(int i=1; i<n; i++){
            if (s[i]!=s[i-1]){
                if (f==k) return 1;
                f=1;
            }
            else f++;
        }
        return f==k;
    }
};