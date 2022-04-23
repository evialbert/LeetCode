class Solution {
    public String interpret(String command) {
        String res = "";
        for(int i=0; i<command.length(); i++){
            char x = command.charAt(i);
            if(x == 'G'){
                res += "G";
                continue;
            }
            if(x == '('){
                if(command.charAt(i+1) == ')'){
                    res += 'o';
                    i++;
                }
                else if(command.charAt(i+1) == 'a'){
                    res += "al";
                    i+=2;
                }
                
            }
        }
        return res;
    }
}