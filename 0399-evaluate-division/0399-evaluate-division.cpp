class Solution {
public:
    double helper(string start, string target,map<int,string>& mx, map<string,int>& mp, vector<vector<double>>& v,vector<bool>& f){
        if(mp.find(start)==mp.end() || mp.find(target)==mp.end()){
            return (-1.00000);
        }
        if(v[mp[start]][mp[target]]!=(-1.00000)){
                return (v[mp[start]][mp[target]]);
        }
        f[mp[start]]=true;
        for(int i=0;i<v[mp[start]].size();i++){
            if(f[i]==true){
                continue;
            }
            if(v[mp[start]][i]!=(-1.00000)){
                double ans = helper(mx[i],target,mx,mp,v,f);
                if(ans!=(-1.00000)){
                    return (ans*v[mp[start]][i]);
                }                
            }
        }        
        return (-1.00000);
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size();
        int n = 2;
        int idx = 0;
        map<string,int> mp;
        map<int,string> mx;
        for(int i=0;i<m;i++){
            for(int j=0;j<2;j++){
                if(mp.find(equations[i][j])==mp.end()){
                    mp[equations[i][j]] = idx;
                    mx[idx] = equations[i][j];
                    idx++;
                }
            }            
        }
        vector<vector<double>> v(idx,vector<double>(idx,-1.00000));
        vector<double> res(queries.size());
        for(int i=0;i<m;i++){
            v[mp[equations[i][0]]][mp[equations[i][1]]] = values[i]; 
            v[mp[equations[i][1]]][mp[equations[i][0]]] = (1/values[i]); 
        }
        for(int i=0;i<queries.size();i++){
            if(mp.find(queries[i][0])==mp.end() || mp.find(queries[i][1])==mp.end()){
                res[i] = -1.00000;
            }
            else if(queries[i][0]==queries[i][1]){
                res[i] = 1.00000;
            }
            else if(v[mp[queries[i][0]]][mp[queries[i][1]]]!=(-1.00000)){
                res[i] = v[mp[queries[i][0]]][mp[queries[i][1]]];
            }            
            else{
                vector<bool> f(idx,false);
                res[i] = helper(queries[i][0],queries[i][1],mx,mp,v,f);
            }
        }
        return res;                                
    }
};