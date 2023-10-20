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
    bool isPalindrome(ListNode* head) {
        if(!head)   return false;
        if(!head->next) return true;

        ListNode *rev_head = NULL , *ptr = head;
        while(ptr != NULL)
        {
            ListNode *temp = new ListNode(ptr->val);
            temp->next = rev_head;
            rev_head = temp;
            ptr = ptr->next;
        }

        while(head && rev_head)
        {
            if(head->val != rev_head->val)  return false;
            else
            {
                head = head->next;
                rev_head = rev_head->next;
            }
        }
        return true;


        
    }
};