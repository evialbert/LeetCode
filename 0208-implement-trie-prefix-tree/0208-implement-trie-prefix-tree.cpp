class Node {
private:
    char c;
    unordered_map<char, Node*> nextChars;
    bool isEnd; 
public:
    Node() {
        isEnd = false;
        nextChars = unordered_map<char, Node*>();
    }
    
    Node(char c) : Node() {
        this->c = c;
    }
    
    void setEnd() {
        isEnd = true;
    }
    
    bool getIsEnd() {
        return isEnd;
    }
    
    Node* addNode(char c) {
        if (nextChars.find(c) == nextChars.end()) {
            nextChars[c] = new Node(c);
        }
        return nextChars[c];
    }
    
    Node* getNode(char c) {
        return nextChars[c];
    }
    
    bool contains(char c) {
        if (nextChars.find(c) == nextChars.end()) return false;
        return true;
    }
    
    char getChar() {
        return c;
    }
    
};


class Trie {
private:
    Node* root;
    
    void insertHelper(Node* n, string word, int k) {
        if (k >= word.size()) {
            n->setEnd();
            return;
        }
        n = n->addNode(word[k]);
        insertHelper(n, word, k + 1);  
    }
    
    bool searchHelper(Node* n, string word, int k) {
        if (k >= word.size()) return n->getIsEnd();
        if (!n->contains(word[k])) return false;
        return searchHelper(n->getNode(word[k]), word, k + 1);
    }
    
    bool startsWithHelper(Node* n, string word, int k) {
        if (k >= word.size()) return true;
        if (!n->contains(word[k])) return false;
        return startsWithHelper(n->getNode(word[k]), word, k + 1);
    }
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        insertHelper(root, word, 0);
        
    }
    
    bool search(string word) {
        if (root == NULL) return (word.size() == 0);
        return searchHelper(root, word, 0);
    }
    
    bool startsWith(string prefix) {
        if (root == NULL) return (prefix.size() == 0);
        return startsWithHelper(root, prefix, 0);
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */