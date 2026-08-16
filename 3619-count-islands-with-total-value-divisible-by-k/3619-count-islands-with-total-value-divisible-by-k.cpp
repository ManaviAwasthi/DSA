class Solution {
private:
    bool isvalid(int nr, int nc, int n, int m){
        return nr>=0 && nr<n && nc>=0 && nc<m;
    }
    vector <int> dr= {-1,0,1,0};
    vector <int> dc= {0,1,0,-1};

    void bfs(int sr, int sc, vector<vector<int>>& grid, vector <vector <int>> &vis, long long &sum){
        int n=grid.size();
        int m=grid[0].size();
        
        queue <pair <int,int>> q;
        q.push({sr,sc});
        while (!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            sum+=grid[r][c];

            for (int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if (isvalid(nr,nc,n,m) && !vis[nr][nc] && grid[nr][nc]!=0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector <vector <int>> vis(n, vector <int> (m,0));
        int count =0;
        long long sum=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]!=0 && !vis[i][j]){
                    vis[i][j]=1;
                    bfs(i,j,grid,vis,sum);
                    if (sum%k==0) count++;
                    sum=0;
                }
            }
        }

        return count;  
    }
};