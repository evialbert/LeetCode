class Solution {
    public long interchangeableRectangles(int[][] arr) {
        HashMap<Double, Integer> map = new HashMap<>();
        long ans = 0;
        
        for(int i = 0 ; i < arr.length ; i ++){
            double v = arr[i][0]/(double)arr[i][1];
            
            if(map.containsKey(v)){
                ans+=map.get(v);
            }
            map.put(v, map.getOrDefault(v,0)+1 );
            // System.out.println(map);
            
        }
        return ans;
    }
}