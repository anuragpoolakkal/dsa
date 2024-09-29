class Solution {
public:
    unordered_map<int, vector<pair <int, int>>> graph;
    int count, ss, n;

    void dfs(int node, int parent, int distance) {
        if (distance % ss == 0) count++;
        
        for (auto [child, dis] : graph[node]) {
            if (child != parent) {
                dfs(child, node, distance + dis);
            }
        }
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        n = edges.size() + 1, ss = signalSpeed;

        for (auto vec : edges) {
            int u = vec[0], v = vec[1], d = vec[2];
            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }

        vector<int> number_of_pairs(n, 0);

        for (int parent = 0; parent < n; parent++) {
            int answer = 0, sum = 0;
            vector<int> temp;

            for (auto [child, distance] : graph[parent]) {
                count = 0;
                dfs(child, parent, distance);
                temp.push_back(count);
                sum += count;
            }

            for (auto el : temp) answer += (sum - el) * el;
            number_of_pairs[parent] = answer / 2;
        }
        return number_of_pairs;
    }
};