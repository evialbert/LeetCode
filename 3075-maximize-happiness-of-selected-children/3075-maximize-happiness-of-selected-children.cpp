class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int n=happiness.size()-1;
        int count=0;
        long long sum=0,ans=0;
        while(k!=0){
            sum = happiness[n] - count;
            if(sum<=0) ans += 0;
            else ans += sum;
            k--; 
            n--;
            count++;
        }
        return ans;
    }
};