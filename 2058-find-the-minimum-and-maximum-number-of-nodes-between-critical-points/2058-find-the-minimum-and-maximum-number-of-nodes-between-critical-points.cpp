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
    bool criticalPoint(ListNode* prev, ListNode* curr, ListNode* next)
    {
        if(prev == NULL || curr == NULL || next == NULL)
        {
            return false;
        }
        if((prev-> val < curr-> val && curr-> val > next-> val) || (prev-> val > curr-> val && curr-> val < next-> val))
        {
            return true;
        }
        return false;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v = {-1,-1};
        vector<int> index;

        if(head-> next == NULL || head == NULL || head-> next-> next == NULL)
        {
            return {-1,-1};
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head-> next;
        int i = 1;

        while(next != NULL)
        {
            bool check = criticalPoint(prev,curr,next);
            if(check)
            {
                index.push_back(i);
            }
            prev = curr;
            curr = next;
            next = next-> next;
            i++;
        }

        if(index.size() < 2)
        {
            return v;
        }

        int minDis = INT_MAX;
        int maxDis = index.back() - index.front();
        int n = index.size();

        for(int i=1;i<n;i++)
        {
            minDis = min(minDis, index[i] - index[i-1]);
        }

        v[0] = minDis;
        v[1] = maxDis;

        return v;
    }
};