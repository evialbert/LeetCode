class Solution {
   public int numRabbits(int[] answers) {
		int[] freq = new int[1000]; //Size is given in contraints
		int ans = 0;
		for (int ele : answers) {
			if(freq[ele] == 0){
				ans+=(ele + 1); 
			}
			freq[ele]++;
			if(freq[ele] == ele + 1) freq[ele] = 0;
		}
		return ans;
	}
}