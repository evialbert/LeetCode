class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
            String s1="",s2="",s3="";
	        for(int i=0;i<firstWord.length();i++){
	            s1 = s1 + (Character.getNumericValue(firstWord.charAt(i))-10);
	        }
	        for(int i=0;i<secondWord.length();i++){
	            s2 = s2 + (Character.getNumericValue(secondWord.charAt(i))-10);
	        }
	        for(int i=0;i<targetWord.length();i++){
	            s3 = s3 + (Character.getNumericValue(targetWord.charAt(i))-10);
	        }
	        return Integer.valueOf(s1)+Integer.valueOf(s2) == Integer.valueOf(s3);
    }
}