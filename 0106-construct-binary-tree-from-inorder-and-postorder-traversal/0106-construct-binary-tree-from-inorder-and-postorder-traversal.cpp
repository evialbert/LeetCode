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
    int last_index_postorder;

    TreeNode *makeTree(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(end < start){
            return NULL;
        }

        last_index_postorder--;
        int rootVal = postorder[last_index_postorder];
        int rootIdx;

        TreeNode *root = new TreeNode(rootVal);

        for(int i = start; i <= end; i++){
            if(inorder[i] == rootVal){
                rootIdx = i;
                break;
            }
        }
        root->right = makeTree(inorder, postorder, rootIdx+1, end);
        root->left = makeTree(inorder, postorder, start, rootIdx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        last_index_postorder = postorder.size();
        return makeTree(inorder, postorder, 0, postorder.size()-1);
    }
};