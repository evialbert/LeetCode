class Solution {
public:
    bool consecutiveSetBits(int n) {

        bool prevOne = false;
        int pairCount = 0;

        while(n > 0){

            int currBit = n & 1;
            
            if(currBit == 1 && prevOne){
                pairCount++;
            }

            prevOne = (currBit == 1);

            n = n >> 1;
        }

        return pairCount == 1;
    }
};