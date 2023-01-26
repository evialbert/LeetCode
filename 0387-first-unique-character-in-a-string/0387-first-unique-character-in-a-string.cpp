class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> a(26,0);
        for(auto x:s)
             a[x-'a']++;
        for(int i=0;i<s.length();i++)
        {
             if(a[s[i]-'a']==1)
                 return i;
        }
        return -1;
    }
};