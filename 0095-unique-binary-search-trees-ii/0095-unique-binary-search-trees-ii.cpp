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
public:
    vector<TreeNode*> dp[10][10];

    vector<TreeNode*> generateTrees(int n) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = {};
            }
        }

        return _generateTrees(1, n);
    }

    vector<TreeNode*> _generateTrees(int lBound, int rBound) {
        vector<TreeNode*> ret;
        vector<TreeNode*> lTree;
        vector<TreeNode*> rTree;
        TreeNode* root = nullptr;
        int lCnt = 0;
        int rCnt = 0;

        if (dp[lBound][rBound].size()) {
            return dp[lBound][rBound];
        }

        if (lBound == rBound) {
            root = new TreeNode(lBound);
            ret = {root};
            goto End;
        }

        if (lBound >= rBound) {
            ret = {nullptr};
            goto End;
        }

        for (int mid = lBound; mid <= rBound; mid++) {
            lCnt = mid - lBound;
            rCnt = rBound - mid;

            lTree = _generateTrees(lBound, mid-1);
            rTree = _generateTrees(mid+1, rBound);

            for (auto lRoot : lTree) {
                for (auto rRoot : rTree) {
                    root = new TreeNode(mid);
                    root->left = lRoot;
                    root->right = rRoot;

                    ret.push_back(root);
                }
            }
        }

End:
        return dp[lBound][rBound] = ret;
    }
};