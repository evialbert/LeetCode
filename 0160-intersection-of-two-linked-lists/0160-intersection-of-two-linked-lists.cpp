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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    
        int length1=0, length2=0;
        ListNode *p1=headA, *p2=headB;

        while(p1!=NULL){
            length1++;
            p1 = p1->next;
        }
        
        while(p2!=NULL){
            length2++;
            p2 = p2->next;
        }

        p1 = headA;
        p2 = headB;

        int diff = length1-length2;

        if(diff > 0)
            for(int i=0; i<diff; i++)
                p1 = p1->next;

        if(diff < 0)
            for(int i=0; i<abs(diff); i++)
                p2 = p2->next;
        
        while(p1!=NULL && p2!=NULL){

            if(p1 == p2)
                return p1;

            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }
};