class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_size = s.size(),t_size = t.size(),i=0,j=0;
        while(i < s_size and j < t_size)
        {
            if(s[i]==t[j]) i++;
            j++;
        }
        return i == s_size ? true : false; 
    }
};