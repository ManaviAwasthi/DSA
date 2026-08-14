class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector <vector <int>> adj(n);
        for (int i=0; i<roads.size(); i++){
            int u= roads[i][0];
            int v= roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int rank= adj[i].size()+ adj[j].size();

                for (auto it: adj[i]){
                    if (it==j) {
                        rank--;
                        break;
                    }
                }

                ans=max(ans,rank);
            }
        }
        return ans;
    }
};