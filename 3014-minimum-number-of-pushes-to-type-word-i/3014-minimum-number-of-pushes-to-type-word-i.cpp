class Solution {
public:
    int minimumPushes(string word) {
        short int total=0,i=0,value=1;
        while(i<word.length()){
            if(i!=0 && i%8==0){
                value=value+1;
            }
            total=total+value;
            i++;
        }
        return total;
    }
};