class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        unordered_map<int,int> m;
        for(auto x : passengers){
            m[x]++;
        }
        
        sort(passengers.begin(),passengers.end());
        sort(buses.begin(),buses.end());
        
        int i = 0;
        int answer = 0;
        int j = 0;
        int cap = 0;
        
        while(j<buses.size()){
            priority_queue<int> pq;
            cap=0;
            while((i<passengers.size()) && (passengers[i] <= buses[j]) && (cap+1 <=capacity)){
                pq.push(passengers[i]);
                i++;
                cap++;
            }
            
            if(cap+1<=capacity){
                if(m[buses[j]]==0){
                    answer = max(answer,buses[j]);
                }
            }
            
            while(pq.size()>0){
                if(m[pq.top()-1] == 0){
                    answer = max(answer,pq.top()-1);
                    break;
                }
                pq.pop();
            }
            
            j++;
        }
        
        
        return answer;
    }
};