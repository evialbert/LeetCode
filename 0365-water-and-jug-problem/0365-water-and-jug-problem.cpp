class Solution {

    bool dfs(int val,vector<int>&visit,vector<int>&vals,int &maxi,int &tC){
        if(val==tC)return 1;
        visit[val]=1;

        for(auto it:vals){
            int n_v = val+it;
            if(n_v>=0 && n_v<=maxi && !visit[n_v]){
                if(dfs(n_v,visit,vals,maxi,tC))
                    return 1;
            }
        }
        return 0;
    }

public:
    bool canMeasureWater(int jC1, int jC2, int tC) {
        vector<int>vals(4,0);
        vals[0]=jC1;
        vals[1]=-jC1;
        vals[2]=jC2;
        vals[3]=-jC2;

        int maxi=jC1+jC2;

        vector<int>visit(maxi+1,0);

        return dfs(0,visit,vals,maxi,tC);
    }
};