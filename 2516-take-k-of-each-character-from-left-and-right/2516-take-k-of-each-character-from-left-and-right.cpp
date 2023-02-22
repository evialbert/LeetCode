class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3,0);

        for(auto x:s){
            cnt[x-'a']++;
        }

        if(cnt[0]<k || cnt[1]<k || cnt[2]<k){
            return -1;
        }
        int l=0;
        int ans=INT_MAX;
        int n=s.length();
        for(int r=0;r<n;r++){
            //exclude and check how large window we can exclude
            cnt[s[r]-'a']--;
            //if still cnt[s[r]-'a]>=k we can exclude l to r winodow
            //else reduce size of window
            while(cnt[s[r]-'a']<k){
                cnt[s[l]-'a']++;
                l++;
            }
            ans=min(ans,n-(r-l+1));
        }
        return ans;
    }
};
