class Solution {
    public List<Long> mergeAdjacent(int[] nums) {
        List<Long> arr = new ArrayList<>();

        for (int num : nums) 
        {
            long curr = num;

            while (!arr.isEmpty() && arr.get(arr.size() - 1) == curr)
            {
                curr = curr + arr.remove(arr.size() - 1);
            }

            arr.add(curr);
        }

        return arr;
    }
}