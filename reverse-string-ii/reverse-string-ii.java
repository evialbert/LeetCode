class Solution {
    public String reverseStr(String s, int k) {
        char[] lst = s.toCharArray();
        for(int st = 0; st < lst.length; st += 2*k){
            int i = st;
            int j = (st+k-1 < lst.length) ? (st+k-1) : (lst.length-1);
            while(i < j){
                char temp = lst[j];
                lst[j] = lst[i];
                lst[i] = temp;
                i++;
                j--;
            }
        }
        return new String(lst);
    }
}