class Solution {
    public boolean isPrefixString(String s, String[] words) {
        String str=words[0];
        
        int len_s=s.length();
        int len_str=str.length();
        if(str.equals(s))return true;
        for(int i=1;i<words.length;i++){
            if(len_str>len_s)break;
            str=str + words[i];
            len_str+=words[i].length();
            if(str.equals(s))return true;
        }
        
        return false;
    }
}