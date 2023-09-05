/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Edge case
        if(head == NULL) return NULL;

        // Make a hash table that stores the node node to index key->pair values for the original List
        map<Node*, int> mp;
        mp[head] = 0;
        int idx = 1;

        // Iterate through the original list to form the deep copy (entirely new list) & the hash table
        // The deep copy has only the next nodes set here & the random nodes are not set here
        Node *res = new Node(head -> val), *temp = head -> next, *store = res;
        while(temp != NULL){
            mp[temp] = idx++;
            Node *t = new Node(temp -> val);
            res -> next = t;
            res = t;
            temp = temp -> next;
        }

        // Iterate through both the lists (two-pointers) & update the 'random' pointers in the deep copy by using the hash table
        // We cannot set the random pointers of the deepcopy nodes in the previos loop as they may be pointing to a node ahead that doesn't exits in the deep copy formed so far
        temp = head;
        res = store;
        while(temp != NULL){
            // If the random value for the current node is NULL (as NULL is not mapped in the hash table)
            if(temp -> random == NULL){
                res -> random = NULL;
            }
            // Else check the hash table for the index of the random pointer to the current node
            else{
                int i = mp[temp->random];
                head = store;
                // Find the respective pointer in the deep copy
                while(i > 0){
                    head = head -> next;
                    i--;
                }
                res -> random = head;
            }

            // Move ahead in the lists
            res = res -> next;
            temp = temp -> next;
        }

        // Return the head of the deep copy
        return store;
    }
};