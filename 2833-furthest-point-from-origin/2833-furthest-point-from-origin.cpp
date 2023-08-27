class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count =0;
        unordered_map<char,int>mp;
       for(auto it:moves){
           mp[it]++;
       }
      return max(mp['L'],mp['R']) - min(mp['L'],mp['R']) + mp['_'];
    }
};