class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        // find the most views for first popular creators
        unordered_map<string, long> vmap;
        for(long i=0; i<creators.size(); i++)
            vmap[creators[i]]+=views[i];
        long mostPopular = 0;
        for(auto p : vmap)
            mostPopular = max(mostPopular, p.second);
       
        // select the most popular creators out
         unordered_map<string, pair<int, string>> mmap;
        for(int i=0; i<creators.size(); i++)
            if(vmap[creators[i]] == mostPopular &&( mmap.count(creators[i]) == 0 || mmap[creators[i]] > pair{-views[i], ids[i]}))
                    mmap[creators[i]] = {-views[i], ids[i]};
        
        // put it into a string vector
        vector<vector<string>> ans;
        for(auto p : mmap)
            ans.push_back(vector<string>{p.first, p.second.second});
        return ans;
         
    }
};