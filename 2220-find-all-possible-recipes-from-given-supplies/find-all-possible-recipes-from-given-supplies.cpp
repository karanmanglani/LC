class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> supplySet(supplies.begin(), supplies.end());
    unordered_map<string, vector<string>> recipeForIngredient;
    unordered_map<string, int> indegree;
    
    // Build the dependency graph and initialize indegree for each recipe.
    for (int i = 0; i < recipes.size(); i++) {
        indegree[recipes[i]] = 0;
        for (const auto &ing : ingredients[i]) {
            recipeForIngredient[ing].push_back(recipes[i]);
            // If the ingredient is not available initially, it contributes to the indegree.
            if (supplySet.find(ing) == supplySet.end())
                indegree[recipes[i]]++;
        }
    }
    
    // Queue recipes that can be immediately made (indegree 0)
    queue<string> q;
    vector<string> ans;
    for (int i = 0; i < recipes.size(); i++) {
        if (indegree[recipes[i]] == 0) {
            q.push(recipes[i]);
            ans.push_back(recipes[i]);
            supplySet.insert(recipes[i]); // Treat recipe as a supply once made.
        }
    }
    
    // Process the recipes in a BFS manner.
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        // For each recipe that depends on the current ingredient.
        for (const auto &next : recipeForIngredient[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
                ans.push_back(next);
                supplySet.insert(next);
            }
        }
    }
    return ans;
}

};