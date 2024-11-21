/**
 * @param {string[]} strs
 * @return {string[][]}
 */
const groupAnagrams = function(strs) {
  const map = new Map();
  
  for (let str of strs) {
    let curr = [...str].sort().join('');
    if (!map.has(curr)) map.set(curr, []);
    map.get(curr).push(str);
  }
  return Array.from(map.values());
};