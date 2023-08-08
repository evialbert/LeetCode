class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return purchaseAmount%10<5?100-(purchaseAmount/10)*10:100-((purchaseAmount/10)+1)*10;
    }
};