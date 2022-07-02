class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb=new StringBuilder();
             
      int sum=0;
        for(char ch : s.toCharArray()){
            sb.append(ch-'a'+1);
        }
        while(k-->0){
     
          sum=0;
            for(char ch : sb.toString().toCharArray())
                sum+=Character.getNumericValue(ch);
            sb.setLength(0);sb.append(sum);
        }
        return sum;
    }
}