public class Solution {

    public int findLHS(int[] nums) {

        int count = 0;

        Map<Integer, Integer> map = new HashMap<>();

        

        for (int num : nums) {

            map.put(num, map.getOrDefault(num, 0) + 1);

            

            if (map.containsKey(num - 1)) {

                count = Math.max(count, map.get(num) + map.get(num - 1));

            }

            

            if (map.containsKey(num + 1)) {

                count = Math.max(count, map.get(num) + map.get(num + 1));

            }

        }

        

        return count;

    }

}