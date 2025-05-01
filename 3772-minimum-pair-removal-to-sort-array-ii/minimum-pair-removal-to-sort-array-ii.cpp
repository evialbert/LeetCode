struct Node {
    long long val;
    int prevI;
    int nextI;
    bool active;
    int pos;
};

struct Pair {
    long long tot;
    int first;
    int second;
    int leftPos;
};

struct PairComp {
    bool operator()(const Pair& p1, const Pair& p2) const {
        return (p1.tot == p2.tot) ? p1.leftPos < p2.leftPos : p1.tot < p2.tot;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        vector<Node> temp;
        temp.reserve(n * 2);

        for (int i = 0; i < n; i++) {
            temp.push_back({(long long)nums[i], i - 1, i + 1, true, i});
        }
        temp[n - 1].nextI = -1;

        int start = 0;
        int inv = 0;
        for (int i = 0; i < n - 1; i++) {
            if (temp[i].val > temp[i + 1].val)
                inv++;
        }

        set<Pair, PairComp> pairs;
        for (int i = 0; i < n - 1; i++) {
            pairs.insert(
                {temp[i].val + temp[i + 1].val, i, i + 1, temp[i].pos});
        }

        int ops = 0;
        int newIdx = n;

         auto check = [&](int x, int y) -> int {
            return (x == -1 || y == -1) ? 0 : (temp[x].val > temp[y].val ? 1 : 0);
        };


        auto rem = [&](int x, int y) {
            if (x != -1 && y != -1) {
                pairs.erase({temp[x].val + temp[y].val, x, y, temp[x].pos});
            }
        };

        while (inv > 0) {
            while (!pairs.empty() &&
                   (temp[pairs.begin()->first].nextI != pairs.begin()->second ||
                    !temp[pairs.begin()->first].active ||
                    !temp[pairs.begin()->second].active)) {
                pairs.erase(pairs.begin());
            }
            if (pairs.empty())
                break;

            Pair small = *pairs.begin();
            pairs.erase(pairs.begin());

            int left = small.first, right = small.second;
            int bleft = temp[left].prevI;
            int aright = temp[right].nextI;

            int vrem =
                check(bleft, left) + check(left, right) + check(right, aright);

            long long merged = temp[left].val + temp[right].val;
            int mergedPos = temp[left].pos;

            int vnew = (bleft != -1 && temp[bleft].val > merged ? 1 : 0) +
                       (aright != -1 && merged > temp[aright].val ? 1 : 0);

            inv += vnew - vrem;

            if (bleft != -1) rem(bleft, left);
            rem(left,right);
            if (aright != -1) rem(right,left);

            temp[left].active = false;
            temp[right].active = false;

            temp.push_back({merged, bleft, aright, true, mergedPos});

            int mergedIdx = newIdx ++;

            if (bleft != -1) temp[bleft].nextI = mergedIdx;
            if (aright != -1) temp[aright].prevI = mergedIdx;

            if (bleft == -1) start = mergedIdx;

            if (bleft != -1) pairs.insert({temp[bleft].val + merged, bleft, mergedIdx, temp[bleft].pos});
            if (aright != -1) pairs.insert({merged + temp[aright].val, mergedIdx, aright, mergedPos});

            ops++;
            
        }
        return ops;
    }
};