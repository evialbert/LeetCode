class Solution {
public:
    unordered_map<int,int> mp;
    unordered_map<string,int> dp;
    bool solve(vector<int> &arr,int i,int jp)
    {
        if(i==arr.size()-1) return true;

        string str = to_string(i)+","+to_string(jp);
        if(dp.find(str)!=dp.end()) return dp[str];

        bool a = false,b = false,c = false;
        int jp1 = arr[i]+jp;
        int jp2 = arr[i]+jp+1;
        int jp3 = arr[i]+jp-1;

        if(mp.find(jp1)!=mp.end() && mp[jp1]!=i) a = solve(arr,mp[jp1],abs(arr[mp[jp1]]-arr[i]));
        if(mp.find(jp2)!=mp.end() && mp[jp2]!=i) b = solve(arr,mp[jp2],abs(arr[mp[jp2]]-arr[i]));
        if(mp.find(jp3)!=mp.end() && mp[jp3]!=i) c = solve(arr,mp[jp3],abs(arr[mp[jp3]]-arr[i]));

        return dp[str] = a | b | c;   
    }
    bool canCross(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0;i<n;i++) mp[arr[i]] = i;
        return solve(arr,0,0);
    }
};