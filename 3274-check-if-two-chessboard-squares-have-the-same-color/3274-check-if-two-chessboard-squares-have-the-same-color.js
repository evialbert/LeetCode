/**
 * @param {string} coordinate1
 * @param {string} coordinate2
 * @return {boolean}
 */
var checkTwoChessboards = function(coordinate1, coordinate2) {
    return (coordinate2[0].charCodeAt(0) - coordinate1[0].charCodeAt(0) + +coordinate2[1] - +coordinate1[1]) % 2 === 0;
};