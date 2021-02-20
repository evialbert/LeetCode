public class Solution {  
    public int distributeCandies(int[] candies) {  
    Set<Integer> kinds = new HashSet<>();  
        for (int candy : candies) kinds.add(candy);  
        int kindsnum = kinds.size();  
        int sum = candies.length;  
            if(sum>=kindsnum*2){  
        return kindsnum;  
    }  
        return sum/2;  
    }  
}  