class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false;
                }
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false;
                }
            }
        }
        
        int rootNode = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (rootNode != -1) {
                    return false;
                }
                rootNode = i;
            }
        }
        
        if (rootNode == -1) {
            return false;
        }
        
        vector<bool> visited(n, false);
        stack<int> dfs;
        dfs.push(rootNode);
        
        while (!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();
            
            if (visited[node]) {
                return false;
            }
            
            visited[node] = true;
            
            if (leftChild[node] != -1) {
                dfs.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                dfs.push(rightChild[node]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        
        return true;
    }
};
