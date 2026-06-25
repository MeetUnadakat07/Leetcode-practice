class Solution {
public:
    vector<int> par, rank;

    int find(int x) {
        if (par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB)
            return;

        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        par.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }

        vector<int> indeg(n + 1, 0);
        vector<int> candA, candB;

        // Step 1: Detect the node with 2 parents
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];

            if (indeg[v] == 0) {
                indeg[v] = u;
            } else {
                candA = {indeg[v], v};
                candB = {u, v};
                break;
            }
        }

        // Step 2: Run DSU (Union find)
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];

            // Skip the second parent if edge exists
            if (!candB.empty() && u == candB[0] && v == candB[1]) {
                continue;
            }

            if (find(u) == find(v)) {       // Cycle found
                if (candA.empty()) {        // only cycle, no two parents
                    return e;
                }
                return candA;               // Cyclr + two parents
            }

            unionByRank(u, v);
        }
        // If no cycle found after skipping candB
        return candB;
    }
};
