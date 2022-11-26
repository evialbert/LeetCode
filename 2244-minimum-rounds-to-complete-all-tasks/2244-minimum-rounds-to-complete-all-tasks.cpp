class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        int ans=0;
        for(auto it:tasks){
            m[it]++;
        }
        for(auto it:m){
            int val=it.second;
            if(val<2){
                return -1;
            }
            if(val%3==0){
                ans+=val/3;
            }
            if(val%3==2){
                ans+=(val/3)+1;
            }
            if(val%3==1){
                ans+=((val/3)-1)+2;
            }
        }
        return ans;
    }
};