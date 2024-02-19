class Twitter {
    private Map<Integer, List<Integer>> tweets; // User ID to list of tweet IDs
    private Map<Integer, Set<Integer>> follows; // Follower ID to set of followee IDs
    private Map<Integer, List<int[]>> timeline;

    int timestamp;

    public Twitter() {
        tweets = new HashMap<>();
        follows = new HashMap<>();
        timeline = new HashMap<>();
        timestamp = 0;
        
    }
    
    public void postTweet(int userId, int tweetId) {
        if (!tweets.containsKey(userId)) {
            tweets.put(userId, new ArrayList<>());
        }
        tweets.get(userId).add(tweetId);

        if (!timeline.containsKey(userId)) {
            timeline.put(userId, new ArrayList<>());
        }
        timeline.get(userId).add(new int[]{tweetId, timestamp++});
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        if (timeline.containsKey(userId)) {
            pq.addAll(timeline.get(userId));
        }
        if (follows.containsKey(userId)) {
            for (int followeeId : follows.get(userId)) {
                if (timeline.containsKey(followeeId)) {
                    pq.addAll(timeline.get(followeeId));
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!pq.isEmpty() && result.size() < 10) {
            result.add(pq.poll()[0]);
        }
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        if (!follows.containsKey(followerId)) {
            follows.put(followerId, new HashSet<>());
        }
        follows.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (follows.containsKey(followerId)) {
            follows.get(followerId).remove(followeeId);
        }
    }
}