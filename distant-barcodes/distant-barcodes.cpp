class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        int n=barcodes.size();
        unordered_map<int, int> m;

        for(int i=0;i<barcodes.size();i++)      // Storing the count
            m[barcodes[i]]++;

        priority_queue<pair<int, int>> pq;

        for(auto x:m)
            pq.push(make_pair(x.second, x.first));      // Adding the count, value pair in priority queue


        vector<int> ans(n,0);       

        int idx=0;
        while(!pq.empty())
        {
            int count=pq.top().first;       // count stores the frequency of most frequent element remaining
            int ele=pq.top().second;        // ele stores the value of the element

            while(count--)
            {
                if(idx>=n)  idx=1;          // After filling even indices, switch to odd indices
                ans[idx]=ele;               // Start placing the most frequent element at even indices
                idx+=2;
            }

            pq.pop();
        }

        return ans;

        
        
    }
};