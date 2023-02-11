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
	ListNode* removeNodes(ListNode* head) {
		ListNode* ptr=head;
		stack<int>s;

		while(ptr){
			if(s.empty()){
				s.push(ptr->val);
			}
			else{
				if(!s.empty() && s.top()<ptr->val){
					while(!s.empty() && s.top()<ptr->val){
						s.pop();
					}
				}
				s.push(ptr->val);
			}
			ptr=ptr->next;
		}
        
        // Basically creating a new LL.
		ListNode *root = NULL;
		while(!s.empty()){
			ListNode* temp = new ListNode;
		    temp->val= s.top();
		    temp->next = root;
		    root = temp;
			s.pop();
		}
		return root;
	}
};