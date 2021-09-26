class Solution {
    public boolean parseBoolExpr(String expression) {
        return helper(expression, 0, expression.length()-1);
    }
    
    private boolean helper(String e, int lo, int hi){
        if(lo == hi){
            return e.charAt(lo) == 'f' ? false:true;
        }
        
        char op=e.charAt(lo);
        int count=0;
        boolean res=(op == '|') ? false:true;
        
        
        int prev=lo+2;
        for(int i=lo+1;i <= hi;i++){
            char c=e.charAt(i);
            
            if(c == '('){
                count++;
            }
            
            else if(c ==')'){
                count--;
            }
            
            if((count == 1 && c == ',') || (count == 0 && c ==')')){
                boolean next=helper(e,prev,i-1);
                prev=i+1;
                if(op == '|'){
                    res=res | next;
                } else if(op == '&'){
                    res=res & next;
                } else{
                    res=!next;
                }
            }
           
        }
         return res;
    }
}