class Solution {
public:
    vector<vector<int>>ans;
    vector<int>ok;
    void call(int pos,int n,vector<int>&v){
        if(n==0){
            ans.push_back(ok);
            return ;
        }
        if(n<0)return;
        for(int i=pos;i<v.size();i++)
        {
            ok.push_back(v[i]);
            call(i,n-v[i],v);
            ok.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& v, int n) {
        call(0,n,v);
        return ans;
    }
};