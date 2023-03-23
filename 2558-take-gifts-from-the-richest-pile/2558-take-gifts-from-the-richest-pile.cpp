class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <int> pq;
        for(auto &i:gifts)
        {
            pq.push(i);
        }
        for(int i=0;i<k;i++)
        {
            pq.push(floor(pow(pq.top(),0.5)));
            pq.pop();
        }
        
        long long sum = 0;
        for(int i=0;i<gifts.size();i++)
        {
            sum = sum+pq.top();
            pq.pop();
        }
        
        return sum;
    }
};