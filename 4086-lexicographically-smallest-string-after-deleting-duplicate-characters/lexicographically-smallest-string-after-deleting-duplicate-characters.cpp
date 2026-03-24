class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n = s.size(); 
        stack<int> st; 
        st.push(0);
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++; 
        }
        for(int i = 1; i < n; i++) {
            char ch = s[i];
            while(!st.empty() && s[st.top()] > ch && mp[s[st.top()]] > 1) {
                mp[s[st.top()]]--; 
                st.pop();
                
            }
            st.push(i);
        }
        string res = s; 
        int sz = st.size(); 
        int j = sz-1;
        while(!st.empty()) {
            res[j--] = s[st.top()]; 
            st.pop(); 
        }
        res = res.substr(0,sz);
        while(res.size() >= 2) {
            int sz = res.size(); 
            char last = res[sz-1];
            if(mp[last] > 1) {
                res.pop_back();
                mp[last]--; 
            } else {
                break;
            }
        }
        return res;
    }
};