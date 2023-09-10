class Solution {
public:
    vector<string> parse(string & ex) {
        vector<string> ret;
        string curr = "";
        for (auto &x:ex) {
            if (x == '-' || x == '+' || x == '*') {
                ret.push_back(curr);
                ret.push_back(string(1,x));
                curr = "";
            } else {
                curr += x;
            }
        }
        ret.push_back(curr);
        
        return ret;
    }
    
    int calc(int a, int b, string & c) {
        if (c == "-") {
            return a - b;
        } else if (c == "+") {
            return a + b;
        }
        
        return a * b;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<string> arr = parse(expression);
        const int n = (int)arr.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i+=2) {
            nums[i] = stoi(arr[i]);
        }
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
		
		// i is the end point
        for (int i = 0; i < n; i+=2) {
		
		    // j is the start point
            for (int j = i; j >= 0; j-=2) {
                if (i == j) {
                    dp[j][i].push_back(nums[i]);
                } else {
                    for (int k = j; k < i; k+=2) {
                        for(auto& x:dp[j][k]) {
                            for(auto & y:dp[k+2][i]) {
                                dp[j][i].push_back(calc(x,y, arr[k+1]));
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};