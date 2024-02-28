class Solution {
public:
    bool check(int index, vector<int>& nums, vector<int>& changeIndices) {
        const int n = nums.size();
        unordered_map<int,int> last;

        for (int i = 0; i <= index; i++) {
            int cur = changeIndices[i];
            last[cur] = i;
        }
        if (last.size() != n) return false;
        int count = 0;
        for (int i = 0; i <= index; i++) {
            int cur = changeIndices[i];
            if (i == last[cur]) {
                int need = nums[cur];
                count -= need;
                if (count < 0) return false;
            }
            else {
                count++;
            }
        }
        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        const int m = changeIndices.size();

        for (int i = 0; i < changeIndices.size(); i++) {
            changeIndices[i]--;
        }

        int left = 0; int right = m-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (check(mid, nums, changeIndices)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left < m ? left+1 : -1;
    }
};