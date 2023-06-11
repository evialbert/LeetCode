/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
const join = function(arr1, arr2) {
    const ids = {};
    for(const o of arr1) ids[o.id] = o; 
    for(const o of arr2) ids[o.id] = ids[o.id] ? {...ids[o.id], ...o} : o;
    return Object.values(ids);
};