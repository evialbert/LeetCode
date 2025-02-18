class Solution {
    public String smallestNumber(String pattern) {
        StringBuilder res=new StringBuilder();
        int len=pattern.length();
        int[] stack=new int[len+1];
        int index=0;
        for(int i=0;i<=len;i++)
        {
            stack[index]=i+1;
            index++;

            if(i==len || pattern.charAt(i)=='I'){
                while(index>0){
                    index--;
                    res.append(stack[index]);
                }
            } 
        }
        return res.toString();

    }
}