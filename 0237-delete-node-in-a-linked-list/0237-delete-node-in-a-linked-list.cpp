/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // swap the value of node and node -> next
        
        swap(node -> val, node -> next -> val);
        
        // now point the node -> next to node -> next -> next
        
        node -> next = node -> next -> next;
    }
};