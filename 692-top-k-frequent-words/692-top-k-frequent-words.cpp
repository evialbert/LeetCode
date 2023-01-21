class Solution {
public:
    static bool cmp(pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first)  return a.second<b.second;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(int i=0;i<words.size();++i){
            mp[words[i]]++;
        }
        vector<pair<int,string>>v;
        for(auto it:mp){
            v.push_back(make_pair(it.second,it.first));
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
            vector<string>a;
        for(int i=0;i<k;i++){
            a.emplace_back(v[i].second);
        }
        return a;
    }
};