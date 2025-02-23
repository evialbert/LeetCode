class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        sort(nums1.begin(), nums1.end());

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums2[i], i});
        }
        
        vector<int> res(n, -1);
        int start = 0, end = n - 1;

        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int val = p.first, index = p.second;
            if (nums1[end] > val) {
                res[index] = nums1[end];
                end--;
            }
            else {
                res[index] = nums1[start];
                start++;
            }
        }

        return res;
    }
};