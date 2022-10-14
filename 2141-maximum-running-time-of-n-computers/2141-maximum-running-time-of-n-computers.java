class Solution {
    public long maxRunTime(int n, int[] batteries) {
        // Sort is necessary to prevent single batteries being used simultaneously
        Arrays.sort(batteries);
        long sum = 0;
        int min = 0;
        for (int battery : batteries) {
            sum += battery;
            min = Math.min(min, battery);
        }
        // Given n <= batteries.length, the batteries can at least run min(batteries) mins
        long left = min, right = sum / n;
        while (left + 1 < right) {
            long mid = left + (right - left) / 2;
            boolean canRun = checkRunTime(n, batteries, mid);
            if (canRun) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return checkRunTime(n, batteries, right) ? right : left;
    }
    
    private boolean checkRunTime(int n, int[] batteries, long time) {
        long currSum = 0;
        int numOfComputers = 0;
        for (int battery : batteries) {
            currSum += battery;
            if (currSum >= time) {
                numOfComputers++;
                // The remaining battery life can be used by the next computer.
                currSum -= time;
            }
        }
        return numOfComputers >= n;
    }
}