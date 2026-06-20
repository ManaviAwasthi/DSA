class Solution {
private: 
    bool bfs (int node, vector<vector<int>>& v, vector <int> &vis){
        int n=v.size();
        vis[node]=0;
        queue <int> q;
        q.push(node);

        while (!q.empty()){
            int nd=q.front();
            q.pop();

            for (auto it: v[nd]){
                if (vis[it]==-1){
                    vis[it]=!vis[nd];
                    q.push(it);
                }
                else if (vis[it]==vis[nd]){
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int start, int col, vector<vector<int>>& v, vector <int> &vis){
        vis[start]=col;
        for (auto it: v[start]){
            if (vis[it]==-1){
                if (dfs(it,!col,v,vis)==false) return false;
            }
            else if (vis[it]==vis[start]){
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector <int> vis(n,-1);
        for (int i=0; i<n;i++){
            if (vis[i]==-1){
                if (dfs(i,0,v,vis)==false) return false;
            }
        }
        return true; 
    }
};