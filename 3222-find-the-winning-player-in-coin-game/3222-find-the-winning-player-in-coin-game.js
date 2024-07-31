/**
 * @param {number} x
 * @param {number} y
 * @return {string}
 */
var losingPlayer = function(x, y) {
    return Math.min(Math.floor(x), Math.floor(y / 4)) % 2 ? "Alice" : "Bob";
};