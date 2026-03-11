class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            st.insert(s[i]);
            if(st.size()==(i+1)%3)
                cnt++;
            if(st.size()>=3)
            return cnt;
        }
        return cnt;
    }
};