class Solution {
public:
    int v[100001];
    void sieve()
    {
      memset(v, 1, sizeof(v));
      v[0] = v[1] = 0;
      for (int i = 2; i * i <= 100000; i++)
      {
        if (v[i])
        {
          for (int j = i * i; j <= 100000; j += i)
          {
            v[j] = 0;
          }
        }
      }
    }
    int minOperations(int n, int m) {
        sieve();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({n,n});
        vector<int> dist(100000,1e6);
        dist[n]=n;
        while(!pq.empty()) {
            int node=pq.top().second,d=pq.top().first;
            pq.pop();
            if(v[node]) continue;
            if(node==m) return d;
            string s=to_string(node);
            for(int i=0;i<s.size();i++) {
                string t=s;
                if(t[i]!='9') {
                    t[i]=t[i]+1;
                    int x=stoi(t);
                    if(d+x<dist[x]) {
                        dist[x]=d+x;
                        pq.push({dist[x],x});
                    }
                }
                t=s;
                if(t[i]!='0') {
                    t[i]--;
                    int x=stoi(t);
                    if(d+x<dist[x]) {
                        dist[x]=d+x;
                        pq.push({dist[x],x});
                    }
                }
            }
        }
        return -1;
    }
};