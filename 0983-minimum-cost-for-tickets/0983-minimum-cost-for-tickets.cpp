class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int minCost[366];
        minCost[0] = 0;
        
        unordered_map<int,bool> daysIncluded;
        for(auto day : days)
            daysIncluded[day]=true;
        
        for(int i=1;i<=365;i++)
        {
            if(!daysIncluded[i])
                minCost[i]=minCost[i-1];
            else
            {
                int _1DayPass = minCost[i-1] + costs[0];
                int _7DayPass = minCost[max(0,i-7)] + costs[1];
                int _30DayPass = minCost[max(0,i-30)] + costs[2];

                minCost[i] = min(_1DayPass,min(_7DayPass,_30DayPass));
            }
        }
        return minCost[365];
    }  
};