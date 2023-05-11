class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        map<pair<int,int>,int>dis;
        
        pq.push({0,start[0],start[1]});
        dis[{start[0],start[1]}]=0;

        int best=(abs(start[0]-target[1])+abs(target[0]-start[1]));
        
        while(!pq.empty()){
            int currNodei=pq.top()[1];
            int currNodej=pq.top()[2];
            int currDist=pq.top()[0];

            pq.pop();

            best=min(best,abs(currNodei-target[0])+abs(currNodej-target[1])+currDist);

            for(auto &it:specialRoads){
                int cost=currDist+abs(it[0]-currNodei)+abs(it[1]-currNodej)+it[4];
                if(dis.find({it[2],it[3]})==dis.end()){
                    dis[{it[2],it[3]}]=cost;
                    pq.push({cost,it[2],it[3]});
                }
                else if(dis[{it[2],it[3]}]>cost){
                    dis[{it[2],it[3]}]=cost;
                    pq.push({cost,it[2],it[3]});
                }
            }
            
        }
        return best;
    }
};