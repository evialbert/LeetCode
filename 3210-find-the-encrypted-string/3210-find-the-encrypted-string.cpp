class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string ans ;
        for(int i=0; i<s.size(); i++)
        {
            ans += s[(i + k) % n];
        }
        return ans;
    }
};