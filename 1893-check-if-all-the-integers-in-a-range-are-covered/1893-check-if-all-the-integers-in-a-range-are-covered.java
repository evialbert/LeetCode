class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
       
        Set<Integer> set = IntStream.rangeClosed(left, right).boxed().collect(Collectors.toSet());
        
        for(int i=0;i<ranges.length;i++){
        
            set.removeAll(IntStream.rangeClosed(ranges[i][0], ranges[i][1]).boxed().collect(Collectors.toSet()));
        
            if(set.isEmpty()){
                return true;
            }
        }
        return false;
    }
}