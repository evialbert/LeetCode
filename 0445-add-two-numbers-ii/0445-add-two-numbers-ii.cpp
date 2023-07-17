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
    ListNode * reverseList(ListNode *head){
        ListNode *curr=head,*first=NULL,*second=NULL;
        while(curr!=NULL){
            second=first;
            first=curr;
            curr=curr->next;
            first->next=second;
        }
        return first;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1=reverseList(l1);
        ListNode *head2=reverseList(l2);
        ListNode *head3=new ListNode(),*curr=head3;
        int carry=0;
        while((head1!=NULL || head2!=NULL)|| carry){
            int sum=0;
            if(head1!=NULL){
                sum+=head1->val;
                head1=head1->next;
            }
            if(head2!=NULL){
                sum+=head2->val;
                head2=head2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *temp=new ListNode(sum%10);
            curr->next=temp;
            curr=curr->next;
        }
        return reverseList(head3->next);
    }
};