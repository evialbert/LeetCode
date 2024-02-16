class Solution {
public:

    typedef long long ll;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        int n = arr.size();
        unordered_map <ll, int> mpp;

        for(auto x: arr)
            mpp[x]++;

        priority_queue <ll, vector <ll>, greater <ll>> pq;

        for(auto x: mpp)
            pq.push(x.second);

        while(!pq.empty() && k > 0)
        {
            k -= pq.top();

            if(k >= 0)
                pq.pop();
        }

        return pq.size();        
    }
};