class Solution {
    public int countSegments(String s) {
        if(s == null || s.length() == 0) {
            return 0;
        }
        String arr[] = s.split("\\s+");
        int cnt = 0;
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
            if(arr[i].length() > 0) {
                cnt++;
            }
        } 
        return cnt;    
    }
}