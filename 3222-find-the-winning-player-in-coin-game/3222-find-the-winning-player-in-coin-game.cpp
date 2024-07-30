class Solution {
public:
    string losingPlayer(int x, int y) {
        int flag=-1;
        while(true){
            if(x>0 && y>=4){
                x--;
                y=y-4;
            }
            else{
                break;
            }
          flag=flag*-1;
        }
        if(flag==-1){
            return "Bob";
        }
        else return "Alice";
    }
};