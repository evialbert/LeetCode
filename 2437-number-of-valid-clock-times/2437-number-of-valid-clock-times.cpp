class Solution {
public:
    int countTime(string time) {
        int ans = 1;
       if(time[0] == '?' and time[1] == '?'){
           ans*=24;
       }
       if(time[0] == '?' and time[1] != '?'){
           if(time[1] >= '4'){
               ans*=2;
           }
            else if(time[1] <= '3'){
                ans*=3;
            }
           
       }
       if(time[0] != '?' and time[1] == '?'){
           if(time[0] == '0'){
               ans*=10;
           }
            else if(time[0] == '1'){
                ans*=10;
            }
            else if(time[0] == '2'){
                ans*=4;
            }
       }
        if(time[3] == '?' and time[4] == '?'){
            ans*=60;
        }
        if((time[3]=='?' and time[4]!='?')){
            ans*=6;
        }
        if((time[3]!='?' and time[4]=='?'))
        {
            ans*=10;
        }
        return ans;
    }
};