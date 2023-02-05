/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int depth[100005], height[100005];

    // max and second max height at depth d
    int max_h[100005][2];
    
    
    int dfs(TreeNode* root, int d) {
        if(root == NULL)
            return 0;
			
        depth[root->val] = d;
        int left = dfs(root->left, d+1);
        int right = dfs(root->right, d+1);
        
        int h = 1 + max(left, right);
        height[root->val] = h;
        
        if(h > max_h[d][0]) {
            max_h[d][1] = max_h[d][0];
            max_h[d][0] = h;
        } else {
            max_h[d][1] = max(max_h[d][1], h);
        }
        
        return h;
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        
        for(int i = 0; i <= 3; i++) 
            cout << max_h[i][0] << " " << max_h[i][1] << endl;
        cout << endl;
        
        vector<int> ans;
        for(int u: queries) {
            int d = depth[u];
            if(max_h[d][1] == 0) 
                ans.push_back(d-1);
            else if(max_h[d][0] == height[u]) 
                ans.push_back(d+max_h[d][1]-1);
            else 
                ans.push_back(d+max_h[d][0]-1);
        }
        
        return ans;
    }
};