class Solution {
    public List<String> letterCasePermutation(String S) {
        List<String> ans = new ArrayList<>();
        ans.add("");
        
        for(char c : S.toCharArray()){
            if(Character.isLetter(c)){
                List<String> newAns = new ArrayList<>();
                for(String t : ans){
                    newAns.add(t+Character.toString(Character.toLowerCase(c)));
                    newAns.add(t+Character.toString(Character.toUpperCase(c)));
                }
                ans = newAns;
            }else{
                for(int i = 0; i < ans.size(); i++){
                    ans.set(i, ans.get(i) + Character.toString(c));
                }
            }
        }
        return ans;
    }
}