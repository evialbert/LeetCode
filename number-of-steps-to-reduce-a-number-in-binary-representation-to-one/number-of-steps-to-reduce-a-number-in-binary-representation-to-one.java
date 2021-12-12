class Solution {
    public int numSteps(String s) {
        int count=0;
        String temp=s;
        while(temp.length()!=1){
            if(temp.charAt(temp.length()-1)=='1'){
                temp=addOne(temp);
                System.out.println(temp);
            }
            else{
                temp=divideTwo(temp);
                System.out.println(temp);
            }
            count++;
            

        }
        return count;
    }
    
    private String divideTwo(String s){
        String temp="";
        for(int i=0;i<s.length()-1;i++){
            temp=temp+s.charAt(i);
        }
        return temp;
        
    }
    
    
    private String addOne(String s){
       char prevDiff='0';
        String temp="";
       if(s.charAt(s.length()-1)=='1'){
           temp=temp+"0";
           prevDiff='1';
       }
        int count=s.length()-2;
       while(count>=0 && prevDiff=='1'){
           if(s.charAt(count)=='1'){
               temp="0"+temp;
           }
           else{
               temp="1"+temp;
               prevDiff='0';
           }
           count--;
       }
       if(prevDiff=='0'){
       temp=s.substring(0,count+1)+temp;
       }
        else{
            temp=prevDiff+temp;
        }
        
        return temp;
}
}