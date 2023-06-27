class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        long long sum=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            sum+=target[i];
            pq.push(target[i]);
        }
        
        while(pq.top()!=1){
            int x=pq.top();
            pq.pop();
            
            sum-=x;
            if(sum>=x || sum<=0)return false;
            x%=sum;
            sum+=x;
            if(x)pq.push(x);
            else pq.push(sum);
        }
        return true;
    }
};