class Solution {
public:
    bool canAliceWin(int n) {
        int stoneremove = 10 ;
        // first we will give turn to alice so it is true 
        bool alice_turn = true ;

        while(n > 0)
        {
            //the turn will be change to bob
            if(stoneremove > n)return !alice_turn ;
            //update the n 
            n -= stoneremove ;
            stoneremove-- ;
            alice_turn = !alice_turn ;
        }
        return !alice_turn ;
    }
};