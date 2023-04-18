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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long,vector<long>,greater<long>> pq;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()){
            int size=que.size();
            long sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                sum+=node->val;
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            if(pq.size()<k)
                pq.push(sum);
            else if(pq.size()==k){
                if(pq.top()<sum){
                    pq.push(sum);
                    pq.pop();
                }
            }
        }
        if(pq.size()<k)
            return -1;
        return pq.top();
    }
};