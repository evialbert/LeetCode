public class Solution {
    public int[] singleNumber(int[] nums) {
        
        int xor = 0;
        for(int num : nums){
        	xor = xor ^ num;
        }

        int bit = 0;
        for(int i = 0; i < 32; i++){
        	if(((xor >>> i) & 1) != 0){
        		bit = i;
        		break;
        	}
        }
        xor = (1 << bit);

        int[] result = new int[2];
        int a = 0; 
        int b = 0;

        for(int num : nums){

        	if((num & xor) == 0){
        		a = a ^ num;
        	}
        	else if((num & xor) != 0){
        		b = b ^ num;
        	}
        }
        result[0] = a;
        result[1] = b;
        return result;
    }
}