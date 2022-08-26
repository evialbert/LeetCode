class Solution {
    public List<Integer> twoOutOfThree(int[] a1, int[] a2, int[] a3) {
        Set<Integer> set = new HashSet<>();

        helper(a1, a2, set);
        helper(a1, a3, set);
        helper(a2, a3, set);
        
        List<Integer> list = new ArrayList<>(set);
        return list;
    }

    private static void helper(int[] arr1, int[] arr2, Set<Integer> list) {
        for (int i : arr1) {
            for (int j = 0; j < arr2.length; j++) {
                if (i == arr2[j]) {
                    list.add(i);
                }
            }
        }
    }
}