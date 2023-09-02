/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
    stack<TreeNode*> st;
    for (auto p = 0, len = 0, level = 0; p < S.size(); p += len) {
        level = 0, len = 0;

        //acquiring the level 
        while (S[p] == '-') ++level, ++p;

        //acquiring the number
        while (p + len < S.size() && S[p + len] != '-') ++len;

        //creating the node with the acquired number
        TreeNode* n = new TreeNode(stoi(S.substr(p, len)));

        //if we have 3 elements in the stack and the current level is 1
        //the pop the elements until the level and elements in the stack
        //becomes equal
        while (st.size() > level) 
            st.pop();

        //if the left of a node is already is attached then attach the 
        //the new node to the right
        if (!st.empty()) {
            if (st.top()->left == nullptr) 
                st.top()->left = n;
            else 
                st.top()->right = n;
        }
        st.push(n);
    }
    while (st.size() > 1) st.pop();
    return st.top();
    }
};