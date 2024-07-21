class Solution {
public:
    bool dfs(int src, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& curr, vector<int>& res) {
        if (curr.count(src)) return false;
        if (visited.count(src)) return true;
        curr.insert(src);
        for (int neighbor : graph[src]) {
            if (!dfs(neighbor, graph, visited, curr, res)) {
                return false;
            }
        }
        curr.erase(src);
        visited.insert(src);
        res.push_back(src);
        return true;
    }
    vector<int> top_sort(unordered_map<int, vector<int>>& graph, int k) {
        unordered_set<int> visited;
        unordered_set<int> curr;
        vector<int> res;
        for (int src = 1; src <= k; ++src) {
            if (!dfs(src, graph, visited, curr, res)) {
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, vector<int>> rowGraph, colGraph;
        for (const auto& edge : rowConditions) {
            rowGraph[edge[0]].push_back(edge[1]);
        }
        for (const auto& edge : colConditions) {
            colGraph[edge[0]].push_back(edge[1]);
        }
        vector<int> row_sorting = top_sort(rowGraph, k);
        vector<int> col_sorting = top_sort(colGraph, k);
        if (row_sorting.empty() || col_sorting.empty()) {
            return {};
        }
        vector<vector<int>> res(k, vector<int>(k, 0));
        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < k; ++i) {
            position[row_sorting[i]].first = i;
            position[col_sorting[i]].second = i;
        }
        for (int i = 1; i <= k; ++i) {
            int row = position[i].first;
            int col = position[i].second;
            res[row][col] = i;
        }
        return res;
    }
};