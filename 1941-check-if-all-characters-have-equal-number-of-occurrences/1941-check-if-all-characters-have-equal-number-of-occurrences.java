class Solution {
    public boolean areOccurrencesEqual(String s) {
        char[] ch=s.toCharArray();
        int cnt=0;
        HashMap<Integer,Character> map=new HashMap<>();
        for(int i=0;i<ch.length;i++){
            cnt=0;
            if(ch[i]=='0'){
                    continue;
                }
            for(int j=i+1;j<ch.length;j++){
                
                if(ch[i]==ch[j]){
                    cnt++;
                    ch[j]='0';
                }
                
            }
            map.put(cnt,ch[i]);
        }
        if(map.size()==1){
            return true;
        }
        return false;
    }
}