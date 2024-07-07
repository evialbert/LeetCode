class Solution {
public:
     int numWaterBottles(int full, int exchange) {
        int consumed = full;
        int empty = consumed;
        int remaining=0;
        while(empty/exchange>=1){
            full = empty/exchange;
            remaining = empty%exchange;
            consumed = consumed + full;
            empty = remaining + full;
        }
        return consumed;
    }
};