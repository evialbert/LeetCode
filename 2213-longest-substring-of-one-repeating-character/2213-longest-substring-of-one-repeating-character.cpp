class Solution {
public:
    struct Node {
        char prefixChar;
        char suffixChar;
        int prefixLen;
        int suffixLen;
        int maxLen;
        int totalLen;
        Node(char c) {
            prefixChar = c;
            suffixChar = c;
            prefixLen = 1;
            suffixLen = 1;
            maxLen = 1;
            totalLen = 1;
        }

        void merge(Node* l, Node* r) {
            maxLen = max(l->maxLen, r->maxLen);
            if(l->suffixChar == r->prefixChar) {
                maxLen = max(maxLen, l->suffixLen+r->prefixLen);
            }
            totalLen = l->totalLen + r->totalLen;

            prefixChar = l->prefixChar;
            suffixChar = r->suffixChar;
            prefixLen = l->prefixLen + (l->prefixLen == l->totalLen && l->suffixChar == r->prefixChar ? r->prefixLen : 0);
            suffixLen = r->suffixLen + (r->suffixLen == r->totalLen && l->suffixChar == r->prefixChar ? l->suffixLen : 0);
        }
    };

    vector<struct Node*> st;

    void buildST(string& s, int idx, int l, int r) {
        st[idx] = new Node(s[l]);
        if(l != r) {
            int m = l + (r-l)/2;
            buildST(s, 2*idx+1, l, m);
            buildST(s, 2*idx+2, m+1, r);
            st[idx]->merge(st[2*idx+1], st[2*idx+2]);
        }
    }

    void update(int idx, int pos, char c, int l, int r) {
        if(l == r) {
            st[idx]->prefixChar = c;
            st[idx]->suffixChar = c;
            return;
        }

        int m = l + (r-l)/2;
        if(pos <= m) {
            update(2*idx+1, pos, c, l, m);
        } else {
            update(2*idx+2, pos, c, m+1, r);
        }
        st[idx]->merge(st[2*idx+1], st[2*idx+2]);
    }

    vector<int> longestRepeating(string s, string C, vector<int>& I) {
        vector<int> res;
        int N = s.size();
        st.resize(4*N);
        buildST(s, 0, 0, N-1);
        for(int i = 0; i < C.size(); i++) {
            update(0, I[i], C[i], 0, N-1);
            res.push_back(st[0]->maxLen);
        }
        return res;
        
    }
};