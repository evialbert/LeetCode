class Solution {
    class ResultType {
        int p1;
        int p2;
        public ResultType(int p1, int p2) {
            this.p1 = p1;
            this.p2 = p2;
        }
    }
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        int l = (int)Math.pow(10, 9) + 7;
        // find largest interval
        ResultType hResult = findCut(h, horizontalCuts);
        ResultType vResult = findCut(w, verticalCuts);
        
        long res = (long)(hResult.p2 - hResult.p1) * (long)(vResult.p2 - vResult.p1);
        return (int)(res % l);
    }
    
    private ResultType findCut(int last, int[] cuts) {
        int[] newCuts = new int[cuts.length+2];
        for (int i = 0; i < cuts.length; i++) {
            newCuts[i+1] = cuts[i];
        }
        newCuts[cuts.length+1] = last;
        
        int delta = 0;
        int p1 = 0;
        int p2 = 0;
        for (int i = 1; i < newCuts.length; i++) {
            if (newCuts[i] - newCuts[i-1] > delta) {
                delta = newCuts[i] - newCuts[i-1];
                p1 = newCuts[i-1];
                p2 = newCuts[i];
            }
        }
        
        return new ResultType(p1, p2);
    }
}