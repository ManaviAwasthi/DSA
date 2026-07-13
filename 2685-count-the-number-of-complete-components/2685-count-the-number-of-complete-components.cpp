class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &nodes, int &edges) {
        if (vis[node]==1) {
            return;
        }
        vis[node] = 1;
        nodes++;
        for (int nb : adj[node]) {
            edges++;
            dfs(nb, adj, vis, nodes, edges);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector <vector <int>> adj(n);

        for (auto it: edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector <int> vis (n,0);
        int ans=0;

        for (int i=0; i<n; i++){
            int nodes=0,edge=0;
            if (!vis[i]){
                dfs(i,adj,vis,nodes,edge);
                if (nodes*(nodes-1)==edge){
                    ans++;
                }
            }
        }
        return ans;
    }
};