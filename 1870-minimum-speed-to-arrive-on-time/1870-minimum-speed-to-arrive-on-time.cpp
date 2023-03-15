class Solution {
public:
    bool canbeTravelled(vector<int>& dist, int speed, double hour){
        double time = 0;int i = 0;
        for(; i < dist.size() - 1; i++){
            if(dist[i] % speed == 0) time += (dist[i] / speed);
            else time += (dist[i]/speed) + 1;
        }
        time += (dist[i]/(double)speed);
        if(time <= hour) return true;
        return false;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        int l = 1, r = 1000000000;
        while(l <= r){
            int mid = (l + r)/2;
            if(canbeTravelled(dist, mid, hour)){
                ans = mid; r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};