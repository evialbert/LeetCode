public class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        HashMap<Integer, Integer> hashmap=new HashMap<>();
        for(int i =0; i< points.length; i++){
            for(int j=0; j< points.length; j++){
                if(i == j){
                    continue;
                }
                int distance = getDistance(points[i], points[j]);
                hashmap.put(distance, hashmap.getOrDefault(distance, 0) + 1);
                
            }
            for(int val : hashmap.values()) {
                res += val * (val-1);
            }            
            hashmap.clear();
        }
        return res;
    }
    public int getDistance(int[] point1, int[] point2){
        int dx= point2[0] - point1[0];
        int dy=point2[1] - point1[1];
        return dx*dx + dy*dy;
    }
}