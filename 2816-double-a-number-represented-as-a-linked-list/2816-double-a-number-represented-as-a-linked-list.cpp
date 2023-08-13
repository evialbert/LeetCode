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
    ListNode* doubleIt(ListNode* head) {
        vector<int>a,b;
        ListNode*t=head;
        while(t!=NULL)
        {
            a.emplace_back(t->val);
            t=t->next;
        }
        if(a.size()==1 and a[0]==0)
            return head;
        else
        {
            int c=0;
            for(int i=a.size()-1;i>=0;i--)
            {
                c=a[i]*2+c;
                b.emplace_back(c%10);
                c/=10;
            }
            if(c>0)
                b.emplace_back(c);
            
            head=NULL;
            t=NULL;
            for(int i=b.size()-1;i>=0;i--)
            {
                ListNode*newnode=new ListNode(b[i]);
                if(head==NULL)
                    head=t=newnode;
                else
                {
                    t->next=newnode;
                    t=newnode;
                }
            }
            return head;
        }
    }
};