class Solution {
    public int minOperations(String[] logs) {
     Stack<Integer>  st=new Stack<>();
    
    for(int i=0;i<logs.length;i++){
        if(!st.isEmpty() && logs[i].contains("../")){
            st.pop();
        }
        else if(logs[i].contains("./")){
            continue;
        }
        else{
            st.push(1);
        }
    }
    return st.size();
}
}