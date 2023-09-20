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

    void swapNode(ListNode* curr, ListNode* prev, ListNode* prev2, ListNode*&head){
        if(prev2==NULL){
            prev->next=curr->next;
            curr->next=prev;
            head=curr;
        }
        else{
            prev->next=curr->next;
            curr->next=prev;
            prev2->next=curr;
        }
    }


    ListNode* swapPairs(ListNode* head) {
        ListNode* prev2=NULL;
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        if(head==NULL){
            return NULL;
        }
        if(head and !head->next){
            return head;
        }
        if(head and head->next){
            curr=head->next;
            prev=head;
            while(curr){
                cout<<curr->val;
                cout<<prev->val;
                if(prev2){
                    cout<<prev2->val;
                }
                swapNode(curr, prev, prev2, head);
                prev2=prev;
                prev=prev->next;
                if(curr){
                    curr=curr->next;
                }
                if(curr){
                    curr=curr->next;
                }
                if(curr){
                    curr=curr->next;
                }
            
            }
        }
        return head;
    }
};