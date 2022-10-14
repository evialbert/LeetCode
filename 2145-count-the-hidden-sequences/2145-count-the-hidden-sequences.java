class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        long current = 0, min = 0, max = 0;
        int res = 0;
        for(int one : differences){
        	current = current + one;
        	min = Math.min(current, min);
        	max = Math.max(current, max);
        }
        int resultdiff = (int) (max - min);
        int originaldiff = upper - lower;
        if(originaldiff-resultdiff+1>0)
        	res = originaldiff-resultdiff+1;
        return res;
    }
}