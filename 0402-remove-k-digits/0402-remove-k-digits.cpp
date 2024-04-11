class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<int> st;
        
        for(char c : num)
        {
            while(!st.empty() && k > 0 && st.top() > c - '0')
            {
                st.pop();
                k--;
            }
            st.push(c - '0');
        }
        
        while(k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }
        
        string ans;
        while (!st.empty())
        {
            ans += st.top() + '0';
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        int i = 0;
        while(i < ans.size() && ans[i] == '0')
            i++;
        
        return i == ans.size() ? "0" : ans.substr(i);
    }
};