/**
 * @param {string} S
 * @return {number[]}
 */
var partitionLabels = function(S) {
  var result = [], partition = 0;
  var map = {}, parts = 0;

  /**
   * We first store the last available indexes of each character in the first loop
   */
  for (var i = 0; i < S.length; ++ i) {
      var char = S[i];
      map[char] = i;
  }
  
  /**
   * 1. Iterate and set the first character's last position / index as the end of a partition.
   * 2. We keep iterating, if the next character has the last index more than the current partition, we change the partition to the new last index
   * 3. We keep repeating until we reach a position where the current loop 'i' value and the partition value is same. This means, we have reached the end of one successful partition.
   * 4. Repeating this gives all other paritions, we add the lengths in the array and return them
   */
  for (var i = 0; i < S.length; ++ i) {
      var char = S[i];
      if (partition + parts === i && map[char] <= i) {
          result.push(partition + 1); // Since 0 indexed
          parts += partition + 1; // Since 0 indexed
          partition = 0;
      }
      if (map[char] !== undefined) {
          partition = Math.max(partition, map[char] - parts); // Since we need only lengths
      }
  }
  
  return result;
};