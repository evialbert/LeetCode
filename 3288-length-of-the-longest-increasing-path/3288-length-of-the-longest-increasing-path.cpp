class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        vector<int> keyCordinate = coordinates[k];

        sort(begin(coordinates), end(coordinates), [](const vector<int> &a, const vector<int> &b) -> bool {
			return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0]; // sort x -direction first, if x is same then y should be larger to consider for lis
		});

        vector<int> left, right;
        for(auto &coordinate: coordinates){
            if(coordinate[0] < keyCordinate[0] and coordinate[1] < keyCordinate[1]){
                left.push_back(coordinate[1]);
            }
            if(coordinate[0] > keyCordinate[0] and coordinate[1] > keyCordinate[1]){
                right.push_back(coordinate[1]);
            }
        }
       
        auto lisComputation = [](const vector<int>& pointsY){
            int i, n = pointsY.size();
		    vector<int> lis;
            for (i = 0; i < n; ++i) {
                auto index = lower_bound(lis.begin(), lis.end(), pointsY[i]) - lis.begin();
                if (index >= lis.size()) {
                    lis.push_back(pointsY[i]);
                }
                else {
                    lis[index] = pointsY[i];
                }
            }
            return lis.size();
        };

        return lisComputation(left) +lisComputation(right)+1;
    }
};