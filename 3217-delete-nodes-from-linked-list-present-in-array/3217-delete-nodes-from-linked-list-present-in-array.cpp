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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> mp;
        for (int i : nums)
            mp[i] = true;

        while(mp[head->val]){
            head = head->next;
        }
        ListNode* temp = head;
        while (head->next) {
            if (mp[head->next->val]) {
                head->next = head->next->next;
            } else
                head = head->next;
        }
        return temp;
    }
};