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
class Solution {
public:
    
    void helper(ListNode* right, int floor){
        if(right == NULL)
          return;

          helper(right->next, floor + 1);

          if(floor > sz/2){
              ListNode* temp = fleft->next;
              fleft->next = right;
              right->next = temp;
              fleft = temp;
          }
          else if(floor == sz/2)
              right->next = NULL;
    }
    
    int sz = 0;
    void size(ListNode* temp){
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
    }
    
    ListNode* fleft;
    void reorderList(ListNode* head) {
        size(head);
        fleft = head;
        helper(head, 0);
    }
};