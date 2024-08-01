class Solution {
    public int countSeniors(String[] details) {
        int count=0;
        for(String s:details){
            int age=((s.charAt(11)-'0')*10)+s.charAt(12)-'0';
            if(age>60) count++;
        }
        return count;
    }
}