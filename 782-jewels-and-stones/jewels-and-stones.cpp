class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int nJewels = jewels.length();
        int nStones = stones.length();
        int count = 0;
        for (int i = 0; i < nJewels; i++) {
            for (int j = 0; j < nStones; j++) {
                if (jewels[i] == stones[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};