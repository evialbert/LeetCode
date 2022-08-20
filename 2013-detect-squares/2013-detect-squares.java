class DetectSquares {

    Map<List<Integer>, Integer> map;
    List<List<Integer>> points;
    public DetectSquares() {
        map = new HashMap<>();
        points = new ArrayList<>();
    }
    
    public void add(int[] point) {
        List<Integer> pt = getCoordinates(point);
        map.put(pt, map.getOrDefault(pt, 0) + 1);
        points.add(pt);
    }
    
    public int count(int[] point) {
        int x = point[0];
        int y = point[1];
        int res = 0;
        for (List<Integer> pt : points) {
            int px = pt.get(0);
            int py = pt.get(1);
            if (Math.abs(x - px) != Math.abs(y - py) || x == px || y == py) {
                continue;
            }
            List<Integer> one = new ArrayList<>();
            List<Integer> two = new ArrayList<>();
            one.add(px);
            one.add(y);
            two.add(x);
            two.add(py);
            if (map.get(one) != null && map.get(two) != null) {
               res += map.get(one) * map.get(two); 
            }            
        }
        return res;
    }
    
    private List<Integer> getCoordinates(int[] point) {
        List<Integer> pt = new ArrayList<>();
        for(int p : point) {
            pt.add(p);
        }
        return pt;
    }
}