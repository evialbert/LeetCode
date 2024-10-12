/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, k) {
    const q = new MinPriorityQueue(nums);
    let count =0
    
    for(const num of nums)q.enqueue(num)

    while(q.size() && q.front().element < k){
        const a = q.dequeue().element;
        const b = q.dequeue().element;

        const val = Math.min(a,b) * 2 + Math.max(a,b)
        q.enqueue(val)
        count++
    }
    
    
    return count
};