/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function(num) {
    let digits = [];
    let originalNum = num;

    // Extract digits into array
    while (num > 0) {
        digits.push(num % 10);
        num = Math.floor(num / 10);
    }

    let n = digits.length;
    let currMax = -1;

    // Find the first peak (a digit greater than the next one)
    for (let i = n - 2; i >= 0; i--) {
        if (digits[i] > digits[i + 1]) {
            currMax = i;
            break;
        }
    }

    // If no peak is found, return the original number
    if (currMax === -1) return originalNum;

    // Find the maximum digit to the right of the peak
    for (let i = currMax + 1; i >= 0; i--) {
        if (digits[i] >= digits[currMax]) {
            currMax = i;
        }
    }

    // Swap the first smaller digit with the largest one found
    for (let i = n - 1; i >= 0; i--) {
        if (digits[i] < digits[currMax]) {
            [digits[i], digits[currMax]] = [digits[currMax], digits[i]];
            break;
        }
    }

    // Rebuild the number
    let result = 0;
    for (let i = n - 1; i >= 0; i--) {
        result = result * 10 + digits[i];
    }

    return result;
};