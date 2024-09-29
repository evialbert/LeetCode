class Solution {
public:
    void help(string s,string t,int in,int i,vector<int>&ans){
        while(in<t.size() && i<s.size()){
            if(t[in]==s[i])ans.push_back(i),in++;
            i++;
        }   
    }
    vector<int> validSequence(string word1, string word2) {
        vector<int>ans;
        int i=0;
        while(i<word2.size() && word1[i]==word2[i])ans.push_back(i),i++;
        if(i==word2.size())return ans;
        vector<int>suf(word2.size(),-1);
        int in=word2.size()-1;
        for(int j=word1.size()-1;j>=0 && in>=0;j--){
            if(word1[j]==word2[in])suf[in]=j,in--;
        }
        suf.push_back(INT_MAX); 
        in=i;
        // for(int &i:suf)cout<<i<<" ";
        // cout<<endl;
        for(int k=i;in<word2.size() && k<word1.size();k++){
            if(suf[in+1]>k){
                ans.push_back(k);
                help(word1,word2,in+1,k+1,ans);
                return ans;
            }
            if(word1[k]==word2[in])ans.push_back(k),in++;
        }
        if(ans.size()!=word2.size())return {};
        return ans;
    }
};