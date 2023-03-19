struct TrieNode {
    TrieNode(){
        children = vector<TrieNode*>(26, nullptr);
    }
    vector<TrieNode*> children;
    bool end=false;
};

class WordDictionary {
public:
    
    TrieNode _dict;
    WordDictionary() {
            
    }
    
    void addWord(string word) 
    {
        auto node = &_dict;
        for(int i=0; i<word.length(); i++){
            if(!node->children[word[i]-'a']) 
                node->children[word[i]-'a'] = new TrieNode();
            node = node->children[word[i]-'a'];
        }
        node->end=true;
        
    }
    
    bool search(string word) {
    
        return search(word, 0, &_dict);
    }
    
    bool search(string& word, int i, TrieNode* node){
        
        if(!node) 
            return false;
        
        if(i==word.length()) 
            return node->end;
        
        if(word[i]!='.') 
            return search(word, i+1, node->children[word[i]-'a']);
           
        bool res=false;
        for(int j=0; j<26 && !res; j++){
            res = search(word, i+1, node->children[j]);
        }
        
        return res;            
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */