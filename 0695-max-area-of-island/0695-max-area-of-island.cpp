class Solution {
    vector <int> dr={-1,0,1,0};
    vector <int> dc={0,1,0,-1};
    void bfs(int sr, int sc, vector <vector <int>> &grid, vector <vector<int>> & vis, int &sz){
        int m=grid.size();
        int n=grid[0].size();
        queue <pair <int, int>> q;
        q.push({sr, sc});
        sz=1;

        while (!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for (int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                    sz++;
                }
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector <vector <int>> vis(m, vector <int> (n,0));
        int ans=0;
        int sz=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    bfs(i,j,grid,vis,sz);
                    ans=max(sz,ans);
                    sz=0;
                }
            }
        }
        return ans;
    }
};