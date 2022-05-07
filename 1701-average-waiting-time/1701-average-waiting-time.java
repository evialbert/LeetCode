class Solution {
   public double averageWaitingTime(int[][] customers) {
	double sumOfTime = 0;
	int preFinishTime = 0;
	for(int[] customer : customers){
		preFinishTime = Math.max(customer[0], preFinishTime);
		sumOfTime+=(preFinishTime+customer[1])-customer[0];
		preFinishTime+=customer[1];
	}
	return sumOfTime/customers.length;
}
}