class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> ans;

        // Iterate through all possible starting digits
        for (int i = 0; i < str.size(); i++) {
            // Form sequential substrings starting from the current digit
            for (int j = i, temp = 0; j < str.size(); j++) {
                temp = temp * 10 + (str[j] - '0');

                // Check if the formed number is within the given range
                if (temp <= high && temp >= low)
                    ans.push_back(temp);
            }
        }

        // Sort the result vector
        sort(ans.begin(), ans.end());

        return ans;
    }
};