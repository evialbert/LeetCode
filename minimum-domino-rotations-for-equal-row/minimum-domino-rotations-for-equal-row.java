class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int result = Integer.MAX_VALUE;
        for(int target = 1; target < 7;target++){
            int topCount = helper(tops, bottoms, target, true);
            int botCount = helper(tops, bottoms, target, false);
            
            if(topCount != -1 && botCount != -1)
                result = Math.min(result, Math.min(topCount, botCount));
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }

    int helper(int[] tops, int[] bottoms, int target, boolean topFlag){
        int counter = 0;
        
        for(int i=0;i < tops.length; i++ ){
            if(topFlag && tops[i] != target && bottoms[i] == target )
                counter++;
            else if (!topFlag && tops[i] == target && bottoms[i] != target)
                counter++;
            else if (tops[i] != target && bottoms[i] != target)
                return -1;
        }
        return counter;
    }
    
}