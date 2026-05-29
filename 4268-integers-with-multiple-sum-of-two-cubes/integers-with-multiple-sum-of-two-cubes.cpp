class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        //Hardy-ramanujan number question i.e. generate all hardy ramanujan number
        vector<int>sums;
        for(int a=1;a<n;a++){  // till n calculate all the sums
            long long a3= 1ll* a* a* a;
            if(a3>n){break;}
            for(int b=a;b<n;b++){  // for unique combination start with a not 1
                long long b3= 1ll*b*b*b;
                long long sum=a3+b3;
                if(sum>n){break;} // 1000^3 will be 1e9 so stop
                sums.push_back(sum);
            }
        }
        sort(sums.begin(),sums.end());
        vector<int>res;
        for(int i=1;i<sums.size();i++){
            if(sums[i]==sums[i-1]){   // this sum can be formed mutiple times push only once
                if(res.size()==0 || res.back()!=sums[i]){
                res.push_back(sums[i]);
                }
            }
        }
    return res;
    }
};