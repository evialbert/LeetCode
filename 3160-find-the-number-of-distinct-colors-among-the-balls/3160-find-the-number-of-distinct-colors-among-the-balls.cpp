class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        vector<int> ans;
        unordered_map<int,int> m,val;
        for(auto x:queries)
        {
            int a = x[0];
            int b = x[1];
            if(m.find(a)!=m.end())
            {
                int col = m[a];
                val[col]--;
                if(val[col] == 0)
                val.erase(col);
            }
            val[b]++;
            m[a] = b;
            ans.push_back(val.size());
        }
        return ans;

    }
};