class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> hash1(26,-1);
        vector<int> hash2(26,-1);
        for(int i=0; i<s.length(); i++){
            hash1[s[i]-'a']=i;
            hash2[t[i]-'a']=i; 
        }
        int diff=0;
        for(int i=0; i<26; i++){
            diff+=abs(hash1[i]-hash2[i]);
        }
        return diff;
    }
};