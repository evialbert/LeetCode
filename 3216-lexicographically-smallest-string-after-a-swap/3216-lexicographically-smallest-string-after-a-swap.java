class Solution {
    void swap(char ch[], int i, int j){
        char tp = ch[j];
        ch[j] = ch[i];
        ch[i] = tp;
    }
    public String getSmallestString(String s) {
        String ans = s; int n = s.length();
        char ch[] = s.toCharArray();

        for(int i=0;i<n-1;i++){

            int parity = ch[i]%2;
            int nextpartity = ch[i+1]%2;

            if(parity == nextpartity){

                swap(ch,i,i+1);
                String cur = new String(ch);
                if(cur.compareTo(ans)<0) ans = cur;  
                swap(ch,i,i+1);

            }
            
        }
        return ans;
    }
}