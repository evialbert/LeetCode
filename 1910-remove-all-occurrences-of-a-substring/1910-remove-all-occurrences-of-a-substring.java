class Solution {
   public String removeOccurrences(String s, String part) {
        if(part.equals(s)) return "";
        String arr[] = s.split(part,2);
        if(arr[0]==s) return s;
        StringBuilder ans = new StringBuilder();
        for(String t: arr)
            ans.append(t);
        return removeOccurrences(ans.toString(), part);
    }
}