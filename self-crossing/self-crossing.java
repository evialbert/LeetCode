class Solution {
  public boolean isSelfCrossing(int[] x) {
	boolean snakeTrapped = false;
	for (int i=2;i<x.length;i++){
		if (snakeTrapped){
		     if (x[i]>=x[i-2])
			    return true;
			 else if (i>=4 && x[i-1]==x[i-3] && x[i-4]+x[i]>=x[i-2])
			     return true;
			 else if (i>=5 && x[i-3]-x[i-1]-x[i-5]<=0 && x[i-3]>x[i-5] && x[i]+x[i-4]>=x[i-2])
			     return true;
		}
		else if (x[i]<=x[i-2])
			snakeTrapped = true;
	}
	return false;
}
}