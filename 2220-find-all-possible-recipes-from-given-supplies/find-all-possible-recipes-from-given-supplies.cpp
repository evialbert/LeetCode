class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> indegree;
        unordered_map<string,vector<string>> adj;
        unordered_set<string> recipesRecord;
        vector<string> ans;
        stack<string> stk;

        // Build graph and indegree
        for(int i=0; i<ingredients.size(); i++){
            string recipi = recipes[i];
            recipesRecord.insert(recipi);
            for(string ingredient : ingredients[i]){
                adj[ingredient].push_back(recipi);
                indegree[recipi]++;
            }
        }

        // Push all initial supplies into stack
        for(string supply : supplies){
            stk.push(supply);
        }

        // Topological Sort using stack
        while(!stk.empty()){
            string top = stk.top();
            stk.pop();

            if(recipesRecord.find(top) != recipesRecord.end()) {
                ans.push_back(top);
            }

            for(string adjNode : adj[top]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    stk.push(adjNode);
                }
            }
        }

        return ans;
    }
};