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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n =  0 ;
        for(ListNode* temp = head ; temp ; temp = temp->next) n++ ;

        int rem = n%k , len = n/k ;
        vector<ListNode*> ans(k , NULL) ;
        ListNode* node = head, *prev = nullptr;
        for(int i = 0 ; head && i < k ; i++ ,rem--){
            ans[i] = head ;
            for(int j = 0 ; j < len + (rem>0) ; j++){
                prev = head ;
                head = head->next ;
            }
            prev-> next = NULL ;
        }
        return ans ;
    }

};
