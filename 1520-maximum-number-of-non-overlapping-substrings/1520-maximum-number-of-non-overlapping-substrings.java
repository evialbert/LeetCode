class Solution {
    
    int[] l;
    int[] r;
    
    public List<String> maxNumOfSubstrings(String s) {
        List<String> res = new ArrayList<String>();
        l = new int['z'-'a'+1];
        r = new int['z'-'a'+1];
        Arrays.fill(l,Integer.MAX_VALUE);
        Arrays.fill(r,-1);
        for(int i = 0;i<s.length();i++){
            int index = s.charAt(i)-'a';
            l[index] = Math.min(i,l[index]);
            r[index] = i;
        }
        Stack<int[]> st = new Stack<int[]>();
        for(int i = 0;i<s.length();i++){
            int[] range = getRange(i,s);
            if(range==null)continue;
            while(!st.isEmpty() && range[0]>=st.peek()[0] && range[1]<=st.peek()[1])
                st.pop();
            st.push(range);
        }
        while(!st.isEmpty()){
            int[] range = st.pop();
            res.add(s.substring(range[0],range[1]+1));
        }
        return res;
    }
    
    private int[] getRange(int i, String s){
        char c = s.charAt(i);
        int right = r[c-'a'];
        for(int j = i;j<=right;j++){
            c = s.charAt(j);
            if(l[c-'a']<i)return null;
            right = Math.max(right,r[c-'a']);
        }
        return new int[]{i,right};
    }
}