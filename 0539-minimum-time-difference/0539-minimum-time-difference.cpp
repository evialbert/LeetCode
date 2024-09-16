class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time; int n=timePoints.size();
        int ntu;
        for(int i=0;i<n;i++){
            ntu = stoi(timePoints[i].substr(0,2)) *60;
            ntu+=stoi(timePoints[i].substr(3,2));
            time.push_back(ntu);
        }
        sort(time.begin(),time.end());
        int miny=INT_MAX;
        for(int i=1;i<n;i++){
             miny=min(miny,time[i]-time[i-1]);

        }
        return min(miny,(1440-time[n-1])+time[0]);
    }
};