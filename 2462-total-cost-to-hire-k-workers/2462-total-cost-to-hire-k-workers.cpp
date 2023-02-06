class Solution {
public:
	long long totalCost(vector<int>& costs, int k, int candidates) {
		priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
		int n=costs.size();
		long long res=0;
		int i=0,j=n-1,sz=0;

		while(i<candidates) pq.push({costs[i],i++});

		while(j>=i&&sz++<candidates) pq.push({costs[j],j--});

		while(k-->0) {
			if(pq.top()[1]>=j) {
				res+=pq.top()[0];
				pq.pop();
				if(i<=j) pq.push({costs[j],j--});
			}
			else {
				res+=pq.top()[0];
				pq.pop();
				if(i<=j) pq.push({costs[i],i++});
			}
		}
		return res;
	}
};