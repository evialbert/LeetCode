class Solution {
    public int maximumLengthSubstring(String s) {
        int[] arr = new int[26];
        int left = 0, right = 0;
        int max = 0;
        while(right < s.length()){
            arr[s.charAt(right) - 'a']++;
            right++;
            while(left < right && check(arr)){
                arr[s.charAt(left) - 'a']--;
                left++;
            }
            max = Math.max(right - left, max);
        }
        return max;
    }
    public boolean check(int[] arr){
        for(int i=0; i<26; i++){
            if(arr[i] > 2)
                return true;
        }
        return false;
    }
}