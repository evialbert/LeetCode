class Solution {
    public int numDifferentIntegers(String s) {
        ArrayList<String> a = new ArrayList<String>();
        int i=0;
        while(i<s.length())
        {
        while(i<s.length()&&s.charAt(i)>='a')
            i++;
        int k=i;
        while(i<s.length()&&s.charAt(i)=='0')
            i++;
        k=i;
        while(i<s.length()&&s.charAt(i)<='9')
            i++;
        if(k==i&&s.charAt(i-1)=='0'&&!a.contains("0"))
        a.add("0");
        else if(k<s.length()&&!a.contains(s.substring(k,i))&&s.substring(k,i)!="")
        a.add(s.substring(k,i));
        }  
        return a.size();
    }
}