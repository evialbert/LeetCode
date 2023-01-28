class TrieNode {
public:
    TrieNode* chld[26];
    int cnt;
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            chld[i] = NULL;
        }
        cnt = 0;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void constructTrie(string s) {
        TrieNode* temp = root;
        for(char &c:s) {
            if(!temp->chld[c - 'a'])
                temp->chld[c - 'a'] = new TrieNode();
            temp = temp->chld[c - 'a'];
            temp->cnt++;
        }
    }
    int getPrefScore(string word) {
        int score = 0;
        TrieNode* temp = root;
        for(char &c:word) {
            temp = temp->chld[c  - 'a'];
            score += temp->cnt;
        } 
        return score;
    }
};

class Solution {
private:
    Trie* trie = new Trie();
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string &word:words) {
            trie->constructTrie(word);
        }
        vector<int> prefScores;
        for(string &word:words) {
            prefScores.push_back(trie->getPrefScore(word));
        }
        return prefScores;
    }
};