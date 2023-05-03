/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    for (let num of arr) {
        if (Array.isArray(num)) {
            yield* inorderTraversal(num)
        } else {
            yield num;
        }
    }
};