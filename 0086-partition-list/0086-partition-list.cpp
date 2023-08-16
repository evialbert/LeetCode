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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)return head;
        ListNode* beforeList=new ListNode(0);
        ListNode* afterList=new ListNode(0);
        
        ListNode* temp1=beforeList,*temp2=afterList;
        
        ListNode* cur=head;
        
        while(cur){
            if(cur->val<x){
                temp1->next=new ListNode(cur->val);
                temp1=temp1->next;
            }else{
                temp2->next=new ListNode(cur->val);
                temp2=temp2->next;
            }
            cur=cur->next;
        }
        temp1->next=afterList->next;
        return beforeList->next;
        
    }
};