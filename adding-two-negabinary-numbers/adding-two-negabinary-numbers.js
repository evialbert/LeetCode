/**
 * @param {number[]} arrA
 * @param {number[]} arrB
 * @return {number[]}
 */
var addNegabinary = function(arrA, arrB) {
    const lenA = arrA.length, lenB = arrB.length
    const maxLen = Math.max(lenA, lenB)
    arrA.reverse()
    arrB.reverse()
    
    
    let result = [], carry = 0, i = 0
    for (; i < maxLen; i++) {
        const valA = arrA[i] || 0, valB = arrB[i] || 0
        let sum = valA + valB - carry
        let outcome
        if (sum < 0) {
            sum += 2
            carry = -1
            outcome = sum % 2
        } else {
            outcome = sum % 2
            if (sum >= 2) {
                carry = 1
            } else {
                carry = 0
            }
        }
        
        
        result.push(outcome)
    }
    
    if (carry) {
        result.push(1, 1)
    }
    

    while (result.length > 1 && result[result.length - 1] === 0)
        result.pop()
    
    
    result.reverse()
    return result
};