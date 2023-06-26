class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        int n=costs.size();
        int i=0,j=n-1;
        priority_queue <int, vector<int>, greater<int>> fst,lst; 
        long long int ans=0;
        while(k>0){
            while(fst.size()<can and i<=j){
                fst.push(costs[i]);
                i++;
            }
            while(lst.size()<can and i<=j){
                lst.push(costs[j]);
                j--;
            }
            int a,b;
            if(fst.size()>0){
                a=fst.top();
            }
            else{
                a=INT_MAX;
            }
            if(lst.size()>0){
                b=lst.top();
            }
            else{
                b=INT_MAX;
            }
            if(b<a){
                ans+=b;
                lst.pop();
            }
            else{
                ans+=a;
                fst.pop();
            }
            k--;
        }
        return ans;
    }
};