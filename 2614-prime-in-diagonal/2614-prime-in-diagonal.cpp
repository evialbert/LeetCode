class Solution {
public:
    bool isprime(int num){
        if(num==0 || num==1)return false;
        for(int i=2; i*i<=num; i++){
            if(num%i==0)return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int prime=0;
    for(int i=0; i<nums.size(); i++){
            if(isprime(nums[i][i])){
                prime=max(prime, nums[i][i]);
            }
    }
    int j=0;
    for(int i=nums.size()-1; i>=0; i--, j++){
        if(isprime(nums[j][i])){
                prime=max(prime, nums[j][i]);
        }
    }
        return prime;
    }
};