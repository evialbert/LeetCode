class Solution {
     public boolean isPalindrome(String s) {
       char arr[]=s.toLowerCase().toCharArray();
        StringBuffer str=new StringBuffer();
        for(int i=0;i<arr.length;i++) {
        	if(arr[i]>='a'&&arr[i]<='z'||arr[i]>='0'&&arr[i]<='9')
        		str.append(arr[i]);
        }
        	return str.toString().equals(str.reverse().toString());
    }

}