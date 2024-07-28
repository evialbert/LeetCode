/**
 * @param {number} m
 * @param {number} n
 * @param {number[]} horizontalCut
 * @param {number[]} verticalCut
 * @return {number}
 */
var minimumCost = function (m, n, horCut, verCut) {
  let totalCost = 0;
  const cuts = [1, 1];
  [...horCut.map(v => [v, 1]), ...verCut.map(v => [v, 0])].sort((x, y) => y[0] - x[0])
    .forEach(([cost, dir]) => (totalCost += cost * cuts[dir], cuts[1 - dir]++));
  return totalCost;
};
