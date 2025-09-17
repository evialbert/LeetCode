class FoodRatings {
    unordered_map<string, string> mpp1; // food and cuisine
    unordered_map<string, int> mpp2;    // food and ratings

    // cusisine to (food and rating) ka ek ds bnega
    // same cuisine pr saare food with rating store hone chahiye

    unordered_map<string, set<pair<int, string>>> mpp3;
    // cuisine key bnegi
    // values mein bhut saare pairs hai , set mein food and rating ke pair
    // store honge aur same cuisine pr insert krke saare foods+rating store ho
    // jaeynge

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            mpp1[foods[i]] = cuisines[i];
            mpp2[foods[i]] = ratings[i];
            mpp3[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = mpp1[food];
        int oldRating = mpp2[food];
        mpp3[cuisine].erase({-oldRating,food});
        mpp3[cuisine].insert({-newRating,food});
        mpp2[food] = newRating;
    }

    string highestRated(string cuisine) {
       return mpp3[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */