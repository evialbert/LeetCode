class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // sort the time in non-decreasing order
        sort(time.begin(),time.end());
        
        long long l=0,h=(long long)time.back()*totalTrips;
        long long ans;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            long long cnt=0;
            // for a given amount of time (i.e. mid) caluculate the maximum number of trips
            for(int i=0;i<time.size();i++)
            {
                if(time[i]>mid)
                    break;
                cnt+=(mid/time[i]);
            }
            // if count is greater than the trips then assume that to be answer
            // and search in the range [l,mid-1]
            if(cnt>=totalTrips)
            {
                ans=mid;
                h=mid-1;
            }
            // else search in the range [mid+1,h]
            else l=mid+1;
        }
        return ans;
    }
};