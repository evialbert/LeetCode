class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>v;
        if(n<2) return 0;
        int ans=0,cam=0;
        for(int i=0;i<n;i++){
            string temp=bank[i];
            for(auto j:temp){
                if(j=='1') cam+=1;
            }
            if(cam>0)   {v.push_back(cam);cam=0;}
        }
        for(int i=0;i<v.size();i++){
            if(i!=0)    ans=ans+(v[i]*v[i-1]);
        }
        return ans;
    }
};