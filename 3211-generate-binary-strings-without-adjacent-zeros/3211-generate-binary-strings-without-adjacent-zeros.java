class Solution {
    List<String> res = new ArrayList<>();

    public List<String> validStrings(int n) {
        create("", n);
        return res;
    }

    public void create(String s, int n) {
        if(s.length() == n) {
            res.add(s);
            return;
        }

        if(s.isEmpty() || s.charAt(s.length()-1) == '1') {
            create(s+'0', n);
        }

        create(s+'1', n);        
    }
}