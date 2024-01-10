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
   
    void tree_to_graph(TreeNode* root,unordered_map<int,vector<int>> &graph)
    {
        if(root==NULL)
         return ;
        if(root->left!=NULL)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            tree_to_graph(root->left,graph);
        }
        if(root->right!=NULL)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            tree_to_graph(root->right,graph);
        }
    }
    int dfs(int node,  unordered_map<int,vector<int>> &graph, vector<bool> &visited)
    {
        visited[node]=true;
        int maxi=0;
        for(auto &child:graph[node])
        {
            if(!visited[child])
            {
                int distance=dfs(child,graph,visited);
                maxi=max(maxi,distance);
            }
        }

        return maxi+1;
    }
    int amountOfTime(TreeNode* root, int start) {
        

        unordered_map<int,vector<int>> graph;
        tree_to_graph(root,graph);
        vector<bool> visited(1e5+1,false);
        return dfs(start,graph,visited)-1;




    }
};