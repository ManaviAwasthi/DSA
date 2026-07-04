class Solution {
public:
    int minScore(int p, vector<vector<int>>& v) {
        vector<vector<pair<int,int>>> adj(p + 1);

        for (int i = 0; i < v.size(); i++) {
            int u = v[i][0];
            int l = v[i][1];
            int d = v[i][2];

            adj[u].push_back({l, d});
            adj[l].push_back({u, d});
        }

        vector<int> vis(p + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int mind = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                int nb = it.first;
                int wt = it.second;

                mind = min(mind, wt);

                if (!vis[nb]) {
                    vis[nb] = 1;
                    q.push(nb);
                }
            }
        }

        return mind;
    }
};