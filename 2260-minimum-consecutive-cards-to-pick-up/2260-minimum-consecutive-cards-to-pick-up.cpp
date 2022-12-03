class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = 10e5+10;
        int n = cards.size();
        unordered_map<int,pair<int,int>> cnt; // elm -> {cnt, lastIndx};
        for(int i=0;i<n;i++){
            int lastCnt = cnt[cards[i]].first;
            int lastIdx = cnt[cards[i]].second;

            cnt[cards[i]].first += 1;
            cnt[cards[i]].second = i;
            
            if(cnt[cards[i]].first > lastCnt && lastCnt != 0){
                int curr = i - lastIdx + 1;
                ans = min(curr,ans);
            }
        }
        if(ans == 10e5+10) return -1;
        return ans;
    }
};