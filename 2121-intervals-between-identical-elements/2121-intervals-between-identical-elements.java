class Solution {
    public long[] getDistances(int[] arr) {
        long [] out = new long [arr.length];
        Map<Integer, long []> preSum = new HashMap<>(); // pre index sum and number of index used
        for(int i=0;i<arr.length;i++){
            long [] inner = preSum.get(arr[i]);
            if(inner == null){
                inner = new long[2];
                preSum.put(arr[i], inner);
            }else {
                out[i] = (inner[1] * i) - inner[0]; // number of index multiplied by index value minus sum
            }
            inner[0] += i;
            inner[1]++;
        }
        Map<Integer, long []> revSum = new HashMap<>(); // pre index sum and number of index used in reverse direction
        for(int i=arr.length-1;i>=0;i--){
            long [] inner = revSum.get(arr[i]);
            if(inner == null){
                inner = new long[2];
                revSum.put(arr[i], inner);
            }else {
                out[i] += (inner[0] - (inner[1] * i)); // number of index multiplied by index value minus sum
            }
            inner[0] += i;
            inner[1]++;
        }
        return out;
    }
}