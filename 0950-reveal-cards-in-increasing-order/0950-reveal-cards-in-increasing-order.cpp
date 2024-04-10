class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> d1;
        sort(deck.begin(),deck.end(),greater<int>());
        int n = deck.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(d1.size() > 1)
            {
                int x = d1.back();
                d1.pop_back();
                d1.push_front(x);
            }
            d1.push_front(deck[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            deck[i] = d1.front();
            d1.pop_front();
        }
        return deck;
    }
};