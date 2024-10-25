class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        stack<string> s;
        s.push(folder[0]);
        for(int i=1;i<folder.size();i++)
        {
            string s1=s.top();
            string s2=folder[i].substr(0,s1.size());
            if(s1==s2 && !(isalpha(folder[i][s1.size()])))
            continue;
            else
            s.push(folder[i]);
        }
        vector<string> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;

    }
};