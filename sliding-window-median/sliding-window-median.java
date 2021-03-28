class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] ans = new double[nums.length - k + 1];
        List<Integer> temp = new ArrayList<>();
        
        for(int i=0; i<k; i++) temp.add(nums[i]);
        
        Collections.sort(temp);
        
        ans[0] = getMedian(temp, k);
        
        for(int i=1; i<= nums.length - k; i++) {
            int prev = nums[i-1];
            int next = nums[i+k-1];
            
            int prevIdx = binarySearch(temp, prev);
            temp.remove(prevIdx);

            int nextIdx = binarySearch(temp, next);
            if(nextIdx < temp.size() && next > temp.get(nextIdx)) 
                temp.add(nextIdx+1, next);
            else temp.add(nextIdx, next);            
            
            ans[i] = getMedian(temp, k);
        }
        return ans;
    }
    private double getMedian(List<Integer> arr, int k) {
        int midIdx = (int) k/2;
        if(k % 2 == 1) return (double) arr.get(midIdx);
        else {
            long sum = (long) arr.get(midIdx) + arr.get(midIdx-1);
            return (double) sum/2;
        }
    }
    
    private int binarySearch(List<Integer> temp, int num) {
        int s = 0;
        int e = temp.size()-1;
        
        while(s < e) {
            int mid = (s+e)/2;
            if(num == temp.get(mid)) return mid;
            else if(num > temp.get(mid)) s = mid + 1;
            else e = mid - 1;
        }
        return s;
    }
}