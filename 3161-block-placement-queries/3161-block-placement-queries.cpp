class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        map<int,int> mp;
        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            if(queries[i][0] == 1){
                int x = queries[i][1]; //blockage
                
                map<int,int>::iterator it = mp.lower_bound(x);
                if(it == mp.begin()){
                    mp.insert(make_pair(x, x));    
                }else{
                    mp.insert(make_pair(x, max(x- prev(it)->first, prev(it)->second)));
                }
                
                //update max of all elements
                it = mp.upper_bound(x);
                
                for(; it!=mp.end(); it++){
                    int prev_max = it->second;
                    it->second = max(prev(it)->second, it->first - prev(it)->first);
                    if(it->second == prev_max) break;
                }
            } else{
                int x = queries[i][1];
                int sz = queries[i][2];
                
                map<int,int>::iterator it = mp.lower_bound(x);
                if(it == mp.end() || it->first !=x){
                    int m;
                    if(it == mp.begin()){
                        m = x;
                    }else m = max(x-prev(it)->first, prev(it)->second);
                    
                    if(m>=sz) ans.push_back(true);
                    else ans.push_back(false);
                }else{
                    if(it->second >= sz)  ans.push_back(true);
                    else ans.push_back(false);
                }
            }
        }
        return ans;
    }
};