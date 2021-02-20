class Solution {
    public int getSum(int a, int b) {
        
        // One line recursive solution
        //return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
       
        while(b!=0){
        
            // Carry is obtained by ANDing the bits
            int c = a&b;
            // Final sum value is obtained by XORing the bits
            a=a^b;
            // b is the new carry value obtained by left shifting by 1
            // next iteration onwards b is the carry to be added
            b=c<<1;
        }
 
        return a;
        
    }
}