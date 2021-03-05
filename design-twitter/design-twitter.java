class Twitter {

    class Tweet{
        int id;
        int time;
        public Tweet(int id,int time){
            this.id = id;
            this.time = time;
        }
    }
    
    Map<Integer,ArrayList<Tweet>> tweets;
    Map<Integer,Set<Integer>> followers;
    int timeStamp = 0;
    
    /** Initialize your data structure here. */
    public Twitter() {
        tweets = new HashMap();
        followers = new HashMap();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        tweets.computeIfAbsent(userId,a->new ArrayList()).add(new Tweet(tweetId,timeStamp++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        int k = 10;
        
        PriorityQueue<Tweet> feed = new PriorityQueue<Tweet>((a,b)->{
            return b.time - a.time;
        });
        
        List<Integer> ans = new ArrayList();
        
        for(Tweet tweet : tweets.getOrDefault(userId,new ArrayList<Tweet>())){
            feed.add(tweet);
        }
        
        for(Integer follower : followers.getOrDefault(userId,Collections.emptySet())){
            for(Tweet tweet : tweets.getOrDefault(follower,new ArrayList<Tweet>())){
                feed.add(tweet);
            }
        }
        
        int size = 0;
        while(feed.size() > 0 && size++ < 10){
            ans.add(feed.poll().id);
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        followers.computeIfAbsent(followerId, a->new HashSet()).add(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        if(followers.containsKey(followerId)){
            followers.get(followerId).remove(followeeId);
        }
    }
}