class Solution {
public:
    long long calc(vector<int>&ranks,int cars,long long mid){
        long long sum=0LL;
        for(int i=0;i<ranks.size();i++){
            sum+=floor(sqrt(1.0*mid/ranks[i]));
        }
        return sum>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long a=1,b=LONG_MAX;
        while(a<b){
            long long mid=a-(a-b)/2;
            if(calc(ranks,cars,mid))
                b=mid;
            else
                a=mid+1;
        }
        return a;
    }
};
/*
r * n^2 = mid
n = (mid/r)^0.5

*/