/**
 * @param {number} k
 * @param {number} x
 * @return {number}
 */
var findMaximumNumber = function(k, x) {
    const masks = []
    const ub = (1 << x) * k
    for (let mask = 1 << (x - 1), factor = 2 ** x; mask <= ub; mask *= factor) {
        masks.push(mask)
    }

    function getTotalPrice(n) {
        let result = 0
        for (const mask of masks) {
            if (mask > n)   break

            let outcome
            if (mask === 1) {
                outcome = Math.ceil(n / 2)
            } else {
                const doubled = mask * 2
                const rmd = n % doubled
                const times = (n - rmd) / doubled
                outcome = times * mask
                if (rmd >= mask) {
                    outcome += 1 + rmd - mask
                }
            }

            result += outcome
        }
        
        return result
    }


    let low = 1, high = ub 
    // find latest low where
    // getTotalPrice(low) <= k
    while (low < high) {
        const mid = Math.ceil((low + high) / 2)
        const midVal = getTotalPrice(mid)
        if (midVal <= k)    low = mid
        else    high = mid - 1
    }


    return low
};