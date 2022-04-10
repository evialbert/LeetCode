class Solution {
    public String getSmallestString(int n, int k) {
        String ans = "";
        int l = (int)((k-n)/25);
        ans += new String(new char[l]).replace("\0", "z");
        k = k-(26*l);
        n = n -l;
        if(n!=k){
            int j = k-n+1;
            char i = (char) ('a' + j-1);
            ans = String.valueOf(i)+ans; 
            k = k-j;
            n--;
        }
        String repeated = new String(new char[n]).replace("\0", "a");
        return repeated+ans;
    }
}