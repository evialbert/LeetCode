class Solution {
public:
    //Time complexity: O(n)
    //Space complexity: O(1)
    int minOperations(vector<int>& A, vector<int>& B) {
        int ans = 0;
        int n = A.size();
        
        auto count = [&]() {
            int ans = 0;
            
            for(int i = n - 2;i >= 0;i--) {
                if(A[n - 1] < A[i]) {
                    if(B[i] > A[n - 1] || A[i] > B[n - 1]) {
                        return -1;
                    }
                    ans++;
                } else if(B[n - 1] < B[i]) {
                    if(B[i] > A[n - 1] || A[i] > B[n - 1]) {
                        return -1;
                    }
                    ans++;
                }
            }
            
            return ans;
        };
        
        int ans1 = count(), ans2 = -1;
        swap(A[n - 1], B[n - 1]);
        ans2 = count();
        if(ans2 != -1) ans2++;
        
        if(ans1 == -1) return ans2;
        if(ans2 == -1) return ans1;
        
        return min(ans1, ans2);
    }
};