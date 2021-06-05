class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        int n = positions.length;
        int[] height = new int[n];
        int maxHeight = 0;
        ArrayList<Integer> res = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            int left = positions[i][0];
            int right = positions[i][0] + positions[i][1];
            int h = 0;
            for(int j = 0; j < i; j++){
                int l = positions[j][0];
                int r = positions[j][0] + positions[j][1];
                if( !(right <= l || left >= r))
                    h = Math.max(height[j],h);
            }
            height[i] = h + positions[i][1];
            maxHeight = Math.max(height[i],maxHeight);
            res.add(maxHeight);
        }        
        return res;     
    }
}