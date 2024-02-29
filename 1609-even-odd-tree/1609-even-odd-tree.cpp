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
bool check(queue<TreeNode*>&q,int &level){
    int sz=q.size();
    int prev= !level?-1:INT_MAX ; //setting prev to '-1' if level even and 'infinity' if level odd
    while(sz--){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
        if(!level){ //for even level ie strictly increasing
            if(curr->val%2==0 || curr->val<=prev)return false;
            prev=curr->val;
        }
        else{   //for odd level i.e strictly decreasing
            if(curr->val%2==1 || curr->val>=prev)return false;
            prev=curr->val;
        }
    }
    return true;
}
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        int level=0;// '0' = even level , '1' = odd level
        q.push(root);
        //layer by layer bfs
        while(!q.empty()){
            if(!check(q,level))return false;
            level=!level;
        }
        return true;
    }
};