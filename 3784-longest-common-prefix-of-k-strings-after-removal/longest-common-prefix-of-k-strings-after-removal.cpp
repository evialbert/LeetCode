class TrieNode {
public:
    int freq;
    bool isTerminal;
    TrieNode* child[26];
    int maxDepth; 

    TrieNode() : freq(0), isTerminal(false), maxDepth(0) {
        memset(child, 0, sizeof(child));
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(const string &word) {
        TrieNode* node = root;
        node->freq++;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
            node->freq++;
        }
        node->isTerminal = true;
    }

   
    void updateMaxDepth(TrieNode* node, int depth, int k) {
        if (node->freq < k) {
            node->maxDepth = -1; 
        } else {
            int candidate = depth;  
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && node->child[i]->maxDepth > candidate)
                    candidate = node->child[i]->maxDepth;
            }
            node->maxDepth = candidate;
        }
    }

   
    void remove(const string &word, int k) {
        vector<pair<TrieNode*, int>> path; 
        TrieNode* node = root;
        int depth = 0;
        path.push_back({node, depth});
        node->freq--;
        for (char c : word) {
            int idx = c - 'a';
            node = node->child[idx];
            depth++;
            node->freq--;
            path.push_back({node, depth});
        }
        node->isTerminal = false;
        
        for (int i = path.size() - 1; i >= 0; i--) {
            updateMaxDepth(path[i].first, path[i].second, k);
        }
    }

 
    void reinsert(const string &word, int k) {
        vector<pair<TrieNode*, int>> path;
        TrieNode* node = root;
        int depth = 0;
        path.push_back({node, depth});
        node->freq++;
        for (char c : word) {
            int idx = c - 'a';
            node = node->child[idx];
            depth++;
            node->freq++;
            path.push_back({node, depth});
        }
        node->isTerminal = true;
        for (int i = path.size() - 1; i >= 0; i--) {
            updateMaxDepth(path[i].first, path[i].second, k);
        }
    }

    
    int solve() {
        return root->maxDepth;
    }


    void initMaxDepth(TrieNode* node, int depth, int k) {
        for (int i = 0; i < 26; i++) {
            if (node->child[i])
                initMaxDepth(node->child[i], depth + 1, k);
        }
        if (node->freq < k)
            node->maxDepth = -1;
        else {
            int candidate = depth;
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && node->child[i]->maxDepth > candidate)
                    candidate = node->child[i]->maxDepth;
            }
            node->maxDepth = candidate;
        }
    }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie tr;
     
        for (auto &w : words) {
            tr.insert(w);
        }
     
        tr.initMaxDepth(tr.root, 0, k);

        vector<int> ans;
       
        for (auto &w : words) {
            tr.remove(w, k);
            ans.push_back(max(tr.solve() , 0));
            tr.reinsert(w, k);
        }
        return ans;
    }
};