/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
var customSortString = function(order, s) {
    const map = {};
    for (let i = 0; i < order.length; i++) {
        map[order.charAt(i)] = i + 1;
    };

    const notIncluded = [];
    const included = [];
    for (let i = 0; i < s.length; i++) {
        const letter = s.charAt(i);
        if (map[letter]) {
            included.push(letter)
        } else {
            notIncluded.push(letter)
        }
    }

    const result = included
        .sort((a,b) => map[a] - map[b])
        .join("");

    return result + notIncluded.join("");
};