class Solution {
    public int countArrays(int[] original, int[][] bounds) {
        int l = original.length;
        
//    	int ans=0;
    	
    	int curMin = bounds[0][0];
    	int curMax = bounds[0][1];
    	
    	for(int i=1; i<l; i++) {
    		
    		int reqDiff = original[i]-original[i-1];
//    		System.out.println("---"+reqDiff+"-----");
    		
    		int reqMinVal = curMin+reqDiff;
    		int reqMaxVal = curMax+reqDiff;
    		
    		if(reqMinVal>bounds[i][1]) {
    			return 0;
    		}else {
    			curMin = reqMinVal;
    			if(reqMinVal<bounds[i][0]) {
    				curMin = bounds[i][0];
    			}
    			if(bounds[i][1]>reqMaxVal) {
    				
    				curMax = reqMaxVal;
    			}else {
    				curMax = bounds[i][1];
    			}
    		}
//    		System.out.println(reqMinVal+"::"+reqMaxVal);
//    		System.out.println(curMin+"::"+curMax);
    	}
    	
//    	System.out.println(curMin+"::"+curMax);

        int ans = curMax-curMin+1;
        if(ans<0){
            return 0;
        }
    	return ans;
    }
}