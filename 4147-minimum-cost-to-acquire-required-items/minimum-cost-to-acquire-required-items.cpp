class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 < need2){
            // swap so that need1 >= need2
            return minimumCost(cost2, cost1, costBoth, need2, need1);
        }else {
            return min<long long>(
                {
                    // only type 1 and type 2 items
                    1LL * cost1 * need1 + 1LL * cost2 * need2,
                    // only type 3 items, covers both
                    1LL * costBoth * need1,
                    // type 3 for need2, type 1 for rest
                    1LL * costBoth * need2 + 1LL * cost1 * (need1 - need2)
                }
            );
        }
    }
};