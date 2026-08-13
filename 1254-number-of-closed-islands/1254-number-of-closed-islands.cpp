class Solution {
     vector <int> dr= {-1,0,1,0};
     vector <int> dc= {0,1,0,-1};
    void bfs(int sr, int sc, vector<vector<int>>& grid, vector <vector <int>> &vis){
        int m=grid.size();
        int n=grid[0].size();
        queue <pair<int,int>> q;
        q.push({sr,sc});

        while (!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();

            for (int i=0; i<4; i++){
                int nr= r+dr[i];
                int nc= c+dc[i];

                if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector <vector <int>> vis (m, vector <int> (n,0));
        for (int i=0; i<m; i++){
            if (grid[i][0]==0 && !vis[i][0]){
                vis[i][0]=1;
                bfs(i,0,grid,vis);
            }
            if (grid[i][n-1]==0 && !vis[i][n-1]){
                vis[i][n-1]=1;
                bfs(i,n-1,grid,vis);
            }
        }
        for (int j=0; j<n; j++){
            if (grid[0][j]==0 && !vis[0][j]){
                vis[0][j]=1;
                bfs(0,j,grid,vis);
            }
            if (grid[m-1][j]==0 && !vis[m-1][j]){
                vis[m-1][j]=1;
                bfs(m-1, j, grid,vis);
            }
        }

        int ans=0;
        for (int i=1; i<m-1; i++){
            for (int j=1; j<n-1; j++){
                if (grid[i][j]==0 && !vis[i][j]){
                    vis[i][j]=1;
                    ans++;
                    bfs(i,j ,grid,vis);

                }
            }
        }
        return ans;
    }
};