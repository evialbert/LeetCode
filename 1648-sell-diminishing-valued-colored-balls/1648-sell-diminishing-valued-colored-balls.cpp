class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size(), mod = 1000000007;;
        sort(inventory.begin(), inventory.end());
        long long answer = 0;
		
        for(int j = n - 1; j >= 0 && orders; j--) {
            long long val = inventory[j];
            long long units = min((long long) orders, (n - j) * (val - (j ? inventory[j - 1] : 0)));                 
            long long itr = val - units / (n - j);
            answer = (answer + (n - j) * (val * (val + 1) - itr * (itr + 1)) / 2) % mod;
            answer = (answer + units % (n - j) * itr) % mod;
            orders-= units;
        }
        
        return answer;
    }
};