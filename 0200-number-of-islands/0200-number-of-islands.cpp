class Solution {
    void bfs(int i,int j, vector <vector<int>> &vis, vector<vector<char>>& grid ){
        int m=grid.size();
        int n=grid[0].size();
        queue <pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        vector <int> dr={-1,0,1,0};
        vector <int> dc={0,1,0,-1};
        while (!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for (int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if (nr>=0 && nr<m && nc>=0 && nc<n &&!vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector <vector <int>> vis(m,vector <int> (n));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};