class Info {
public:
    int u;
    int cost;
    int stops;

    Info(int u, int cost, int stops) {
        this -> u = u;
        this -> cost = cost;
        this -> stops = stops;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push(Info(src, 0, -1));

        while(!q.empty()) {
            Info curr = q.front();
            q.pop();

            for(int i = 0; i < flights.size(); i++) {
                if(flights[i][0] == curr.u) {
                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if(dist[v] > curr.cost + wt && curr.stops < k) {
                        dist[v] = curr.cost + wt;
                        q.push(Info(v, dist[v], curr.stops + 1));
                    }
                }
            }
        }

        if(dist[dst] != INT_MAX) {
            return dist[dst];
        } else {
            return -1;
        }
    }
};
