class AuctionSystem {
public:
   map<int,map<int,int>>mp;
   map<int,set<pair<int,int>>>st;
    AuctionSystem() {    
    }
    void addBid(int userId, int itemId, int bidAmount) {
        if(mp[itemId].find(userId)!=mp[itemId].end()){
            int old=mp[itemId][userId];
            st[itemId].erase({old,userId});
        }
        mp[itemId][userId] = bidAmount;
       st[itemId].insert({bidAmount,userId});
    }  
    void updateBid(int userId, int itemId, int newAmount) {
          addBid(userId,itemId,newAmount);    
    }   
    void removeBid(int userId, int itemId) {
            
               int old=mp[itemId][userId];
            st[itemId].erase({old,userId});
             mp[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        if (st[itemId].empty()) return -1;
     return st[itemId].rbegin()->second;
        
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */