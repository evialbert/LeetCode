class Solution {
    Random rand;
    ListNode head;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
        rand = new Random();
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        int count = 0;
        int res = -1;
        ListNode curr = head;
        while(curr != null){
            count++;
            int val = rand.nextInt(count);
            if(val == count-1){
                res = curr.val;
            }
            curr = curr.next;
        }
        return res;
    }
}