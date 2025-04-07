class Solution {
public:
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        int n=a.size(), m=b.size();
        vector<int> ans(k,0);
        //For all i possible brute 
        for(int i=max(0,k-m);i<=min(n,k);i++){
            //i-> the no of element from a 
            //k-i -> the no of element from b
            vector<int> stk1,stk2;
            int rem1=n-i;
            int rem2=m-(k-i);
            //Use Monotonic stack to find the max subseq of req. length
            for(int i=0;i<n;i++){
                while(stk1.size() && rem1 && a[i]>stk1.back()) stk1.pop_back(), rem1--;
                stk1.push_back(a[i]);
            }
            while(rem1>0 && rem1--) stk1.pop_back();

            for(int i=0;i<m;i++){
                while(stk2.size() && rem2 && b[i]>stk2.back()) stk2.pop_back(), rem2--;
                stk2.push_back(b[i]);
            }
            //Merge the 2 sorted vectors
            while(rem2>0 && rem2--) stk2.pop_back();
            vector<int> temp;
            int p1=0,p2=0;
            while(p1<i && p2<k-i){
                if(stk1[p1] == stk2[p2]){
                    int ti= p1;
                    int tj= p2;
                    while(ti<i && tj<k-i && stk1[ti]==stk2[tj]){
                        ti++;
                        tj++;
                    }
                    if(tj == k-i) temp.push_back(stk1[p1]), p1++;
                    else if(ti == i) temp.push_back(stk2[p2]), p2++;
                    else if(stk1[ti]>stk2[tj]) temp.push_back(stk1[p1]), p1++;
                    else temp.push_back(stk2[p2]), p2++;
                }
                else if(stk1[p1]>stk2[p2]){
                    temp.push_back(stk1[p1]);
                    p1++;
                }
                else{
                    temp.push_back(stk2[p2]);
                    p2++;
                }
            }
            while(p1<i) temp.push_back(stk1[p1]), p1++;
            while(p2<k-i) temp.push_back(stk2[p2]), p2++;
            //Find max of all such vectors
            ans=max(ans,temp);
        }
        return ans;
    }
};