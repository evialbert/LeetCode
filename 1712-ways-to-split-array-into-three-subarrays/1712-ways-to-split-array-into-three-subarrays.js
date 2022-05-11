/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplit = function(nums) {
    const modMe = 10 ** 9 + 7
    const len = nums.length
    
    const sumSF = new Array(len)
    sumSF[-1] = 0
    for (const [i, val] of nums.entries()) {
        let prevOutcome = sumSF[-1 + i]
        let outcome = val + prevOutcome
        sumSF[i] = outcome
    }
    const total = sumSF[-1 + len]
    
    
    let result = 0
    eachToIndexA:
    for (let toIndexA = 0, minToIndexB = 1, maxToIndexB = 1;
    toIndexA < -2 + len; toIndexA++) {
        const sumA = sumSF[toIndexA]
        
        for (minToIndexB = Math.max(1 + toIndexA, minToIndexB);
        minToIndexB < len - 1; minToIndexB++) {
            const sumB = sumSF[minToIndexB] - sumA
            const sumC = total - sumSF[minToIndexB]
            
            // when it is impossible from now on
            if (sumB > sumC)    continue eachToIndexA
            // first minToIndexB that satisfies condition
            if (sumB >= sumA)   break
        }
        if (minToIndexB === len - 1)    continue
        
        
        for (maxToIndexB = Math.max(minToIndexB, maxToIndexB);
        maxToIndexB < len - 1; maxToIndexB++) {
            const sumB_ = sumSF[1 + maxToIndexB] - sumA
            const sumC_ = total - sumSF[1 + maxToIndexB]
            if (sumB_ > sumC_) {
                break
            }
        }
        if (maxToIndexB === len - 1)
            maxToIndexB--
        

        let outcome = 1 + maxToIndexB - minToIndexB
        result += outcome
        result %= modMe
    }
    
    
    return result
};