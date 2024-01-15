class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> res = new ArrayList<>();
        if(!s.contains(a) || !s.contains(b)) return res;
        int i = s.indexOf(a);
        int j = s.indexOf(b);
        while(i != -1 && j != -1) {
            if(Math.abs(i - j) <= k) {
                res.add(i);
                i = s.indexOf(a, i+1);
            }
            else {
                if(j < i) j = s.indexOf(b, j+1);
                else i = s.indexOf(a, i+1);
            }
        }
        return res;
    }
}