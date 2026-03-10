class Solution {
    public String revinv(String str){
        StringBuilder sb = new StringBuilder(str);
        for(int i=0;i<sb.length();i++){
            if(sb.charAt(i)=='0'){
                sb.setCharAt(i,'1');
            }else{
                sb.setCharAt(i,'0');
            }
        }
        return sb.reverse().toString();
    }
    public char findKthBit(int n, int k) {

        if(k==1) return '0';
        if(n==1) return '0';

        List<String> li = new ArrayList<>();
        li.add("0");

        
        for(int i=1;i<=n;i++){
            StringBuilder sb = new StringBuilder();
            sb.append(li.get(i-1));
            sb.append("1");
            sb.append(revinv(li.get(i-1)));
            li.add(sb.toString());
        }

        return li.get(n-1).charAt(k-1);
    }
}