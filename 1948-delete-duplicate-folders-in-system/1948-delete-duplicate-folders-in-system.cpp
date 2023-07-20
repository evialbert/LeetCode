class TrieNode {
public:
    map<string, TrieNode*> children;
    bool isEnd;
    bool isExcluded;
    string name;
    TrieNode(string folder) {
        name = folder;
        isEnd = false;
        isExcluded = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode("/");
    }
    void insert(vector<string>& path) {
        int n = path.size();
        TrieNode* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr->children.find(path[i]) == curr->children.end()) {
                curr->children[path[i]] = new TrieNode(path[i]);
            }
            curr = curr->children[path[i]];
        }
        curr->isEnd = true;
    }
    void findDuplicate(unordered_map<string, vector<TrieNode*>>& mp) {
        hashAndStore(root, mp);
    }
    string hashAndStore(TrieNode* node, unordered_map<string, vector<TrieNode*>>& mp) {
        string curr = "";
        for (auto child : node->children) {
            curr += hashAndStore(child.second, mp);
            curr.push_back('|');
        }
        if (curr != "") mp[curr].push_back(node);
        return node->name + "|" + curr;
    }
    void markDuplicate(unordered_map<string, vector<TrieNode*>>& mp) {
        for (auto element : mp) {
            if (element.second.size() > 1) {
                for (auto node : element.second) {
                    node->isExcluded = true;
                }
            }
        }
    }
    void getNotDuplicate(vector<vector<string>>& ans, vector<string>& path) {
        _getNotDuplicate(root, ans, path);
    }
    void _getNotDuplicate(TrieNode* node, vector<vector<string>>& ans, vector<string>& path) {
        if (node->isExcluded) return;
        if (node->isEnd) ans.push_back(path);
        for (auto child : node->children) {
            path.push_back(child.second->name);
            _getNotDuplicate(child.second, ans, path);
            path.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* trie = new Trie();
        for (auto path : paths) trie->insert(path);
        
        unordered_map<string, vector<TrieNode*>> mp;
        trie->findDuplicate(mp);
        trie->markDuplicate(mp);
        
        vector<vector<string>> ans;
        vector<string> path;
        trie->getNotDuplicate(ans, path);
        return ans;
    }
};