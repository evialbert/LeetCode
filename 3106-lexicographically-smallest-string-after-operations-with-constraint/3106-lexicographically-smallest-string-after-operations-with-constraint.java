class Solution {
    public String getSmallestString(String s, int k) {
        if(k == 0){
            return s;
        }
        char[] arr = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(char c : arr){
            int b = Math.abs((int)c - 110);
            int a = 13 - b;
            if(k >= a){
                k -= a;
                sb.append('a');
            } else if(k > 0){
                char w = (char)((int)c - k); 
                k=0; 
                sb.append(w);
            }else{
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
