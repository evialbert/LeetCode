/**
 * @param {number[]} start
 * @param {number} d
 * @return {number}
 */
var maxPossibleScore = function(start, d) {
    // Helper function to check if a given mid value is valid
    const check = (start, d, mid) => {
        let prev = start[0];
        for (let i = 1; i < start.length; i++) {
            let next = Math.max(prev + mid, start[i]);
            if (next > start[i] + d) {
                return false;
            }
            prev = next;
        }
        return true;
    };

    // Sort the array
    start.sort((a, b) => a - b);
    
    let low = 0;
    let hi = start[start.length - 1] - start[0] + d;
    let ans = 0;

    // Binary search for the maximum possible score
    while (low <= hi) {
        let mid = Math.floor((low + hi) / 2);
        if (check(start, d, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return ans;
};
