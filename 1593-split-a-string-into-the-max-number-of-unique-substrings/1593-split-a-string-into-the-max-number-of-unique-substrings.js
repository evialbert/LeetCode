/**
 * @param {string} s
 * @return {number}
 */
var maxUniqueSplit = function(s) {
    const n = s.length;
    const seen = new Set();
    
    let maxCount = 0;
    
    backtrack(0);
   
    return maxCount;
    
    function backtrack(start) {
        if (start === n) {
            maxCount = Math.max(maxCount, seen.size);
            return;
        }
        
        for (let i = start; i < n; i++) {
            const sub = s.substring(start, i + 1);
            
            if (!seen.has(sub)) {
                seen.add(sub);
                backtrack(i + 1);
                seen.delete(sub);
            }
        }
        
        return;
    }
};