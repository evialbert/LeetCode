/**
 * @param {number[]} answers
 * @return {number}
 */
var numRabbits = function (answers) {
    const map = new Map();
    let total = 0;

    for (let ans of answers) {
        if (ans === 0) {
            total += 1;
        } else if (!map.has(ans)) {
            map.set(ans, 1);
            total += ans + 1;
        } else {
            map.set(ans, map.get(ans) + 1);
            if (map.get(ans) > ans + 1) {
                map.set(ans, 1);
                total += ans + 1;
            }
        }
    }
    return total;
};