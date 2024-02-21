class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string>a ,b;
        sort(arr1.begin() , arr1.end() , greater<int> ());
        sort(arr2.begin() , arr2.end(), greater<int> ());
        for(auto x : arr1) a.insert(to_string(x));
        for(auto x : arr2) b.insert(to_string(x));
        
        int n = a.size();
        int ans = 0;
        for(auto s : a) {
            string temp = "";
            for(int i = 0; i < s.length(); i++) {
                temp.push_back(s[i]);
                auto it = b.lower_bound(temp);
                string tp = "";
                if(it != b.end())
                    tp = *it;
                int cnt = 0;
                if(it != b.end()) {
                    for(int i = 0; i < min(temp.length(),tp.length()); i++) {
                        if(s[i] == tp[i]) cnt++;
                        else break;
                    }
                }
                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};