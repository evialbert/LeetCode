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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>v(m,vector<int>(n,-1));
         int row = 0,col = 0;
        int rf = m-1, cf = n-1;
         while(head && row<=rf && col<=cf)
        {
            if(row<=rf)
            {
                for(int i = col;i<=cf && head;i++)
                {
                 
                    v[row][i] = head->val;
                    head = head->next;
                    
                }
                row++;
            }
            if(col<=cf)
            {
                for(int i = row;i<=rf && head;i++)
                {
                   
                    v[i][cf] = head->val;
                    head = head->next;
                }
                cf--;
            }
            if(row<=rf)
            {
                for(int i = cf;i>=col && head;i--)
                {
                    
                    v[rf][i] = head->val;
                    head = head->next;
                    
                }
                rf--;
            }
            if(col<=cf)
            {
                for(int i = rf;i>=row && head;i--)
                {
                   
                    v[i][col] = head->val;
                    head = head->next;
                }
                col++;
            }
        }
        return v;
    }
};