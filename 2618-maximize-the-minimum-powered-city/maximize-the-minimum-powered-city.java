class Solution {
    public long maxPower(int[] stations, int r, int k) {
        int n = stations.length;
        long l = 0; 
        long h = k;
        for(int ele : stations) h += ele;
        long ans = 0;

        long[] slide = new long[n];
        
        long sum = 0;
        for(int i = 0; i <= r && i < n; i++){
            sum += stations[i];
        }
        slide[0] = sum;

        for(int i = 1; i < n; i++){
            int sIdx = i - r - 1;
            int aIdx = i + r;

            if(sIdx >= 0) sum -= stations[sIdx];
            if(aIdx < n) sum += stations[aIdx];
            slide[i] = sum;
        }

        while(l <= h){
            long mid = l + (h-l)/2;

            if(check(slide, r, k, mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }

    public boolean check(long[] slide, int r, int k, long mid){
        int n = slide.length;

        long powerGained = 0;
        long[] diff = new long[n];

        for(int i = 0; i < n; i++){
            
            powerGained += diff[i];
            long total = slide[i] + powerGained;

            if(total < mid){
                long needed = mid - total;
                k -= needed;
                if(k < 0) return false;
                
                powerGained += needed;
                int idx = i + 2*r + 1;
                if(idx < n) diff[idx] -= needed;
            }
        }

        return true;


    }
}