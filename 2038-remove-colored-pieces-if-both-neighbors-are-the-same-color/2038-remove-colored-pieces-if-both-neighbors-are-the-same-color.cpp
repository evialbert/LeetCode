class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0,aChances=0,bChances=0;
        for(int i=0;i<colors.length();i++){
            if(colors[i]=='A'){
                if(i-1>-1 && colors[i-1]!='A'){
                    bChances+=b>2? b-2:0;
                    a=0,b=0;
                }
                a++;
            }
            else{
                if(i-1>-1 && colors[i-1]!='B'){
                    aChances+=a>2? a-2:0;
                    b=0,a=0;
                }
                b++;
            }
        }
        aChances+=a>2? a-2:0;
        bChances+=b>2? b-2:0;
        return aChances>bChances? true:false;
    }
};