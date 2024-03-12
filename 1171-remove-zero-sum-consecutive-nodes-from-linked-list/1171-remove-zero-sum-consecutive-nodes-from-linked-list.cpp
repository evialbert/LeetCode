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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        map<int,ListNode*>prefix;
        int sum = 0;
        prefix[sum] = dummy;
        
        while(head!= NULL) {
            sum += head->val;
            if(prefix.find(sum) != prefix.end()) {
                ListNode* removeNode = prefix[sum]->next;
                int removeSum = sum;
                while(removeNode != head) {
                    removeSum += removeNode->val;
                    prefix.erase(removeSum);
                    removeNode = removeNode->next;
                }
                prefix[sum]->next = head->next;
            }
            else {
                prefix[sum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};