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
        
    TreeNode *helperBst(ListNode *head, ListNode *tail)
    {
        if(head == tail)
        {
            return NULL;
        }
        //tortoise and hare method to find mid of element
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode * root = new TreeNode(slow->val);
        root->left = helperBst(head, slow);
        root->right = helperBst(slow->next, tail);
        return root;
            
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return helperBst(head, NULL);
    }
};