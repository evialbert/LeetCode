class Solution {
public:
    string minimizeStringValue(string s) 
    {
        int hash[26] = {0}, len = 1;
        string ans;
        for (char c : s) 
        {
            if (c != '?') ++hash[c - 'a'];
            else  ++len;
        }

        while (--len) 
        {
            int k = -1 ,min = INT_MAX;
            for (int i = 0; i < 26; i++) 
            {
                if (hash[i] < min)
                {
                    min = hash[i];
                    k = i;
                }
            }
            ans.push_back(char(k + 'a'));
            hash[k]++;
        }
        sort(ans.begin(), ans.end());
        int k = 0;
        for (char& c : s) if (c == '?') 
            c = ans[k++] ;
        return s;
    }
};