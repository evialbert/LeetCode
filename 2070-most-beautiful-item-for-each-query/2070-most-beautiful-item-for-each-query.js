/**
 * @param {number[][]} items
 * @param {number[]} queries
 * @return {number[]}
 */
var maximumBeauty = function(items, queries) {
    var arr = [], vlarr, max;
    items.sort((a,b) => b[1] - a[1]);
    for (var i of queries) {
        vlarr = items.find(v => v[0] <=i);
        if (vlarr) {
            arr.push(vlarr[1])
        }else {
            arr.push(0)
        }
    }
    return arr.length ? arr : [0]
};