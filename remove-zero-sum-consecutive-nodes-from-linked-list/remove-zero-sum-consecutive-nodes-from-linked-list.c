/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeZeroSumSublists(struct ListNode* head){
   //create a dummy point prior to original head
    struct ListNode* first = calloc(1, sizeof(struct ListNode));
    first ->next = head;
    head = first;
    
    while (first != NULL && first->next != NULL) {
        int sum = 0;
        struct ListNode* sec = first->next;
        sum += sec->val;
        sec = sec->next;

        while (sec != NULL && sum != 0) {
            sum += sec->val;
            sec = sec->next;
        }
		
        if (sum == 0) 
            first->next = sec;  // Do not move to next since the link is changed after reconnect
        else   
            first = first->next;
    }
   
    return head->next;
}