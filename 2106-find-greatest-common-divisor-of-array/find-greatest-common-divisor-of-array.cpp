class Solution {
private:
int gcd(int a, int b){
    if(a == 0) {
        return b;
    }
    return gcd(b%a, a);
}
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        return gcd(nums[0], nums[nums.size()-1]);
    }
};