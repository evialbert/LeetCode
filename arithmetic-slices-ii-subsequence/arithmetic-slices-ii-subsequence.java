class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if (A.length < 3) return 0;

        int result = 0;
        int n = A.length;
        HashMap<Integer, Integer> map[] = new HashMap[n];
        
        for (int i = 0; i < n; i++) map[i] = new HashMap<>();
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i] - (long)A[j];
                
                if (diff <= Integer.MIN_VALUE || diff >= Integer.MAX_VALUE) continue;
                
                int apsEndingOnJ = map[j].getOrDefault((int)diff, 0);
                int apsEndingOnI = map[i].getOrDefault((int)diff, 0);
                
                result += apsEndingOnJ;
                
                map[i].put((int)diff, apsEndingOnI + apsEndingOnJ + 1);
            }
        }

        return result;
    }
}