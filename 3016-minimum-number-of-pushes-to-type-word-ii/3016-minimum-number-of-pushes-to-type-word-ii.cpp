class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int curr=1,count=0,ans=0;
        for(int i=0;i<freq.size()&&freq[i]>0;i++){
            if(count!=8){
                ans+=(freq[i]*curr);
                count++;
            }
            else{
                count=0;
                curr++;
                ans+=(freq[i]*curr);
                count++;
            }
        }
        return ans;
    }
};