class Twitter:

    def __init__(self):
        self.users = {}        
        self.tweets = []

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.users:
            self.users[userId] = {}
            
        self.tweets.append([tweetId,userId])
            
    def getNewsFeed(self, userId: int) -> List[int]:
        i = len(self.tweets)-1
        feed = []
        
        while i>=0 and len(feed)<10:
            temp = self.tweets[i]
            if temp[1]==userId or (temp[1] in self.users[userId]):
                feed.append(temp)
            i -= 1
        
        return list(map(lambda x: x[0],feed))

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.users:
            self.users[followerId] = {}
            
        self.users[followerId][followeeId] = None
    
    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.users[followerId]:
            del self.users[followerId][followeeId]


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)