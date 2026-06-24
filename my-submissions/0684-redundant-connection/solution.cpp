class Disjoint {
public:
    int n;
    vector<int> par;
    vector<int> rank;

    Disjoint(int n) {
        this -> n = n;

        for(int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(par[a] == par[b]) return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjoint dj(edges.size() + 1);
        for(int i = 0; i < edges.size(); i++) {
            if(dj.find(edges[i][0]) == dj.find(edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            } else {
                dj.unionByRank(edges[i][0], edges[i][1]);
            }
        }
        return {-1};
    }
};
