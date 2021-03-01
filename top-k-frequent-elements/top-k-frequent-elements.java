class Solution {
  public int[] topKFrequent(int[] nums, int k) {
    /*
     * The idea is to find the frequency of each number
     * Group them by frequency
     * return the K frequent element
     * exemple: [5,5,5,4,7,3,3,7,9,6,6,3]
     *  5[3], 4[1], 7[2], 3[3], 9[1], 6[2]
     * Grouped by frequency we have: 3[5, 3], 1[4, 9], 2[7, 6]
     * By looking at the table of frequencies we see that
     * the k(2) most frequent elements are 5 and 3
     * the k(3) most frequent elements are 5, 3 and 7
     * the k(4) most frequent elements are 5, 3, 7 and 6
     * ....
     * time: O(n)
     * space: O(n)
     */
    
    if(nums.length == k){
      return nums;
    }
    
    //Build the freuency of elements
    int maxFreq = 0; //we will just keep this for the size of the grouped frequencies bucket
    HashMap<Integer, Integer> freq = new HashMap<>();
    for(int i : nums){
      int f = freq.getOrDefault(i, 0) + 1;
      freq.put(i, f);
      maxFreq = Math.max(maxFreq, f);
    }
    
    //we need to group the elements by frequencies
    //maxFreq + 1 so that we can store maxFreq index
    List<Integer>[] group = new ArrayList[maxFreq + 1];
    for(int i : freq.keySet()){
      int fq = freq.get(i);
      if(group[fq] == null){
        group[fq] = new ArrayList<>();
      }
      group[fq].add(i);
    }
    
    //Now we just need to go in the group list and take the K elements with the highest frequency
    int[] res = new int[k];
    int index = 0;
    for(int i = group.length - 1; i >= 0; i--){
      List<Integer> els = group[i];
      if(els != null){
        for(int el : els){
          if(index == k){
            return res;
          }
          res[index++] = el;
        }
      }
    }
    
    return res;
  }
}