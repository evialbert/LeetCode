class Solution {
     public static List<String> generateParenthesisAns(String p, int open, int close, ArrayList<String> list){
        if(open==0 && close==0){
            list.add(p);
            return list;
        }

        if(open!=0){
            generateParenthesisAns(p+"(",open-1,close,list);
        }
        if(close>open){
            generateParenthesisAns(p+")",open,close-1,list);
        }

        return list;
    }
    
    public List<String> generateParenthesis(int n) {
       return generateParenthesisAns("",n,n,new ArrayList<>());
    }
}