class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        int n = arr.size();
        
        unordered_map<string,vector<string>> mp1;
        unordered_map<string,int> mp2;
        
        for(int i=0; i<n; i++) {
            unordered_set<string> st;
            for(int x=0; x<arr[i].size(); x++) {
                string str="";
                for(int y=x; y<arr[i].size(); y++) {
                    str += arr[i][y];
                    mp1[arr[i]].push_back(str);
                    st.insert(str);
                }
            }
            for(string it: st)  mp2[it]++;
        }
        
        vector<string> ans(n);
        
        for(int i=0; i<n; i++) {
            string str="";
            for(auto it: mp1[arr[i]]) {
                if(mp2[it] == 1) {
                    if(str=="") str = it;
                    else {
                        if(str.length() == it.length() && str > it) {
                            str = it;
                        }
                        else if(str.length() > it.length()) {
                            str = it;
                        }
                    }
                    
                }
            }
            ans[i] = str;
        }
        
        return ans;
    }
};