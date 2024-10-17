class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        priority_queue<pair<int,int>>q2;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        unordered_map<int,int>cnt;
        unordered_map<int,bool>in;
        long long cur;
        vector<long long>ans;
        for(int i=0;i<k;i++){
            cnt[nums[i]]++;
            cur+=nums[i];
        }
        for(auto &x:cnt){
            q1.push(make_pair(x.second,x.first));
            in[x.first]=true;
        }
        while(q1.size()>x){
            q2.push(q1.top());
            in[q1.top().second]=false;
            cur-=(long long)q1.top().second*(long long)q1.top().first;
            q1.pop();
        }
        int a = q1.size();
        for(int i=0;i<n-k+1;i++){
            if(i!=0){
                cnt[nums[i+k-1]]++;
                if(in[nums[i+k-1]]) {
                    q1.push(make_pair(cnt[nums[i+k-1]],nums[i+k-1]));
                    cur+=nums[i+k-1];
                }
                else q2.push(make_pair(cnt[nums[i+k-1]],nums[i+k-1]));
                cnt[nums[i-1]]--;
                if(in[nums[i-1]]) {
                    q1.push(make_pair(cnt[nums[i-1]],nums[i-1]));
                    cur-=nums[i-1];
                }
                else q2.push(make_pair(cnt[nums[i-1]],nums[i-1]));
                while(!q2.empty()){
                    if(cnt[q2.top().second]!=q2.top().first||in[q2.top().second]) q2.pop();
                    else break;
                }
                while(!q1.empty()){
                    if(cnt[q1.top().second]!=q1.top().first||!in[q1.top().second]) q1.pop();
                    else break;
                }
                if(!q2.empty()){
                    a++;
                    in[q2.top().second]=true;
                    cur+=(long long)q2.top().first*(long long)q2.top().second;
                    q1.push(q2.top());
                    q2.pop();
                }
                if(a>x){
                    in[q1.top().second]=false;
                    cur-=(long long)q1.top().first*(long long)q1.top().second;
                    q2.push(q1.top());
                    q1.pop();
                    a--;
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};