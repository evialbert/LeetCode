class Solution {
     public String removeOuterParentheses(String S) {
          int count = 0;
         StringBuilder sb = new StringBuilder();
         for(int i = 0; i<S.length(); i++){
              char c = S.charAt(i);
              if(c == '('){
                  count++;
                  if(count == 1){
                     continue;
                 }
             }else{
                count--;
                if(count == 0){
                     continue;
                 }
             }
             
             sb.append(c);
         }
         
         return sb.toString();
     }
}
