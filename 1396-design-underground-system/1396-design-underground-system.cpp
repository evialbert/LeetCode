class UndergroundSystem {
public:
    map<string,vector<int>> m;
    map<int,pair<int,string>> inn;
    vector<int> v;
    double ans;
    UndergroundSystem() {
    
    }
    
    void checkIn(int id, string stationName, int t) {
        inn[id]={t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        m[inn[id].second+"to"+stationName].push_back(t-inn[id].first);
    }
    
    double getAverageTime(string startStation, string endStation) {
        v = m[startStation+"to"+endStation];
        ans =0;
        for(int i=0;i<v.size();i++){
            ans+=v[i];
        }
        return ans/v.size();
    }
};