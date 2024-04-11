class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long f=LONG_MIN,s=LONG_MIN,t=LONG_MIN;
        for(auto& i:nums){
            if(i==f || i==s || i==t) continue;
            if(i>f){
                t=s;
                s=f;
                f=i;
            }
            else if(i>s){
                t=s;
                s=i;
            }
            else if(i>t)t=i;
        }
        return t==LONG_MIN?f:t;
    }
};