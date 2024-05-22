class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>>ans=new ArrayList<>();
        List<String>temp=new ArrayList<>();
        solve(0,s,ans,temp);
        return ans;
    }
    public void solve(int ind,String s,List<List<String>>ans,List<String>temp){
        if(ind==s.length()){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                temp.add(s.substring(ind,i+1));
                solve(i+1,s,ans,temp);
                temp.remove(temp.size()-1);
            }
        }
    }

    public boolean isPalindrome(String s,int start,int end){
        while(start<=end){
            if(s.charAt(start++)!=s.charAt(end--)){
                return false;
            }
        }
        return true;
    }
}