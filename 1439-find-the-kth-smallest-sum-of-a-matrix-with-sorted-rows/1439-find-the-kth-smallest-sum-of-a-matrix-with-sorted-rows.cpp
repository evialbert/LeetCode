class Solution {
public:
    int kthSmallest(vector<vector<int>>& list, int k) {
        int m=list.size(),n=list[0].size();
        priority_queue < vector<int> > pq;
        int sum=0;
        vector<int> temp(m+1,0);
        for(int i=0;i<m;i++){
            sum+=list[i][0];
        }
        temp[0]= -(sum);
        pq.push(temp);
        int count=1;
        map<vector<int>, int> maps;
        maps[temp]=1;
        while(!pq.empty()){
            if(count==k) break;
            temp = pq.top();
            pq.pop();
            for(int i=0;i<m;i++){
                vector<int> t=temp;
                if(t[i+1]<n-1){
                    int val = -t[0];
                    val-=list[i][t[i+1]];
                    val+=list[i][t[i+1]+1];
                    t[i+1]++;
                    t[0]=-val;
                    if(maps[t]!=1){
                        pq.push(t);
                        maps[t]=1;
                    }
                }
            }
            count++;
        }
        temp = pq.top();
        return -temp[0];
    }
};