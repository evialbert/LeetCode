class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if(s1==null || s2==null || s2.length()*n2 > s1.length()*n1) return 0;
        if(s2=="") return 0;
        
        int str2Index = 0;
        int count = 0;
        int k=0;
        while(k<n1)
        {
            for(int i=0;i<s1.length();i++){
                if(s1.charAt(i)==s2.charAt(str2Index))
                    str2Index++;
                if(str2Index==(s2.length())){
                    str2Index=0;
                    count++;
                }
            }
            k++;
            if(str2Index==0)
            {
                if(n1%2==0 || n1 < 2)
                    count*=n1/k;
                else
                    count=(count*(n1-1)/k)+1;
                break;
            }
        }

        return count/n2;
    }
}
