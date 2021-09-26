class Solution {
  public List<Integer> pathInZigZagTree(int label) {
    List<Integer> result = new ArrayList<Integer>();

    // find current row of label
    int row = 0;
    int current = label;
    while (current > 0) {
      current = current >> 1;
      ++row;
    }
    //add current label to result
    result.add(label);
    --row;
    //move upwards for each parent
    while (row > 0) {
      label = Math.floorDiv(label, 2);
      int start = 1 << (row - 1);
      int end = (1 << row) - 1;
      if (row % 2 == 1) {
        label = (end - label) + start;
      } else {
        label = end - (label - start);
      }
      result.add(label);
      --row;
    }

    Collections.reverse(result);
    return result;
  }
}