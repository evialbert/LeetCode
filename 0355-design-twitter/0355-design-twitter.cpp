class Twitter {
public:
    vector<pair<int,int>> posts;
    unordered_map<int,unordered_set<int>> mp;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int count = 0;
        for(int i = posts.size() - 1;i >= 0 && count < 10;i--){
            if(posts[i].first == userId || mp[userId].find(posts[i].first) != mp[userId].end()){
                ans.push_back(posts[i].second);
                count++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */