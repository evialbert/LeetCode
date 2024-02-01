class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector<int> v;
        int l=0,r=mp[s[l]],prev=0;
        while(l<n && r<n){
            while(l<r){
                if(mp[s[l]]>r){
                    r=mp[s[l]];
                }
                l++;
            }
            if(l==r){
                v.push_back(r-prev+1);
                prev=l+1;
                l++;
                r=mp[s[l]];
            }
        }
        return v;
    }
};