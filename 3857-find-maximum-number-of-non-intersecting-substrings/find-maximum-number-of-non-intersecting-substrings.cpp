class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map<char,queue<int>>mp;
        vector<pair<int,int>>vec;
        int i=0;
        while(i<word.size()){
            if(mp.find(word[i])==mp.end() || mp[word[i]].back()!=i) mp[word[i]].push(i);
            if(i-mp[word[i]].front()>2){
                vec.push_back({mp[word[i]].front(),i});
                mp[word[i]].pop();
            }
            else i++;
        }
        if(vec.size()==0) return 0;
        sort(vec.begin(),vec.end(),[](pair<int,int>&p1,pair<int,int>&p2){
            return p1.second<p2.second;
        });
        int cnt=1,freeT=vec[0].second;
        for(int i=1;i<vec.size();i++){
            if(vec[i].first>freeT){
                cnt++;
                freeT=vec[i].second;
            }
        }
        return cnt;
    }
};