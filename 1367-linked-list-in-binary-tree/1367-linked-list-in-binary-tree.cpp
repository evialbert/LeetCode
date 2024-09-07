/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode* curr,ListNode* head){
        
        if(curr->val!=head->val)return false;
        if(head->next==NULL)return true;
        bool ans=false;
        if(curr->left)ans|=check(curr->left,head->next);
        if(curr->right)ans|=check(curr->right,head->next);
        return ans;
    }
    bool dfs(TreeNode* curr,ListNode* head){
        bool ans=false;
        if(check(curr,head))return true;       //check for every node
        if(curr->left)ans|=dfs(curr->left,head);
        if(curr->right)ans|=dfs(curr->right,head);
        return ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root,head);
    }
};