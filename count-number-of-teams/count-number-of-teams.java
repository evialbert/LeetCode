class Solution {
    public int numTeams(int[] rating) {
        
        int len = rating.length;
        
        int count = 0;
        
        for (int i = 0; i < len; ++i) {
            
            count += helper(rating, i, true);
            count += helper(rating, i, false);
        }
        return count;
    }
    
    
    private int helper(int[] rating, int index, boolean increase) {
        
        if (index == 0 || index == rating.length-1)
            return 0;
        
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < rating.length; ++i) {
            
            if (i == index)
                continue;
            
            if (i < index) {
                
                if (increase && rating[i] < rating[index])
                    left++;
                else if (!increase && rating[i] > rating[index])
                    left++;
            } else {
                
                if (increase && rating[i] > rating[index])
                    right++;
                else if (!increase && rating[i] < rating[index])
                    right++;
            }
        }
        return left * right;
    }
}