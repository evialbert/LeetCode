class Solution {
public:
    int minimumLength(string &s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r && s[l]==s[r]){
            l++;r--;
            while(s[l-1]==s[l] && l<=r)l++;
            while(s[r+1]==s[r] && r>=l)r--;
        }
        return r-l+1;
    }
};