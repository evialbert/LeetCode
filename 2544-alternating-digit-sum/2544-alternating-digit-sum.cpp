class Solution {
public:
     int alternateDigitSum(int n) {
        string num=to_string(n);
        int hold=0;
        for(int i=0;i<num.size();i++){
            int dig=num[i]-'0';
            if(i%2==0){
                hold+=dig;
            }else{
                hold-=dig;
            }
        }
        return hold;
    }
};