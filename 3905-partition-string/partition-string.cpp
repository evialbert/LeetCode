class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> st;
        vector<string> ans;
         int n = s.size();

            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += s[j]; 
                if (st.find(temp) == st.end()) {
                    st.insert(temp);
                    ans.push_back(temp); 
                    temp="";
                    
                }
            }
        return ans;
    }
};