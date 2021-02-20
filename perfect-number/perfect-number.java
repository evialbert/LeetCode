class Solution {
    public boolean checkPerfectNumber(int num) {
   if (num==1) return false;
        int i=2, j=num/2;
        int total = 0;
        while(i<=num/i){
            if (num%i==0 && i<num/i) total +=i+num/i;
            i++;
        }
        return total+1==num;
    }
}