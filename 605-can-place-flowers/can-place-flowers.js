/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbed, n) {
  const len = flowerbed.length;
  if (n === 0 || (n === 1 && flowerbed[0] === 0 && len === 1)) {
    return true;
  }

  for (let i = 0; i < len; i++) {
    if (flowerbed[i] === 1) continue;

    const c1 = i === 0 && i + 1 < len && flowerbed[i + 1] === 0;
    const c2 = i === len - 1 && i - 1 >= 0 && flowerbed[i - 1] === 0;
    const c3 = i > 0 && i < len - 1 && flowerbed[i - 1] === 0 && flowerbed[i + 1] === 0;

    if (c1 || c2 || c3) {
      flowerbed[i] = 1;
      n--;
    }

    if (n === 0) return true;
  }

  return false;
};