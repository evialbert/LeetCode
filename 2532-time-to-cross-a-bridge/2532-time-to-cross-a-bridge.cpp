class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) 
    {
        priority_queue<pair<int,int>>left;
        priority_queue<pair<int,int>>right;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>waitLeft;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>waitRight;
        for(int i=0;i<time.size();i++)left.push({time[i][0]+time[i][2],i});
        int curTime=0;
        while(n>=0)
        {
            // cout << curTime << " " << n << endl;
            if(right.size()>0)
            {
                int rightIndex=right.top().second;
                // cout << "right" << " " << rightIndex << endl;
                right.pop();
                curTime=curTime+time[rightIndex][2];
                waitLeft.push({curTime+time[rightIndex][3],rightIndex});
            }else if(left.size()>0&&n>0)
            {
                int leftIndex=left.top().second;
                // cout << "left " << leftIndex << endl;
                left.pop();
                curTime=curTime+time[leftIndex][0];
                waitRight.push({curTime+time[leftIndex][1],leftIndex});
                n--;
            }else
            {
                // cout << "None" << endl;
                int leftTime=waitLeft.size() == 0 ? INT_MAX : waitLeft.top().first;
                int rightTime=waitRight.size() == 0 ? INT_MAX : waitRight.top().first;
                // cout << leftTime << " " << rightTime << endl;
                if(n>0)
                    curTime=min(leftTime,rightTime);
                else
                    curTime=rightTime;
            }
            while(waitLeft.size()&&waitLeft.top().first<=curTime)
            {
                int leftIndex=waitLeft.top().second;
                waitLeft.pop();
                left.push({time[leftIndex][0]+time[leftIndex][2],leftIndex});
            }
            while(waitRight.size()&&waitRight.top().first<=curTime)
            {
                int rightIndex=waitRight.top().second;
                waitRight.pop();
                right.push({time[rightIndex][0]+time[rightIndex][2],rightIndex});
            }
            if(n==0&&waitRight.size()==0&&right.size()==0)break;
        }
        return curTime;
    }
};