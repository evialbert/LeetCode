class Solution {
     Set<Integer> set= new HashSet<>();
    
    public boolean isHappy(int n) {
       int temp=0;
            
        while(n != 0){
            int index = n % 10;
            temp += index * index;
            n = n / 10;
        }
            
        if(temp == 1){
            return true;
        }  
        
        if(set.contains(temp)){
            return false;
        }
         
        set.add(temp);
        
        return isHappy(temp);
    }
}