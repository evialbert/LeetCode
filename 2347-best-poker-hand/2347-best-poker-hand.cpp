class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> sameSuits( 5 );
        vector<int> sameRanks( 14 );

        for ( int i = 0; i < suits.size(); ++i ) 
        {
            ++sameRanks[ ranks[i] ];
            ++sameSuits[ suits[i] - 'a' ];
        }

        sort( sameSuits.begin(), sameSuits.end(), greater<int>() );
        if ( sameSuits[0] == 5 ) return "Flush";

        sort( sameRanks.begin(), sameRanks.end(), greater<int>() );
        if ( sameRanks[0] >= 3 ) return "Three of a Kind";
        else if ( sameRanks[0] >= 2 ) return "Pair";

        return "High Card";
    }
};