class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        auto m = false;
        auto n = false;
        auto i = 0;
        auto j = nums.size() - 1;

        while (i <= j) {

            if(!m)
                if(!IsPrime(nums[i])) i++;
                else m = true; 

            if(!n)
                if(!IsPrime(nums[j])) j--;
                else n = true;
            if(m && n) break; 
        }
        return j - i;
    }

private:
    bool IsPrime(int n) {
        if (n == 1) return false;
        for (auto i = 2; i <= n / 2; i++)
            if (n % i == 0) return false;
        return true;
    }
};