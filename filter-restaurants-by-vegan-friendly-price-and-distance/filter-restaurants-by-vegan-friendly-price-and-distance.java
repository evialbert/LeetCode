class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[1] == b[1] ? b[0]-a[0] : b[1] - a[1]);
        for(int i = 0; i < restaurants.length; i++) {
            if(restaurants[i][2] >= veganFriendly && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) pq.offer(new int[]{restaurants[i][0],restaurants[i][1]});
        }
        List<Integer> res = new ArrayList<>();
        while(!pq.isEmpty()) res.add(pq.poll()[0]);
        return res;
    }
}