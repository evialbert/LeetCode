/**
 * @param {number[]} nums
 * @param {number[]} freq
 * @return {number[]}
 */
var mostFrequentIDs = function(nums, freq) {
    const cnt = new Map(); 
    const pq = new PriorityQueue({ compare : (x, y) => y[0]-x[0] }); 
    const ans = []; 
    for (const [i, x] of nums.entries()) {
        const f = freq[i]; 
        cnt.set(x, f + (cnt.get(x) ?? 0)); 
        while (pq.size() && cnt.get(pq.front()[1]) != pq.front()[0]) pq.dequeue(); 
        pq.enqueue([cnt.get(x), x]); 
        ans.push(pq.front()[0]); 
    }
    return ans; 
};