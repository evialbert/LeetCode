/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
    Node res = head;

    while(head != null) {
        if(head.child != null) {
            Node children = flatten(head.child);
            head.child = null;
            Node temp = head.next;

			//connect child nodes with head
            head.next = children;
            children.prev = head;

			//find tail of child node
            while(children.next != null) 
                children = children.next;
			
			//connect tail with head.next node
            children.next = temp;
            if(temp != null) temp.prev = children;

            head = temp;
        }
        else
            head = head.next;
    }

    return res;
}
}