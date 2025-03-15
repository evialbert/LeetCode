class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& v) {
        vector<vector<int>> ans(2, vector<int>(v.size()));
        vector<int> t(v.size());
        if(u+l!=accumulate(v.begin(), v.end(), 0))return {};
        int c=0;
        for(auto i:v)if(i==2)c++;
        if(c>u or c>l)return {};
        for(int i=0; i<v.size(); i++){
            if(v[i]==2)ans[0][i]=1, ans[1][i]=1, u--, l--, c--;
            else if(v[i]==1 and u>c)ans[0][i]=1, u--;
            else if(v[i]==1 and l>c)ans[1][i]=1, l--;

        }
       return ans;
    }
};