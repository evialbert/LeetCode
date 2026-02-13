class Solution {
public:
    int n;

    int helper(string s, char x, char y) {
        int countx = 0, county = 0, maxL = 0;
        map<int,int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {

            // break sequence if other character appears
            if (s[i] != x && s[i] != y) {
                mp.clear();
                countx = 0;
                county = 0;
                continue;
            }

            if (s[i] == x) countx++;
            else county++;

            if (countx == county) {
                maxL = max(maxL, countx + county);
                continue;
            }

            if (mp.find(countx - county) != mp.end()) {
                maxL = max(maxL, i - mp[countx - county]);
            } else {
                mp[countx - county] = i;
            }
        }

        return maxL;
    }

    int longestBalanced(string s) {
        n = s.size();
        int maxS = 0;

        // Case 1: single character longest run
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) count++;
            else {
                maxS = max(maxS, count);
                count = 1;
            }
        }
        maxS = max(maxS, count);

        // Case 2: two-character balance
        maxS = max(maxS, helper(s, 'a', 'b'));
        maxS = max(maxS, helper(s, 'b', 'c'));
        maxS = max(maxS, helper(s, 'a', 'c'));

        // Case 3: all three characters balanced
        int countA = 0, countB = 0, countC = 0;
        map<pair<int,int>, int> diffMap;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') countA++;
            if (s[i] == 'b') countB++;
            if (s[i] == 'c') countC++;

            if (countA == countB && countA == countC) {
                maxS = max(maxS, countA + countB + countC);
                continue;
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;
            pair<int,int> key = {diffAB, diffAC};

            if (diffMap.count(key)) {
                maxS = max(maxS, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }

        return maxS;
    }
};