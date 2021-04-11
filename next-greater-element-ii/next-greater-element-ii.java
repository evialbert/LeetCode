class Solution {

	public int[] nextGreaterElements(int[] arr) {
	
		int len=arr.length;
		int[] ans = new int[len];
		Stack<Integer> st = new Stack<>();
		
		for (int i = 0; i <= 2 * len; i++) {
			int val=(i==2*len?Integer.MAX_VALUE:arr[i%len]);
			
			while (st.size() > 0 && arr[st.peek()] < val) {
				if(i==2*len){
					ans[st.pop()%len]=-1;
				}else{
					ans[st.pop()%len]=arr[i%len];
				}
			}
			if (i < len)
				st.push(i);
		}
		
		return ans;
	}
}