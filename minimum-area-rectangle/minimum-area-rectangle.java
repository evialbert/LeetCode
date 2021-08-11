class Solution {
   public int minAreaRect(int[][] points) {
        HashMap<Integer, HashSet<Integer>> mapX = new HashMap<>();
        HashMap<Integer, HashSet<Integer>> mapY = new HashMap<>();

        for(int i = 0; i < points.length; i++) {
            int[] point = points[i];
            mapX.computeIfAbsent(point[0], x->new HashSet<>()).add(point[1]);
            mapY.computeIfAbsent(point[1], x->new HashSet<>()).add(point[0]);
        }

        Arrays.sort(points, (a, b) -> {
            if(a[1] == b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });

        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < points.length; i++) {
            int x0 = points[i][0], y0 = points[i][1];

            for(int y: mapX.get(x0)) {
                if(y <= y0) continue;
                for(int x: mapY.get(y)){
                    if(x <= x0) continue;
                    if(mapY.get(y0).contains(x)) {
                        ans = Math.min(ans, (x - x0) * (y - y0));
                    }
                }
            }
        }
        return ans == Integer.MAX_VALUE? 0: ans;
    }
}