class Solution {
    public long maximumSubarraySum(int[] array, int windowSize) {
        int maxElement = 0;
        for (int element : array) {
            maxElement = Math.max(maxElement, element);
        }
        
        int[] frequency = new int[maxElement + 1];
        int duplicateCount = 0;
        long maxSum = 0;
        long currentSum = 0;
        
        // Initialize the first window
        for (int i = 0; i < windowSize; i++) {
            if (frequency[array[i]] >= 1) {
                duplicateCount++;
            }
            frequency[array[i]]++;
            currentSum += array[i];
        }
        
        if (duplicateCount == 0) {
            maxSum = currentSum;
        }
        
        // Slide the window over the rest of the array
        for (int i = windowSize; i < array.length; i++) {
            if (frequency[array[i]] >= 1) {
                duplicateCount++;
            }
            frequency[array[i]]++;
            currentSum += array[i];
            
            if (frequency[array[i - windowSize]] > 1) {
                duplicateCount--;
            }
            frequency[array[i - windowSize]]--;
            currentSum -= array[i - windowSize];
            
            if (duplicateCount == 0) {
                maxSum = Math.max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
}