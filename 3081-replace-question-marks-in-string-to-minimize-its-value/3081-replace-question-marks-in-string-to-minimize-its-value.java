class Solution {
    public String minimizeStringValue(String s) {
        //Map<Character,Integer> hMap = new HashMap<>();
        int a[] = new int[26];
        int b[] = new int[26];
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)>='a' && s.charAt(i)<='z'){
                a[s.charAt(i)-'a']++;
            }
            else{
                count++;
            }
        }
        while(count-->0){
            boolean check = true;
            for(int i=0;i<26;i++){
                if(a[i]==0){
                    b[i]++;
                    a[i]++;
                    check = false;
                    break;
                }
            }
            if(check){
                int min  = Integer.MAX_VALUE;
                int index = -1;
                for(int i=0;i<26;i++){
                    if(a[i]<min){
                        min = Math.min(min,a[i]);
                        index = i;
                    }
                }
                a[index]++;
                b[index]++;
            }
        }
        StringBuilder str = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)>='a' && s.charAt(i)<='z'){
                str.append(s.charAt(i));
            }
            else{
                for(int j=0;j<26;j++){
                    if(b[j]>0){
                        str.append((char)(j+'a'));
                        b[j]--;
                        break;
                    }
                }
            }
        }
        return str.toString();
    }
}