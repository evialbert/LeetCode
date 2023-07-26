class Solution {
public:
    struct Node{
        Node* child[26];
        bool isTerminal;

        Node(){
            isTerminal=false;
            for(int i=0;i<26;i++)  child[i]=NULL;
        }
    };

    Node* root=new Node();

    // insert all the forbiddens
    void insert(string &s){
        int n=s.size();
        Node* curr=root;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';

            if(curr->child[idx]==NULL){
                curr->child[idx]=new Node();
            }

            curr=curr->child[idx];
        }

        curr->isTerminal=true;
    }
    
    //search if any forbiddens present starting with word[l]
    bool search(string& word,int l,int r){
        Node* curr=root;
        for(;l<=r;l++){
            int idx=word[l]-'a';
            if(curr->child[idx]==NULL) return false;
            curr=curr->child[idx];
            if(curr->isTerminal==true) return true;
        }
        return false;
    }
    
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n=word.length();
        //(Trie Data Structure)
        for(auto &words : forbidden) insert(words);
        
        int ans=0;
        int j=n-1;
        for(int i=n-1;i>=0;i--){
            while(i<=j && search(word,i,j)) j--;
            ans=max(ans,j-i+1);
        }
        
        return ans;
    }
};