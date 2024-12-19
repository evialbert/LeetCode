/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
  const n = arr.length;
  let leftIndex = n;
  let chunksCount = 0;
  for (let i = n - 1; i >= 0; --i) {
    leftIndex = Math.min(leftIndex, arr[i]);
    if (leftIndex === i) {
      chunksCount++;
    }
  }
  return chunksCount;
};