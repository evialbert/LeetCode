/**
 * @param {number} n
 * @return {string[]}
 */
var validStrings = (n, subs = ['0', '1']) =>
    n > 1 ? validStrings(n - 1, [...subs.map(v => v + 1), ...subs.map(v => v + 0)]) : subs.filter(s => s.indexOf('00') < 0);