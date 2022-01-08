class Solution {
    public int[] getStrongest(int[] arr, int k) {
        Arrays.sort(arr);
        int median = arr[(arr.length-1)/2];
        
        return Arrays.stream(arr).boxed().sorted(
            (a,b) -> {
                int comp = Integer.compare(Math.abs(b-median), Math.abs(a-median));
                return comp == 0 ? Integer.compare(b,a) : comp;
            }
        ).limit(k).mapToInt(Integer::intValue).toArray();
    }
}