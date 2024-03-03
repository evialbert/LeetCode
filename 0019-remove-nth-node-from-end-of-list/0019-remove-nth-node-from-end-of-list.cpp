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
    int length(ListNode* head){
        ListNode* p = head;
        int l = 0;
        while(p != NULL){
            l++;
            p = p->next;
        }
        return l;
    }
    ListNode* solve(ListNode* head,int k){
        if(head == NULL)return NULL;
        if(k==0)return head->next;
        head->next = solve(head->next,k-1);
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = length(head);
        return solve(head,l-n);
    }
};