class Solution {
    public int[] closestDivisors(int num) {
        int one=num+1;
        int two=num+2;
        for(int i=(int)(Math.sqrt(two));i>=0;i--){
            if(one%i==0)
                return new int[]{i,one/i};
            if(two%i==0)
                return new int[]{i,two/i};
        }return new int[]{};
        
    }
}