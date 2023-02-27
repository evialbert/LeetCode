/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* solve(int i, int j, int n, vector<vector<int>> &grid) {

        Node* root;
        int sum = 0;
        
        for(int r = i; r < i+n; r++) {
            for(int c = j; c < j+n; c++) {
                sum += grid[r][c];
            }
        }
        
        if(sum == 0) {
            root = new Node(0, 1);
        }
        else if(sum == n*n) {
            root = new Node(1, 1);
        }
        else {
            root = new Node(1, 0);
            root -> topLeft = solve(i, j, n/2, grid);
            root -> topRight = solve(i, j+n/2, n/2, grid);
            root -> bottomLeft = solve(i+n/2, j, n/2, grid);
            root -> bottomRight = solve(i+n/2, j+n/2, n/2, grid);
        }
        return root;
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        
        int n = grid.size();
        return solve(0, 0, n, grid);
    }
};