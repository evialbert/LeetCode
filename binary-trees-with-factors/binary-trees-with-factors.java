class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        
        Map<Integer, Long> map = new HashMap<>();
        Arrays.sort(arr); // sort in acsending order
        
        for (int i = 0; i < arr.length; ++i) {
            
            Long cnt = 1L;
            
            for (int j = 0; j < i; ++j)
                if (arr[i] % arr[j] == 0 && map.containsKey(arr[i] / arr[j]))
                    cnt += map.get(arr[j]) * map.get(arr[i] / arr[j]);
            
            map.put(arr[i], cnt);
        }
        
        long res = 0L;
        for (int n : arr)
            res = (res + map.get(n)) % ((int) (1e9 + 7));
        
        return (int) res;
    }
}