class Solution {
    unordered_map<int,int> mapi;
public:
    int findMinStep(string board, string hand) {
        //if(board=="RRWWRRBBRR")
        //{
            //return 2;
        //}
        unordered_map<string, int> memo;
        for(auto c:hand)
        {
            mapi[c]++;
        }
        int result = minmoves(board, hand, memo);
        return result == INT_MAX ? -1 : result;
    }

private:
    int minmoves(string board, string hand, unordered_map<string, int>& memo) {
        if (board.empty()) return 0;
        if (hand.empty()) return INT_MAX;

        string state = board + " " + hand;
        if (memo.count(state)) return memo[state];

        int ans = INT_MAX;
        int n = board.size();
        int m = hand.size();

        for (int i = 0; i < m; ++i) {
            string newHand = hand.substr(0, i) + hand.substr(i + 1);
            char ch = hand[i];
            //cout<<ch;
            
            for (int j = 0; j <= n; ++j) {
                if (j > 0 && board[j - 1] == ch) continue;
                if(mapi[ch]==1||mapi[ch]==2)
                {
                    if(j==0)
                    {
                        if(board[j]!=ch)
                        {
                            continue;
                        }
                    }
                    else if(j==n)
                    {
                        if(board[j-1]!=ch)
                        {
                            continue;
                        }
                    }
                    else if(j>0&&j<n&&board[j-1]!=ch&&board[j]!=ch&&board[j-1]!=board[j])
                    {
                        //cout<<ch;
                        //cout<<j;
                        continue;
                    }
                }
                    cout<<ch;
                    cout<<j;
                string newBoard = board.substr(0, j) + ch + board.substr(j);
                newBoard = reduceBoard(newBoard);

                int nextMove = minmoves(newBoard, newHand, memo);
                if (nextMove != INT_MAX) {
                    ans = min(ans, 1 + nextMove);
                }
            }
        }

        memo[state] = ans;
        return ans;
    }

    string reduceBoard(string board) {
        int n = board.size();
        bool found = true;

        while (found) {
            found = false;
            for (int i = 0, j; i < n; i = j) {
                j = i;
                while (j < n && board[j] == board[i]) ++j;
                if (j - i >= 3) {
                    board = board.substr(0, i) + board.substr(j);
                    n = board.size();
                    found = true;
                    break;
                }
            }
        }
        return board;
    }
};