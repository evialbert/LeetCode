class Solution {
    public long maxSubarrays(int n, int[][] cp) {
        for (int[] pair : cp) {
            if (pair[0] > pair[1]) {
                int temp = pair[0];
                pair[0] = pair[1];
                pair[1] = temp;
            }
        }
        
        Arrays.sort(cp, Comparator.comparingInt(a -> a[0]));
        
        long[] contributions = new long[cp.length];
        long totalPossible = (long) n * (n + 1) / 2;
        
        TreeMap<Integer, List<Integer>> endPointMap = new TreeMap<>();
        int currentIndex = cp.length - 1;
        
        for (int start = n; start >= 1; start--) {
            while (currentIndex >= 0 && cp[currentIndex][0] >= start) {
                int end = cp[currentIndex][1];
                endPointMap.computeIfAbsent(end, k -> new ArrayList<>()).add(currentIndex);
                currentIndex--;
            }
            
            if (endPointMap.isEmpty()) {
                continue;
            }
            
            Map.Entry<Integer, List<Integer>> firstEntry = endPointMap.firstEntry();
            int smallestEnd = firstEntry.getKey();
            int pairIndex = firstEntry.getValue().get(0);
            
            if (firstEntry.getValue().size() == 1) {
                endPointMap.remove(smallestEnd);
            } else {
                firstEntry.getValue().remove(0);
            }
            
            long covered = n - smallestEnd + 1;
            totalPossible -= covered;
            
            if (endPointMap.isEmpty()) {
                contributions[pairIndex] += covered;
            } else {
                int nextEnd = endPointMap.firstKey();
                contributions[pairIndex] += nextEnd - smallestEnd;
            }
            
            endPointMap.computeIfAbsent(smallestEnd, k -> new ArrayList<>()).add(pairIndex);
        }
        
        long result = totalPossible;
        for (long contribution : contributions) {
            result = Math.max(result, totalPossible + contribution);
        }
        
        return result;
    }
}