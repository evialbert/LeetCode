class Solution {
public:

    int divisors(int num){
        int sum = 0;
        int cnt = 0;
        for(int i=1;i*i<=num;i++){ 
            if(num%i==0){
                cnt++;
                sum+=i;
                if(i!=num/i){
                    cnt++;
                    sum+=num/i;
                }
            } 
            if(cnt>4) return 0;
        } 
        if(cnt<4) return 0;
        return sum;
    }

    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        for(auto el:nums){
            if(m.find(el)==m.end()) m[el] = divisors(el);
            ans+=m[el];
        }
        return ans;
    }
};