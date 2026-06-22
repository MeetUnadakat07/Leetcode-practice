class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> minDist(V, INT_MAX);
        vector<bool> mst(V, false);

        minDist[0] = 0;
        int minCost = 0;

        for(int i = 0; i < V; i++) {
            int u = -1;
            for(int v = 0; v < V; v++) {
                if(!mst[v] && (u == -1 || minDist[v] < minDist[u])) {
                    u = v;
                }
            }

            mst[u] = true;
            minCost += minDist[u];

            for(int v = 0; v < V; v++) {
                if(!mst[v]) {
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], wt);
                }
            }
        }
        return minCost;
    }
};
