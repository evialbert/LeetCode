class Router {
public:
    set<vector<int>>s;
    queue<vector<int>>q;
    map<int,vector<int>>mp;
    int memory;

    Router(int memoryLimit) {
        memory=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(s.find({source,destination,timestamp})!=s.end()){
            return false;
        }
        else
        {
            if(q.size()==memory){
                vector<int>vec=q.front();
                q.pop();
                int t=vec[2];
                int d=vec[1];
                
                auto it=find(mp[d].begin(),mp[d].end(),t);
                mp[d].erase(it);
            }
                
            s.insert({source,destination,timestamp});
            q.push({source,destination,timestamp});
            mp[destination].push_back(timestamp);
            return true;
        }
    }
    
    vector<int>forwardPacket() {
        if(q.size())
        {
            vector<int>vec=q.front();
            s.erase(vec);
            q.pop();
            int t=vec[2];
            int d=vec[1];
           
            auto it=find(mp[d].begin(),mp[d].end(),t);
            mp[d].erase(it);
            return vec;
        }
        return {};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int cnt=0;
          for(auto it:mp[destination])
              {
                  if(it>=startTime and it<=endTime)
                      cnt++;
              }
        return cnt;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */