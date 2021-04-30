class Solution {
    
    public int[] decompose(String s) {
        int idx = s.indexOf("+");
        int n = s.length();
        
        return new int[] {
            Integer.valueOf(s.substring(0, idx)),
            Integer.valueOf(s.substring(idx + 1, n-1))
        };
    }
        
    public String complexNumberMultiply(String a, String b) {
        int[] first = decompose(a);
        int[] second = decompose(b);
        
        StringBuilder sb = new StringBuilder();
        
        return sb.append((first[0]*second[0]-first[1]*second[1]))
            .append("+")
            .append((first[0]*second[1]+first[1]*second[0]))
            .append("i")
            .toString();
    }
}