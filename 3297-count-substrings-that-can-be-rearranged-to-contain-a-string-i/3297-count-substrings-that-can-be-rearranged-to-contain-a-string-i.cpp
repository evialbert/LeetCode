class Solution {
public:
#define ll long long
    long long validSubstringCount(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        if(n<m)return 0;
        ll ans=0;

        unordered_map<char,int>mp1,mp2;
        for(auto i:word2)mp2[i]++;

        auto check=[&](){
            for(auto i:mp2){
            if(!mp1.count(i.first) or i.second>mp1[i.first])
                return false;
            }
            return true;
        };
        
        int j=0;
        for(int i=0;i<n;i++){
            mp1[word1[i]]++;
            while(j<=i and check()){
                mp1[word1[j]]--;
                j++;
                ans+=n-i;
            }            
        }
        return ans;      

    }
};