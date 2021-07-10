/**
 * @param {number[]} fronts
 * @param {number[]} backs
 * @return {number}
 */
var flipgame = function (fronts, backs) {
  let unAvoidable = new Set(), rtn = Number.MAX_SAFE_INTEGER
  for (let i = 0; i < fronts.length; i++) {
    if (fronts[i] == backs[i]) unAvoidable.add(fronts[i])
  }
  for (let i = 0; i < fronts.length; i++) {
    if (!unAvoidable.has(fronts[i])) rtn = Math.min(fronts[i], rtn)
    if (!unAvoidable.has(backs[i])) rtn = Math.min(backs[i], rtn)
  }
  return rtn == Number.MAX_SAFE_INTEGER ? 0 : rtn
};