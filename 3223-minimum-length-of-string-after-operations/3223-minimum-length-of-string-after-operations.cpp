class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char,int> m;

        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }

        int cnt = 0;
        for(auto it: m)
        {
            if(it.second%2 == 0) cnt+=2;
            else cnt+=1;
        }
        return cnt;
    

    }
};