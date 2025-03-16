class Solution {
    public long repairCars(int[] ranks, int cars) {
        long low = 1;
        long high = Arrays.stream(ranks).max().getAsInt();
        high = high * cars * cars;
        while(low <= high){
            long mid = low + (high - low)/2;
            if(isPossible(ranks , cars , mid)){
                high = mid - 1;
            }else low = mid + 1;
        }
        return low;
    }

    private boolean isPossible(int[] ranks , int cars , long mid){
        long total = 0;
        for(int i : ranks){
            total += (long) Math.sqrt(mid / i);
            if(total >= cars) return true;
        }
        return false;
    }
}