class Solution {
public:
    int longestSubstring(string s, int k) {
    int n = s.size();
    if(n<k) return 0;
    unordered_map<char,int>m;
    for(auto x:s){
        m[x]++;
    }
    int j = 0;
    while(j<n && m[s[j]]>=k) j++;
    if(j>=n-1) return j;
    int c1 = longestSubstring(s.substr(0,j),k);
    while(j<n && m[s[j]]<k) j++;
    int c2 = longestSubstring(s.substr(j),k);
    return max(c1,c2);
}
};