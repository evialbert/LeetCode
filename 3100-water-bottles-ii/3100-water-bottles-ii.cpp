class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int eb=numBottles;
        int bd=numBottles;
        numBottles=0;
        while(eb>=numExchange){
            
            eb-=numExchange;
            numExchange+=1;
            eb+=1;
            bd+=1;
            cout<<eb<<numExchange<<bd;
        }
        return bd;
    }
};