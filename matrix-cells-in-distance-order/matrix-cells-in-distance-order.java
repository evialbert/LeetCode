class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        TreeMap<Integer, List<int[]>> map = new TreeMap<>();
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                int key=Math.abs(r0-i)+Math.abs(c0-j);
                int[] arr= new int[]{i,j};
                if(!map.containsKey(key)) {
                    map.put(key, new ArrayList<>());
                }
                map.get(key).add(arr);
            }
        }
        int[][] result = new int[R*C][2];
        int index=0;
        for(Map.Entry<Integer, List<int[]>> entry : map.entrySet()) {
            List<int[]> list = entry.getValue();
            for(int[] arr : list) {
                result[index++]=arr;
            }
        }
        return result;
        
    }
}