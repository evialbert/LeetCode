class Solution {
public:
    int maxProduct(int n) {
        int ans =1;
        vector<int> num;
        while(n>0){
            int remainder=n%10;
            num.push_back(remainder);
            n=n/10;
        }
        sort(num.rbegin(), num.rend());
        ans=num[0]*num[1];
        return ans;
    }
};