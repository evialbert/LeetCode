class Solution {
    public int evaluate(String expression) {
        String[] expr=parse(expression);  // parse
        Stack<String> st=new Stack<>();
        Stack<String> op=new Stack<>();
        st.push(expr[0]);
        for(int i=1;i<expr.length;i++){
            if(expr[i-1].equals("(")){
                op.push(expr[i]);
            }
            
// when ")" comes in, evaluate the inner expression. If the variable is not an integer, we search for its value in the stack from top to bottom.
            else if(expr[i].equals(")")){
                String operator=op.pop();
                int ans;
                if(operator.equals("let")){
                    String tmp=st.pop();
                    if(!isInteger(tmp)) tmp=findValue(st,tmp);
                    ans=Integer.parseInt(tmp);
                    while(!st.peek().equals("(")) st.pop();
                    st.pop();
                }
                else{
                    String s1=st.pop();
                    String s2=st.pop();
                    st.pop();
                    if(!isInteger(s1)) s1=findValue(st,s1);
                    if(!isInteger(s2)) s2=findValue(st,s2);
                    if(operator.equals("add")){
                        ans=Integer.parseInt(s1)+Integer.parseInt(s2);
                    }else{
                        ans=Integer.parseInt(s1)*Integer.parseInt(s2);
                    }
                } 
                if(op.isEmpty()) return ans;
                else st.push(String.valueOf(ans));
            }
            else st.push(expr[i]);   
        }
        return 0;
    }
    private String[] parse(String expression){
        List<String> result=new ArrayList<>();
        int start=0;
        for(int i=0;i<expression.length();i++){
            if(expression.charAt(i)=='('){
                result.add(expression.substring(i,i+1));
                start=i+1;
            }
            if(expression.charAt(i)==')'){
                if(expression.charAt(i-1)!=')') result.add(expression.substring(start,i));
                result.add(expression.substring(i,i+1));
                start=i+1;                
            }
            if(expression.charAt(i)==' '){
                if(expression.charAt(i-1)!=')') result.add(expression.substring(start,i));
                start=i+1;
            }
        }
        return result.toArray(new String[result.size()]);
    }
// check whether a String is an integer
    private boolean isInteger(String s){
        try{
            Integer.parseInt(s);
        }catch(NumberFormatException e){
            return false;
        }catch(NullPointerException e){
            return false;
        }
        return true;
    }
// search for the value of non-integer String from top to bottom
    private String findValue(Stack<String> st, String s){
        List<String> ls=new ArrayList<>(st);
        for(int j=ls.size()-2;j>=0;j--){
            if(ls.get(j).equals(s)){
                s=ls.get(j+1);
                if(isInteger(s)) return s;
            }
        } 
        return s;
    }
}