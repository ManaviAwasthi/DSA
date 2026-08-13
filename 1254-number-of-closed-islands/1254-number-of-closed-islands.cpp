class Solution {
    void bfs(queue <pair<int,int>> q, vector<vector<int>>& grid, vector <vector <int>> &vis){
        int m=grid.size();
        int n=grid[0].size();
        vector <int> dr= {-1,0,1,0};
        vector <int> dc= {0,1,0,-1};

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
        queue <pair<int,int>> q;
        vector <vector <int>> vis (m, vector <int> (n,0));
        for (int i=0; i<m; i++){
            if (grid[i][0]==0 && !vis[i][0]){
                vis[i][0]=1;
                q.push({i,0});
                bfs(q,grid,vis);
            }
            if (grid[i][n-1]==0 && !vis[i][n-1]){
                vis[i][n-1]=1;
                q.push({i,n-1});
                bfs(q,grid,vis);
            }
        }
        for (int j=0; j<n; j++){
            if (grid[0][j]==0 && !vis[0][j]){
                vis[0][j]=1;
                q.push({0,j});
                bfs(q,grid,vis);
            }
            if (grid[m-1][j]==0 && !vis[m-1][j]){
                vis[m-1][j]=1;
                q.push({m-1,j});
                bfs(q,grid,vis);
            }
        }

        int ans=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==0 && !vis[i][j]){
                    vis[i][j]=1;
                    ans++;
                    q.push({i,j});
                    bfs(q,grid,vis);

                }
            }
        }
        return ans;
    }
};