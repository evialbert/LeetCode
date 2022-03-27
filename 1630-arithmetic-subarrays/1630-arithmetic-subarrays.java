class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> result = new ArrayList<>();

        for (int i = 0; i < l.length; i++)
            result.add(canBeRearranged(Arrays.copyOfRange(nums, l[i], r[i] + 1)));

        return result;
    }

    private boolean canBeRearranged(int[] subArray) {
        Arrays.sort(subArray);

        for (int i = 1; i < subArray.length - 1; i++) {
            if ((subArray[i + 1] - subArray[i]) != (subArray[1] - subArray[0]))
                return false;
        }
        return true;
    }
}