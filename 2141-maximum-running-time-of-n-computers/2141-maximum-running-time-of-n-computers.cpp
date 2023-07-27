class Solution {
public:
    bool isPossible(vector<int>& bat, int n, long long avgPowerPerPC){
        long long pow=avgPowerPerPC*n;
        for(int i=0;i<bat.size();i++){
            pow-=min(avgPowerPerPC,(long long)bat[i]);
            if(pow<=0){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& bat) {
        int m=bat.size();
        long long low=*min_element(bat.begin(),bat.end());
        long long high=accumulate(bat.begin(),bat.end(),0L)/n;
        long long ans=0;
        while(low<=high){
            long long avgPowerPerPC=(low+high)/2;
            if(isPossible(bat,n,avgPowerPerPC)==true){
                ans=avgPowerPerPC;
                low=avgPowerPerPC+1;
            }
            else{
                high=avgPowerPerPC-1;
            }
        }
        return ans;
    }
};