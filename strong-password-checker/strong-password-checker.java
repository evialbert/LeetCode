class Solution {
    public int strongPasswordChecker(String password) {
        int len=password.length();
        if(len<5)return 6-len;
        int hasLower=1, hasUpper=1, digit=1;
        List<Integer>more=new ArrayList<>();
        for(int i=0;i<len;i++){
            int start=i;
            while(i<len-1&&password.charAt(i+1)==password.charAt(start))i++;
            if(i-start>1)more.add(i-start+1);
            char c=password.charAt(i);
            if(hasUpper==1&&c<='Z'&&c>='A')hasUpper=0;
            if(hasLower==1&&c<='z'&&c>='a')hasLower=0;
            if(digit==1&&c<='9'&&c>='0')digit=0;
        }
        int lack=hasUpper+hasLower+digit;
        int[]temp=new int[4];
        int dup=0;
        for(Integer i:more){
            dup+=i/3;
            temp[(i+1)%3]++;
            temp[3]+=(i-2)/3;
        }
        int del=0;
        if(len>20){
            del=len-20;
            int d=del;
            for(int i=1;i<4;i++){
                if(d>=temp[i]*i){
                    dup-=temp[i];
                    d-=temp[i]*i;
                }else{
                    dup-=d/i;
                    break;
                }
            }
        }
        if(len==5)return Math.max(lack,1);
        return del+Math.max(dup,lack);
    }
}