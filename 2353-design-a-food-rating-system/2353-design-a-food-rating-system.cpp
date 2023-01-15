class FoodRatings {
public:
    class comp{
        public:
            bool operator()(pair<int,string> p1,pair<int,string> p2){
                if(p1.first>p2.first)
                    return false;
                if(p1.first==p2.first){
                    if(p1.second<p2.second)
                        return false;
                }
                return true;
            }
    };
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>> mp;
    unordered_map<string,pair<int,string>> mm;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            mp[cuisines[i]].push({ratings[i],foods[i]});
            mm[foods[i]].first=ratings[i];
            mm[foods[i]].second=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        mm[food].first=newRating;
        string req_cuisine=mm[food].second;
        mp[req_cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(mp[cuisine].size()){
            pair<int,string> p=mp[cuisine].top();
            string s=p.second;
            int r=p.first;
            if(mm[s].first==r)
                return s;
            mp[cuisine].pop();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */