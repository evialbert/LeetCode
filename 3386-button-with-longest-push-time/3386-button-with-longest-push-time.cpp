class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxt=0;
        int index=0;
        for(int i=1;i<events.size();i++)
        {
                if(events[i][1]-events[i-1][1]>maxt)
                {
                    maxt=events[i][1]-events[i-1][1];
                    index=events[i][0];
                }
                if(events[i][1]-events[i-1][1]==maxt && index>events[i][0])
                {
                    maxt=events[i][1]-events[i-1][1];
                    index=events[i][0];
                }
        }
        if(events[0][1]>maxt )
        {
            index=events[0][0];
        }
         if(events[0][1]==maxt && index>events[0][0])
        {
            index=events[0][0];
        }
        return index;
    }
};