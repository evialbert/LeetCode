class Solution {
    
    private List<List<String>> ingredients;
    private Set<String> supplies;
    private Map<String, Integer> recipes = new HashMap<>();
    
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        this.ingredients = ingredients;
        this.supplies = new HashSet<>(); // O(K), for O(1) check
        
        for (String s : supplies) {
            this.supplies.add(s);
        }
        
        for (int i = 0; i < recipes.length; ++i) { // O(N), for O(1) check and index retrieval
            this.recipes.put(recipes[i], i);
        }
        
        // Each recipe is checked exactly once if we used the "checked cache"
        // for each recipe, its ingredients list is checked exactly once
        // O(NK)
        List<String> ans = new ArrayList<>();
        Map<Integer, Boolean> checked = new HashMap<>(); // O(N)
        for (int i = 0; i < recipes.length; ++i) {
            if (dfs(i, checked, new HashSet<>())) {
                ans.add(recipes[i]);
            }
        }
        return ans;
    }
    
    boolean dfs(int cur, Map<Integer, Boolean> checked, Set<Integer> visited) {
        if (checked.containsKey(cur)) { // already checked, return result
            return checked.get(cur);
        }
        if (visited.contains(cur)) { // form a circle, cannot work
            return false;
        }
        
        visited.add(cur);
        
        List<String> ings = ingredients.get(cur);
        for (String ing : ings) {
            // if it is a node
            if (recipes.containsKey(ing)) {
                boolean canMake = dfs(recipes.get(ing), checked, visited);
                // if that node can't be made
                if (!canMake) {
                    checked.put(cur, false);
                    return canMake;
                }
            }
            // if it is a leaf and not provided
            else if (!supplies.contains(ing)) {
                checked.put(cur, false);
                return false;
            }
        }
        // all node and leaves can be made/provided
        checked.put(cur, true);
        return true;
    }
}
