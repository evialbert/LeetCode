class Trie{
public:
    int ind=INT_MAX;
    int len=INT_MAX;
    unordered_map<char,Trie*>m;
};

class Solution {
    Trie *root;
public:
    Solution(){
       root=new Trie();
    }
    vector<int> stringIndices(vector<string>& words, vector<string>& queries) {
        int j=0;
        for(auto s: words){
            reverse(s.begin(),s.end());
            Trie *node= root;
            int n=s.length();
            // root node
            if(node->len > n) {
                node->len=n;
                node->ind=j;
            }
            //child nodes
            for(auto c: s){
                if(node->m.find(c)==node->m.end()){
                    node->m[c]=new Trie();
                }
                if(node->m[c]->len > n){
                    node->m[c]->len=s.length();
                    node->m[c]->ind=j;
                }
                node=node->m[c];
            }
            j++;
        }
     
        vector<int>ans;
         for(auto s: queries){
            reverse(s.begin(),s.end());
            Trie *node= root;
            for(auto c: s){
                if(node->m.find(c)==node->m.end())  break;
                node=node->m[c];
            }
            ans.push_back(node->ind);
        }
        return ans;
    }
};