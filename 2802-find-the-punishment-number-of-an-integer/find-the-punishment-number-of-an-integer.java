class Solution {
    public int punishmentNumber(int n) {
       int sum = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(String.valueOf(square), 0, i)) {
                sum += square;
            }
        }
        return sum;
    }

    private static boolean canPartition(String str, int index, int target) {
        if (index == str.length()) {
            return target == 0;
        }

        int num = 0;
        for (int j = index; j < str.length(); j++) {
            num = num * 10 + (str.charAt(j) - '0');
            if (num > target) break; 
            if (canPartition(str, j + 1, target - num)) {
                return true;
            }
        }
        return false;
    }
}