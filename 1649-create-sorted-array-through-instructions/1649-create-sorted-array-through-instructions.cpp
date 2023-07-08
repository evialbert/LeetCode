class Solution {
   public:
    int createSortedArray(vector<int>& ins) {
        const auto n = ins.size();
        auto sorted = ins;
        sort(sorted.begin(), sorted.end());

        vector<int> lts(n, 0);
        vector<int> gts(n, 0);
        vector<int> eqs(n, 0);
        int ret = 0;
        for (auto v : ins) {
            const auto [lt, gt] = find(sorted, lts, gts, eqs, v);
            insert(sorted, lts, gts, eqs, v);

            ret += min(lt, gt);
            ret %= int(1e9 + 7);
        }

        return ret;
    }

    template <class T>
    pair<int, int> find(
        const T& a, const T& lts, const T& gts, const T& eqs, int v) {
        int l = 0;
        int r = a.size();

        int lt = 0;
        int gt = 0;
        while (true) {
            const auto m = l + (r - l) / 2;
            if (a[m] < v) {
                lt += lts[m] + eqs[m];
                l = m + 1;
            } else if (v < a[m]) {
                gt += gts[m] + eqs[m];
                r = m;
            } else {
                return {lt + lts[m], gt + gts[m]};
            }
        }
    }

    template <class T>
    void insert(const T& a, T& lts, T& gts, T& eqs, int v) {
        int l = 0;
        int r = a.size();
        while (true) {
            const auto m = l + (r - l) / 2;
            if (a[m] < v) {
                ++gts[m];
                l = m + 1;
            } else if (v < a[m]) {
                ++lts[m];
                r = m;
            } else {
                ++eqs[m];
                return;
            }
        }
    }
};