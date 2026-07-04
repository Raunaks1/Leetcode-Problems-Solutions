class Solution {
public:
    int minscore = INT_MAX;

    void dfs(int u, vector<vector<pair<int,int>>> &adj, vector<bool> &vis)
    {
        vis[u] = true;

        for (auto &[v, cost] : adj[u])
        {
            minscore = min(minscore, cost);

            if (!vis[v])
                dfs(v, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &e : roads)
        {
            int u = e[0];
            int v = e[1];
            int d = e[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> vis(n + 1, false);

        dfs(1, adj, vis);

        return minscore;
    }
};