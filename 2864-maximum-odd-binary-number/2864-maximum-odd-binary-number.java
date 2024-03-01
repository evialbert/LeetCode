class Solution {
    public String maximumOddBinaryNumber(String s) {
        int o=0,z=0;
        char f;
        for(int i=0;i<s.length();i++){
            f = s.charAt(i);
            if(f=='0') z++;
            else o++; 
        }
        StringBuilder sb = new StringBuilder();
        while(o!=1){
            sb.append('1');
            o--;
        }
        while(z!=0){
            sb.append('0');
            z--;
        }
        sb.append('1');
        return sb.toString();
    }
}