/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var minSumOfLengths = function(arr, target) {
    const len = arr.length
    const sumFL = new Array(len)
    sumFL[-1] = 0
    for (let i = 0; i < len; i++) {
        const val = arr[i]
        sumFL[i] = val + sumFL[-1 + i]
    }
    
    const sumFR = new Array(1 + len)
    sumFR[len] = 0
    for (let i = -1 + len; i >= 0; i--) {
        const val = arr[i]
        sumFR[i] = val + sumFR[1 + i]
    }
    
    
    const bestFL = new Array(len)
    bestFL[-1] = Infinity
    const lastIndexFL = new Map()
    lastIndexFL.set(0, -1)
    for (let i = 0; i < len; i++) {
        const sumSF = sumFL[i]
        const seekMe = sumSF - target
        
        let outcome
        if (lastIndexFL.has(seekMe)) {
            outcome = i - lastIndexFL.get(seekMe)
        } else {
            outcome = Infinity
        }
        bestFL[i] = Math.min(bestFL[i - 1], outcome)
        
        lastIndexFL.set(sumSF, i)
    }
    
    const bestFR = new Array(1 + len)
    bestFR[len] = Infinity
    const firstIndexFR = new Map()
    firstIndexFR.set(0, len)
    for (let i = -1 + len; i >= 0; i--) {
        const sumSF = sumFR[i]
        const seekMe = sumSF - target
        
        let outcome
        if (firstIndexFR.has(seekMe)) {
            outcome = firstIndexFR.get(seekMe) - i
        } else {
            outcome = Infinity
        }
        bestFR[i] = Math.min(bestFR[i + 1], outcome)
        
        firstIndexFR.set(sumSF, i)
    }
    
    
    let result = Infinity
    for (let i = 0; i < len - 1; i++) {
        let outcome = bestFL[i] + bestFR[1 + i]
        result = Math.min(result, outcome)
    }

    
    if (result === Infinity)    result = -1
    return result
};