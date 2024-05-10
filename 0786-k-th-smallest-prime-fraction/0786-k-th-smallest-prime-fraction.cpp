class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<double> fractions;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                fractions.push_back((double)arr[i] / arr[j]);
            }
        }

        sort(fractions.begin(), fractions.end());

        double required = fractions[k - 1];

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if ((double)arr[i] / arr[j] == required) {
                    return {arr[i], arr[j]};
                }
            }
        }
        return {}; // Return an empty vector if no fraction is found.
    }
};