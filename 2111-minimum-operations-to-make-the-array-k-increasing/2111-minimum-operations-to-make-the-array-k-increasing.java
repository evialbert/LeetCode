class Solution {
    public int kIncreasing(int[] arr, int k) {
        int result = 0;
        
        for (int i = 0; i < k; i++) {
            // check arr[i, i+k, i+2k, ...]
            //
            // find longest increasing sub seq
            List<Integer> list = new ArrayList<>();
            
            for (int j = i; j < arr.length; j += k) {
                list.add(arr[j]);
            }
            
            int longestIncreasingSubSeq = lengthOfLIS(list);
            
            result += list.size() - longestIncreasingSubSeq;
        }
        
        return result;
    }
    
    public int lengthOfLIS(List<Integer> nums) {
        ArrayList<Integer> sub = new ArrayList<>();
        sub.add(nums.get(0));
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums.get(i);
            if (num >= sub.get(sub.size() - 1)) { // this >= check the `increasing subsequence` condition in this question
                sub.add(num);
            } else {
                int j = binarySearch(sub, num);
                sub.set(j, num);
            }
        }
        
        return sub.size();
    }
    
    private int binarySearch(List<Integer> sub, int num) {
        int left = 0, right = sub.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (sub.get(mid) <= num) { // this <= check the `increasing subsequence` condition in this question
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
}