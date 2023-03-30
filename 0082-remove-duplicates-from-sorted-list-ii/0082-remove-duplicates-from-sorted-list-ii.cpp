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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t=head;
        int c=1;
        ListNode* dummy=new ListNode(1);
        ListNode* ans=dummy;
        int f=1;
        while(f && t)
        {
            ListNode* p=t;
            int c=0;
            while(t->next && t->val==t->next->val)
            {
                c++;
                t=t->next;
            }
            if(c==0)
            {
                ans->next=p;
                ans=ans->next;
            }
            t=t->next;
        }
        ans->next=NULL;
        return dummy->next;
    }
};