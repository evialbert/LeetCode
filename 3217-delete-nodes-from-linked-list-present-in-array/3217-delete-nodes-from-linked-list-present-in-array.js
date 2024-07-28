/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
    let node = new ListNode(0, head), numsSet = new Set(nums)
    while(node.next !== null) {
        let val = node.next.val
        if (numsSet.has(val)) {
            if (node.next === head) head = head.next
            node.next = node.next.next
        } else node = node.next
    }
    return head
};