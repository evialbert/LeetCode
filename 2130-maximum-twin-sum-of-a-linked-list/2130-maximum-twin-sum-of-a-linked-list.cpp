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
    int pairSum(ListNode* head) {
        ListNode* ptr=head;
       vector<int>v;
        while(ptr!=NULL){
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        int n=v.size();
        int maxsum=0;
        for(int i=0;i<v.size();i++){
            if(i>=0 && i<=(n/2)-1)
            {int sum=v[i]+v[n-1-i];
            
            maxsum=max(maxsum,sum);
            }

        }
        return maxsum;

    }
};