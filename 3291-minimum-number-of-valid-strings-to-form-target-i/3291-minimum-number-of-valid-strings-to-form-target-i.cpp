class Solution {
    struct TrieNode{
        TrieNode* next[26]={0};
    };
    void insert(TrieNode* root,string& str) {
        TrieNode* n=root;
        for(char c : str){
            if(!n->next[c-'a']) n->next[c-'a']=new TrieNode();
            n=n->next[c-'a'];
        }
    }
    int minPre(TrieNode* root,const string& tar,vector<int>& dp,int i) {
        int n=tar.length();
        if(i==n) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int min_=-1,s=i;
        TrieNode* p=root;
        while(i<n&&p->next[tar[i]-'a']){
            p=p->next[tar[i]-'a'];
            int nextp=minPre(root,tar,dp,i+1);
            if(nextp!=-1) min_=(min_==-1 ? 1+nextp : min(min_,1+nextp)); 
            i++;
        }
        return dp[s]=min_;
    }
public:
    int minValidStrings(vector<string>& words, string target) {
        int n=target.size();
        vector<int> dp(n,INT_MIN);
        TrieNode* root=new TrieNode();
        for(string w : words){
            insert(root,w);
        }
        return minPre(root,target,dp,0);
    }
};