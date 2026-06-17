class Solution {
public:
    bool dfs(int curr, int dest, vector<bool> &vis, unordered_map<int, vector<int>> &graph) {
        if(curr == dest) return true;

        vis[curr] = true;
        for(auto neigh : graph[curr]) {
            if(!vis[neigh]) {
                bool found = dfs(neigh, dest, vis, graph);
                if(found) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;

        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        return dfs(source, destination, vis, graph);
    }
};

// BFS
/* 
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;

        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr == destination) return true;

            for(auto neigh : graph[curr]) {
                if(!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }

        return false;
    }
*/
